PROG= inc_dec inc_dec2 
CFLAGS= -g -rdynamic
LDFLAGS= -lm

all: $(PROG)

inc_dec:inc_dec.c
	gcc -o $@ $<  $(CFLAGS)

inc_dec2:inc_dec2.c
	gcc -o $@ $<  $(CFLAGS)


clean:
	rm -f $(PROG) *.o
