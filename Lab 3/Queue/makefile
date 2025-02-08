runQueueWithArray : queueDriver.o queue_array.o heap_usage.o
	gcc -o runQueueWithArray_exe queueDriver.o queue_array.o heap_usage.o
	./runQueueWithArray_exe

queueDriver.o : queueDriver.c
	gcc -c queueDriver.c

queue_array.o : queue_array.c
	gcc -c queue_array.c

heap_usage.o : heap_usage.c
	gcc -c heap_usage.c

clean : 
	rm *.o
	rm *_exe

