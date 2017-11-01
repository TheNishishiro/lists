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
	*printType = 0;
	}
	else if(page == 1)
	{
	printf("\n21) Add to non-cyclic list");
	printf("\n22) remove from non-cyclic list");
	printf("\n23) Free non-cyclic list");
	printf("\n24) find in non-cyclic list");
	*printType = 1;
	}
	else if(page == 2)
	{
	printf("\n31) Add to cyclic list");
	printf("\n32) remove from cyclic list");
	printf("\n33) Free cyclic list");
	printf("\n34) find in cyclic list");
	printf("\n35) Remove every n-element");
	*printType = 2;
	}
	else if(page == 3)
	{
	printf("\n41) Add to oneway cyclic list");
	printf("\n42) Remove present in other");
	*printType = 3;
	}
	
	printf("\n---------------------------------------------------");
	printf("\n60) Quit");
	printf("\n-1) previous page | -2) next page\n\n");
}




