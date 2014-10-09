#include "structs.c"

void DFS(struct node *head);
void DFS_Visit(struct node *head, struct node*temp);
void push(struct node *node, struct queueNode *stack);
struct node* pop(struct queueNode *stack);
void printStack(struct queueNode *stack);

int time =0;

void DFS(struct node *head)
{
	//push head onto stack
	//push(head, stackHead);
	/*
	struct queueNode *stackHead;
	(stackHead) = malloc(sizeof(struct queueNode));
	(stackHead)->node = head;
	(stackHead)->next =NULL;
	*/
	struct node *temp = head;
	struct adj *adjacent;
	while(temp != NULL)
	{
		//printStack(temp);
		//pop stackhead, push its adjacent onto stack
		//temp = pop(stackHead);
		//adjacent = temp->adj;
		if(temp->visited == 0) //node is unvisited
		{
			DFS_Visit(head, temp);
		}
		temp = temp->next;
	}
}


void DFS_Visit(struct node *head, struct node*temp)
{
	time++;
	temp->start = time;
	temp->visited = 1;
	//Go through temp's adjacents
	struct adj *adjacent = temp->adj;
	while(adjacent != NULL)
	{
		if (adjacent->original->visited ==0)
		{
			DFS_Visit(head, adjacent->original);
		}
		adjacent= adjacent->next;
	}
	temp->visited = 2;
	time ++;
	temp->finish = time;
}

void push(struct node *node, struct queueNode *stack)
{
	printf("\npushing %d onto stack", node->number);
	struct queueNode *newnode = malloc(sizeof(struct queueNode));
	if(stack == NULL)
	{
		stack = newnode;
		newnode->next = NULL;
		newnode->node = node;
		newnode->node->visited = 1;
	}
	else
	{	
		newnode->next = stack;
		stack = newnode;
		newnode->node = node;
		newnode->node->visited = 1;
	}
}


struct node* pop(struct queueNode *stack)
{
	struct node *returnPtr = (stack)->node;
	struct queueNode *temp = stack;

	(stack) = (stack)->next;
	free(temp);
	return returnPtr;
}




void printStack(struct queueNode *stack)
{
	struct queueNode *temp = stack;
	while(temp != NULL)
	{
		printf(">%d", temp->node->number);
		temp= temp->next;
	}
}










