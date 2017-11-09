#include "ONP.h"

void PrintListONP(listaONP list)
{
	printf("List: ");
	listaONP l = list;
	while (l)
	{
		printf ("%s-", l->klucz);
		l = l->nast; 
	}
	printf ("|\n"); 
}
