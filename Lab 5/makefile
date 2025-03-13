runHomeExercise2 : homeExercise2.o
	gcc -o homeExercise2_exe homeExercise2.o
	./homeExercise2_exe

runHomeExercise1 : homeExercise1.o
	gcc -o homeExercise1_exe homeExercise1.o
	./homeExercise1_exe

runTask5 : task5.o
	gcc -o task5_exe task5.o
	./task5_exe

runTask4 : task4.o
	gcc -o task4_exe task4.o
	./task4_exe

runTask3 : task3.o
	gcc -o task3_exe task3.o 
	./task3_exe

runTask2 : task2.o
	gcc -o task2_exe task2.o
	./task2_exe input_files/numbers10000.txt 10000

runTask1 : task1.o
	gcc -o task1_exe task1.o
	./task1_exe 

homeExercise2.o : homeExercise2.c 
	gcc -c homeExercise2.c 

homeExercise1.o : homeExercise1.c 
	gcc -c homeExercise1.c 

task5.o : task5.c 
	gcc -c task5.c

task4.o : task4.c 
	gcc -c task4.c

task3.o : task3.c
	gcc -c task3.c

task2.o : task2.c
	gcc -c task2.c

task1.o : task1.c
	gcc -c task1.c

clean : 
	rm *.o
	rm *_exe 
