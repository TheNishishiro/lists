#include "ONP.h"
#include "listy.h"
#include <stdio.h>
#include <stdlib.h>


void CreateONP(lista *l)
{
	char line[100];
	char buffer[10];
	char indexer;
	int i = 0, bufferHelper = 0;
	
	fseek(stdin,0,SEEK_END);
	
	printf("Please enter ONP with spaces as seperator:\n> ");
	
	fgets(&line, 100, stdin); 
	indexer = line[i];

	
	while(indexer){
		if(line[i] != ' ')
		{
			buffer[bufferHelper] = line[i];
			bufferHelper++;
		}
		if(line[i + 1] == ' ' || line[i + 1] == '\n') 
		{
			if(buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
			{
				if(ListLength(l) >= 2)
				{
					int result = 0;
					int num1 = ReturnFirst(l);
						RemoveFirst(l);
					int num2 = ReturnFirst(l);
						RemoveFirst(l);
					
					switch(buffer[0])
					{
						case '+':
							result = num1 + num2;
							break;
						case '-':
							result = num1 - num2;
							break;
						case '*':
							result = num1 * num2;
							break;
						case '/':
							result = num1 / num2;
							break;
					}
				
					AddElement(l, result);
				}
				else
				{
					printf("Not enough numbers in stack!\n");
					FreeList(l);
					system("pause");
					return;
				}
			}
			else
			{
				int number = atoi(buffer);
				
				lista p = (lista)malloc(sizeof(elListy));
				
				AddElement(l, number);
				
				while(bufferHelper > 0)
				{
					buffer[bufferHelper] = "";
					bufferHelper--;
				}
			}
			
			bufferHelper = 0;
		}
		
		i++;
		indexer = line[i];
	}
	if(ListLength(l) > 1)
		printf("Not enough operators!\n");
	else
		printf("Result: %d\n", ReturnFirst(l));
		
	FreeList(l);
	system("pause");
}

