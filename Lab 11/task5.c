#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct person{
    int id;
    char name[30];
    int age;
    int height;
    int weight;
}Person;

typedef struct heap{
    Person *data;
    int size;
    int capacity;
    int depth;
}Heap;

Heap* heap_create(){
    Heap* h = (Heap*)malloc(sizeof(Heap));

    h->data = (Person*)malloc(sizeof(Person));
    h->size = 0;
    h->capacity = 1;
    h->depth = 0;

    return h;
}

int power(int a, int n){
    int res = 1;
    for(int i = 0 ; i < n ; i++){
        res *= a;
    }

    return res;
}

void add_to_tree(Heap* h, Person val){
    
    if(h->capacity == h->size){
        h->depth++;
        h->data = (Person*)realloc(h->data,sizeof(Person)*(power(2,h->depth+1) -1));
        h->capacity = power(2,h->depth+1)-1;

    }

    h->data[h->size] = val;
    h->size++;

}

int parent(Heap* h, int node){
    return (node-1)/2;
}

int left_child(Heap* h, int node){
    return 2*(node) + 1;
}

int right_child(Heap* h, int node){
    return 2*(node) + 2;
}

void display(Heap* h){
    for(int i = 0 ; i < h->size ; i++){
        printf("%d %s %d %d %d\n",h->data[i].id,h->data[i].name,h->data[i].age,h->data[i].height,h->data[i].weight);
    }
    printf("\n");
}

void max_heapify(Heap* h, int index){
    
    int left = left_child(h,index);
    int right = right_child(h,index);
    int largest = index;

    if(left < h->size && h->data[left].height > h->data[largest].height){
        largest = left;
    }

    if(right < h->size && h->data[right].height > h->data[largest].height){
        largest = right;
    }

    if(largest != index){
        Person temp = h->data[index];
        h->data[index] = h->data[largest];
        h->data[largest] = temp;
        max_heapify(h,largest);
    }
}

void build_max_heap(Heap* h){
    int size =h->size;

    for(int i = h->size-1 ; i>= 0 ;i--){
        max_heapify(h,i);
    }

    return;
}

int depth_of_node(Heap* h, int depth){
    
    if(depth < h->depth){
        return power(2,depth);
    }else if(depth > h->depth){
        return 0;
    }else{
        return (h->size - power(2,depth)+1);
    }
}

void heap_sort(Heap* h){
    build_max_heap(h);
    int size = h->size;
    for(int i = h->size - 1 ; i>=1 ; i--){
        Person temp = h->data[0];
        h->data[0] = h->data[i];
        h->data[i] = temp;
        h->size = h->size - 1;
        max_heapify(h,0);
    }
    h->size = size;
}


void main(){
    Heap* h = heap_create();

    FILE* fptr = fopen("dat1000.csv","r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    char line[100];

    while(fgets(line,100,fptr)){
        Person p;
        char* token = strtok(line,",");
        p.id = atoi(token);
        token = strtok(NULL,",");
        strcpy(p.name, token);
        token = strtok(NULL,",");
        p.age = atoi(token);
        token = strtok(NULL,",");
        p.height = atoi(token);
        token = strtok(NULL,",");
        p.weight = atoi(token);

        add_to_tree(h,p);

    }

    display(h);
    build_max_heap(h);
    heap_sort(h);
    display(h);


    return;
}