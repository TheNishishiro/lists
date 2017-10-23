#ifndef HEADER_LISTY
#define HEADER_LISTY
struct el
{
	int klucz;
	struct el *nast;	
};
typedef struct el elListy;
typedef elListy *lista;

void PrintList(lista list);
void AddElement(lista *l, int i);
void AddElementAtEnd(lista *l, int i);
void AddElementSorted(lista *l, int value);
void AddElementSortedRec(lista *l, lista p, lista w, lista q, int value);
void FreeList(lista *l);
void FreeListRec(lista *l);
void RemoveFirst(lista *l);
void RemoveLast(lista *l);
lista ReverseList(lista *l);
void PrintReversedList(lista *l);
void PrintReversedListRec(lista l);
void SearchList(lista list, int number);
void RemoveElement(lista *l, int index);
void RemoveAllOf(lista *l, int number);
void RemoveAllOfRec(lista *l, int number);
void ReverseConnections(lista *l);
void SortList(lista *l, int Wartownik);
void SortListWartownik(lista *l);
void RemoveEven(lista *l);


#endif
