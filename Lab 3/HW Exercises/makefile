runComputeSpan : computeSpan.o stack_ll.o heap_usage.o linked_list.o
	gcc -o computeSpan_exe computeSpan.o stack_ll.o heap_usage.o linked_list.o
	./computeSpan_exe

computeSpan.o : computeSpan.c
	gcc -c computeSpan.c 

stack_ll.o : ../Stack/stack_ll.c 
	gcc -c ../Stack/stack_ll.c 

heap_usage.o : ../Stack/heap_usage.c
	gcc -c ../Stack/heap_usage.c

linked_list.o : ../Stack/linked_list.c 
	gcc -c ../Stack/linked_list.c

runHome_Exercise : home_exercise4.o queue_ll.o linked_list_q.o
	gcc -o home_exercise4_exe home_exercise4.o queue_ll.o linked_list.o
	./home_exercise4_exe

home_exercise4.o : home_exercise4.c 
	gcc -c home_exercise4.c 

queue_ll.o : queue_ll.c 
	gcc -c queue_ll.c

linked_list_q.o: linked_list.c 
	gcc -c linked_list.c

clean :
	rm *.o
	rm *_exe 