#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "menu.h"
#include "listy.h"
#include "listyC.h"
#include "listyPrior.h"
#include "listyNC.h"
#include "listyOC.h"
#include "binaryTree.h"
#include "ONP.h"
#include "Sorting.h"
#include "binaryTreeCHAR.h"
#include "graphs.h"
#include "filemanager.h"

int main()
{
	srand(time(NULL));
	
	lista list = 0, ostatni = 0;
	lista list2 = 0;
	listaPrior listPrior = 0;
	listaC listC = 0, listC2 = 0;
	
	listaOC listOC = 0;
	listaOC listOC2 = 0, ostatni2 = 0;

	listaNC listNC = 0;
	
	drzewo tree = 0, tree2 = 0, tree3 = 0, *w;
	drzewoCHAR treeC = 0, tree2C = 0, tree3C = 0, *wC;
	char text[2048];
	int* numbers;
	float* numbersF;
	int i = 0, sizeOfArray = 0;
	
	int number = 0, priority = 0, exit = 1;
	int printType = 0, page = 0;
	
	int options = 0;
	
	int* NeighborArray;
	int graphPoints = 0; 
	lista* ListArray;
	listaPrior* ListPriorArray;

	FileManager fm = 0, fm_root = 0, *ffm;

	AddElement(&list2, 5);
	AddElement(&list2, 8);
	AddElement(&list2, 16);
	AddElement(&list2, 19);
	
	AddToBinaryTree(&tree2, &tree3, 13);
	AddToBinaryTree(&tree2, &tree3, 8);
	AddToBinaryTree(&tree2, &tree3, 5);
	AddToBinaryTree(&tree2, &tree3, 40);
	AddToBinaryTree(&tree2, &tree3, 35);
	AddToBinaryTree(&tree2, &tree3, 77);
	
	
	AddToBinaryTree(&tree, &tree3, 35);
	AddToBinaryTree(&tree, &tree3, 5);
	AddToBinaryTree(&tree, &tree3, 13);
	AddToBinaryTree(&tree, &tree3, 8);
	AddToBinaryTree(&tree, &tree3, 77);
	AddToBinaryTree(&tree, &tree3, 40);
//	AddToBinaryTree(&tree, &tree3, 82);
	
	SortList(&list2, 0);
	
	AddElementOC(&listOC2, &ostatni2, 1);
	AddElementOC(&listOC2, &ostatni2, 3);
	AddElementOC(&listOC2, &ostatni2, 5);
	AddElementOC(&listOC2, &ostatni2, 7);
	AddElementOC(&listOC2, &ostatni2, 9);
	AddElementOC(&listOC2, &ostatni2, 11);
	
	AddElementC(&listC2, 1);
	AddElementC(&listC2, 3);
	AddElementC(&listC2, 7);
	AddElementC(&listC2, 11);
	AddElementC(&listC2, 15);
	AddElementC(&listC2, 21);

	while(exit)
	{
		DrawMenu(page, &printType);
		
		if(printType == 0)
		{
			PrintList(list);
			PrintList(list2);
		}
		else if(printType == 1)
			PrintListNC(listNC);
		else if(printType == 2)
		{
			PrintListC(listC);
			PrintListC(listC2);
		}
		else if(printType == 3)
		{
			PrintListOC(listOC);
			PrintListOC(listOC2);
		}
		else if(printType == 4)
			PrintBinaryTree(tree);
		else if(printType == 5)
			PrintBinaryTreeCHAR(treeC);
		else if(printType == 6)
			PrintListPrior(listPrior);
		else if(printType == 9)
		{
			PrintPath(fm_root);
			PrintFolder(fm, fm_root);	
		}
		printf("\n>");
		lista buf;
		int num = 0;
			
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
			case 100:
				exit = 0;
				break;
			default:
				switch(printType)
				{
					case 0:
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
								FreeListRec(&list);
								break;
							case 6:
								PrintReversedList(list);
								system("pause");
								break;
							case 7:
								list = ReverseList(&list);
								break;
							case 8:
								printf("Number: ");
								scanf("%d", &number);
								lista x = SearchList(list, number);
								if(x != 0)
									printf("%d \n", x->klucz);
								else
									printf("not found\n");
								system("pause");
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
								AddElementSortedRec(&list, number);
								break;
							case 15:
								MergeLists(&list, &list2);
								break;
							case 16:
								FindDifference(&list, &list2);
								break;
							case 17:
								GetMostFrequnet(list);
								break;
							case 18:
								printf("Number: ");
								scanf("%d", &number);
								FIFOadd(&list, &ostatni, number);
								break;
							case 19:
								FIFO(&list);
								break;
							case 20:
								CreateONP(&list);
								break;
							case 21:
								list = RevRec(list, 0);
								PrintList(list);
								break;
							case 22:
								FreeList(&list);
								break;
							case 23:
								printf("Number: ");
								scanf("%d", &number);
								RemoveAllOf(&list, number);
								break;
							case 24:
								ReverseConnections(&list);								
								break;
							case 25:
								printf("Number: ");
								scanf("%d", &number);
								AddElementSorted(&list, number);
								break;
						}
						break;
					case 1:
						switch(options)
						{
							case 1:
								printf("Number: ");
								scanf("%d", &number);
								AddElementNC(&listNC, number);
								break;
							case 2:
								RemoveElementNC(&listNC);
								break;	
							case 3:
								FreeListNC(&listNC);
								break;
							case 4:
								printf("Number: ");
								scanf("%d", &number);
								FindElementNC(listNC, number);
								break;
							}
						break;
					case 2:
						switch(options)
						{
							case 1:
								printf("Number: ");
								scanf("%d", &number);
								AddElementC(&listC, number);
								break;
							case 2:
								RemoveElementC(&listC);
								break;	
							case 3:
								FreeListC(&listC);
								break;
							case 4:
								printf("Number: ");
								scanf("%d", &number);
								FindElementC(listC, number);
								break;	
							case 5:
								printf("Remove every: ");
								scanf("%d", &number);
								RemoveEveryOther(&listC, number);
								break;
							case 6:
								MergeListsC(&listC, &listC2);
								break;
						}
						break;
					case 3:
						switch(options)
						{
							case 1:
								printf("Number: ");
								scanf("%d", &number);
								AddElementOC(&listOC, &ostatni2, number);
								break;	
							case 2:
								RemoveInEach(&listOC, &listOC2);
								break;
						}
						break;
					case 4:
						switch(options)
						{
							case 1:
								printf("Number: ");
								scanf("%d", &number);
								AddToBinaryTree(&tree, &tree3, number);
								break;
							case 2:
								printf("Number: ");
								scanf("%d", &number);
								RemoveFromBinaryTree(&tree, number);
								break;
							case 3:
								printf("Number: ");
								scanf("%d", &number);
								w = FindInBinaryTree(&tree, number);
								if(w != 0)
									printf("%d[%d]\n", (*w)->klucz, w);
								else
									printf("Not found\n");
								system("pause");
								break;
							case 4:
								w = FindMaxBinaryTree(&tree);
								if(w != 0)
									printf("Max: %d[%d]\n", (*w)->klucz, w);
								w = FindMinBinaryTree(&tree);
								if(w != 0)
									printf("Min: %d[%d]\n", (*w)->klucz, w);
								system("pause");
								break;
							case 5:
								FreeBinaryTree(&tree);
								break;
							case 6:
								CompareTrees(tree, tree2);
								break;
							case 7:
								w = FindMinBinaryTreeRec(&tree);
								if(w != 0)
									printf("Min: %d[%d]\n", (*w)->klucz, w);
								w = FindMaxBinaryTreeRec(&tree);
								if(w != 0)
									printf("Max: %d[%d]\n", (*w)->klucz, w);
								system("pause");
								break;
							case 8:
								FreeBinaryTreeIT(&tree);
								break;
							case 9:
								printf("Number: ");
								scanf("%d", &number);
								w = FindInBinaryTreeIT(&tree, number);
								if(w != 0)
									printf("%d[%d]\n", (*w)->klucz, w);
								else
									printf("Not found\n");
								system("pause");
								break;
							case 10:
								printf("Number: ");
								scanf("%d", &number);
								AddToBinaryIT(&tree, number);
								break;
							case 11:
								GetTreeDepth(tree);
								break;
							case 12:
								GetTreeLeafs(tree);
								break;
							case 13:
								printf("Number: ");
								scanf("%d", &number);
								AddToBinaryTreeWithoutOrder(&tree, &tree3, number, 'l');
								break;
							case 14:
								if(tree != 0)
								{
									if(TestSymmetry(tree->lewy, tree->prawy) == 1)
										printf("\nTree ISN'T symmetrical\n");
									else
										printf("\nTree IS symmetrical\n");
								}
								else
									printf("Tree is empty\n");
								system("pause");
								break;
							}
							break;
					case 5:
						switch(options)
						{
							case 1:
								printf("String: ");
								scanf("%s", text);
								AddToBinaryTreeCHAR(&treeC, &tree3C, text);
								memset(text, 0, sizeof text);
								break;
							case 2:
								printf("String: ");
								scanf("%s", text);
								wC = FindInBinaryTreeCHAR(&treeC, text);
								if(wC != 0)
									printf("%s[%d]", (*wC)->klucz, wC);
								else
									printf("Not found\n");
								memset(text, 0, sizeof text);
								system("pause");
								break;
							case 3:
								wC = FindMaxBinaryTreeCHAR(&treeC);
								if(wC != 0)
									printf("Max: %s[%d]\n", (*wC)->klucz, wC);
								wC = FindMinBinaryTreeCHAR(&treeC);
								if(wC != 0)
									printf("Min: %s[%d]\n", (*wC)->klucz, wC);
								system("pause");
								break;
							case 4:
								printf("String: ");
								scanf("%s", text);
								RemoveFromBinaryTreeCHAR(&treeC, text);
								break;
							case 5:
								FreeBinaryTreeCHAR(&treeC);
								break;
							}
							break;
					case 6:
						switch(options)
						{
							case 1:
								printf("Number: ");
								scanf("%d", &number);
								printf("Priority: ");
								scanf("%d", &priority);
								AddElementSortedPrior(&listPrior, number, priority);
								break;
							case 2:
								RemoveElementPrior(&listPrior);
								break;
							case 3:
								printf("Index: ");
								scanf("%d", &number);
								printf("New priority: ");
								scanf("%d", &priority);
								EditPrior(&listPrior, number, priority);
								break;
							case 4:
								printf("Number: ");
								scanf("%d", &number);
								printf("Priority: ");
								scanf("%d", &priority);
								AddElementPrior(&listPrior, number, priority);
								break;
							case 5:
								printf("Number: ");
								scanf("%d", &number);
								printf("Priority: ");
								scanf("%d", &priority);
								AddElementSortedPriorReverse(&listPrior, number, priority);
								break;
							case 6:
								printf("Number: ");
								scanf("%d", &number);
								printf("Priority: ");
								scanf("%d", &priority);
								RearrangePriorList(&listPrior, number, priority);
								break;
							}
							break;
					case 7:
						switch(options)
						{
							case 1:
								printf("Size of array: ");
								scanf("%d", &sizeOfArray);
								numbers = calloc(sizeOfArray, sizeof(int));
								for(i = 0; i < sizeOfArray; i++)
								{
									numbers[i] = rand() % 100;
								}
								break;
							case 2:
								sizeOfArray = (rand() % 2000) + 9000;
								printf("Size of array: %d\n", sizeOfArray);
								numbers = calloc(sizeOfArray, sizeof(int));
								for(i = 0; i < sizeOfArray; i++)
								{
									numbers[i] = rand() % 100;
								}
								system("pause");
								break;
							case 3:
								printf("Size of array: ");
								scanf("%d", &sizeOfArray);
								numbers = calloc(sizeOfArray, sizeof(int));
								for(i = 0; i < sizeOfArray; i++)
								{
									printf("Add to array: ");
									scanf("%d", &number);
									numbers[i] = number;
								}
								system("pause");
								break;
							case 4:
								printArray(numbers, sizeOfArray);
								system("pause");
								break;
							case 5:
								InsertionSort(numbers, sizeOfArray, 1);
								system("pause");
								break;
							case 6:
								printf("Numbers from 1 to k=: ");
								scanf("%d", &number);
								CountingSort(numbers, sizeOfArray, number, 1);
								system("pause");
								break;
							case 7:
								BubbleSort(numbers, sizeOfArray, 1);
								system("pause");
								break;
							case 8:
								HeapSort(numbers, sizeOfArray, 1);
								system("pause");
								break;
							case 9:
								Quicksort(numbers, 0, sizeOfArray, 1);
								system("pause");
								break;
							case 10:
								ShellSort(numbers, sizeOfArray, 1);
								system("pause");
								break;
							case 11:
								printf("Print sorted arrays? [0/1]\n");
								scanf("%d", &number);
								BubbleSort(numbers, sizeOfArray, number);
								InsertionSort(numbers, sizeOfArray, number);
								ShellSort(numbers, sizeOfArray, number);
								Quicksort(numbers, 0, sizeOfArray, number);
								HeapSort(numbers, sizeOfArray, number);
								system("pause");
								break;
							case 12:
								printf("Size of array: ");
								scanf("%d", &sizeOfArray);
								numbersF = float_rand(sizeOfArray);
								printArrayF(numbersF, sizeOfArray);
								printf("\n");
								HeapSortF(numbersF, sizeOfArray, 1);
								system("pause");
								break;
							}
							break;
					case 8:
						switch(options)
						{
							case 1:
								printf("Insert number of points:\n");
								scanf("%d", &graphPoints);
								NeighborArray = CreateGraphArray(graphPoints);
								break;
							case 2:	
								printf("Insert number of points:\n");
								scanf("%d", &graphPoints);
								ListArray = CreateGraphList(graphPoints);
								break;
							case 3:	
								PrintGraphArray(NeighborArray, graphPoints);
								system("pause");
								break;
							case 4:	
								PrintGraphList(ListArray, graphPoints);
								system("pause");
								break;
							case 5:	
								NeighborArray = ConvertGraphListToArray(ListArray, graphPoints);
								break;
							case 6:	
								ListArray = CreateGraphReversed(ListArray, graphPoints);
								system("pause");
								break;
							case 7:	
								printf("Insert number of points:\n");
								scanf("%d", &graphPoints);
								ListPriorArray = CreateGraphListPrior(graphPoints);
								break;
							case 8:	
								PrintGraphListPrior(ListPriorArray, graphPoints);
								system("pause");
								break;
							case 9:	
								printf("Source: ");
								scanf("%d", &number);
								printf("Destination: ");
								scanf("%d", &priority);
								Dijkstra(ListPriorArray, graphPoints, number, priority);
								system("pause");
								break;
						}
						break;
					case 9:
						switch(options)
						{
							case 1:
								printf("Folder name: ");
								scanf("%s", text);
								AddToFolder(&fm, &fm_root, text);
								memset(text, 0, sizeof text);
								break;
							case 2:
								printf("Folder name: ");
								scanf("%s", text);
								EnterFolder(&fm, &fm_root, text);
								memset(text, 0, sizeof text);
								break;
							case 3:
								LeaveFolder(&fm, &fm_root);
								break;
							case 4:
								printf("Folder name: ");
								scanf("%s", text);
								RemoveFile(&fm, &fm_root, text);
								memset(text, 0, sizeof text);
								break;
							case 5:
								EmptyFolder(&fm);
							//	fm_root->sub = 0;
								break;
							case 6:
								printf("Folder name: ");
								scanf("%s", text);
								ffm = FindFolder(&fm, text);
								if(ffm == 0)
									printf("Not found");
								else
									printf("%s [%d]\n", (*ffm)->klucz, ffm);
								memset(text, 0, sizeof text);
								system("pause");
								break;
						}
						break;
				}
		}

		system("cls");
		
		
	}
	
	
	return 0;
}
