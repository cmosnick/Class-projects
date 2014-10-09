#include "fileReadFuncs.c"
struct graphs* readFile(char filename[]);
struct graphs* createNodeList(int numNodes);
struct adj* createAdjNode(struct node *orig, int num);
void clearMemory(struct node *head);
void addAdjNode(struct node *head, int node, int adj);