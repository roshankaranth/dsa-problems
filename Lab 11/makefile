runPriorities : priorities.o
	gcc -o priorities_exe priorities.o
	./priorities_exe

runTask5 : task5.o
	gcc -o task5_exe task5.o
	./task5_exe

runMinHeap : min_heap.o
	gcc -o min_heap_exe min_heap.o
	./min_heap_exe

runHeap : heap.o
	gcc -o heap_exe heap.o
	./heap_exe 

priorities.o : priorities.c 
	gcc -c priorities.c 

task5.o : task5.c 
	gcc -c task5.c

min_heap.o : min_heap.c
	gcc -c min_heap.c

heap.o : heap.c 
	gcc -c heap.c

clean : 
	-rm *.o
	-rm *_exe