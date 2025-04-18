runTriev2 : trieADTv2.o
	gcc -o trieADTv2_exe trieADTv2.c
	./trieADTv2_exe 

runTrie : trie_ADT.o
	gcc -o trie_ADT_exe trie_ADT.c
	./trie_ADT_exe 

trieADTv2.o : trieADTv2.c 
	gcc -c trieADTv2.c 

trie_ADT.o : trie_ADT.c 
	gcc -c trie_ADT.c 

clean : 
	rm *.o
	rm *_exe 