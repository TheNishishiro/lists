#include "listyNC.h"

void PrintListNC(listaNC l)
{
	printf("Non-cyclic: ");
	if(l != 0)
	{
		while(l)
		{
			printf("%d - ", l->klucz);
			l = l->nast;
		}	
	}
	printf("|\n");
}

void AddElementNC(listaNC *l, int i)
{
	listaNC p = 0, n = 0;
	
	if(*l == 0)
	{
		p = (listaNC)malloc(sizeof(elListyNC));
		p->klucz = i;
		*l = p;
		p->nast = 0;
		p->pop = 0;
	}
	else
	{
		if((*l)->klucz <= i)
		{
			while((*l)->nast && i > (*l)->nast->klucz)
				l = &(*l)->nast;
			AddElementNCSorted(l, i);
		}
		else
		{
			p = (listaNC)malloc(sizeof(elListyNC));
			p->klucz = i;
			p->pop = (*l)->pop;
			p->nast = *l;
			(*l)->pop = p;
			*l = p;
		}
	}
	
}

void AddElementNCSorted(listaNC *l, int i)
{
	listaNC p = 0, n = 0;
	p = (listaNC)malloc(sizeof(elListyNC));
	p->klucz = i;
	
	p->nast = (*l)->nast;	
	(*l)->nast = p;
	p->pop = *l;
	if(p->nast != 0)
		p->nast->pop = p;
	
	
//	*l = p;
}


void RemoveElementNC(listaNC *l)
{
	listaNC p;
	if(*l == 0) return;
	if((*l)->nast == 0)
	{
		free(*l);
		*l = 0;
	}
	else
	{
		p = *l;
		p->nast->pop = 0;
		*l = p->nast;
		free(p);
	}
}

void FreeListNC(listaNC *l)  
{ 
	while (*l)  
		RemoveElementNC(l); 
}


void FindElementNC(listaNC l, int x)
{
	int i = 0;
	while(l)
	{
		if(l->klucz == x)
			printf("found %d at %d index\n", l->klucz, i);
		i++;
		l = l->nast;
	}
	system("pause");
}
