#include "Sorting.h"
#include <time.h>
#include <stdlib.h>

#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*i + 2)

int comparisons = 0, substitution = 1;

float* float_rand(int size)
{
	float *A = malloc(size * sizeof(*A));
	int i = 0;
	for(i = 0; i < size; i++)
	{
    	A[i] = (float)rand() / ((float)(RAND_MAX) / 200.0f);
	}	
    return A;
}

void printArray(int a[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void printArrayF(float a[], int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		printf("%f ", a[i]);
	}
}

int * CopyArray(int a[], int n)
{
	int *newArray = calloc(n, sizeof(int));
	int i;
	for(i = 0; i < n; i++)
	{
		newArray[i] = a[i];
	}
	return newArray;
}

float * CopyArrayF(float a[], int n)
{
	float *newArray = calloc(n, sizeof(float));
	int i;
	for(i = 0; i < n; i++)
	{
		newArray[i] = a[i];
	}
	return newArray;
}

void PrintStats(char *name, int print, int a[], int n)
{
	printf("%s: \n", name);
	if(print)
	{
		printArray(a, n);
		printf("\n");
	}
	printf("\tSubstitution: %d\n\tComparisons: %d\n\tActions: %d\n", substitution, comparisons, substitution+comparisons);

	free(a);
}

void PrintStatsF(char *name, int print, float a[], int n)
{
	printf("%s: \n", name);
	if(print)
	{
		printArrayF(a, n);
		printf("\n");
	}
	printf("\tSubstitution: %d\n\tComparisons: %d\n\tActions: %d\n", substitution, comparisons, substitution+comparisons);

	free(a);
}

void InsertionSort(int input[], int n, int print)
{
	int i, j, x;
	int *a;
	a = CopyArray(input, n);
	comparisons = 0, substitution = 1;
	for(i = 1; i < n; i++)
	{
		if(a[i] < a[0])
		{
			x = a[0];
			a[0] = a[i];
			substitution += 2;
		}
		else
		{
			x = a[i];
			substitution++;
		}
		for(j = i - 1; x < a[j]; j--)
		{
			a[j + 1] = a[j];
			comparisons++;
			substitution += 2;
		}
		a[j + 1] = x;
		
		comparisons += 3;
		substitution += 3;
	}
	
	PrintStats("Insertion Sort", print, a, n);
}

void SelectionSort(int input[], int n, int print)
{
	int i, j, k, x;
	int *a;
	a = CopyArray(input, n);
	comparisons = 0, substitution = 1;
	
	for(i = 0; i < n - 1; i++)
	{
		k = i;
		x = a[i];
		for(j = i + 1; j < n; j++)
		{
			if(a[j] < x)
			{
				k = j;
				x = a[j];
				substitution += 2;
			}
			a[k] = a[i];
			a[i] = x;
			
			comparisons += 2;
			substitution += 3;
		}
		comparisons += 2;
		substitution += 4;
	}
	
	PrintStats("Selection Sort", print, a, n);
}

void BubbleSort(int input[], int n, int print)
{
	int i, j, x;
	int *a;
	a = CopyArray(input, n);
	comparisons = 0, substitution = 1;
	for(i = 1; i < n; i++)
	{
		for(j = n - 1; j >= i; j--)
		{
			if(a[j - 1] > a[j])
			{
				x = a[j - 1];
				a[j - 1] = a[j];
				a[j] = x;	
				substitution += 3;
			}
			comparisons += 2;
			substitution++;
		}
		comparisons += 2;
		substitution += 2;
	}
	
	PrintStats("Bubble Sort", print, a, n);
}

void Heapify(int A[], int i, int heapSize)
{
	int l, r, x, largest;
	l = LEFT(i);
	r = RIGHT(i);
	substitution += 2;
	comparisons++;
	if(l < heapSize && A[l] > A[i])
	{
		largest = l;	
	}
	else
	{
		largest = i;	
	}
	substitution++;
	comparisons++;
	if(r < heapSize && A[r] > A[largest])
	{
		largest = r;
		substitution++;
	}
	comparisons++;
	if(largest != i)
	{
		x = A[i];
		A[i] = A[largest];
		A[largest] = x;
		substitution += 3;
		Heapify(A, largest, heapSize);	
	}

}

void BuildHeap(int A[], int n)
{
	int i;
	substitution++;
	for(i = (n - 1) / 2; i >= 0; i--)
	{
		Heapify(A, i, n);
		
		comparisons++;
		substitution++;
	}
}

void HeapSort(int input[], int n, int print)
{
	int i, x, heapSize = n;
	int *A;
	A = CopyArray(input, n);
	comparisons = 0, substitution = 1;
	BuildHeap(A, n);
	for(i = n - 1; i > 0; i--)
	{
		x = A[0];
		A[0] = A[i];
		A[i] = x;
		Heapify(A, 0, --heapSize);	
	}
	
	PrintStats("Heap Sort", print, A, n);
}


void HeapifyF(float A[], int i, int heapSize)
{
	int l, r, largest;
	float x;
	l = LEFT(i);
	r = RIGHT(i);
	substitution += 2;
	comparisons++;
	if(l < heapSize && A[l] > A[i])
	{
		largest = l;	
	}
	else
	{
		largest = i;	
	}
	substitution++;
	comparisons++;
	if(r < heapSize && A[r] > A[largest])
	{
		largest = r;
		substitution++;
	}
	comparisons++;
	if(largest != i)
	{
		x = A[i];
		A[i] = A[largest];
		A[largest] = x;
		substitution += 3;
		HeapifyF(A, largest, heapSize);	
	}

}

void BuildHeapF(float A[], int n)
{
	int i;
	substitution++;
	for(i = (n - 1) / 2; i >= 0; i--)
	{
		HeapifyF(A, i, n);
		
		comparisons++;
		substitution++;
	}
}

void HeapSortF(float input[], int n, int print)
{
	int i, heapSize = n;
	float x;
	float *A;
	A = CopyArrayF(input, n);
	comparisons = 0, substitution = 1;
	BuildHeapF(A, n);
	for(i = n - 1; i > 0; i--)
	{
		x = A[0];
		A[0] = A[i];
		A[i] = x;
		HeapifyF(A, 0, --heapSize);	
	}
	
	PrintStatsF("Heap Sort", print, A, n);
}


void Quicksort(int input[], int p, int r, int print)
{
	int *A;
	A = CopyArray(input, r);
	comparisons = 0, substitution = 0;
	
	Quicksort0(A, p, r - 1);
	
	PrintStats("Quick Sort", print, A, r);
}

void Quicksort0(int A[], int p, int r)
{
	int q;	
	comparisons++;
	if(p < r)
	{
		q = Partition(A, p, r);
		substitution++;
		Quicksort0(A, p, q);
		Quicksort0(A, q + 1, r);
	}
}

int Partition(int A[], int p, int r)
{
	int _r = rand()%(r-p+1)+p;
	int x, i, j;

	x = A[p];
	A[p] = A[_r];
	A[_r] = x;
	x = A[p];
	i = p - 1;
	j = r + 1;
	substitution += 7;
	do
	{
		do
		{
			j--;	
			substitution++;
			comparisons++;
		}while(A[j] > x);
		do
		{
			i++;
			substitution++;
			comparisons++;
		}while(A[i] < x);
		comparisons++;
		if(i < j)
		{
			x = A[i];
			A[i] = A[j];
			A[j] = x;	
			substitution+=3;
		}
		comparisons++;
	}while(i < j);
	return j;
}

void ShellSort(int input[], int n, int print)
{
	int *a;
	a = CopyArray(input, n);
	comparisons = 0, substitution = 0;
	
	int inner, outer, valueToInsert, interval = 1;
	
	while(interval <= n/3)
	{
		comparisons++;
		interval = interval * 3 + 1;
		substitution++;	
	}
	
	while(interval > 0)
	{
		comparisons+=2;
		substitution++;	
		for(outer = interval; outer < n; outer++)
		{
			valueToInsert = a[outer];
			inner = outer;
			substitution+=2;	
			while(inner > interval - 1 && a[inner - interval] >= valueToInsert)
			{
				a[inner] = a[inner - interval];
				inner -= interval;
				comparisons+=2;
				substitution+=2;
			}
			
			a[inner] = valueToInsert;
			substitution++;
			comparisons+=2;
		}
		
		interval = (interval - 1) / 3;
		substitution++;
		comparisons++;
	}
	
	PrintStats("Shell Sort", print, a, n);
}
