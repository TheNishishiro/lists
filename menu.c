#include "menu.h"

void DrawMenu(int page, int *printType)
{
	printf("Page %d\n", page);
	if(page == 0)
	{
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
		printf("\n1) Add to non-cyclic list");
		printf("\n2) remove from non-cyclic list");
		printf("\n3) Free non-cyclic list");
		printf("\n4) find in non-cyclic list");
		*printType = 1;
	}
	else if(page == 2)
	{
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
		printf("\n1) Add to oneway cyclic list");
		printf("\n2) Remove present in other");
		*printType = 3;
	}
	else if(page == 4)
	{
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
		*printType = 4;
	}
	else if(page == 5)
	{
		printf("\n1) Add to priority list");
		printf("\n2) Remove highest priority");
		printf("\n3) Edit priority");
		*printType = 5;
	}
	
	printf("\n---------------------------------------------------");
	printf("\n100) Quit");
	printf("\n-1) previous page | -2) next page\n\n");
}




