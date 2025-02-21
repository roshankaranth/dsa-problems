runhomeExercise2 : homeExercise2.c
	gcc -c homeExercise2.c
	gcc -o homeExercise2_exe homeExercise2.o
	./homeExercise2_exe

runhomeExercise1 : homeExercise1.c
	gcc -c homeExercise1.c
	gcc -o homeExercise1_exe homeExercise1.o
	./homeExercise1_exe dat1000.csv 1000
	./homeExercise1_exe dat10000.csv 10000
	./homeExercise1_exe dat100000.csv 100000
	./homeExercise1_exe dat1000000.csv 1000000

runExternalMergeSort : externalMergeSort.o personMergeAuxIter.o personMerge.o
	gcc -o externalMergeSort_exe externalMergeSort.o personMerge.o personMergeAuxIter.o
	./externalMergeSort_exe dat7578440.csv 1000000

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

runMergeSortInsert : intMergeSort.o intMergeByInsert.o heap_usage.o
	gcc -o MergeSort_exe intMergeSort.o intMergeByInsert.o heap_usage.o
	./MergeSort_exe

runMergeSortRec : intMergeSort.o intMerge.o intMergeAuxRec.o heap_usage.o
	gcc -o MergeSort_exe intMergeSort.o intMerge.o intMergeAuxRec.o heap_usage.o
	./MergeSort_exe

runMergeSortIter : intMergeSort.o intMerge.o intMergeAuxIter.o heap_usage.o
	gcc -o MergeSort_exe intMergeSort.o intMerge.o intMergeAuxIter.o heap_usage.o
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

heap_usage.o : heap_usage.c 
	gcc -c heap_usage.c

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
	rm *_aux.csv