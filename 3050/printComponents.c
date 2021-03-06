#include "structs.c"

void printComponents(struct node *head);


void printComponents(struct node *head)
{
	struct node *temp = head;
	struct adj *temp2;
	printf("\n%4s| %7s| adjacent nodes:", "node", "finish");
	//Go through each node
	while(temp != NULL)
	{	
		printf("\n%4d| %7d|", temp->number, temp->finish);
		temp2 = temp->adj;
		//go through each of its adjacent nodes
		while(temp2!=NULL)
		{
			printf(">%d", temp2->number);
			temp2 = temp2->next;
		}
		temp= temp->next;
	}
	return;
}