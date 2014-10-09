#ifndef FILE_DOUBLE_C
#define FILE_DOUBLE_C
#include "fileReadDouble.c"

struct graphs* readDoubleFile(char filename[]);
struct graphs* createDoubleNodeList(int nodes);
void addAdjNode(struct node *head, int node, int adj);
struct adj* createAdjNode(struct node *orig, int num);
void clearMemory(struct node *head);