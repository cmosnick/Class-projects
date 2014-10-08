#include "fileReadFuncs.c"
struct node* readFile(char filename[]);
struct node* createNodeList(int numNodes);
struct adj* createAdjNode(struct node *orig);
void clearMemory(struct node *head);
void addAdjNode(struct node *head, int node, int adj);