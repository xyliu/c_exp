PROG= test_sqrt
CFLAGS= -g
LDFLAGS= -lm

all: $(PROG)

$(PROG):$(PROG).c
	gcc -o $@ $< -lm

clean:
	rm -f $(PROG) *.o
