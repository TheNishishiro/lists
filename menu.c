#include "menu.h"

/*
	Zadania:
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 18, 20, 21, 22, 24
		
		Wywolania znajduja sie w pliku main.c
		
		Legenda:
			linia | nazwa_funkcji | linia_wywolania
		
		1)
			Plik: 
				listy.c
			Funkcje:
				15  | AddElement(lista *l, int i)            |  140                            
				24  | AddElementAtEnd(lista *l, int i)       |  145                          
				3   | PrintList(lista list)                  |  93                           
				247 | PrintReversedList(lista *l)            |  157                           
		2)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                     
				205 | RemoveAllOf(lista *l, int number)      |  229
				220 | RemoveAllOfRec(lista *l, int number)   |  181
		3)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                      
				68  | GetMostFrequnet(lista l)   |  206                          
		4)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                      
				366 | RemoveEven(lista *l)       |  192                         
		5)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                      
				153 | RevRec(lista l, lista prop)  |  220  
				291	| ReverseConnections(lista *l) |  232
		6)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                      
				328 | SortList(lista *l, int Wartownik)  | 189                                 
		7)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                      
				381 | MergeLists(lista *l1, lista *l2)   | 200                                 
		8)                                                                                
			Plik:                                                                         
				listy.c                                                                   
			Funkcje:                                                                      
				429 | FindDifference(lista *l1, lista *l2)  | 203                              
		9)                                                                                
			Plik:                                                                         
				listyC.c                                                                  
			Funkcje:                                                                      
				18  | AddElementC(listaC *l, int i)   | 268                                    
				110 | FindElementC(listaC l, int x)   | 279                                    
				67  | RemoveElementC(listaC *l)       | 271                                  
				                                                                          
			Plik:                                                                         
				listyNC.c                                                                 
			Funkcje:                                                                      
				17  | AddElementNC(listaNC *l, int i)  | 247                                  
				92  | FindElementNC(listaNC l, int x)  | 258                                  
				67  | RemoveElementNC(listaNC *l)      | 250                                  
		10)                                                                               
			Plik:                                                                         
				listyC.c                                                                  
			Funkcje:                                                                      
				86  | RemoveEveryOther(listaC *l, int jump) | 284                              
		11)                                                                               
			Plik:                                                                         
				listyPrior.c                                                              
			Funkcje:                                                                      
				24  | AddElementSortedPrior(listaPrior *l, int value, int priority)  | 441     
				38  | RemoveElementPrior(listaPrior *l)                              | 444                              
				98  | EditPrior(listaPrior *l, int index, int priority)              | 451    
		12)                                                                               
			Plik:                                                                         
				listyOC.c                                                                 
			Funkcje:                                                                      
				47  | RemoveInEach(listaOC *l1, listaOC *l2)       | 300                       
		13)                                                                               
			Plik:                                                                         
				binaryTreeCHAR.c                                                          
			Funkcje:                                                                      
				25  | AddToBinaryTreeCHAR(drzewoCHAR *d, drzewoCHAR *ojciec, char* text)  | 400
				85  | RemoveFromBinaryTreeCHAR(drzewoCHAR *d, char* text)				  | 426
				46  | FindInBinaryTreeCHAR(drzewoCHAR *d, char* text)                     | 406
				67  | FindMinBinaryTreeCHAR(drzewoCHAR *d)                                | 418
				59  | FindMaxBinaryTreeCHAR(drzewoCHAR *d)                                | 415
				4   | PrintBinaryTree0CHAR(drzewoCHAR d, int glebokosc)                   | 111
		15)                                                                               
			Plik:                                                                         
				binaryTree.c                                                              
			Funkcje:                                                                      
				369 | CompareTrees(drzewo d1, drzewo d2)  |  340                             
		18)                                                                               
			Plik:                                                                         
				ONP.c                                                                     
			Funkcje:                                                                      
				7   | CreateONP(lista *l)  | 217                                               
		20)                                                                               
			Plik:                                                                         
				Sorting.c                                                                 
			Funkcje:                                                                      
				160 | BubbleSort(int input[], int n, int print)        | 543                   
				87  | InsertionSort(int input[], int n, int print)     | 544                   
				384 | ShellSort(int input[], int n, int print)         | 545                  
				321 | Quicksort(int input[], int p, int r, int print)  | 546                  
		21)                                                                               
			Plik:                                                                         
				Sorting.c                                                                 
			Funkcje:                                                                      
				288 | BuildHeapF(float A[], int n)                                        
				253 | HeapifyF(float A[], int i, int heapSize)                            
				301 | HeapSortF(float input[], int n, int print)     |  556                   
		22)                                                                               
			Plik:                                                                         
				Sorting.c                                                                 
			Funkcje:                                                                      
				121 | CountingSort(int input[], int n, int k, int print)   | 521               
		24)                                                                               
			Plik:                                                                         
				graphs.c                                                                  
			Funkcje:                                                                      
				191 | Dijkstra(listaPrior* graph, int n, int source, int destination)   |  603  
				181 | Relax(int u, int v, int w, listaPrior *Q)                           
				167 | Init_Single_Source(int n, int s)                                    
*/



void DrawMenu(int page, int *printType)
{
	char line[25] = "========================";
	printf("Page %d\n", page);
	if(page == 0)
	{
		printf("%s SINGLY LINKED LIST %s", line, line);
		printf("\n1) Add at the begining");
		printf("\n2) Add at the end");
		printf("\n3) Remove first");
		printf("\n4) Remove last");
		printf("\n5) Remove list");
		printf("\n6) View reverse list");
		printf("\n7) Reverse List");
		printf("\n8) Search for");
		printf("\n9) Remove by index");
		printf("\n10) Remove all with specific value rec");
		printf("\n11) Reverse connections rec");
		printf("\n12) Sort list");
		printf("\n13) Remove all even numbers");
		printf("\n14) Add sorted element rec");
		printf("\n15) Merge lists");
		printf("\n16) Find difference between lists");
		printf("\n17) Find most frequent");
		printf("\n18) FIFO add");
		printf("\n19) FIFO take");
		printf("\n20) Calculate ONP equation");
		printf("\n21) Reverse connections rec");
		printf("\n22) Free list rec");
		printf("\n23) Remove all with specific value");
		printf("\n24) Reverse connections");
		printf("\n25) Add element sorted");
		*printType = 0;
	}
	else if(page == 1)
	{
		printf("%s DOUBLY LINKED LIST %s", line, line);
		printf("\n1) Add to non-cyclic list");
		printf("\n2) remove from non-cyclic list");
		printf("\n3) Free non-cyclic list");
		printf("\n4) find in non-cyclic list");
		*printType = 1;
	}
	else if(page == 2)
	{
		printf("%s CIRCULAR DOUBLY LINKED LIST %s", line, line);
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
		printf("%s CIRCULAR LINKED LIST %s", line, line);
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
		printf("\n2) Remove element");
		printf("\n3) Edit priority");
		printf("\n4) Add to priority list without order");
		printf("\n5) Add to priority list with reversed order");
		printf("\n6) Rearrange priority list");
		*printType = 6;
	}
	else if(page == 7)
	{
		printf("%s SORTING %s", line, line);
		printf("\n1) Create array of randoms with given length");
		printf("\n2) Create random array");
		printf("\n3) Create custom array");
		printf("\n4) Print array");
		printf("\n5) Insertion Sort");
		printf("\n6) Counting Sort");
		printf("\n7) Bubble Sort");
		printf("\n8) Heap Sort");
		printf("\n9) Quick Sort");
		printf("\n10) Shell Sort");
		printf("\n11) Compare");
		printf("\n12) Heap sort with float numbers");
		*printType = 7;
	}
	else if(page == 8)
	{
		printf("%s GRAPHS %s", line, line);
		printf("\n1) Create neighbor array");
		printf("\n2) Create list array");
		printf("\n3) Print neighbor array");
		printf("\n4) Print list array");
		printf("\n5) Convert list to array");
		printf("\n6) Reverse list graph");
		printf("\n%s%s", line, line);
		printf("\n7) Create prior list array");
		printf("\n8) Print prior list array");
		printf("\n9) Dijkstra");
		*printType = 8;
	}
	else if(page == 9)
	{
		printf("%s File Manager %s", line, line);
		printf("\n1) Add to folder");
		printf("\n2) Enter subfolder");
		printf("\n3) Leave folder");
		printf("\n4) Remove subfolder");
		printf("\n5) Force remove subfolders [NI]");
		printf("\n6) Find folder");
		*printType = 9;
	}
	
	printf("\n---------------------------------------------------");
	printf("\n100) Quit");
	printf("\n-1) previous page | -2) next page\n\n");
}




