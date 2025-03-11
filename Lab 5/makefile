runTask3 : task3.o
	gcc -o task3_exe task3.o 
	./task3_exe

runTask2 : task2.o
	gcc -o task2_exe task2.o
	./task2_exe input_files/numbers10000.txt 10000

runTask1 : task1.o
	gcc -o task1_exe task1.o
	./task1_exe 

task3.o : task3.c
	gcc -c task3.c

task2.o : task2.c
	gcc -c task2.c

task1.o : task1.c
	gcc -c task1.c

clean : 
	rm *.o
	rm *_exe 
