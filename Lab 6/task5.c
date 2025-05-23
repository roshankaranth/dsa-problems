#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/time.h>


double time_taken_MOM = 0;

typedef struct person {
    int id;
    char name[100];
    int age;
    int height;
    int weight;

}Person;

int min(int i, int j){
    if(i>j) return j;
    else return i;
}

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

void insertionSort(Person* data, int l, int r){

    for(int i = l+1 ; i <= r ; i++){
        Person p = data[i];
        int j = i-1;
        while(j>=l){
            if(data[j].height > p.height) data[j+1] = data[j];
            else break;

            j--;
        }

        data[j+1] = p;
    }

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

int mediansOfMedians(Person* data, int l, int r){
    
    int size = (r-l) + 1;
    
    if(size <= 5){
        
        Person temp[size];
    
        for(int i = 0 ; i < size; i++){
            temp[i] = data[l+i];
        }

        for(int i =  1; i < size ; i++){
            Person val = temp[i];
            int j = i - 1;
            while(j>=0){
                if(val.height < temp[j].height){
                    temp[j+1] = temp[j];
                }else break;
                j--;
            }

            temp[j+1] = val;
        }

        for(int i = l ; i <= r ; i++){
            if(data[i].id == temp[size/2].id) return i;
        }

    }

    int MedianGroups = 0;
    if(size % 5 == 0) MedianGroups = size/5;
    else MedianGroups = (size/5) + 1;

    Person Medians[MedianGroups];
    
    for(int i = 0; i < MedianGroups ; i++){
        Medians[i] = data[mediansOfMedians(data , l + i*5, min(r,l + i*5 + 4))];
    }

    int x = mediansOfMedians(Medians, 0, MedianGroups-1);
    for(int i = l ; i <= r ; i++){
        if(data[i].id == Medians[x].id) return i;
    }

}

int recursiveQuickSelect(Person* data, int l, int r, int k){
    int size = (r-l+1);
    if(size <= 5){

        Person temp[size];
        for(int i = 0 ; i < size ; i++){
            temp[i] = data[l+i];
        }

        for(int i = 0 ; i <= size-1; i++){
            Person p = temp[i];
            int j = i -1;
            while(j>=0){
                if(temp[j].height > p.height) temp[j+1] = temp[j];
                else break;

                j--;
            }

            temp[j+1] = p;
        }
        
        for(int i = l; i <= r ; i++){
            if(data[i].id == temp[k-1].id) return i;
        }

    }

    int MedianGroups = 0;
    if(size%5 == 0) MedianGroups = size/5;
    else MedianGroups = (size/5) + 1;

    Person Medians[MedianGroups];
    for(int i = 0 ; i < MedianGroups ; i++){
        Medians[i] = data[recursiveQuickSelect(data,l + i*5, min(r,l+i*5 + 4),((min(r,l+i*5 + 4) - l+i*5)/2) + 1)];
    }

    int x = recursiveQuickSelect(Medians,0,MedianGroups-1,(MedianGroups/2) + 1);
    int pv = 0;
    for(int i = l ; i <= r ; i++ ){
        if(data[i].id == Medians[x].id){
            pv = i;
            break;
        }
    }

    if(pv==k-1) return pv;
    else if(pv > k-1) return recursiveQuickSelect(data,l,pv-1,k);
    else return recursiveQuickSelect(data,pv+1,r,k);
}

void QuickSort1(Person* data, int l, int r){
    if(l>=r) return;
    
    struct timeval tv;
    gettimeofday(&tv,NULL);
    srand(tv.tv_sec + tv.tv_usec*1e6);

    int pv = (rand() % (r-l)) + l;
    int pvInd = twoWayHoarePartition(data, l, r, pv);
    QuickSort1(data,l,pvInd-1);
    QuickSort1(data,pvInd+1,r);
}

void QuickSort2(Person* data, int l, int r){
    if(l>=r) return;
    int pv = 0;
    int mid = (l+r)/2;
    if(((data[l].height <= data[mid].height) && (data[mid].height <= data[r].height)) || ((data[r].height <= data[mid].height) && (data[mid].height <= data[l].height))) pv = mid;
    else if(((data[mid].height <= data[l].height) && (data[l].height <= data[r].height)) || ((data[r].height <= data[l].height) && (data[l].height <= data[mid].height))) pv = l;
    else pv = r;

    int pvInd = lomutoPartition(data, l, r, pv);
    QuickSort2(data,l,pvInd-1);
    QuickSort2(data,pvInd+1,r);
}

void QuickSort3(Person* data, int l, int r){
    if(l>=r) return;
    
    int pv = mediansOfMedians(data, l, r);
    int pvInd = twoWayHoarePartition(data, l, r, pv);
    QuickSort3(data,l,pvInd-1);
    QuickSort3(data,pvInd+1,r);
}

void QuickSort4(Person* data, int l, int r){
    if(r-l+1 < 10){
        insertionSort(data,l,r);
        return;
    }
    
    int pv = recursiveQuickSelect(data,l,r,((r-l)/2) + 1);
    //int pv = r;
    int pvInd = threeWayHoarePartition(data, l, r, pv);
    QuickSort4(data,l,pvInd-1);
    QuickSort4(data,pvInd+1,r);
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
    Person* data4 = (Person*)malloc(sizeof(Person)*size);

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
        data4[i] = itoe(ID, name, age, height, weight);
        i++;

    }

    struct timeval t1, t2;
    double time_interval;

    gettimeofday(&t1,NULL);
    QuickSort1(data1, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("Recursive QuickSort using two-way Hoare partition and random pivot selection took %f amount of time.\n", time_interval);

    gettimeofday(&t1,NULL);
    QuickSort2(data2, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("Recursive QuickSort with Lomuto Partitioning with median of three pivot took %f amount of time.\n", time_interval);

    gettimeofday(&t1,NULL);
    //QuickSort3(data3, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("Iterative Quicksort using two-way Hoare partition and iterative median of medians took %f amount of time.\n", time_interval);
    gettimeofday(&t1,NULL);
    QuickSort4(data4, 0, size-1);
    gettimeofday(&t2,NULL);

    time_interval = (t2.tv_sec - t1.tv_sec);
    time_interval += (t2.tv_usec-t1.tv_usec)*1e-6;
    
    printf("Hybrid QuickSort using three-way Hoare partitioning and recursive quickselect took %f amount of time.\n", time_interval);

}