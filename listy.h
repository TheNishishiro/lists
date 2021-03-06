#ifndef HEADER_LISTY
#define HEADER_LISTY
struct el
{
	int klucz;
	int licznik;
	struct el *nast;	
};
typedef struct el elListy;
typedef elListy *lista;

void PrintList(lista list);
void AddElement(lista *l, int i);
void AddElementAtEnd(lista *l, int i);
void AddElementSorted(lista *l, int value);
void AddElementSortedRec(lista *l, int value);
void FreeList(lista *l);
void FreeListRec(lista *l);
lista* ReturnFirst(lista *l);
int ListLength(lista *l);
void RemoveFirst(lista *l);
void RemoveLast(lista *l);
lista ReverseList(lista *l);
void PrintReversedList(lista *l);
void PrintReversedListRec(lista l);
lista* SearchList(lista list, int number);
void RemoveElement(lista *l, int index);
void RemoveAllOf(lista *l, int number);
void RemoveAllOfRec(lista *l, int number);
void ReverseConnections(lista *l);
void SortList(lista *l, int Wartownik);
void SortListWartownik(lista *l);
void RemoveEven(lista *l);
void MergeLists(lista *l1, lista *l2);
void FindDifference(lista *l1, lista *l2);
void GetMostFrequnet(lista l);
void FIFOadd(lista *l, lista *p, int i);
void FIFO(lista *l);

#endif
