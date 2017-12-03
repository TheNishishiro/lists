#include "menu.h"

void DrawMenu(int page, int *printType)
{
	char line[25] = "========================";
	printf("Page %d\n", page);
	if(page == 0)
	{
		printf("%s LISTS %s", line, line);
		printf("\n1) Add at the begining");
		printf("\n2) Add at the end");
		printf("\n3) Remove first");
		printf("\n4) Remove last");
		printf("\n5) Remove list");
		printf("\n6) View reverse list");
		printf("\n7) Reverse List");
		printf("\n8) Search for");
		printf("\n9) Remove by index");
		printf("\n10) Remove all with specific value");
		printf("\n11) Reverse connections");
		printf("\n12) Sort list");
		printf("\n13) Remove all even numbers");
		printf("\n14) Add sorted element");
		printf("\n15) Merge lists");
		printf("\n16) Find difference between lists");
		printf("\n17) Find most frequent");
		printf("\n18) FIFO add");
		printf("\n19) FIFO take");
		printf("\n20) Calculate ONP equation");
		*printType = 0;
	}
	else if(page == 1)
	{
		printf("%s TWO WAYS NON CYCLIC LISTS %s", line, line);
		printf("\n1) Add to non-cyclic list");
		printf("\n2) remove from non-cyclic list");
		printf("\n3) Free non-cyclic list");
		printf("\n4) find in non-cyclic list");
		*printType = 1;
	}
	else if(page == 2)
	{
		printf("%s CYCLIC LISTS %s", line, line);
		printf("\n1) Add to cyclic list");	
		printf("\n2) remove from cyclic list");
		printf("\n3) Free cyclic list");
		printf("\n4) find in cyclic list");
		printf("\n5) Remove every n-element");
		printf("\n6) Merge cyclic lists");
		*printType = 2;
	}
	else if(page == 3)
	{
		printf("%s ONE WAY CYCLIC LISTS %s", line, line);
		printf("\n1) Add to oneway cyclic list");
		printf("\n2) Remove present in other");
		*printType = 3;
	}
	else if(page == 4)
	{
		printf("%s BINARY TREES %s", line, line);
		printf("\n1) Add to binary tree");
		printf("\n2) Remove from binary tree");
		printf("\n3) Search in binary tree");
		printf("\n4) Find min and max in binary tree");
		printf("\n5) Free binary tree");
		printf("\n6) Compare trees");
		printf("\n7) Find min and max in binary tree recursively");
		printf("\n8) Free binary tree iteratively");
		printf("\n9) Search in binary tree iteratively");
		printf("\n10) Add to binary tree iteratively");
		printf("\n11) Find depth of a binary tree");
		printf("\n12) Count leafs");
		printf("\n13) Add to tree without order");
		printf("\n14) Test symmetry");
		*printType = 4;
	}
	else if(page == 5)
	{
		printf("%s BINARY TREES CHAR %s", line, line);
		printf("\n1) Add to tree");
		printf("\n2) Search in tree");
		printf("\n3) Find min and max in tree");
		printf("\n4) Remove from tree");
		printf("\n5) Free tree");
		*printType = 5;
	}
	else if(page == 6)
	{
		printf("%s PRIORITY LISTS %s", line, line);
		printf("\n1) Add to priority list");
		printf("\n2) Remove highest priority");
		printf("\n3) Edit priority");
		*printType = 6;
	}
	else if(page == 7)
	{
		printf("%s SORTING %s", line, line);
		printf("\n1) Create array of randoms with given length");
		printf("\n2) Create random array");
		printf("\n3) Print array");
		printf("\n4) Insertion Sort");
		printf("\n5) Selection Sort");
		printf("\n6) Bubble Sort");
		printf("\n7) Heap Sort");
		printf("\n8) Quick Sort");
		printf("\n9) Shell Sort");
		printf("\n10) Compare");
		*printType = 7;
	}
	
	printf("\n---------------------------------------------------");
	printf("\n100) Quit");
	printf("\n-1) previous page | -2) next page\n\n");
}




