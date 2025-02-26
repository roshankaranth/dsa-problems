#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>

typedef struct person {
    int id;
    char name[100];
    int age;
    int height;
    int weight;

}Person;

Person itoe(int ID, char* name, int age, int height, int weight){
    Person p;
    p.id = ID;
    strcpy(p.name, name);
    p.age = age;
    p.height = height;
    p.weight = weight;

    return p;
}

void display(Person* data, int size){
    for(int i = 0 ; i < size; i ++){
        printf("%d %s %d %d %d\n", data[i].id, data[i].name, data[i].age, data[i].height, data[i].weight);
    }
}

void swap(Person* data, int i, int j){
    Person temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int lomutoPartition(Person* data, int l, int r, int pv){
    swap(data,r,pv);

    int i = l-1;
    int j = l;
    
    while(j<=r-1){
        while(j<=r-1 && data[j].height > data[r].height) j++;
        
        if(j<=r-1){
            i++;
            swap(data,i,j);
            j++;
        }
    }

    swap(data,i+1,r);
    return i+1;
}

int threeWayHoarePartition(Person* data, int l, int r, int pv){
    swap(data,pv,r);
    int  i = l;
    int j = r-1;
    int mid = l;
    while(mid<=j){
        if(data[mid].height < data[r].height){
            swap(data,mid,i);
            i++;
            mid++;
        }else if(data[mid].height > data[r].height){
            swap(data,mid,j);
            j--;
        }else{
            mid++;
        }
    }

    swap(data,mid,r);
    return mid;
}  

int twoWayHoarePartition(Person* data, int l, int r, int pv){
    swap(data,r,pv);

    int i = l;
    int j = r-1;
    while(i<=j){
        
        while(j>=l && data[j].height > data[r].height) j--;
        while(i<=r-1 && data[i].height <= data[r].height) i++;
        if(i<j){
            swap(data,i,j);
        }
    }
    swap(data,i,r);
    return i;
}

void QuickSort1(Person* data, int l, int r){
    if(l>=r) return;
    
    int pv = (l+r)/2; 
    int pvInd = twoWayHoarePartition(data, l, r, pv);
    QuickSort1(data,l,pvInd-1);
    QuickSort1(data,pvInd+1,r);
}

void QuickSort2(Person* data, int l, int r){
    if(l>=r) return;
    
    int pv = (l+r)/2; 
    int pvInd = threeWayHoarePartition(data, l, r, pv);
    QuickSort2(data,l,pvInd-1);
    QuickSort2(data,pvInd+1,r);
}

void QuickSort3(Person* data, int l, int r){
    if(l>=r) return;
    
    int pv = (l+r)/2; 
    int pvInd = lomutoPartition(data, l, r, pv);
    QuickSort3(data,l,pvInd-1);
    QuickSort3(data,pvInd+1,r);
}



void main(int argc, char* argv[]){
    int size = atoi(argv[2]);
    FILE* fptr = fopen(argv[1], "r");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }

    Person* data1 = (Person*)malloc(sizeof(Person)*size);
    Person* data2 = (Person*)malloc(sizeof(Person)*size);
    Person* data3 = (Person*)malloc(sizeof(Person)*size);

    char line[100];
    int i = 0;
    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        int ID = atoi(token);
        token = strtok(NULL,",");
        char* name = token;
        token = strtok(NULL,",");
        int age = atoi(token);
        token = strtok(NULL,",");
        int height = atoi(token);
        token = strtok(NULL,",");
        int weight = atoi(token);

        data1[i] = itoe(ID, name, age, height, weight);
        data2[i] = itoe(ID, name, age, height, weight);
        data3[i] = itoe(ID, name, age, height, weight);
        i++;

    }

    struct timeval t1, t2;
    double time_interval;

    gettimeofday(&t1,NULL);
    QuickSort1(data1, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("QuickSort with two way Hoare's Partition took %f amount of time.\n", time_interval);

    gettimeofday(&t1,NULL);
    QuickSort1(data2, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("QuickSort with three way Hoare's Partition took %f amount of time.\n", time_interval);

    gettimeofday(&t1,NULL);
    QuickSort1(data3, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("QuickSort with Lomuto Partition took %f amount of time.\n", time_interval);
    //display(data1, size);

}