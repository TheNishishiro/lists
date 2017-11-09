#ifndef HEADER_ONP
#define HEADER_ONP
struct elONP
{
	char klucz;
	struct elONP *nast;	
};
typedef struct elONP elListyONP;
typedef elListyONP *listaONP;
#endif
