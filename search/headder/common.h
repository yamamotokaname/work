#ifndef _COMMON_H_
#define _COMMON_H_

#define SearchKeyFilePath keyfile/
#define dBufferSize         (32)
#define dKeySize            (32)
#define dKeySetSize         (100000)
#define dTargetKeySetSize   (100000)
#define dErrNum             (-1)
#define dTextSize           (3200000)
#define dTrue               (!0)
#define dFalse              (0)

typedef struct _KEYCELL{
	char key[dKeySize];
}KEYCELL;

typedef struct _KEYSET{
	KEYCELL key[dKeySetSize];
	int ct;
}KEYSET;

void PrintKeySet(KEYSET *head);

#endif
