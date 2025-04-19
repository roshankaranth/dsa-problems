runT2 : t2.o
	gcc -o t2_exe t2.o
	./t2_exe 

runT1 : t1.o
	gcc -o t1_exe t1.o
	./t1_exe 

t2.o : t2.c
	gcc -c t2.c

t1.o : t1.c
	gcc -c t1.c	

clean : 
	-rm *.o
	-rm *_exe