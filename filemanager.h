#ifndef HEADER_FILEMANAGER
#define HEADER_FILEMANAGER

struct elFileMan
{
	char *klucz;
	struct elFileMan *ojciec;
	struct elFileMan *nast;
	struct elFileMan *pop;
	struct elFileMan *sub;
};
typedef struct elFileMan wFileMan;
typedef wFileMan* FileManager;


#endif
