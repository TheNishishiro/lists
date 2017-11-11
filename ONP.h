#ifndef HEADER_ONP
#define HEADER_ONP
struct elONP
{
	char znak;
	int liczba;
	struct elONP *nast;	
};
typedef struct elONP elListyONP;
typedef elListyONP *listaONP;

void PrintListONP(listaONP list);
void CreateONP(listaONP *l);
void ExecuteONP(listaONP *l);
#endif
