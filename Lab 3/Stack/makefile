runStackWithArray: stackDriver.o stack_array.o
	gcc -o runStackWithArray_exe stackDriver.o stack_array.o
	./runStackWithArray_exe

stackDriver.o: stackDriver.c 
	gcc -c stackDriver.c

stack_array.o: stack_array.c 
	gcc -c stack_array.c

clean:
	rm *.o
	rm *_exe