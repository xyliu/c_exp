PROGS = test_siglongjmp test_longjmp

.PHONY: all clean release
all: $(PROGS)	


#test01: test01.c
#		gcc $@.c -o $@

clean:
	rm -f $(PROGS) 

release:
	$(MAKE) all
	rm -rf bin
	mkdir -p bin
	cp $(PROGS) bin/
	$(MAKE) clean

