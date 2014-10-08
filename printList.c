#include <stdio.h>

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


void printList(struct node *head)
{


}