runTask5 : task5.o
	gcc -o task5_exe task5.o
	./task5_exe dat1000.csv 1000

runTask4 : task4.o
	gcc -o task4_exe task4.o
	./task4_exe dat100000.csv 100000

runTask3 : task3.o
	gcc -o task3_exe task3.o
	./task3_exe dat10000.csv 10000

runTask2 : task2.o
	gcc -o task2_exe task2.o
	./task2_exe

runTask1 : task1.o
	gcc -o task1_exe task1.o
	./task1_exe dat100000.csv 100000


runQuickSort : quickSort.o
	gcc -o quickSort_exe quickSort.o
	./quickSort_exe

quickSort.o : quickSort.c
	gcc -c quickSort.c

task1.o : task1.c 
	gcc -c task1.c

task2.o : task2.c
	gcc -c task2.c

task3.o : task3.c 
	gcc -c task3.c

task4.o : task4.c 
	gcc -c task4.c

task5.o : task5.c 
	gcc -c task5.c

clean : 
	rm *.o
	rm *_exe