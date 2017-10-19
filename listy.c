#include "listy.h"

void PrintList(lista list)
{
	printf("Lista: ");
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

void SearchList(lista list, int number)
{
	lista l = list;
	int i = 0;
	while(l)
	{
		if(l->klucz == number)
		{
			printf("\nFound %d at index %d", number, i);	
		}
		l = l->nast; 
		i++;
	}
	printf("\n");
	system("pause");
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

