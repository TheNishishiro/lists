#include <stdio.h>
#include <stdlib.h>
#include "listy.h"
#include "menu.h"

int main()
{
	lista list = 0;
	int number = 0, options = 0, exit = 1;
	
	int i=0;

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
				FreeList(&list);
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
				SearchList(list, number);
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
				break;
			case 11:
				ReverseConnectionsRec(&list, 0, 0);
				//ReverseConnections(&list);
				break;
			case 12:
				SortList(&list);
				break;
			case 20:
				exit = 0;
				break;
			default:
				printf("Unknown command");	
		}

		system("cls");
		
		PrintList(list);
	}
	
	
	return 0;
}
