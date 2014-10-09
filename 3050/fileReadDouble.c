#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"
#include <math.h>
#define MAX_LINE_LENGTH 128


struct graphs* readDoubleFile(char filename[]);
struct graphs* createDoubleNodeList(int nodes);
void addAdjNode(struct node *head, int node, int adj);
struct adj* createAdjNode(struct node *orig, int num);
void clearMemory(struct node *head);



struct graphs* readDoubleFile(char filename[])
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


	struct graphs *graphs = createNodeList(nodes);
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
				addAdjNode(graphs->graph, node1, node2);
				addAdjNode(graphs->transGraph, node2, node1);
			}
			token = strtok(NULL, "(");
		}
	}
	fclose(file);
	return graphs;
}


/*
Creates a linked list of nodes, according to number of nodes specified
Creates transverse of graph at same time
*/
struct graphs* createDoubleNodeList(int nodes)
{
	int i;
	//Create head
	struct node *gHead = malloc(sizeof(struct node));
	struct node *gtHead = malloc(sizeof(struct node));
	struct graphs *graphs = malloc(sizeof(struct graphs));
	graphs->graph = gHead;
	graphs->transGraph = gtHead;

	gHead->number = 1;
	gtHead-> number =1;
	struct node *current = gHead;
	struct node *gtcurrent = gtHead;

	//Create rest of nodes in linked list
	for(i=2 ; i<nodes+1 ; i++)
	{
		//Create new nodes, add to linked list, for both graph and tranverse of graph
		current->next = malloc(sizeof(struct node));
		gtcurrent->next = malloc(sizeof(struct node));

		current = current->next;
		gtcurrent = gtcurrent->next;

		current->number = i;
		gtcurrent->number = i;

		current->next=NULL;
		gtcurrent->next = NULL;

		current->adj = NULL;
		gtcurrent->adj = NULL;

		current->dist = -INFINITY;
		gtcurrent->dist = -INFINITY;

		current->visited = 0;
		gtcurrent->visited = 0;	
	}

	//Create array of pointers to nodes
	return graphs;
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