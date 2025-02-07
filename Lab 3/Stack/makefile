runcgStackDriverSmall : cgStackDriver.o stack_ll.o heap_usage.o linked_list.o
	gcc -o cgStackDriverSmall_exe stack_ll.o heap_usage.o cgStackDriver.o linked_list.o
	./cgStackDriverSmall_exe small.csv

runcgStackDriverMedium : cgStackDriver.o stack_ll.o heap_usage.o linked_list.o
	gcc -o cgStackDriverMedium_exe stack_ll.o heap_usage.o cgStackDriver.o linked_list.o
	./cgStackDriverMedium_exe medium.csv

runcgStackDriverLarge : cgStackDriver.o stack_ll.o heap_usage.o linked_list.o
	gcc -o cgStackDriverLarge_exe stack_ll.o heap_usage.o cgStackDriver.o linked_list.o
	./cgStackDriverLarge_exe large.csv

runStackWithArray: stackDriver.o stack_array.o heap_usage.o
	gcc -o runStackWithArray_exe stackDriver.o stack_array.o heap_usage.o
	./runStackWithArray_exe

runStackWithLL: stackDriver.o stack_ll.o linked_list.o heap_usage.o
	gcc -o runStackWithLL_exe stackDriver.o stack_ll.o linked_list.o heap_usage.o
	./runStackWithLL_exe

cgStackDriver.o: cgStackDriver.c
	gcc -c cgStackDriver.c

stackDriver.o: stackDriver.c 
	gcc -c stackDriver.c

stack_array.o: stack_array.c 
	gcc -c stack_array.c

stack_ll.o: stack_ll.c linked_list.c
	gcc -c stack_ll.c 

linked_list.o: linked_list.c
	gcc -c linked_list.c

heap_usage.o : heap_usage.c
	gcc -c heap_usage.c

clean:
	rm *.o
	rm *_exe

