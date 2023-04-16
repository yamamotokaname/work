#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lineararr.h"
#include"common.h"


//最後まで見つからなかった場合は最後の位置を返し，ctとの比較で成功/不成功を判断する
//逆転した時点で返すので，見つかったかどうかも上位側で判断する
int Search(TARGETSET *set, char *key, int *pos){
	int i;
	int search;
	int diff;
	
	for(i = 0, search = 0; i < set->ct && (diff = strcmp(set->data[i]->key, key)) < 0; i++)
		;
	
	*pos = i;
	return (diff == 0)? dTrue : dFalse;
}

int ctSearch(TARGETSET *set, char *key){
	int i;
	int search;
	int diff;
	
	for(i = 0, search = 0; i < set->ct && (diff = strcmp(set->data[i]->key, key)) < 0; i++)
		search++;

	if(diff == 0){
		set->ssearch += ++search;
		set->hits++;
	}
	else set->fsearch += search + 1;

	return i;
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
	for(i = set->ct; i > pos; i--)
		set->data[i] = set->data[i - 1];
	return dTrue;
}

int Delete();
