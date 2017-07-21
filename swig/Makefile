All:
	swig -python example.i
	#gcc -fpic -c example.c example_wrap.c  -I/usr/local/include
	gcc -fpic -c example.c example_wrap.c  -I /home/woliu/virtual/p3/include/python3.5m/
	ld -shared example.o example_wrap.o -o _example.so
Setup:
	sudo apt-get install swig
	sudo apt-get install python3-dev
clean:
	rm -f *.o _* example_wrap.c example.py -r __pycache__


