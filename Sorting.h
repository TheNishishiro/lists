#ifndef HEADER_SORTING
#define HEADER_SORTING

float* float_rand(int size);
void printArray(int a[], int n);
void printArrayF(float a[], int n);
int * CopyArray(int a[], int n);
float * CopyArrayF(float a[], int n);
void PrintStats(char *name, int print, int a[], int n);
void PrintStatsF(char *name, int print, float a[], int n);
void InsertionSort(int input[], int n, int print);
void SelectionSort(int input[], int n, int print);
void BubbleSort(int input[], int n, int print);
void Heapify(int A[], int i, int heapSize);
void BuildHeap(int A[], int n);
void HeapSort(int input[], int n, int print);
void HeapifyF(float A[], int i, int heapSize);
void BuildHeapF(float A[], int n);
void HeapSortF(float input[], int n, int print);
void Quicksort(int input[], int p, int r, int print);
void Quicksort0(int A[], int p, int r);
int Partition(int A[], int p, int r);
void ShellSort(int input[], int n, int print);


#endif
