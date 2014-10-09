#ifndef STRUCTS_C
#define STRUCTS_C
#include <stdlib.h>
#include <stdio.h>
#define NEGINFINITY -INFINITY
typedef int bool;
#define true  1
#define false  0


struct node
{
	int number;
	struct node *next;
	struct adj *adj;
	bool visited;
	float dist;
};
struct adj
{
	int number;
	struct adj *next;
	struct node *original;
};
struct queueNode
{
	struct node *node;
	struct queueNode *next;
};
struct queue
{
	struct queueNode *front;
	struct queueNode *end;
};

#endif