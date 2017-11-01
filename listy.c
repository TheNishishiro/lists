#include "listy.h"

void PrintList(lista list)
{
	printf("List: ");
	lista l = list;
	while (l)
	{
		printf ("%d-", l->klucz);
		l = l->nast; 
	}
	printf ("|\n"); 
}

void AddElement(lista *l, int i)
{
	lista p = (lista)malloc(sizeof(elListy));
	p->klucz = i;
	p->nast = *l;
	*l = p;
}

void AddElementAtEnd(lista *l, int i)
{
	lista p = (lista)malloc(sizeof(elListy));
	p->klucz = i;
	p->nast = 0;
	while((*l))
	{
		l = &(*l)->nast;
	}
	*l = p;
}

void AddInTheMiddle(lista *l, lista *p, lista *w, lista *q, int value)
{
	*p = (lista)malloc(sizeof(elListy));
	(*p)->klucz = value;
	(*p)->nast = *l;
	(*w)->nast = *p;
	*l = *q;
}

void AddFirst(lista *l, lista *p, lista *w, int value)
{
	(*p) = (lista)malloc(sizeof(elListy));
	(*p)->klucz = value;
	(*p)->nast = *w;
	*l = *p;
}

void AddElementSorted(lista *l, int value)
{
	lista p = 0, w = *l, q = *l;
	if(*l == 0)
	{
		AddElement(l, value);
		return;
	}
	while(1)
	{
		if((*l == 0 || (*l)->klucz >= value) && w != *l)
		{
			AddInTheMiddle(l, &p, &w, &q, value);
			return;
		}
		else if(w == *l && (*l)->klucz >= value)
		{
			AddFirst(l, &p, &w, value);
			return;
		}
		else
		{
			w = *l;
			*l = (*l)->nast;
		}
	}
}

void AddElementSortedRec(lista *l, lista p, lista w, lista q, int value)
{
	if(q == 0)
	{
		w = *l;
		q = *l;
		if(*l == 0)
		{
			AddElement(l, value);
			return;
		}
	}		
	if((*l == 0 || (*l)->klucz >= value) && w != *l)
	{
		AddInTheMiddle(l, &p, &w, &q, value);
		return;
	}
	else if(w == *l && (*l)->klucz >= value)
	{
		AddFirst(l, &p, &w, value);
		return;
	}
	else
	{
		w = *l;
		*l = (*l)->nast;
		AddElementSortedRec(l, p, w, q, value);
	}
}

void FreeList(lista *l)
{
	lista p = *l;
	while(p)
	{
		*l = (*l)->nast;
		free(p);
		p = *l;
	}
}

void FreeListRec(lista *l)
{
	if(*l != 0)
	{
		lista p = *l;
		if(p != 0)
		{
			*l = (*l)->nast;
			free(p);
			FreeListRec(l);
		}
	}
}

void RemoveFirst(lista *l)
{
	lista p;
	if(*l != 0)
	{
		p = *l;
		*l = (*l)->nast;
		free(p);
	}
}

void RemoveLast(lista *l)
{
	if(*l == 0) 
		return;
	while((*l)->nast)
		l = &(*l)->nast;
	free(*l);
	*l = 0;
}

void RemoveElement(lista *l, int index)
{
	int currentIndex = 0;
	lista p = 0;
	
	while(*l)
	{
		if(currentIndex == index)
		{
			RemoveFirst(&(*l));
			break;
		}
		l = &(*l)->nast;	
		currentIndex++;
	}
}

void RemoveAllOf(lista *l, int number)
{
	while(*l)
	{
		if((*l)->klucz == number)
		{
			RemoveFirst(&(*l));
		}
		else
		{
			l = &(*l)->nast;
		}
	}
}

void RemoveAllOfRec(lista *l, int number)
{
	if(*l != 0)
	{
		if((*l)->klucz == number)
		{
			RemoveFirst(&(*l));
			RemoveAllOfRec(&(*l), number);
		}
		else
		{
			RemoveAllOfRec(&(*l)->nast, number);
		}
	}
}

lista ReverseList(lista *l)
{
	lista reversed = 0;
	while ((*l))
	{
		AddElement(&reversed, (*l)->klucz);
		l = &(*l)->nast;
	}
	return reversed;
}

void PrintReversedList(lista *l)
{
	lista reversed = 0;
	while ((*l))
	{
		AddElement(&reversed, (*l)->klucz);
		l = &(*l)->nast;
	}
	PrintList(reversed);
	FreeList(&reversed);
	system("pause");
}

void PrintReversedListRec(lista l)
{
	if(l)
	{
		PrintReversedListRec(l->nast);
		printf("%d - ", l->klucz);
	}
}

int SearchList(lista list, int number, int first)
{
	lista l = list;
	int i = 0;
	while(l)
	{
		if(l->klucz == number)
		{
			if(first == 0)
				printf("\nFound %d at index %d", number, i);	
			if(first == 1)
				return 1;
		}
		l = l->nast; 
		i++;
	}
	
	if(first == 0)
	{
		printf("\n");
		system("pause");
	}
	return 0;
}

void ReverseConnectionHelper(lista *l, lista *w, lista *p)
{
		*p = (*l)->nast;
		(*l)->nast = *w;
		*w = *l;
		*l = *p;	
}

void ReverseConnections(lista *l)
{
	lista p = 0, w = 0;
	while(*l)
		ReverseConnectionHelper(l, &w, &p);
		
	*l = w;
	free(p);
}

void ReverseConnectionsRec(lista *l, lista p, lista w)
{
	if(*l)
	{
		ReverseConnectionHelper(l,&w,&p);
		ReverseConnectionsRec(l, p, w);
	}
	else
		*l = w;
}

int SortWhileHelper(lista *l, lista *p, int changes)
{
	int i = 0;
	if((*l)->klucz > (*p)->klucz)
	{
		i = (*l)->klucz;
		(*l)->klucz = (*p)->klucz;
		(*p)->klucz = i;
		changes++;
	}
	*l = *p;
	*p = (*p)->nast;

	return changes;
}

void SortList(lista *l, int Wartownik)
{
		if(Wartownik != 0)
			AddElementAtEnd(l, -1);
		
		int changes = 0, i = 0;
		lista w = (*l);
		lista p = (*l)->nast;
	
		do
		{
			changes = 0;
			*l = w;
			p = w->nast;
			if(Wartownik != 0)
			{
				while(p->klucz != -1)
				{
					changes = SortWhileHelper(l, &p, changes);
				}
			}
			else
			{	
				while((*l)->nast)
				{	
					changes = SortWhileHelper(l, &p, changes);
				}
			}
			
	}while(changes);
	*l = w;
	
	if(Wartownik != 0)
		RemoveLast(l);
}


void RemoveEven(lista *l)
{
	while(*l)
	{
		if((*l)->klucz % 2 == 0)
		{
			RemoveFirst(&(*l));
		}
		else
		{
			l = &(*l)->nast;
		}
	}
}

void MergeLists(lista *l1, lista *l2)
{
	if(*l1 != 0)
	{
		lista w = 0, p = 0, q = 0;
		int element = 0;
		if((*l1)->klucz <= (*l2)->klucz)
		{
			w = *l1;
			p = *l2;
			q = *l1;
		}
		else
		{
			w = *l2;
			p = *l1;
			q = *l2;	
		}
		while(*l2)
		{
			if(element == 0 && w->nast == 0)
			{
				w->nast = p;
				break;
			}
			else if(element == 0 && p->nast == 0)
			{
				p->nast = w->nast;
				w->nast = p;
				break;
			}
			else if(p == 0 || (*l2)->klucz < p->klucz || (*l2)->klucz <= (*l1)->klucz)
			{
				w = (*l1)->nast;
				p = (*l2)->nast;
				(*l1)->nast = *l2;
				*l1 = *l2;
				*l2 = w;
			}
			else
			{
				*l1 = (*l1)->nast;
				p = (*l1)->nast;
			}
			element = 1;
		}
		*l1 = q;
	}
	else
	{
		*l1 = *l2;
	}
}

void FindDifference(lista *l1, lista *l2)
{
	lista l1_missing = 0;
	lista l2_missing = 0;
	lista head_l1 = *l1;
	lista head_l2 = *l2;
	
	while(*l2)
	{
		if(SearchList(head_l1, (*l2)->klucz, 1) == 0)
		{
			AddElementAtEnd(&l1_missing, (*l2)->klucz);
		}
		*l2 = (*l2)->nast;
	}
	*l2 = head_l2;
	*l1 = head_l1;

	while(*l1)
	{
		if(SearchList(head_l2, (*l1)->klucz, 1) == 0)
		{
			AddElementAtEnd(&l2_missing, (*l1)->klucz);
		}
		*l1 = (*l1)->nast;
	}
	
	
	printf("Not found in list1 that are present in list2:\n");
	PrintList(l1_missing);
	printf("Not found in list2 that are present in list1:\n");
	PrintList(l2_missing);
	
	*l1 = head_l1;
	*l2 = head_l2;
	system("pause");
}
