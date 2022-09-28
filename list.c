// list/list.c
// 
// Implementation for linked list.
//
// Yoofi Williams

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

node_t *node_alloc(elem val) {
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->value = val;
  node->next = NULL;
  return node;
}

list_t *list_alloc() {
  list_t *list = (list_t*) malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

void node_free(node_t *n) {
  free(n);
}

void list_free(list_t *l) {
  node_t *prev, *curr;
  prev = l->head;
  curr = prev->next;
  if (l->head == NULL) {
    return;
  }
  else if (curr == NULL) {
    node_free(prev);
  }
  while (prev != curr) {
    node_free(prev);
    prev = curr;
    curr = curr->next;
  }
}

void list_print(list_t *l) {
  node_t *curr = l->head;

  if (l->head == NULL) {
    printf("Empty list!");
  }
  while (curr != NULL) {
    printf("%d -> ", curr->value);
    curr = curr->next;
  }
}

int list_length(list_t *l) {
  node_t *curr = l->head;
  int len = 0; 
  while (curr != NULL) {
    len++;
    curr = curr->next;
  }
  return len;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *new_node;
  new_node = node_alloc(value);

  node_t *curr = l->head;

  if (curr == NULL) {
    printf("List is empty!");
    return;
  }

  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = new_node;
  new_node->next = NULL;
  return;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new_node;
  new_node = node_alloc(value);

  if (l->head == NULL) {
    // l->head = new_node;
    // new_node->next = NULL;
    printf("List is empty!");
    return;
  }

  new_node->next = l->head;
  l->head = new_node;
  return;
}
        
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *new_node;
  new_node = node_alloc(value);

  node_t *prev = NULL;
  node_t *curr = l->head;
  int pos;
  int len = list_length(l);

  if (l->head == NULL) {
    // if (index != 0) {
    //   printf("List is empty!");
    //   return;
    // }
    // else {
    //   l->head = new_node;
    // }
    printf("List is empty!");
    return;
  }
  if ((l->head != NULL) && (index == 0)) {
    list_add_to_front(l, value);
    return;
  }

  while (pos < index) {
    prev = curr;
    curr = curr->next;
    if (curr == NULL) {
      break;
    }
    pos++;
  }

  new_node->next = curr;
  prev->next = new_node;
  return;
}

elem list_remove_from_back(list_t *l) { 
  int popped = 0;

  if (l->head == NULL) {
    return NULL;
  }
  if (l->head->next == NULL) {
    popped = l->head->value;
    node_free(l->head);
    return popped;
  }

  node_t *curr = l->head;
  while (curr->next->next != NULL) {
    curr = curr->next;
  } 

  popped = curr->next->value;
  node_free(curr->next);
  curr->next = NULL;
  return popped;
}

elem list_remove_from_front(list_t *l) { 
  node_t *curr = l->head;
  node_t *next_node;
  int popped;

  if (curr == NULL) {
    return NULL;
  }

  next_node = curr->next;
  popped = curr->value;
  node_free(curr);
  curr = NULL;
  curr = next_node;
  return popped;
  // return -1;
}

elem list_remove_at_index(list_t *l, int index) { 
  node_t *curr = l->head;
  int step = 0;
  int popped = 0;
  int list_len = list_length(l);

  if ((index > list_len) || (index < 0)) {
    return NULL;
  }
  
  while ((curr != NULL) && (step < index)) {
    curr = curr->next;
  }

  popped = curr->next->value;
  curr->next = curr->next->next;
  return popped;
  // return -1;
}

bool list_is_in(list_t *l, elem value) { 
  node_t *curr = l->head;

  while (curr != NULL){
    if (curr->value == value) {
      return true;
    }
    else {
      curr = curr->next;
    }
  }
  return false; 
}

elem list_get_elem_at(list_t *l, int index) { 
  node_t *curr = l->head;
  int list_len = list_length(l);
  int step = 0;

  if ((index >= list_len) || (index < 0) || (curr == NULL)) {
    return NULL; 
  }

  while (curr != NULL) {
    if (step == index) {
      return curr->value;
    }
    step++;
    curr = curr->next;   
  }
  return NULL;
}

int list_get_index_of(list_t *l, elem value) { 
  node_t *curr = l->head;
  int index = 0;

  if (curr == NULL) {
    return -1; 
  }
  while (curr != NULL) {
    if (curr->value != value) {
      index++;
      curr = curr->next;
    } 
    else {
      return index;
    }
  }
  return NULL;
}