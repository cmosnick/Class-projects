#include "structs.c"


void BFS(struct node *head);
void enqueue(struct queue *q, struct node *node, int dist);
struct node* dequeue(struct queue *q);
void enqueueAjdacents(struct node *node, struct queue *q);
void printQ(struct queue *q);


void BFS(struct node *head)
{
	struct queue *q = malloc(sizeof(struct queue));
	q->front = NULL;
	q->end = NULL;

	enqueue(q, head, 0);

	struct node *temp;
	while(q->front != NULL)
	{
		temp = dequeue(q);
		enqueueAjdacents(temp, q);
	}
}


/*
Will create and add new Qnode to end of queue
*/
void enqueue(struct queue *q, struct node *node, int dist)
{	
	//make new Qnode to enqueue to end
	struct queueNode *newnode = malloc(sizeof(struct queueNode));
	//Assign values to new Qnode
	if(newnode != NULL)
	{
		newnode->node = node;
		newnode->next=NULL;
		newnode->node->dist = dist;
		newnode->node->visited = 1;
		if(q->front == NULL)
		{
			q->front = newnode;
		}
		else
		{
			//Make end Qnode referenced by **Qend point to temp as its next
			q->end->next = newnode;
		}
		//Make Qend now point to new Qnode temp
		q->end = newnode;
	}
	else printf("\nEnqueue did not work.");
}


/*
Will remove Qnode from queue, free it from memory
*/
struct node* dequeue(struct queue *q)
{
	struct queueNode *tempPtr;
	struct node *headNode = q->front->node;
	tempPtr=q->front;
	q->front = q->front->next;
	if(q->front == NULL) q->end = NULL;
	free(tempPtr);
	return headNode;
}

/*
Given a Qnode, will enqueue all of its unreached adjacent nodes
*/
void enqueueAjdacents(struct node *node, struct queue *q)
{
	struct adj *adjPtr = node->adj;
	while(adjPtr != NULL)
	{
		if(!adjPtr->original->visited)
		{
			enqueue(q,adjPtr->original, node->dist+1);
		}
		adjPtr = adjPtr->next;
	}
}



void printQ(struct queue *q)
{
	struct queueNode *temp = q->front;
	//printf("\ntemp is at node: %d\n", temp->node->number);
	while(temp != NULL)
	{
		printf(">%d",temp->node->number);
		temp = temp->next;
	}
}