#ifndef HEADER_LISTYPRIOR
#define HEADER_LISTYPRIOR
struct elPrior
{
	int klucz;
	int priorytet;
	struct el *nast;	
};
typedef struct elPrior elListyPrior;
typedef elListyPrior *listaPrior;

void PrintListPrior(listaPrior list);
void AddElementPrior(listaPrior *l, int i, int priority);
void AddElementSortedPrior(listaPrior *l, int value, int priority);
void RemoveElementPrior(listaPrior *l);
void EditPrior(listaPrior *l, int index, int priority);
#endif
