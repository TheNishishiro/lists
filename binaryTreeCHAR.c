#include "binaryTreeCHAR.h"
#include <string.h>

void PrintBinaryTree0CHAR(drzewoCHAR d, int glebokosc)
{
	if(d == 0) return;
	PrintBinaryTree0CHAR(d->lewy, glebokosc + 1);
	int i = 0;
	while(i < glebokosc)
	{
		putchar(' ');
		i += 1;
	}
	printf("%s\n", d->klucz);
	PrintBinaryTree0CHAR(d->prawy, glebokosc + 1);
}

void PrintBinaryTreeCHAR(drzewoCHAR d)
{
	printf("Binary tree:\n");
	PrintBinaryTree0CHAR(d, 0);
	putchar(' ');
}

void AddToBinaryTreeCHAR(drzewoCHAR *d, drzewoCHAR *ojciec, char* text)
{
	
	if(*d == 0)
	{
		char* data = malloc(strlen(text) + 1);
		strcpy(data, text);
		*d = (drzewoCHAR)malloc(sizeof(wDrzewaBCHAR));
		(*d)->klucz = data;
		(*d)->licznik = 1;
		(*d)->ojciec = *ojciec;
		(*d)->lewy = (*d)->prawy = 0;
	}
	else if(strcmp(text, (*d)->klucz) < 0)
		AddToBinaryTreeCHAR(&(*d)->lewy, &(*d), text);
	else if(strcmp(text, (*d)->klucz) > 0)
		AddToBinaryTreeCHAR(&(*d)->prawy, &(*d), text);
	else
		(*d)->licznik++;
}

drzewoCHAR* FindInBinaryTreeCHAR(drzewoCHAR *d, char* text)
{
	if(*d == 0) return 0;
	
	int w = strcoll(text, (*d)->klucz);
	if(w < 0)
		return FindInBinaryTreeCHAR(&(*d)->lewy, text);
	else if(w > 0)
		return FindInBinaryTreeCHAR(&(*d)->prawy, text);
	else
		return d;
}

drzewoCHAR* FindMaxBinaryTreeCHAR(drzewoCHAR *d)
{
	if(*d == 0) return 0;
	while((*d)->prawy)
		d = &(*d)->prawy;
	return d;	
}

drzewoCHAR* FindMinBinaryTreeCHAR(drzewoCHAR *d)
{
	if(*d == 0) return 0;
	while((*d)->lewy)
		d = &(*d)->lewy;
	return d;
}

void FreeBinaryTreeCHAR(drzewoCHAR *d)
{
	if(*d == 0) return;
	FreeBinaryTreeCHAR(&(*d)->lewy);
	FreeBinaryTreeCHAR(&(*d)->prawy);
	free(*d);
	*d = 0;
}

void RemoveFromBinaryTreeCHAR(drzewoCHAR *d, char* text)
{
	drzewoCHAR *dU, us;
	if(*d == 0) return;
	d = FindInBinaryTreeCHAR(d, text);
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
		dU = FindMaxBinaryTreeCHAR(&(*d)->lewy);
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
