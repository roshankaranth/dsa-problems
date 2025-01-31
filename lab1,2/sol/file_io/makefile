clean : 
		rm *_exe
		rm *.o

task5 : task5_exe
		./task5_exe

task5_exe : task5.o
			gcc -o task5_exe task5.o

task5.o : task5.c 
		  gcc -c task5.c 