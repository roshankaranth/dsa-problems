runPriorityQueue : priority_queue.o
	gcc -o priority_queue_exe priority_queue.o
	./priority_queue_exe

runHeapSort : heapsort.o
	gcc -o HeapSort_exe heapsort.o
	./HeapSort_exe

heapsort.o : heapsort.c 
	gcc -c heapsort.c

priority_queue.o : priority_queue.c 
	gcc -c priority_queue.c

clean : 
	rm *.o
	rm *_exe
