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
