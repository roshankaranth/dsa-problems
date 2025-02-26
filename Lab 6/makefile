runTask2 : task2.o
	gcc -o task2_exe task2.o
	./task2_exe

runTask1 : task1.o
	gcc -o task1_exe task1.o
	./task1_exe dat1000.csv 1000
	./task1_exe dat10000.csv 10000
	./task1_exe dat100000.csv 100000
	./task1_exe dat1000000.csv 1000000

runQuickSort : quickSort.o
	gcc -o quickSort_exe quickSort.o
	./quickSort_exe

quickSort.o : quickSort.c
	gcc -c quickSort.c

task1.o : task1.c 
	gcc -c task1.c

task2.o : task2.c
	gcc -c task2.c

clean : 
	rm *.o
	rm *_exe