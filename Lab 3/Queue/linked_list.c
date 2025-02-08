#include "linked_list.h"


LIST createNewList(){
    LIST l = (LIST)myalloc(sizeof(linked_list));
    if(l != NULL) {
        l->count = 0;
        l->head = NULL;
        l->tail = NULL;
    }

    return l;
}

NODE createNewNode(Element data){
    NODE n = (NODE)myalloc(sizeof(node));
    if(n!=NULL){
        n->next = NULL;
        n->data = data;
    }

    return n;
}

void insertNodeIntoList(NODE node, LIST list){
    NODE temp = list->head;
    list->head = node;
    node->next = temp;
    list->count++;
    if(list->count == 1) list->tail = node;
}

void removeFirstNode(LIST list){
    if(list->count == 0) return;
    NODE temp = list->head;
    list->head = temp->next;
    myfree(temp);
    temp = NULL;
    list->count--;
    if(list->count == 0) list->tail = NULL;
}

void insertNodeAtEnd(NODE node, LIST list){
    if(list->count == 0){
        insertNodeIntoList(node,list);
        return;
    }
    list->tail->next = node;
    list->tail = node;
    list->count++;
}

void destroyList(LIST list){
    NODE ptr = list->head;
    while(ptr!=NULL){
        NODE curr = ptr;
        ptr = curr->next;
        myfree(curr);
        curr = NULL;
    }

    myfree(list);
}