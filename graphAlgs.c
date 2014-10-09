#include "structs.c"


void printList(struct node *head);
void BFS(struct node *head);
void enqueue(struct queue *q, struct node *node, int dist);
struct node* dequeue(struct queue *q);
void enqueueAjdacents(struct node *node, struct queue *q);
void printQ(struct queue *q);


void printList(struct node *head)
{
	struct node *temp = head;
	struct adj *temp2;
	//Go through each node
	while(temp != NULL)
	{	
		printf("\n%4d| %4f| ", temp->number, temp->dist);
		temp2 = temp->adj;
		//go through each of its adjacent nodes
		while(temp2!=NULL)
		{
			printf(">%d", temp2->number);
			temp2 = temp2->next;
		}
		temp= temp->next;
	}
}


void BFS(struct node *head)
{
	printf("\nIn BFS!!");
	struct queue *q = malloc(sizeof(struct queue));
	q->front = NULL;
	q->end = NULL;

	enqueue(q, head, 0);

	struct node *temp;
	while(q->front != NULL)
	{
		printQ(q);
		temp = dequeue(q);
		enqueueAjdacents(temp, q);
	}
}


/*
Will create and add new Qnode to end of queue
*/
void enqueue(struct queue *q, struct node *node, int dist)
{	
	printf("\nEnqueueing node:  %d\n", node->number);
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
	printf("\nEnqueueing adjacents of %d", node->number);
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