#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linearlist.h"
#include"common.h"

int ctSearch(TARGETSET *head, char *key){
	TARGETSET *pp, *next;
	long search = 0;
	
	strcpy(head->data.key, key);//banpei
	for(pp = head; strcmp(pp->next->data.key, key); pp = pp->next)
		search++;
	search++;
	if(pp->next != head){
		head->ssearch += search;
		head->hits++;
	}
	else head->fsearch += search;
	return (pp->next != head)? dTrue : dFalse;
}

char *Insert(TARGETSET *tail, char *key){
	TARGETSET *pp, *tmp;

	tail->next = (TARGETSET *)malloc(sizeof(TARGETSET));
	strcpy(tail->next->data.key, key);
	
	return key;
}

void PrintTargetset(TARGETSET *head){
	TARGETSET *pp;
	
	for(pp = head->next; pp != head; pp = pp->next)
		printf("%s", pp->data.key);
}

int Delete(TARGETSET *set, char *key);

void Free(TARGETSET *head){
	TARGETSET *pp, *next;
	
	pp = head->next, next = head->next->next;
	for(head->next = NULL; next != NULL; next = next->next)
		free(pp);
	free(pp);
}
