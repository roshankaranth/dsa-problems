runTask1 : task1.o;
	gcc -o task1_exe task1.o
	./task1_exe dat1000.csv 1000

runQuickSort : quickSort.o
	gcc -o quickSort_exe quickSort.o
	./quickSort_exe

quickSort.o : quickSort.c
	gcc -c quickSort.c

task1.o : task1.c 
	gcc -c task1.c

clean : 
	rm *.o
	rm *_exe