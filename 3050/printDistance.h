#ifndef P_D_C
#define P_D_C
#include "printDistance.c"
void printList(struct node *head);
void BFS(struct node *head);
void enqueue(struct queue *q, struct node *node, int dist);
struct node* dequeue(struct queue *q);
void enqueueAjdacents(struct node *node, struct queue *q);
void printQ(struct queue *q);
#endif