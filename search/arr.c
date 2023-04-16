//207338 山本要人
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#include"common.h"
#include"lineararr.h"

int main(int argc, char *argv[]){
	FILE *keyfp, *targetfp;
	char buf[dBufferSize];
	KEYSET *keyset;
	TARGETSET *targetset;
	int i, texthead;
	
	if((keyfp = fopen(argv[1], "rt")) == NULL){
		fprintf(stderr, "cant open : %s\n", argv[1]);
		return dErrNum;
	}
	
	if((targetfp = fopen(argv[2], "rt")) == NULL){
		fprintf(stderr, "cant open2 : %s\n", argv[2]);
		return dErrNum;
	}
	
	keyset = (KEYSET *)malloc(sizeof(KEYSET));
	for(keyset->ct = 0; fgets(buf, dBufferSize, keyfp) != NULL && keyset->ct < dKeySetSize; keyset->ct++){
		strcpy(keyset->key[keyset->ct].key, buf);
	}
	fclose(keyfp);
	
	targetset = (TARGETSET *)malloc(sizeof(TARGETSET));
	targetset->hits = 0;
	targetset->ssearch = 0;
	targetset->fsearch = 0;
	for(targetset->ct = 0; fgets(buf, dBufferSize, targetfp) != NULL && targetset->ct < dTargetKeySetSize; targetset->ct++){
		//printf("%d\n", targetset->ct);
		Insert(targetset, buf);
	}
	fclose(targetfp);
	
	
	//PrintKeySet(keyset);
	//PrintTargetset(targetset);
	
	
	for(i = 0; i < keyset->ct; i++)
		ctSearch(targetset, keyset->key[i].key);
	
	printf("%d\t%ld\t%ld\t%ld\t%ld\t%ld\t%ld\n", targetset->ct, targetset->hits, targetset->ssearch, targetset->fsearch, targetset->ssearch+targetset->fsearch, (targetset->ssearch+targetset->fsearch)/5000, targetset->shift);
	
	
	free(keyset);
	for(i = 0; i < targetset->ct; i++)
		free(targetset->data[i]);
	free(targetset);
	
	return 0;
}

void PrintKeySet(KEYSET *keyset){
	int i;
	
	for(i = 0; i < keyset->ct; i++)
		printf("%s", keyset->key[i].key);
}

void PrintTargetset(TARGETSET *set){
	int i;
	
	for(i = 0; i < set->ct; i++)
		printf("%s", set->data[i]->key);
}
