PROG= test_bt
CFLAGS= -g -rdynamic
LDFLAGS= -lm

all: $(PROG)

$(PROG):$(PROG).c
	gcc -o $@ $<  $(CFLAGS)

clean:
	rm -f $(PROG) *.o
