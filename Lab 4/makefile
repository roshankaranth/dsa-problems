runTask4 : task4.o personMerge.o personMergeAuxIter.o
	gcc -o task4_exe task4.o personMerge.o personMergeAuxIter.o
	./task4_exe dat1000.csv 1000
	./task4_exe dat10000.csv 10000
	./task4_exe dat100000.csv 100000
	./task4_exe dat1000000.csv 1000000

task4.o : task4.c 
	gcc -c task4.c

personMerge.o : personMerge.c
	gcc -c personMerge.c

personMergeAuxIter.o : personMergeAuxIter.c
	gcc -c personMergeAuxIter.c

runMergeSortInsert : intMergeSort.o intMergeByInsert.o 
	gcc -o MergeSort_exe intMergeSort.o intMergeByInsert.o 
	./MergeSort_exe

runMergeSortRec : intMergeSort.o intMerge.o intMergeAuxRec.o
	gcc -o MergeSort_exe intMergeSort.o intMerge.o intMergeAuxRec.o
	./MergeSort_exe

runMergeSortIter : intMergeSort.o intMerge.o intMergeAuxIter.o
	gcc -o MergeSort_exe intMergeSort.o intMerge.o intMergeAuxIter.o
	./MergeSort_exe

intMergeSort.o : intMergeSort.c 
	gcc -c intMergeSort.c

intMerge.o : intMerge.c
	gcc -c intMerge.c

intMergeAuxIter.o : intMergeAuxIter.c
	gcc -c intMergeAuxIter.c

intMergeAuxRec.o : intMergeAuxRec.c 
	gcc -c intMergeAuxRec.c 

intMergeByInsert.o : intMergeByInsert.c 
	gcc -c intMergeByInsert.c

runTask1 : task1.c
	gcc -c task1.c
	gcc -o task1_exe task1.o
	./task1_exe 

runTask2 : task2.c
	gcc -c task2.c
	gcc -o task2_exe task2.o
	./task2_exe dat1000.csv 1000
	./task2_exe dat10000.csv 10000
	./task2_exe dat100000.csv 100000
	./task2_exe dat1000000.csv 1000000
	
clean : 
	rm *.o
	rm *_exe
