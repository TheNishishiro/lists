#ifndef HEADER_LISTYOC
#define HEADER_LISTYOC
struct elOC
{
	int klucz;
	struct elOC *nast;	
};
typedef struct elOC elListyOC;
typedef elListyOC *listaOC;

void PrintListOC(listaOC l);
void AddElementOC(listaOC *l, listaOC *ostatni, int x);
void RemoveInEach(listaOC *l1, listaOC *l2);

#endif
