#include "filemanager.h"
#include <string.h>

void PrintFolder(FileManager fm, FileManager ojciec)
{
	

	if(ojciec == 0)
		printf("Folders of root:\n");
	else
		printf("Folders of %s:\n", ojciec->klucz);	
		
	while(fm)
	{
		printf("\t%s\n", fm->klucz);
		fm = fm->nast;
	}

}

void PrintPath(FileManager ojciec)
{
	printf("[ ");
	while(ojciec)
	{
		printf("%s/", ojciec->klucz);
		ojciec = ojciec->ojciec;
	}
	printf("root/ ]\n");
}

void AddToFolder(FileManager *fm, FileManager *ojciec, char* text)
{
	char* data = malloc(strlen(text) + 1);
	strcpy(data, text);
	FileManager head = *fm;
	FileManager file = (FileManager)malloc(sizeof(wFileMan));
	
	if(*fm == 0)
	{
		file->klucz = data;
		file->ojciec = *ojciec;
		file->nast = file->pop = file->sub = 0;
		if(*ojciec != 0)
			file->ojciec->sub = file;
		*fm = file;
	}
	else
	{
		while((*fm)->nast)
			*fm = (*fm)->nast;
		printf("a");
		file->klucz = data;
		file->nast = 0;
		file->pop = *fm;
		file->ojciec = (*fm)->ojciec;
		file->sub = 0;
		
		(*fm)->nast = file;
		*fm = head;
	}
	

}

void EnterFolder(FileManager *fm, FileManager *ojciec, char* text)
{
	if(*fm == 0) return;
	FileManager head = *fm;

	while(*fm)
	{
		if(*fm != 0 && strcmp((*fm)->klucz,text) == 0)
		{
			*ojciec = *fm;
			*fm = (*fm)->sub;
			return;
		}
		*fm = (*fm)->nast;
	}
	
	*fm = head;
}

void LeaveFolder(FileManager *fm, FileManager *ojciec)
{
	if(*ojciec == 0) return;
	*fm = *ojciec;
	*ojciec = (*fm)->ojciec;
	
	while((*fm)->pop)
		*fm = (*fm)->pop;
}

void RemoveFile(FileManager *fm, FileManager *ojciec, char* text)
{
	if(*fm == 0) return;
	FileManager head = *fm;
	
	while(*fm)
	{
		if(*fm != 0 && strcmp((*fm)->klucz,text) == 0 && (*fm)->sub == 0)
		{
			FileManager dU = *fm;
			if((*fm)->nast != 0)
				(*fm)->nast->pop = (*fm)->pop;
			if((*fm)->pop != 0)
				(*fm)->pop->nast = (*fm)->nast;	
			if((*fm)->pop == 0 && (*fm)->nast == 0 && *ojciec != 0)
			{
				(*ojciec)->sub = 0;
				LeaveFolder(fm, ojciec);
			}
			else if(*ojciec != 0 && (*fm) == (*ojciec)->sub)
			{
				(*ojciec)->sub = (*fm)->nast;
				*fm = (*ojciec)->sub;
			}
			else if((*fm)->pop == 0 && (*fm)->nast == 0 && *ojciec == 0)
			{
				free(dU);
				*fm = 0;
				return;
			}
			
			free(dU);
			return;
		}
		*fm = (*fm)->nast;
	}
	
	*fm = head;
}

FileManager* FindFolder(FileManager *fm, char* text)
{
	while(*fm)
	{
		if(*fm != 0 && strcmp((*fm)->klucz,text) == 0)
		{
			return fm;
		}
		fm =&(*fm)->nast;
	}
	return 0;
}

void EmptyFolder(FileManager *fm)
{
	if(*fm == 0) return;
	FileManager du = *fm, wu = *fm;
	while(du)
	{
		if((*fm)->sub != 0)
			EmptyFolder(wu->sub);
		else
		{
			
			wu = wu->nast;
			free(du);
			du = wu;	
		}
	}
}
