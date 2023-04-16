#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lineararr.h"
#include"common.h"

int Search(TARGETSET *set, char *key, int *pos){
	int low, high, mid;
	int diff;
	low = 0;
	high = set->ct - 1;
	
	if(high < 0){
		*pos = 0;
		return dFalse;
	}
	
	for(mid = ((low + high) / 2); (diff = strcmp(set->data[mid]->key, key)) != 0 && low <= high; mid = ((low + high) / 2)){
		;
		if(diff < 0) low = mid + 1;
		else high = mid - 1;
	}
	
	*pos = low;
	return (diff == 0)? dTrue : dFalse;
}

int ctSearch(TARGETSET *set, char *key){
	int low, high, mid;
	int diff;
	int search;
	low = 0;
	high = set->ct - 1;
	
	search = 0;
	for(mid = ((low + high) / 2); (diff = strcmp(set->data[mid]->key, key)) != 0 && low <= high; mid = ((low + high) / 2)){
		search++;
		if(diff < 0) low = mid + 1;
		else high = mid - 1;
	}
	
	if(diff == 0){
		//printf("%d\n", search + 1);
		set->ssearch += search + 1;
		set->hits++;
	}
	else{
		//printf("%d\n", search);
		set->fsearch += search;
	}
	
	return (diff == 0)? dTrue : dFalse;
}

char *Insert(TARGETSET *set, char *key){
	int *pos;
	
	Search(set, key, pos);
	Slide(set, *pos);

	set->data[*pos] = (KEYCELL *)malloc(sizeof(KEYCELL));
	strcpy(set->data[*pos]->key, key);
	
	return key;
}

int Slide(TARGETSET *set, int pos){
	int i;
	
	if(set->ct + 1 > dTargetKeySetSize)
		return dFalse;
	for(i = set->ct; i > pos; i--){
		set->data[i] = set->data[i - 1];
		set->shift++;
	}
	return dTrue;
}

void printtargetset(TARGETSET *set){
	int i;
	
	for(i = 0; i < set->ct; i++)
		printf("%s", set->data[i]->key);
}
