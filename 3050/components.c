#include "fileReadDouble.h"
#include "printComponents.h"
#include "dfs.h"


int main(int argc, char *argv[])
{
	//check if file
	if(argc<1)
	{
		perror("\nNo file passed to int main");
	}	
	//Pass file to readFile
	struct graphs *graphs = readDoubleFile(argv[1]);
	if(graphs == NULL) return 0;
	
	//Pass adjlist to be printed
	printf("\n\nNewly created adjacancy list:\n");
	printComponents(graphs->graph);
	printf("\n\nNewly created transverse adjacancy list:\n");
	printComponents(graphs->transGraph);

	//Send to BFS
	DFS(graphs->graph);

	//Print list again
	printf("\n\nAfter DFS:\n");
	printComponents(graphs->graph);

	//Clear memory
	printf("\n");
	clearMemory(graphs->graph);
	clearMemory(graphs->transGraph);
	return 1;
}//end main