#include "ONP.h"
#include <stdio.h>
#include <stdlib.h>

void PrintListONP(listaONP list)
{
	printf("ONP: ");
	listaONP l = list;
	while (l)
	{
		printf ("%d ", l->liczba);
		l = l->nast; 
	}
	printf ("\n"); 
}


void CreateONP(listaONP *l)
{
	char * line;
	char * buffer;
	char indexer;
	int i = 0, bufferHelper = 0;
	listaONP end = 0;
	
	fseek(stdin,0,SEEK_END);
	
	printf("Please enter ONP with spaces as seperator:\n> ");
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
				p->liczba = 0;
			}
			else
			{
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

