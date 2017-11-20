#include "binaryTree.h"

void PrintBinaryTree0(drzewo d, int glebokosc)
{
	if(d == 0) return;
	PrintBinaryTree0(d->lewy, glebokosc + 1);
	int i = 0;
	while(i < glebokosc)
	{
		putchar(' ');
		i += 1;
	}
	printf("%d\n", d->klucz);
	PrintBinaryTree0(d->prawy, glebokosc + 1);
}

void PrintBinaryTree(drzewo d)
{
	printf("Binary tree:\n");
	PrintBinaryTree0(d, 0);
	putchar(' ');
}

int GetTreeDepth0(drzewo d, int glebokosc)
{
	int m1 = 0, m2 = 0;
	if(d == 0) return 0;

	m1 = GetTreeDepth0(d->lewy, glebokosc + 1);

	m2 = GetTreeDepth0(d->prawy, glebokosc + 1);
	
	if(m1 < glebokosc)
		m1 = glebokosc;
	if(m2 > m1)
		return m2;
	else
		return m1;

}

void GetTreeDepth(drzewo d)
{
	printf("Tree depth is: %d\n", GetTreeDepth0(d, 0));
	system("pause");
}

int GetTreeLeafs0(drzewo d, int glebokosc)
{
	int l1 =0, l2 = 0, leafs = 0;
	if(d == 0) return 0;

	l1 = GetTreeLeafs0(d->lewy, glebokosc + 1);

	l2 = GetTreeLeafs0(d->prawy, glebokosc + 1);
	
	leafs = l1 + l2;
	if(d->lewy == 0 && d->prawy == 0)
		return 1;
	else
		return leafs;
}

void GetTreeLeafs(drzewo d)
{
	printf("Tree have %d leafs\n", GetTreeLeafs0(d, 0));
	system("pause");
}

void AddToBinaryTree(drzewo *d, drzewo *ojciec, int number)
{
	if(*d == 0)
	{
		*d = (drzewo)malloc(sizeof(wDrzewaB));
		(*d)->klucz = number;
		(*d)->licznik = 1;
		(*d)->ojciec = *ojciec;
		(*d)->lewy = (*d)->prawy = 0;
	}
	else if(number < (*d)->klucz)
		AddToBinaryTree(&(*d)->lewy, &(*d), number);
	else if(number > (*d)->klucz)
		AddToBinaryTree(&(*d)->prawy, &(*d), number);
	else
		(*d)->licznik++;
}

void AddToBinaryIT(drzewo *d, int number)
{
	drzewo p = (drzewo)malloc(sizeof(wDrzewaB));
	p->klucz = number;
	p->licznik = 1;
	p->ojciec = 0;
	p->lewy = p->prawy = 0;
	if(*d == 0)
	{
		*d = p;
		return;
	}

	while(*d)
	{
		if(number < (*d)->klucz)
		{
			if((*d)->lewy == 0)
			{
				p->ojciec = *d;
				(*d)->lewy = p;
				break;
			}
			else
				d = &(*d)->lewy;	
		}
		else if(number > (*d)->klucz)
		{
			if((*d)->prawy == 0)
			{
				p->ojciec = *d;
				(*d)->prawy = p;
				break;
			}
			else
				d = &(*d)->prawy;
		}
		else
		{
			(*d)->licznik++;
		}
	}
}

drzewo* FindInBinaryTree(drzewo *d, int number)
{
	if(*d == 0) return 0;
	if(number < (*d)->klucz)
		return FindInBinaryTree(&(*d)->lewy, number);
	else if(number > (*d)->klucz)
		return FindInBinaryTree(&(*d)->prawy, number);
	else
		return d;
}

drzewo* FindInBinaryTreeIT(drzewo *d, int number)
{
	while(*d)
	{
		if(number < (*d)->klucz)
		{
			d = &(*d)->lewy;	
		}
		else if(number > (*d)->klucz)
		{
			d = &(*d)->prawy;
		}
		else
			return d;
	}

	return 0;
}

drzewo* FindMaxBinaryTree(drzewo *d)
{
	if(*d == 0) return 0;
	while((*d)->prawy)
		d = &(*d)->prawy;
	return d;	
}

drzewo* FindMaxBinaryTreeRec(drzewo *d)
{
	if(*d == 0) return 0;
	if((*d)->prawy != 0) 
		FindMaxBinaryTreeRec(&(*d)->prawy);
	else
		return &(*d);
}

drzewo* FindMinBinaryTree(drzewo *d)
{
	if(*d == 0) return 0;
	while((*d)->lewy)
		d = &(*d)->lewy;
	return d;
}

drzewo* FindMinBinaryTreeRec(drzewo *d)
{	
	if(*d == 0) return 0;
	if((*d)->lewy != 0) 
		FindMinBinaryTreeRec(&(*d)->lewy);
	else
		return &(*d);	
}

void FreeBinaryTree(drzewo *d)
{
	if(*d == 0) return;
	FreeBinaryTree(&(*d)->lewy);
	FreeBinaryTree(&(*d)->prawy);
	free(*d);
	*d = 0;
}

void FreeBinaryTreeIT(drzewo *d)
{
	if(*d == 0) return;
	drzewo *p = FindMinBinaryTreeRec(d);
	drzewo *rm = 0;
	
	while(*p)
	{
		if((*p)->prawy != 0)
		{
			p = &(*p)->prawy;
		}
		if((*p)->lewy != 0)
		{
			p = FindMinBinaryTreeRec(&(*p));
		}
		if((*p)->prawy == 0)
		{
			
			if( (*p)->ojciec == 0 && (*p)->lewy == 0 && (*p)->prawy == 0)
			{
				free(*p);
				break;	
			}
			rm = *p;
			p = &(*p)->ojciec;
			
			if((*p)->lewy != 0){
				(*p)->lewy = 0;
			}
			else if((*p)->prawy != 0){
				(*p)->prawy = 0;
			}
			free(rm);
		}
	}
	*d = 0;
}

void RemoveFromBinaryTree(drzewo *d, int number)
{
	drzewo *dU, us;
	if(*d == 0) return;
	d = FindInBinaryTree(d, number);
	if(d == 0) return;
	if((*d)->licznik > 1)
	{
		(*d)->licznik--;
		return;
	}
	if((*d)->lewy == 0 || (*d)->prawy == 0)
		dU = d;
	else
	{
		dU = FindMaxBinaryTree(&(*d)->lewy);
		(*d)->klucz = (*dU)->klucz;
		(*d)->licznik = (*dU)->licznik;			
	}
	us = *dU;
	if((*dU)->lewy == 0)
		*dU = (*dU)->prawy;
	else
		*dU = (*dU)->lewy;
	free(us);
}

drzewo* CompareTreesHelper(drzewo *min2, int k2)
{
	int k_old = k2;
	
	while(k_old == k2)
	{
		if(k2 == 0)
		{
			k2 = (*min2)->klucz;
			printf("%d ", k2, k_old);
		}
		else if((*min2)->prawy != 0 && k2 < (*min2)->prawy->klucz)
		{
			min2 = FindMinBinaryTree(&(*min2)->prawy);
			k2 = (*min2)->klucz;
			printf("%d ", k2, k_old);
		}
		else if((*min2)->ojciec != 0)
		{
			min2 = &(*min2)->ojciec;
			if((*min2)->klucz > k2)
			{
				k2 = (*min2)->klucz;
				printf("%d ", k2, k_old);
			}
		}
		else
			break;
	}
	
	return min2;
}

void CompareTrees(drzewo d1, drzewo d2)
{
	drzewo *min1 = FindMinBinaryTree(&d1);
	drzewo *min2 = FindMinBinaryTree(&d2);
	int k = 0, k2 = 0;
	
	while(1)
	{	
		if(k == 0)
		{
			k = (*min1)->klucz;
			printf("%d ", k);
			min2 = CompareTreesHelper(min2, k2);
		}
		else if((*min1)->prawy != 0 && k < (*min1)->prawy->klucz)
		{
			min1 = FindMinBinaryTree(&(*min1)->prawy);
			k = (*min1)->klucz;
			printf("%d ", k);
			min2 = CompareTreesHelper(min2, k2);
		}
		else if((*min1)->ojciec != 0)
		{
			min1 = &(*min1)->ojciec;
			if((*min1)->klucz > k)
			{
				k = (*min1)->klucz;
				printf("%d ", k);
				min2 = CompareTreesHelper(min2, k2);
			}
		}
		else
			break;
			
		k2 = (*min2)->klucz;
		
			
		if(k != k2)
			break;
		
	}
	min2 = FindMaxBinaryTree(&(*min2));
	k2 = (*min2)->klucz;
	
	if(k == k2)
		printf("Trees have the same numbers in them\n");
	else
		printf("Trees DON'T have the same numbers in them\n");
	system("pause");
}

