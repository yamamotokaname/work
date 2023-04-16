#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lineararr.h"
#include"common.h"

int ctSearch(TARGETSET *set, char *key){
	int i;
	int search;
	
	for(search = 0, i = 0; strcmp(key, set->data[i]->key); i++){
		search++;
		if(i == set->ct-1){
			set->fsearch += search;
			return dFalse;
		}
	}
	search++;
	set->ssearch += search;
	set->hits++;
	return i;
}

char *Insert(TARGETSET *set, char *key){

	set->data[set->ct] = (KEYCELL *)malloc(sizeof(KEYCELL));
	strcpy(set->data[set->ct]->key, key);
	
	return key;
}
