CC = cc
HEADDER = headder

COM = ${HEADDER}/common.h
ARR = ${HEADDER}/lineararr.h
LIST = ${HEADDER}/linearlist.h
OBJ = mlls mllr lar las llr lls

lar: arr.o lineararrrand.o
	${CC} arr.o lineararrrand.o -o lar
las: arr.o lineararrsort.o
	${CC} arr.o lineararrsort.o -o las
llr: mllr linearlistrand.o
	${CC} mllr linearlistrand.o -o llr
lls: mlls linearlistsort.o
	${CC} mlls linearlistsort.o -o lls
binary: arr.o binaryfunc.o
	${CC} arr.o binaryfunc.o -o binary

lineararrrand.o: linear/array/lineararrrand.c ${LIST} ${COM}
	${CC} -c -I ${HEADDER} linear/array/lineararrrand.c
lineararrsort.o: linear/array/lineararrsort.c ${LIST} ${COM}
	${CC} -c -I ${HEADDER} linear/array/lineararrsort.c
arr.o: arr.c ${ARR} ${COM}
	${CC} -c -I ${HEADDER} arr.c
	
linearlistrand.o: linear/list/linearlistrand.c ${ARR} ${COM}
	${CC} -c -I ${HEADDER} linear/list/linearlistrand.c
linearlistsort.o: linear/list/linearlistsort.c ${ARR} ${COM}
	${CC} -c -I ${HEADDER} linear/list/linearlistsort.c
mllr: linear/linearlistrand.c ${LIST} ${COM}
	${CC} -c -I ${HEADDER} linear/linearlistrand.c -o mllr
mlls: linear/linearlistsort.c ${LIST} ${COM}
	${CC} -c -I ${HEADDER} linear/linearlistsort.c -o mlls
	
binaryfunc.o: dbinary/binaryfunc.c ${ARR} ${COM}
	${CC} -c -I ${HEADDER} dbinary/binaryfunc.c ${ARR} ${COM}
	
clear:
	rm -f *.o ${OBJ}
