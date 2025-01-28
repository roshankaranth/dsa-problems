rm *.o
rm *_exe
gcc -c quiz.c setA.c
gcc -o check_setA_exe quiz.o setA.o
./check_setA_exe

