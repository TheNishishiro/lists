#ifndef HEADER_ONP
#define HEADER_ONP
struct elONP
{
	int liczba;
	struct elONP *nast;	
};
typedef struct elONP elListyONP;
typedef elListyONP *listaONP;

void PrintListONP(listaONP list);
void CreateONP(listaONP *l);
#endif
