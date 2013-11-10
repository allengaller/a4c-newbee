CC = gcc
CFLG = -c -g
LFLG = -o

all: rotate.o rotate.out count_one_num.o count_one_num.out

rotate.o: rotate.c
	${CC} ${CFLG} $^ 

rotate.out: rotate.o
	${CC} $^ ${LFLG} $@

count_one_num.o: count_one_num.c
	${CC} ${CFLG} $^ 

count_one_num.out: count_one_num.o
	${CC} $^ ${LFLG} $@

clean:
	rm -rf *.o *.out
