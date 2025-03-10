runTask2 : task2.o
	gcc -o task2_exe task2.o
	./task2_exe input_files/numbers10000.txt 10000

task2.o : task2.c
	gcc -c task2.c

task1.o : task1.c
	gcc -c task1.c

clean : 
	rm *.o
	rm *_exe 
	rm *.out