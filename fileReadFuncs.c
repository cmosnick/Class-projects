#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 128


/////////////////////////////////////////////////////Data structres
struct node
{
	int number;
	struct node *next;
	struct adj *adj;
	char color[10];
};
struct adj
{
	int number;
	struct adj *next;
	struct node *original;
};

////////////////////////////////////////////////////Prototypes
struct node* readFile(char filename[]);
struct node* createNodeList(int numNodes);
struct adj* createAdjNode(struct node *orig);
void clearMemory(struct node *head);
void addAdjNode(struct node *head, int node, int adj);


////////////////////////////////////////////////////Functions
/*
Reads file, parses it, creates adjacecny list
*/
struct node* readFile(char filename[])
{
	char line[MAX_LINE_LENGTH];
	int nodes, node1, node2;

	//Open file
	FILE *file = fopen(filename, "r");	
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
	char *token;
	//Scan through rest fo file & parse out pair sets
	while(fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		//Parse line
		token = strtok(line, "(");
		while(token != NULL)
		{
			if(sscanf(token, "%d,%d", &node1, &node2) != EOF)
			{
				printf("\n%d,%d", node1, node2);
				//Send to have node added to adjacency list
				addAdjNode(head, node1, node2);
			}
			token = strtok(NULL, "(");
		}
	}

	fclose(file);
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
	head->number = 1;
	struct node *current = head;
	//Create rest of nodes in linked list
	for(i=2 ; i<nodes+1 ; i++)
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

/*
Finds node in linked list, 
finds last adjacency node in node's adjacancy list, 
adds new adjacent to end of list
*/
void addAdjNode(struct node *head, int node, int adj)
{
	if (head == NULL) 
		{	
			printf("\n head is null in add adj node");
			return;
		}
	struct node *temp=head, *nodePtr=NULL, *tempAdjPtr=NULL;
	struct adj *adjPtr=NULL;
	//Go through list until node is found
	while(temp!=NULL)//&& (nodePtr==NULL && tempAdjPtr==NULL))
	{
		//keep track of node and adjacent
		if(temp->number == node) 	nodePtr=temp;
		if(temp->number == adj) 	tempAdjPtr=temp;
		temp = temp->next;
	}

	//find last adjnode in adjacency list of node
	if(nodePtr->adj == NULL)	
	{	//Create adjacency pointer
		nodePtr->adj = createAdjNode(tempAdjPtr);
	}
	else
	{
		adjPtr = nodePtr->adj;
		while(adjPtr!= NULL)
		{
			if(adjPtr->next == NULL) break;
			adjPtr = adjPtr->next;
		}
		//Create adjacency pointer
		adjPtr->next= createAdjNode(tempAdjPtr);
	}	
}

struct adj* createAdjNode(struct node *orig)
{
	struct adj *node= malloc(sizeof(struct adj));
	node-> next = NULL;
	node->original = orig;
	return node;
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