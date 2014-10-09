#include "fileReadFuncs.h"
#include "graphAlgs.h"
#include "bfs.h"
#include "dfs.h"


int main(int argc, char *argv[])
{
	//check if file
	if(argc<1)
	{
		perror("\nNo file passed to int main");
	}	
	//Pass file to readFile
	struct graphs *graphs = readFile(argv[1]);

	//Pass adjlist to be printed
	printf("\n\nNewly created adjacancy list:\n");
	printList(graphs->graph);
	printf("\n\nNewly created transverse adjacancy list:\n");
	printList(graphs->transGraph);

	//Send to BFS
	DFS(graphs->graph);

	//Print list again
	printf("\n\nAfter DFS:\n");
	printList(graphs->graph);
	//printList(graphs->transGraph);

	//Clear memory
	printf("\n");
	clearMemory(graphs->graph);
	clearMemory(graphs->transGraph);
	return 1;
}//end main