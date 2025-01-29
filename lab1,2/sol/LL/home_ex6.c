#include<stdio.h>
#include<stdlib.h>

typedef struct Node* NODE;
struct Node{
    int ele;
    NODE next;
};

typedef struct List* LIST;
struct List{
    int count;
    NODE head;
};

LIST createNewList(){
    
    LIST l = (LIST)malloc(sizeof(struct List));
    l->count = 0;
    l->head = NULL;
    return l;
     
}

NODE createNewNode(int value){

    NODE n = (NODE)malloc(sizeof(struct Node));
    n->ele = value;
    n->next = NULL;
    return n;

}

void printList(LIST l){
   
    NODE ptr = l->head;
    printf("[HEAD] -> ");
    while(ptr!=NULL){
        printf("%d -> ", ptr->ele);
        ptr = ptr->next;
    }

    printf("[NULL]\n");

    return;
}

void insertFirst(LIST l, NODE n){

    n->next = l->head;
    l->head = n;
    l->count++;
    return;

}

LIST add(LIST num1, LIST num2){
    
    LIST Num3 = createNewList();

    NODE ptr1 = num1->head;
    NODE ptr2 = num2->head;

    int sum = 0;
    int carry = 0;
    int num3_size = 0;
    if(num1->count > num2->count){
        num3_size = num1->count + 1;
    }else{
        num3_size = num2->count + 1;
    }

    int num3[num3_size];
    int i = 0;

    while(ptr1!=NULL && ptr2!=NULL){
        sum = ptr1->ele + ptr2->ele + carry;
        carry = sum /10;
        sum = sum%10;
        
        num3[i] = sum;
        i++;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while(ptr1!=NULL){
        sum = ptr1->ele + carry;
        carry = sum/10;
        sum = sum%10;
        
        num3[i] = sum;
        i++;
        ptr1 = ptr1->next;
    }

    while(ptr2!=NULL){
        sum = ptr2->ele + carry;
        carry = sum/10;
        sum = sum%10;
        
        num3[i] = sum;
        i++;
        ptr2 = ptr2->next;
    }

    for(int j = sizeof(num3)/sizeof(int)-2; j>=0; j--){
        NODE n1 = createNewNode(num3[j]);
        insertFirst(Num3, n1);
    }

    return Num3;
}

void main(){

    LIST Num1 = createNewList();
    LIST Num2 = createNewList();

    char num1[] = "7223487598457";
    char num2[] = "43884529375293875982375928375";



    //123456789012345678901234567890
    //987654321098765432109876543210

    for(int i = 0 ; i<sizeof(num1)/sizeof(char)-1; i++){
        NODE n1 = createNewNode(num1[i]-'0');
        insertFirst(Num1, n1);
    }


    for(int i = 0 ; i<sizeof(num2)/sizeof(char)-1; i++){
        NODE n2 = createNewNode(num2[i] - '0');
        insertFirst(Num2, n2);
    }

    LIST Num3 = add(Num1, Num2);

    printList(Num3);

    
   
}