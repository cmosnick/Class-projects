#include "structs.c"

void printDdistance(struct node *head);


void printDdistance(struct node *head)
{
	struct node *temp = head;
	struct adj *temp2;
	printf("\n%4s| %4s| adjacent nodes:", "node", "dist");
	//Go through each node
	while(temp != NULL)
	{	
		printf("\n%4d| %4.0f|", temp->number, temp->dist);
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