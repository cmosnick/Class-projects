
#include "dfs.c"

void DFS(struct node *head);
void DFS_Visit(struct node *head, struct node*temp, struct queueNode *stack);
void push(struct node *node, struct queueNode *stack);
struct node* pop(struct queueNode *stack);
void printStack(struct queueNode *stack);