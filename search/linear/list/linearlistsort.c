#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linearlist.h"
#include"common.h"

int Search(TARGETSET *head, char *key, TARGETSET *pos){
	TARGETSET *pp, *next;
	long search = 0;
	int diff;
	
	strcpy(head->data.key, key);//banpei
	for(pp = head; (diff = strcmp(pp->next->data.key, key)) < 0; pp = pp->next)
		;
	
	pos = pp;
	return (pp != head)? dTrue : dFalse;
}

int ctSearch(TARGETSET *head, char *key){
	TARGETSET *pp, *next;
	long search = 0;
	int diff;
	
	strcpy(head->data.key, key);//banpei
	for(pp = head; (diff = strcmp(pp->next->data.key, key)) < 0; pp = pp->next)
		search++;
	if(pp->next != head){
		head->ssearch += search + 1;
		head->hits++;
	}
	else head->fsearch += search;
	
	return (pp != head)? dTrue : dFalse;
}

char *Insert(TARGETSET *head, char *key){
	TARGETSET *pp, *tmp, *next;

	Search(head, key, pp);
	tmp = (TARGETSET *)malloc(sizeof(TARGETSET));
	next = pp->next;
	pp->next = tmp;
	strcpy(pp->next->data.key, key);
	pp->next->next = next;
	
	return key;
}

void PrintTargetset(TARGETSET *head){
	TARGETSET *pp;
	
	for(pp = head->next; pp != head; pp = pp->next)
		printf("%s", pp->data.key);
}

int Delete(TARGETSET *set, char *key);
