CC=gcc
DEFS=func1.h func2.h
CFLAG=-Wl,-Map,Sum.map main.o func1.o func2.o

Sum.exe: main.o func1.o func2.o
	$(CC) -o sum.exe main.o func1.o func2.o 
	$(CC)  $(CFLAG)
	
main.o: $(DEFS) main.c
	$(CC) -c main.c 
	
func1.o: func1.h func1.c
	$(CC) -c func1.c 
	
func2.o: func2.h func2.c
	$(CC) -c func2.c 
	
clean: 
	del -f *.o main.o func1.o func2.o		
	del -f *.exe
	del -f *.map
	echo Clean Done	 	
	
	