#include "fileReadFuncs.h"
#include "graphAlgs.h"


int main(int argc, char *argv[])
{
	//check if file
	if(argc<1)
	{
		perror("\nNo file passed to int main");
	}	
	//Pass file to readFile
	struct node *head = readFile(argv[1]);

	//Pass adjlist to be printed
	printList(head);

	//Send ot BFS
	BFS(head);

	//Print list again
	printList(head);

	//Clear memory
	printf("\n");
	clearMemory(head);
	return 1;
}//end main