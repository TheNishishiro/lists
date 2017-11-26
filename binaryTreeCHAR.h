#ifndef HEADER_BTCHAR
#define HEADER_BTCHAR

struct elDrzewaBCHAR
{
	char *klucz;
	int licznik;
	struct elDrzewaBCHAR *lewy;
	struct elDrzewaBCHAR *prawy;
	struct elDrzewaBCHAR *ojciec;
};
typedef struct elDrzewaBCHAR wDrzewaBCHAR;
typedef wDrzewaBCHAR* drzewoCHAR;


#endif
