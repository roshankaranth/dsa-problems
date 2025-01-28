rm *.o
rm *_exe
gcc -c quiz.c setC.c
gcc -o check_setC_exe quiz.o setC.o
./check_setC_exe