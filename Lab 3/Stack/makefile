runStackWithArray: stackDriver.o stack_array.o
	gcc -o runStackWithArray_exe stackDriver.o stack_array.o
	./runStackWithArray_exe

runStackWithLL: stackDriver.o stack_ll.o linked_list.o
	gcc -o runStackWithLL_exe stackDriver.o stack_ll.o linked_list.o
	./runStackWithLL_exe

stackDriver.o: stackDriver.c 
	gcc -c stackDriver.c

stack_array.o: stack_array.c 
	gcc -c stack_array.c

stack_ll.o: stack_ll.c linked_list.c
	gcc -c stack_ll.c 

linked_list.o: linked_list.c
	gcc -c linked_list.c

clean:
	rm *.o
	rm *_exe

