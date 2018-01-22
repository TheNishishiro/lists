#include "listyPrior.h"

void PrintListPrior(listaPrior list)
{
	printf("Priority list: ");
	listaPrior l = list;
	while (l)
	{
		printf ("%d[%d]-", l->klucz, l->priorytet);
		l = l->nast; 
	}
	printf ("|\n"); 
}

void AddElementPrior(listaPrior *l, int i, int priority)
{
	listaPrior p = (listaPrior)malloc(sizeof(elListyPrior));
	p->priorytet = priority;
	p->klucz = i;
	p->nast = *l;
	*l = p;
}

void AddElementSortedPrior(listaPrior *l, int value, int priority)
{
	while(*l && priority < (*l)->priorytet)
		l = &(*l)->nast;
	AddElementPrior(l, value, priority);
}

void AddElementSortedPriorReverse(listaPrior *l, int value, int priority)
{
	while(*l && priority >= (*l)->priorytet)
		l = &(*l)->nast;
	AddElementPrior(l, value, priority);
}

void RemoveElementPrior(listaPrior *l)
{
	if(*l != 0)
	{
		listaPrior p;
		p = *l;
		*l = (*l)->nast;
		free(p);
	}
}

int GetFirstKeyAndRemove(listaPrior *l)
{
	if(*l != 0)
	{
		int key;
		listaPrior p;
		p = *l;
		key = p->klucz;
		*l = (*l)->nast;
		free(p);
		
		return key;
	}
	return 0;
}

void RearrangePriorList(listaPrior *l, int key, int priority)
{
	listaPrior p = 0, head = *l;
	int found = 0;
	
	if(*l == 0) return;
	if((*l)->klucz == key)
	{
		RemoveElementPrior(l);
		found = 1;
	}
	else
	{
		while(*l)
		{
			p = (*l)->nast;
			if(p->klucz == key)
			{
				found = 1;
				(*l)->nast = p->nast;
				free(p);
				break;
			}
			*l = (*l)->nast;
		}
		*l = head;
	}
	if(found == 1)
		AddElementSortedPriorReverse(l, key, priority);
		
	
}

void EditPrior(listaPrior *l, int index, int priority)
{
	listaPrior p = 0, head = *l;
	int value = 0;
	int i = 0, found = 0;
	
	if(*l == 0) return;
	if(index == 0)
	{
		value = (*l)->klucz;
		RemoveElementPrior(l);
		AddElementSortedPrior(l, value, priority);
		return;
	}
	else
	{
		while(*l)
		{
			if(i == index - 1)
			{
				p = (*l)->nast;
				if(p != 0)
				{
					value = p->klucz;
					(*l)->nast = p->nast;
					free(p);
				}
				else
				{
					break;
				}
				found = 1;
			}
			*l=(*l)->nast;
			i++;
		}
	}
	*l = head;
	if(found == 1)
		AddElementSortedPrior(l, value, priority);
}
