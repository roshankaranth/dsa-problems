rm *.o
rm *_exe
gcc -c quiz.c setB.c
gcc -o check_setB_exe quiz.o setB.o
./check_setB_exe

