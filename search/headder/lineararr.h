#ifndef _LINEARARR_H_
#define _LINEARARR_H_

#include"common.h"

typedef struct _TARGETSET{
	KEYCELL *data[dTargetKeySetSize];
	long ssearch;
	long fsearch;
	long hits;
	int ct;
	long shift;
}TARGETSET;

char *Insert(TARGETSET *set, char *key);
int Delete(TARGETSET *set, char *key);
void PrintTargetset(TARGETSET *set);
int Search(TARGETSET *set, char *key, int *pos);
int ctSearch(TARGETSET *set, char *key);
int Slide(TARGETSET *set, int place);

#endif
