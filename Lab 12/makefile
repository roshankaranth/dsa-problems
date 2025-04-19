runT5 : t5.o
	gcc -o t5_exe t5.o
	./t5_exe 

runT4 : t4.o
	gcc -o t4_exe t4.o
	./t4_exe 

runT3 : t3.o
	gcc -o t3_exe t3.o
	./t3_exe 

runT2 : t2.o
	gcc -o t2_exe t2.o
	./t2_exe 

runT1 : t1.o
	gcc -o t1_exe t1.o
	./t1_exe 

t5.o : t5.c
	gcc -c t5.c

t4.o : t4.c
	gcc -c t4.c

t3.o : t3.c
	gcc -c t3.c

t2.o : t2.c
	gcc -c t2.c

t1.o : t1.c
	gcc -c t1.c	

clean : 
	-rm *.o
	-rm *_exe