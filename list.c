#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  l->current = NULL;
  return l;
}

void * firstList(List * list) {
  list->current = list->head;
  if(list->head == NULL) return NULL;
  void* data = list->head->data;
  return data;
}

void * nextList(List * list) {
  if ((list->current == NULL) || (list->current->next == NULL))return NULL;
  list->current=list->current->next;
  return list->current->data;
  
}

void * lastList(List * list) {
    return NULL;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
  Node* x = createNode(data);
  x->next = list->head;
  if (list->head != NULL) list->head->prev = x;
  if(list->head == NULL) list->tail = x;
  list->head = x;
  x->prev = NULL;
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}