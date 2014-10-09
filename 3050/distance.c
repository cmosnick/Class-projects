#include "fileReadSingle.h"
#include "printDistance.h"
#include "bfs.h"



int main(int argc, char *argv[])
{
	//check if file
	if(argc<1)
	{
		perror("\nNo file passed to int main");
	}	
	//Pass file to readFile
	struct node *head = readSingleFile(argv[1]);

	//Send to BFS to find distances form node 1
	BFS(head);

	//Print list
	printf("\n\nDistance from node 1:\n");
	printDistance(head);

	//Clear memory
	printf("\n");
	clearMemory(head);
	return 1;
}//end main