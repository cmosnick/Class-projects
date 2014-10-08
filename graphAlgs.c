#include <stdio.h>
#include "structs.c"


void printList(struct node *head);
void printList(struct node *head)
{
	struct node *temp = head;
	struct adj *temp2;
	//Go through each node
	while(temp != NULL)
	{	
		printf("\n%4d| ", temp->number);
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


struct node* BFS(struct node *head)
{
	return head;
}