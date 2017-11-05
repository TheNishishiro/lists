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

void AddToBinaryTree(drzewo *d, int number)
{
	if(*d == 0)
	{
		*d = (drzewo)malloc(sizeof(wDrzewaB));
		(*d)->klucz = number;
		(*d)->licznik = 1;
		(*d)->lewy = (*d)->prawy = 0;
	}
	else if(number < (*d)->klucz)
		AddToBinaryTree(&(*d)->lewy, number);
	else if(number > (*d)->klucz)
		AddToBinaryTree(&(*d)->prawy, number);
	else
		(*d)->licznik++;
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

drzewo* FindMaxBinaryTree(drzewo *d)
{
	if(*d == 0) return 0;
	while((*d)->prawy)
		d = &(*d)->prawy;
	return d;	
}

drzewo* FindMinBinaryTree(drzewo *d)
{
	if(*d == 0) return 0;
	while((*d)->lewy)
		d = &(*d)->lewy;
	return d;
}

void FreeBinaryTree(drzewo *d)
{
	if(*d == 0) return;
	FreeBinaryTree(&(*d)->lewy);
	FreeBinaryTree(&(*d)->prawy);
	free(*d);
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
