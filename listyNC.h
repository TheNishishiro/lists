#ifndef HEADER_LISTYNC
#define HEADER_LISTYNC
struct elNC
{
	int klucz;
	struct elNC *nast;	
	struct elNC *pop;
};
typedef struct elNC elListyNC;
typedef elListyNC *listaNC;

void AddElementNC(listaNC *l, int i);
void RemoveElementNC(listaNC *l);
void FreeListNC(listaNC *l) ;
void FindElementNC(listaNC l, int x);
void PrintListNC(listaNC l);

#endif
