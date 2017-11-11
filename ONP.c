#include "ONP.h"
#include <stdio.h>
#include <stdlib.h>

void PrintListONP(listaONP list)
{
	printf("ONP: ");
	listaONP l = list;
	while (l)
	{
		if(l->znak == 'N')
			printf ("%d ", l->liczba);
		else
			printf ("%c ", l->znak);
		l = l->nast; 
	}
	printf ("\n"); 
}


void CreateONP(listaONP *l)
{
	char line[100] = "";
	char buffer[10] = "";
	char indexer;
	int i = 0, bufferHelper = 0;
	listaONP end = 0;
	
	fseek(stdin,0,SEEK_END);
	
	printf("Please enter ONP with space as seperator:\n> ");
	fgets(line, 100, stdin); 
	indexer = line[i];
	
	while(indexer){
		if(line[i] != ' ')
		{
			buffer[bufferHelper] = line[i];
			bufferHelper++;
		}
		if(line[i + 1] == ' ' || line[i + 1] == '\n') 
		{
			listaONP p = (listaONP)malloc(sizeof(elListyONP));
			
			if(buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
			{
				p->znak = buffer[0];
				p->liczba = 0;
			}
			else
			{
				int w = 0, number = 0;
				while(w < bufferHelper)
				{
					int k = buffer[w] - '0';
						number += k * (int)pow(10, (bufferHelper - w - 1));
					buffer[w] = "";
					w++;
				}
				p->znak = 'N';
				p->liczba = number;
			}
			
			bufferHelper = 0;
			
			p->nast = 0;
			if(*l == 0)
			{
				*l = p;
				end = p;
			}
			else
			{
				end->nast = p;
				end = p;
			}
		}
		
		
		i++;
		indexer = line[i];
	}
	
}

void ExecuteONP(listaONP *l)
{
	listaONP p = 0;
	int v1 = INT_MAX, v2 = INT_MAX;
	int result = 0;
	char c = 'V';
	
	while (*l){
		if(v1 == INT_MAX){
			v1 = (*l)->liczba;
			p = *l;
			*l=(*l)->nast;
			free(p);
		}
		if(v2 == INT_MAX){
			v2 = (*l)->liczba;
			p = *l;
			*l=(*l)->nast;
			free(p);
		}
		if(c == 'V'){
			c = (*l)->znak;
			p = *l;
			*l=(*l)->nast;
			free(p);
		}
		
		switch(c)
		{
			case '+':
				result = v1 + v2;
				break;
			case '-':
				result = v1 - v2;
				break;
			case '*':
				result = v1 * v2;
				break;
			case '/':
				result = v1 / v2;
				break;
		}
		
		v1 = result;
		v2 = INT_MAX;
		c = 'V';
	}
	*l = 0;
	printf("== %d ==", result);
	system("pause");
}
