#include "fileReadFuncs.h"
#include "printList.h"


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


	//Clear memory
	clearMemory(head);
	return 1;
}//end main


