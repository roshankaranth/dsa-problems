clean : 
		rm *.o
		rm *_exe

task4 : task4_exe
		./task4_exe

task4_exe : task4.o
		   gcc -o task4_exe task4.o

task4.o : task4.c
		  gcc -c task4.c