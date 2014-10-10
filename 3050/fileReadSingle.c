#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"
#include <math.h>
#define MAX_LINE_LENGTH 128


////////////////////////////////////////////////////Prototypes
struct node* readSingleFile(char filename[]);
struct node* createSingleNodeList(int nodes);
void addAdjNode(struct node *head, int node, int adj);
struct adj* createAdjNode(struct node *orig, int num);
void clearMemory(struct node *head);

////////////////////////////////////////////////////Functions
/*
Reads file, parses it, creates adjacecny list
*/

struct node* readSingleFile(char filename[])
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
	
	printf("\nPut in number, please :)");
	int i;
	scanf("%d", &i);
	//get num nodes from first line
	fgets(line, MAX_LINE_LENGTH, file);
	sscanf(line, "%d", &nodes);
	if(nodes == EOF) return NULL;


	struct node *head = createSingleNodeList(nodes);
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
				//Send to have node added to adjacency list
				addAdjNode(head, node1, node2);
			}
			token = strtok(NULL, "(");
		}
	}
	fclose(file);
	return head;
}



struct node* createSingleNodeList(int nodes)
{
	int i;
	//Create head
	struct node *gHead = malloc(sizeof(struct node));
	gHead->number = 1;
	struct node *current = gHead;

	//Create rest of nodes in linked list
	for(i=2 ; i<nodes+1 ; i++)
	{
		//Create new nodes, add to linked list, for both graph and tranverse of graph
		current->next = malloc(sizeof(struct node));
		current = current->next;
		current->number = i;
		current->next=NULL;
		current->adj = NULL;
		current->dist = -INFINITY;
		current->visited = 0;
	}

	//Create array of pointers to nodes
	return gHead;
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
		nodePtr->adj = createAdjNode(tempAdjPtr, adj);
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
		adjPtr->next= createAdjNode(tempAdjPtr, adj);
	}	
}

/*
Creates and sends back adjacent node to add to main node (vertex)
*/
struct adj* createAdjNode(struct node *orig, int num)
{
	struct adj *node= malloc(sizeof(struct adj));
	node-> next = NULL;
	node->original = orig;
	node->number=num;
	return node;
}

/*
Clears memory of allocated objects/structs
*/
void clearMemory(struct node *head)
{
	struct node *prev;
	struct adj *adjHead, *prevAdj;
	while(head != NULL)
	{
		prev = head;
		adjHead = head->adj;
		head = head->next;
		while(adjHead != NULL)
		{
			prevAdj = adjHead;
			adjHead = adjHead->next;
			free(prevAdj);
		}
		free(head);
	}
}