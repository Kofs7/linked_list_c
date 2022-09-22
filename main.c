#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
  elem val;

  printf("Tests for linked list implementation\n");
  list_t *test_list = list_alloc();

  list_print(test_list);

  list_add_to_front(test_list, 1);
  list_add_to_front(test_list, 2);
  list_add_to_front(test_list, 3);
  list_add_to_front(test_list, 4);
  list_add_to_front(test_list, 5);

  list_print(test_list);
  printf("List length: %d\n", list_length(test_list));
  
  list_add_to_back(test_list, 6);
  list_add_to_back(test_list, 7);
  list_add_to_back(test_list, 8);
  list_add_to_back(test_list, 9);
  
  list_print(test_list);
  printf("List length: %d\n", list_length(test_list));

  list_add_at_index(test_list, 10, 2);
  list_print(test_list);
  list_add_at_index(test_list, 20, 0);
  list_print(test_list);
  list_add_at_index(test_list, 30, 9);

  int pop1, pop2, pop3;
  pop1 = list_remove_from_back(test_list);
  pop2 = list_remove_from_back(test_list);
  pop3 = list_remove_from_back(test_list);

  printf("Popped: %d\n", pop1);
  printf("Popped:  %d\n", pop2);
  printf("Popped:  %d\n", pop3);
  bool x = true, y = true, z = true;
  x = list_is_in(test_list, 7);
  y = list_is_in(test_list, 5);
  z = list_is_in(test_list, 30);

  fputs(x ? "true\n" : "false\n", stdout);
  fputs(y ? "true\n" : "false\n", stdout);
  fputs(z ? "true\n" : "false\n", stdout);

  list_print(test_list);
  printf("List length: %d\n", list_length(test_list));

  int index1, index2, index3, index4, index5;  
  index1 = list_get_elem_at(test_list, 0);
  index2 = list_get_elem_at(test_list, 9);
  index3 = list_get_elem_at(test_list, 4);
  index4 = list_get_elem_at(test_list, 20);
  index5 = list_get_elem_at(test_list, -5);

  printf("%d is at index %d\n", index1, 0);
  printf("%d is at index %d\n", index2, 9);
  printf("%d is at index %d\n", index3, 4);
  printf("%d is at index %d\n", index4, 20);
  printf("%d is at index %d\n", index5, 20);

  int value1, value2, value3, value4, value5;
  value1 = list_get_index_of(test_list, 1);
  value2 = list_get_index_of(test_list, 5);
  value3 = list_get_index_of(test_list, 9);
  value4 = list_get_index_of(test_list, 30);
  value5 = list_get_index_of(test_list, 8);
  
  printf("Index of %d: %d\n", 1, value1);
  printf("Index of %d: %d\n", 5, value2);
  printf("Index of %d: %d\n", 9, value3);
  printf("Index of %d: %d\n", 30, value4);
  printf("Index of %d: %d\n", 8, value5);

  return 0;
}
