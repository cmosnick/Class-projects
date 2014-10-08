#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 128

struct node
{
	int number;
	struct node *next;
	struct node *adj;
	char color[10];
};
struct node* fileReader(FILE *file);
struct node* createNodeList(int numNodes);
void clearMemory(struct node *head);


int main(int argc, char *argv[])
{
	//check if file
	if(argc<1)
	{
		perror("\nNo file passed to int main");
	}	

	FILE *file = fopen(argv[1], "r");	
	struct node* head = fileReader(file);
	//Check return value
	if(head == NULL)
	{
		printf("\nnodes array null");
	}

	printf("\nThrough main!!\n\n");

	clearMemory(head);
	return 1;
}//end main


/*
Reads file, parses it, creates adjacecny list
*/
struct node* fileReader(FILE *file)
{
	char line[MAX_LINE_LENGTH];
	int nodes;
	//Check pointer passed
	if(file == NULL)
	{
		perror("\nError opening file.");
		return NULL;
	}

	//get num nodes from first line
	fgets(line, MAX_LINE_LENGTH, file);
	sscanf(line, "%d", &nodes);
	if(nodes == EOF) return NULL;

	//printf("\nNumber of nodes: %d\n\n", nodes);
	struct node *head = createNodeList(nodes);
	
	//Scan through rest fo file & parse out pair sets
	

	
	return head;
}

/*
Creates a linked list of nodes, according to number of nodes specified
*/
struct node* createNodeList(int nodes)
{
	int i;
	//Create head
	struct node *head = malloc(sizeof(struct node));
	head->number = 0;
	struct node *current = head;
	//Creaye rest of nodes in linked list
	for(i=1 ; i<nodes ; i++)
	{
		//Create new nodes, add to linked list
		current->next = malloc(sizeof(struct node));
		current = current->next;
		current->number = i;
		current->next=NULL;
		current->adj = NULL;
	}
	return head;
}


void clearMemory(struct node *head)
{
	struct node *prev;
	while(head != NULL)
	{
		prev = head;
		head = head->next;
		free(head);
	}
}





