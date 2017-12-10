#include "listyOC.h"

void PrintListOC(listaOC l)
{
	printf("Oneway cyclic list: ");
	if(l != 0)
	{
		listaOC p = l;
		do
		{
			printf("%d - ", l->klucz);
			l = l->nast;
		}while(l != p);
	}
	printf("|\n");
}

void AddElementOC(listaOC *l, listaOC *ostatni, int x)
{
	listaOC p = (listaOC)malloc(sizeof(elListyOC));
	p->klucz = x;
	if(*l == 0)
	{
		p->nast = p;
		*ostatni = p;
		*l = p;
	}
	else
	{
		p->nast = *l;
		(*ostatni)->nast = p;
		*l = p;
	}
}

void RemoveFirstOC(listaOC *l)
{
	listaOC p;
	if(*l != 0)
	{
		p = *l;
		*l = (*l)->nast;
		free(p);
	}
}

// Fix this crap 
void RemoveInEach(listaOC *l1, listaOC *l2)
{
	if(*l1 == 0 || *l2 == 0) return;
	
	listaOC p1 = *l1;
	listaOC p2 = *l2;
	
	printf("Second list before: \n\t");
		PrintListOC(*l2);
		
	do
	{
		do
		{
			if((*l1)->klucz == (*l2)->klucz)
			{
				if(*l2 == p2)
					p2 = (*l2)->nast;
				RemoveFirstOC(&(*l2));
			}
			else
			{
				l2 = &(*l2)->nast;
			}
			
		}while(*l2 != p2);
		*l2 = p2;
		*l1 = (*l1)->nast;
	}while(*l1 != p1);
	*l1 = p1;	
	printf("Second list after: \n\t");
		PrintListOC(*l2);	
	system("pause");
}
