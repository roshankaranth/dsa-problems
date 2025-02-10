#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Element itoe (int pid, int arrival_time, int burst_time)
{
    Element e;
    e.pid = pid;
    e.arrival_time = arrival_time;
    e.burst_time = burst_time;
    return e;
}

void main(){

    Queue* q = createQueue();
    FILE* fptr = fopen("fcfs_input.txt","r");
    if(fptr == NULL) {
        printf("Error opening file!");
        exit(0);
    }

    char line[200];
    fgets(line,200,fptr);
    int count = atoi(line);
    
    while(fgets(line,200,fptr)){
        char* token = strtok(line," ");
        int pid = atoi(token);
        token = strtok(NULL," ");
        int arrival_time = atoi(token);
        token = strtok(NULL," ");
        int burst_time = atoi(token);
        
        enqueue(q,itoe(pid,arrival_time,burst_time));
    }

    int time = 0;
    while(!isEmpty(q)){
        Element* e = front(q);
        if(time < e->arrival_time){
            time = e->arrival_time;
        }
        printf("Process %d started at time %d\n", e->pid, time);
        printf("Process %d finished at time %d\n\n", e->pid,time + e->burst_time);
        time += e->burst_time;
        dequeue(q);
    }
}