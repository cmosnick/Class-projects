#ifndef STRUCTS_C
#define STRUCTS_C

struct foo {
    int member;
};
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

#endif