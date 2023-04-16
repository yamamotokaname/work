//207338 山本要人
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#include"common.h"
#include"linearlist.h"

int main(int argc, char *argv[]){
	FILE *keyfp, *targetfp;
	char buf[dBufferSize];
	KEYSET *keyset;
	TARGETSET head, *tail;
	int i;
	
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
	
	head.hits = 0;
	head.ssearch = 0;
	head.fsearch = 0;
	tail = &head;
	for(head.ct = 0; fgets(buf, dBufferSize, targetfp) != NULL; tail = tail->next, head.ct++){
		Insert(tail, buf);
	}
	tail->next = &head;
	fclose(targetfp);
	
	//PrintKeySet(keyset);
	//PrintTargetset(&head);
	
	for(i = 0; i < keyset->ct; i++)
		ctSearch(&head, keyset->key[i].key);
	
	printf("%d\t%ld\t%ld\t%ld\t%ld\n", head.ct, head.hits, head.ssearch, head.fsearch, head.ssearch+head.fsearch);
	
	//free(keyset);
	//free(targetset);
	
	return 0;
}

void PrintKeySet(KEYSET *keyset){
	int i;
	
	for(i = 0; i < keyset->ct; i++)
		printf("%s", keyset->key[i].key);
}
