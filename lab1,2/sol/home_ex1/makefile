clean : 
		rm -f *.o
		rm *_exe

quizA : quizA_exe
		./quizA_exe

quizB : quizB_exe
		./quizB_exe

quizC : quizC_exe
		./quizC_exe

quizA_exe : quiz.o setA.o
		   gcc -o quizA_exe quiz.o setA.o

quizB_exe : quiz.o setB.o
		   gcc -o quizB_exe quiz.o setB.o

quizC_exe : quiz.o setC.o
		   gcc -o quizC_exe quiz.o setC.o

quiz.o : quiz.c
	   gcc -c quiz.c

setA.o : setA.c
	   gcc -c setA.c

setB.o : setB.c
	   gcc -c setB.c

setC.o : setC.c
	   gcc -c setC.c