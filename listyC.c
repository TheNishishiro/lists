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
	listaC p = 0;
	
	if(*l == 0)
	{
		p = (listaC)malloc(sizeof(elListyC));
		p->klucz = i;
		*l = p;
		p->nast = p;
		p->pop = p;
	}
	else
	{
		if((*l)->klucz <= i)
		{
			while((*l)->klucz < (*l)->nast->klucz && i > (*l)->nast->klucz)
				l = &(*l)->nast;
			AddElementCSorted(l, i);
		}
		else
		{
			p = (listaC)malloc(sizeof(elListyC));
			p->klucz = i;
			
			p->pop = (*l)->pop;
			p->nast = (*l);
			(*l)->pop = p;
			
			p->pop->nast = p;
			
			*l = p;
		}
	}
}

void AddElementCSorted(listaC *l, int i)
{
	listaC p = 0, n = 0;
	p = (listaC)malloc(sizeof(elListyC));
	p->klucz = i;

	p->pop = *l;
	p->nast = (*l)->nast;
	(*l)->nast = p;
	p->nast->pop = p;

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
	if(*l == 0) return;
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
	if(l == 0) return;
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

void MergeListsC(listaC *l1, listaC *l2)
{
	if(*l2 == 0) return;
	else if(*l1 == 0)
	{
		*l1 = *l2;
		return;	
	}
	listaC ost1 = (*l1)->pop;
	listaC ost2 = (*l2)->pop;
	
	ost1->nast = (*l2);
	ost2->nast = (*l1);
	(*l2)->pop = ost1;
	(*l1)->pop = ost2;
}

