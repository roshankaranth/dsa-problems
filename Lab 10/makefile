runHW2 : hw2.o
	gcc -o hw2_exe hw2.o
	./hw2_exe

runBST : BST.o
	gcc -o BST_exe BST.o
	./BST_exe

BST.o : BST.c
	gcc -c BST.c

hw2.o : hw2.c 
	gcc -c hw2.c

clean : 
		rm *.o
		rm *_exe