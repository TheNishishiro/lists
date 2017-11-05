#include <stdio.h>
#include <stdlib.h>
#include "listy.h"
#include "listyC.h"
#include "menu.h"
#include "listyNC.h"
#include "listyOC.h"
#include "binaryTree.h"

int main()
{
	lista list = 0;
	lista list2 = 0;
	listaC listC = 0;
	
	listaOC listOC = 0, ostatni = 0;
	listaOC listOC2 = 0, ostatni2 = 0;

	listaNC listNC = 0;
	
	drzewo tree = 0, *w;
	
	int number = 0, options = 0, exit = 1;
	int printType = 0, page = 0;
	
	int i=0;
	
	AddElement(&list2, 1);
	AddElement(&list2, 2);
	AddElement(&list2, 2);
	AddElement(&list2, 4);
	AddElement(&list2, 5);
	AddElement(&list2, 7);
	AddElement(&list2, 9);
	AddElement(&list2, 11);
	AddElement(&list2, 12);
	AddElement(&list2, 13);
	AddElement(&list2, 15);
	AddElement(&list2, 20);
	AddElement(&list2, 24);
	AddElement(&list2, 24);
	AddElement(&list2, 25);
	SortList(&list2, 0);
	
	AddElementOC(&listOC2, &ostatni2, 1);
	AddElementOC(&listOC2, &ostatni2, 3);
	AddElementOC(&listOC2, &ostatni2, 5);
	AddElementOC(&listOC2, &ostatni2, 7);
	AddElementOC(&listOC2, &ostatni2, 9);
	AddElementOC(&listOC2, &ostatni2, 11);
	
	while(exit)
	{
		
		DrawMenu(page, &printType);
		
		if(printType == 0)
			PrintList(list);
		else if(printType == 1)
			PrintListNC(listNC);
		else if(printType == 2)
			PrintListC(listC);
		else if(printType == 3)
			PrintListOC(listOC);
		else if(printType == 4)
			PrintBinaryTree(tree);
					
		printf("\n>");
		
			
		scanf("%d", &options);
		switch(options)
		{
			case -1:
				if(page > 0)
					page -= 1;
				break;
			case -2:
				page += 1;
				break;
			case 1:
				printf("Number: ");
				scanf("%d", &number);
				AddElement(&list, number);
				break;
			case 2:
				printf("Number: ");
				scanf("%d", &number);
				AddElementAtEnd(&list, number);
				break;
			case 3:
				RemoveFirst(&list);
				break;
			case 4:
				RemoveLast(&list);
				break;
			case 5:
				//FreeList(&list);
				FreeListRec(&list);
				break;
			case 6:
				PrintReversedListRec(list);
				system("pause");
				break;
			case 7:
				list = ReverseList(&list);
				break;
			case 8:
				printf("Number: ");
				scanf("%d", &number);
				SearchList(list, number, 0);
				break;
			case 9:
				printf("Index: ");
				scanf("%d", &number);
				RemoveElement(&list, number);
				break;
			case 10:
				printf("Number: ");
				scanf("%d", &number);
				RemoveAllOfRec(&list, number);
				//RemoveAllOf(&list, number);
				break;
			case 11:
				ReverseConnectionsRec(&list, 0, 0);
				//ReverseConnections(&list);
				break;
			case 12:
				printf("Sortowanie z wartownikiem czy bez? [0/1]\n>");
				scanf("%d", &number);
				SortList(&list, number);
				break;
			case 13:
				RemoveEven(&list);
				break;
			case 14:
				printf("Number: ");
				scanf("%d", &number);
			//	AddElementSorted(&list, number);
				AddElementSortedRec(&list, 0, 0, 0, number);
				break;
			case 15:
				MergeLists(&list, &list2);
				break;
			case 16:
				FindDifference(&list, &list2);
				break;
			case 17:
				printf("Number: ");
				scanf("%d", &number);
				FIFOadd(&list, &ostatni, number);
				break;
			case 18:
				FIFO(&list);
				break;
			case 21:
				printf("Number: ");
				scanf("%d", &number);
				AddElementNC(&listNC, number);
				break;
			case 22:
				RemoveElementNC(&listNC);
				break;	
			case 23:
				FreeListNC(&listNC);
				break;
			case 24:
				printf("Number: ");
				scanf("%d", &number);
				FindElementNC(listNC, number);
				break;
			case 31:
				printf("Number: ");
				scanf("%d", &number);
				AddElementC(&listC, number);
				break;
			case 32:
				RemoveElementC(&listC);
				break;	
			case 33:
				FreeListC(&listC);
				break;
			case 34:
				printf("Number: ");
				scanf("%d", &number);
				FindElementC(listC, number);
				break;	
			case 35:
				printf("Remove every: ");
				scanf("%d", &number);
				RemoveEveryOther(&listC, number);
				break;
			case 41:
				printf("Number: ");
				scanf("%d", &number);
				AddElementOC(&listOC, &ostatni, number);
				break;	
			case 42:
				RemoveInEach(&listOC, &listOC2);
				break;
			case 51:
				printf("Number: ");
				scanf("%d", &number);
				AddToBinaryTree(&tree, number);
				break;
			case 52:
				printf("Number: ");
				scanf("%d", &number);
				RemoveFromBinaryTree(&tree, number);
				break;
			case 53:
				printf("Number: ");
				scanf("%d", &number);
				w = FindInBinaryTree(&tree, number);
				if(w != 0)
					printf("%d\n", (*w)->klucz);
				system("pause");
				break;
			case 54:
				w = FindMaxBinaryTree(&tree);
				if(w != 0)
					printf("Max: %d\n", w);
				w = FindMinBinaryTree(&tree);
				if(w != 0)
					printf("Min: %d\n", w);
				system("pause");
				break;
			case 55:
				FreeBinaryTree(&tree);
				break;
			case 60:
				exit = 0;
				break;
			default:
				printf("Unknown command");	
		}

		system("cls");
		
		
	}
	
	
	return 0;
}
