#include "structs.c"


void printDistance(struct node *head);


void printDistance(struct node *head)
{
	struct node *temp = head;
	struct adj *temp2;
	//Go through each node
	while(temp != NULL)
	{	
		printf("\n%4d| %10f| s:%4d| f:%4d|  ", temp->number, temp->dist, temp->start, temp->finish);
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