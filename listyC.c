#include "listyC.h"

void PrintListC(listaC l)
{
	printf("Cyclic list: ");
	if(l != 0)
	{
		listaC p = l;
		do
		{
			printf("%d - ", l->klucz);
			l = l->nast;
		}while(l != p);
	}
	printf("|\n");
}

void AddElementC(listaC *l, int i)
{
	listaC p = 0, n = 0;
	p = (listaC)malloc(sizeof(elListyC));
	p->klucz = i;
	if(*l == 0)
	{
		*l = p;
		p->nast = p;
		p->pop = p;
	}
	else
	{
		n = (*l)->nast;
		p->pop = *l;
		p->nast = n;
		(*l)->nast = p;
		n->pop = p;
	}
}

void RemoveElementC(listaC *l)
{
	listaC p;
	if(*l == 0) return;
	if(*l == (*l)->pop)
	{
		free(*l);
		*l = 0;
	}
	else
	{
		p = *l;
		p->pop->nast = p->nast;
		p->nast->pop = p->pop;
		*l = p->nast;
		free(p);
	}
}

void RemoveEveryOther(listaC *l, int jump)
{
	int i = 0;
	listaC p = 0;
	while((*l)->pop != *l && (*l)->nast != *l)
	{
		if(i == jump)
		{
			RemoveElementC(l);
			i = 0;	
		}
		*l = (*l)->nast;
		i++;
	}
}

void FreeListC(listaC *l)  
{ 
	while (*l)  
		RemoveElementC(l); 
}


void FindElementC(listaC l, int x)
{
	listaC p = l;
	int i = 0;
	do
	{
		if(l->klucz == x)
			printf("found %d at %d index\n", l->klucz, i);
		i++;
		l = l->nast;
	}while(p != l);
	
	system("pause");
}
