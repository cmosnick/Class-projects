#ifndef FILE_SINGLE_C
#define FILE_SINGLE_C
#include "fileReadSingle.c"
struct node* readSingleFile(char filename[]);
struct node* createSingleNodeList(int nodes);
void addAdjNode(struct node *head, int node, int adj);
struct adj* createAdjNode(struct node *orig, int num);
void clearMemory(struct node *head);
#endif