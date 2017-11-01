#ifndef HEADER_LISTYC
#define HEADER_LISTYC
struct elC
{
	int klucz;
	struct elC *nast;	
	struct elC *pop;
};
typedef struct elC elListyC;
typedef elListyC *listaC;

void FindElementC(listaC l, int x);
void RemoveElementC(listaC *l);
void AddElementC(listaC *l, int i);
void PrintListC(listaC l);
void FreeListC(listaC *l);
void RemoveEveryOther(listaC *l, int jump);
void RemoveInEachother(listaC *l1, listaC *l2);
  
#endif
