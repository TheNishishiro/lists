#include <stdio.h>
#include <stdlib.h>
#include "listy.h"
#include "menu.h"

int main()
{
	lista list = 0;
	lista list2 = 0;
	int number = 0, options = 0, exit = 1;
	
	int i=0;
	
	AddElement(&list2, 1);
	AddElement(&list2, 2);
	AddElement(&list2, 3);
	AddElement(&list2, 4);
	AddElement(&list2, 5);
	AddElement(&list2, 9);
	SortList(&list2, 0);
	
	
	while(exit)
	{
		DrawMenu();
		scanf("%d", &options);
		switch(options)
		{
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
			case 20:
				exit = 0;
				break;
			default:
				printf("Unknown command");	
		}

		system("cls");
		
		PrintList(list);
		PrintList(list2);
	}
	
	
	return 0;
}
