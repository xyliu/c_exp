PROG = test_fork
CFLAGS= -g
all: $(PROG)

%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROG)
