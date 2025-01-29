clean : 
		rm *.o
		rm *_exe
		rm *.out

task4 : task4_exe
		./task4_exe

task4_exe : task4.o
		   gcc -o task4_exe task4.o

task4.o : task4.c
		  gcc -c task4.c

home_ex2 : home_ex2_exe
		   ./home_ex2_exe

home_ex2_exe : home_ex2.o
			   gcc -o home_ex2_exe home_ex2.o

home_ex2.o : home_ex2.c
			 gcc -c home_ex2.c