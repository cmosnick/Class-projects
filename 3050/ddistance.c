#include "fileReadSingle.h"
#include "printDdistance.h"
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
	printf("\n\nDistance from node 1 and adjacent nodes: \n");
	printDdistance(head);

	//Clear memory
	printf("\n\n");
	clearMemory(head);
	return 1;
}//end main