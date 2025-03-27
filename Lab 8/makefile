runTask5 : task5.o
	gcc -o task5_exe task5.o
	./task5_exe 

runTask4 : task4.o
	gcc -o task4_exe task4.o
	./task4_exe 

runTask3 : task3.o
	gcc -o task3_exe task3.o
	./task3_exe 

runTask2_double_hashing2 : task2_double_hashing2.o
	gcc -o task2_double_hashing2_exe task2_double_hashing2.o
	./task2_double_hashing2_exe

runTask2_linear_probing : task2_linear_probing.o
	gcc -o task2_linear_probing_exe task2_linear_probing.o
	./task2_linear_probing_exe 

runTask2_quad_probing : task2_quad_probing.o
	gcc -o task2_quad_probing_exe task2_quad_probing.o
	./task2_quad_probing_exe 

runTask2_double_hashing : task2_double_hashing.o
	gcc -o task2_double_hashing_exe task2_double_hashing.o
	./task2_double_hashing_exe 

runTask1 : task1.o
	gcc -o task1_exe task1.o
	./task1_exe 

task5.o : task5.c 
	gcc -c task5.c

task4.o : task4.c 
	gcc -c task4.c

task3.o : task3.c 
	gcc -c task3.c

task2_double_hashing2.o : task2_double_hashing2.c 
	gcc -c task2_double_hashing2.c

task2_double_hashing.o : task2_double_hashing.c 
	gcc -c task2_double_hashing.c

task2_quad_probing.o : task2_quad_probing.c 
	gcc -c task2_quad_probing.c

task2_linear_probing.o : task2_linear_probing.c 
	gcc -c task2_linear_probing.c

task1.o : task1.c 
	gcc -c task1.c
	
clean : 
	rm *.o
	rm *_exe