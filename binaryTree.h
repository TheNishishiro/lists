#ifndef HEADER_BINARYTREE
#define HEADER_BINARYTREE

struct elDrzewaB
{
	int klucz;
	int licznik;
	struct elDrzewaB *lewy;
	struct elDrzewaB *prawy;
	struct elDrzewaB *ojciec;
};
typedef struct elDrzewaB wDrzewaB;
typedef wDrzewaB* drzewo;

void PrintBinaryTree0(drzewo d, int glebokosc);
void PrintBinaryTree(drzewo d);
void AddToBinaryTree(drzewo *d, drzewo *d1, int number);
drzewo* FindInBinaryTree(drzewo *d, int number);
drzewo* FindMaxBinaryTree(drzewo *d);
drzewo* FindMinBinaryTree(drzewo *d);
void FreeBinaryTree(drzewo *d);
void RemoveFromBinaryTree(drzewo *d, int number);

#endif
