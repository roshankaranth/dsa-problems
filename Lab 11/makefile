runMinHeap : min_heap.o
	gcc -o min_heap_exe min_heap.o
	./min_heap_exe

runHeap : heap.o
	gcc -o heap_exe heap.o
	./heap_exe 

min_heap.o : min_heap.c
	gcc -c min_heap.c

heap.o : heap.c 
	gcc -c heap.c

clean : 
	-rm *.o
	-rm *_exe