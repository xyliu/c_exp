# https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
PROG= test_thread
PROG1= test_mutex
#PROG= test_mutex
CFLAGS= -g
LDFLAGS= -lpthread

all: $(PROG) $(PROG1)

$(PROG):$(PROG).c
	gcc -o $@ $< ${CFLAGS} ${LDFLAGS}

$(PROG1):$(PROG1).c
	gcc -o $@ $< ${CFLAGS} ${LDFLAGS}


clean:
	rm -f ${PROG} ${PROG1} *.o
