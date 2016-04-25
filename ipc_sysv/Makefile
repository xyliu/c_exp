PROG = test_semaphore 
CFLAGS= -g
all: $(PROG)

%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROG)
