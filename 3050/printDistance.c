#include "structs.c"

void printDistance(struct node *head);


void printDistance(struct node *head)
{
	struct node *temp = head;
	struct adj *temp2;
	printf("\n%4s| %4s|", "node", "dist");
	//Go through each node
	while(temp != NULL)
	{	
		printf("\n%4d| %4.0f|", temp->number, temp->dist);
		temp= temp->next;
	}
}


