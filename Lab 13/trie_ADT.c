#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define ALPHABET_SIZE 128 //you can instead reduce the alphabet size and create your own mapping of character to index in array

int CHAR_TO_INDEX(char c){
    //custom mapping if alphabet size reduced
    return (int)c;
}

// trie node
typedef struct TrieNode TrieNode;
struct TrieNode{
    TrieNode *children[ALPHABET_SIZE];
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int childCount;
    // void* data; //instead of checking for the presence or absence of a string,
    //if we wish to assign some value with the key as a pair, then this could be
    //uncommented
};

// Returns new trie node (initialized to NULLs)
TrieNode *getNode(void){
    TrieNode *pNode = NULL;
    pNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (pNode){
        int i;
        pNode->isEndOfWord = false;
        pNode->childCount = 0;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index]){
            pCrawl->children[index] = getNode();
            pCrawl->childCount++;
        }

        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;
    TrieNode *pCrawl = root;
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
        return false;
        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

void delete(TrieNode* root, const char* key){
    if(!search(root,key)) return;
    int length = strlen(key);
    TrieNode* pcrawl = root;
    for(int level = 0; level < length ; level++){
        int index = CHAR_TO_INDEX(key[level]);
        pcrawl = pcrawl->children[index];
    }

    pcrawl->isEndOfWord = false;
    return;
}

bool freeTrieRecursive(TrieNode* node, int level, const char* key){
    if(level == strlen(key)){
        node->isEndOfWord = false;
        if(node->childCount == 0){
            free(node);
            return true;
        }

        return false;
    }

    int index = CHAR_TO_INDEX(key[level]);
    bool res = freeTrieRecursive(node->children[index],level+1,key);

    if(!res) return false;
    node->children[index] = NULL;
    node->childCount--;

    if(node->childCount == 0){
        free(node);
        return true;
    }
    return false;
    
}

void delete2(TrieNode* root, const char* key){
    if(!search(root,key)) return;
    freeTrieRecursive(root,0,key);
}

// Driver
void main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    // char keys[][8] = {"the", "a", "there", "answer", "any","by", "bye", "their"};
    char output[][32] = {"Not present in trie", "Present in trie"};
    TrieNode *root = getNode();
    // Construct trie
    // int i;
    // for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
    //     insert(root, keys[i]);

    // Search for different keys
    // printf("%s --- %s\n", "the", output[search(root, "the")] );
    // printf("%s --- %s\n", "these", output[search(root, "these")] );
    // printf("%s --- %s\n", "their", output[search(root, "their")] );
    // printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
    // printf("%s --- %s\n", "a", output[search(root, "a")] );

    // delete2(root,"the");
    // delete2(root,"their");
    // delete2(root,"a");

    // printf("%s --- %s\n", "their", output[search(root, "their")] );
    // printf("%s --- %s\n", "the", output[search(root, "the")] );
    // printf("%s --- %s\n", "a", output[search(root, "a")] );
    // printf("%s --- %s\n", "answer", output[search(root, "answer")] );
    // printf("%s --- %s\n", "any", output[search(root, "any")] );

    FILE* fptr = fopen("names1000.csv","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    char line[100];
    while(fgets(line,100,fptr)){
        char name[30];
        char* token = strtok(line,"\0");
        strcpy(name,token);

        int index = 0;
        while(name[index] != '\n') index++;
        name[index-1] = '\0';

        insert(root,name);
    }

    printf("%s --- %s\n", "Ruby Bila", output[search(root, "Ruby Bila")] );
    delete2(root,"Ruby Bila");
    printf("%s --- %s\n", "Ruby Bila", output[search(root, "Ruby Bila")] );
    printf("%s --- %s\n", "Ruben Schafer", output[search(root, "Ruben Schafer")] );





    return;
}