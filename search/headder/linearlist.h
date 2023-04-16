#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_

#include"common.h"

typedef struct _TARGETSET TARGETSET;
struct _TARGETSET{
	KEYCELL data;
	long ssearch;
	long fsearch;
	long hits;
	int ct;
	TARGETSET *next;
};

int Search(TARGETSET *head, char *key, TARGETSET *pos);
int ctSearch(TARGETSET *head, char *key);
char *Insert(TARGETSET *set, char *key);
int Delete(TARGETSET *set, char *key);
void PrintTargetset(TARGETSET *head);
void Free(TARGETSET *head);

#endif
