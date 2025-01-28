#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer{
    char name[20];
    int age;
    char address[30];
}person;

typedef struct hotel{
    char name[20];
    char address[30];
    int o_rooms;
    person* p;
}tgh;

void takeinfo(person* p){
    printf("\nEnter your name : " );
    scanf("%s", p->name);
    printf("Enter your address : ");
    scanf("%s", p->address);
    printf("Enter your age : ");
    scanf("%d", &p->age);
}

void assignRoom(tgh* h){
    h->p = realloc(h->p,sizeof(person) * (h->o_rooms + 1));
    h->o_rooms++;
    takeinfo(h->p + h->o_rooms - 1);
}

void assignFirstRoom(tgh* h){
    h->p = realloc(h->p, sizeof(person)*(h->o_rooms + 1));
    for(int i = h->o_rooms ; i>=1 ; i--){
        strcpy(h->p[i].name, h->p[i-1].name);
        strcpy(h->p[i].address, h->p[i-1].address);
        h->p[i].age = h->p[i-1].age;
    }
    h->o_rooms++;
    takeinfo(h->p);
}

void vacateRoom(tgh* h){

    int x ;    
    printf("\nEnter the room that need the be vacated : ");
    scanf(" %d", &x);

    if(x>=h->o_rooms){
        printf("Room unocuppied!\n");
        return;
    }
    
    for(int i = x ; i < h->o_rooms-1; i++){
        strcpy(h->p[i].name, h->p[i+1].name);
        strcpy(h->p[i].address, h->p[i+1].address);
        h->p[i].age = h->p[i+1].age;
    }

    h->p = realloc(h->p, sizeof(person)*(h->o_rooms-1));
    h->o_rooms--;
}

void displayInfo(tgh* h){

    int x ;    
    printf("\nEnter the room number : ");
    scanf(" %d", &x);

    if(x>=h->o_rooms){
        printf("Room unocuppied!\n");
        return;
    }

    printf("\nCustomers name : %s\n", h->p[x].name);
    printf("Customers address : %s\n", h->p[x].address);
    printf("Customers age : %d\n", h->p[x].age);
}


void main(){

    tgh* h = calloc(1,sizeof(tgh));

    while(1){
        char ch;
        printf("\nEnter choice : "
               "\n(a)Assign first unoccupied room"
               "\n(b)Assign Room #0"
               "\n(c)Vacate Room"
               "\n(d)Display room info"
               "\n(e)Exit menu ");

        scanf(" %c", &ch);

        switch(ch) {
            case 'a' : assignRoom(h);
                       break;
            
            case 'b' : assignFirstRoom(h);
                       break;
            
            case 'c' : vacateRoom(h);
                       break;
            
            case 'd' : displayInfo(h);
                       break;

            case 'e' : exit(0);
        }
    }

}