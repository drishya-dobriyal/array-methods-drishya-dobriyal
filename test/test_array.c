#include <stdio.h>
#include <assert.h>
#include "../array.h"

void test_map() {
  printf("Testing map\n");
  printf("Should map the given list\n");
  Array_ptr number_list = create_array(5);
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  Mapper increment_address = &increment;
  Array_ptr result = map( number_list , increment_address);
  assert(result->length == 5);
  assert(result->array[0] == 1);
  assert(result->array[1] == 2);
  assert(result->array[2] == 3);
  assert(result->array[3] == 4);
  assert(result->array[4] == 5);
  printf("Should map an empty list\n");
  number_list = create_array(0);
  result = map( number_list , increment_address);
  assert(result->length == 0);
  printf("Test passed\n\n");
}

void test_filter(){
  Predicate is_even_address = &is_even;
  printf("Testing filter\n");
  printf("Should filter the given list\n");
  Array_ptr number_list = create_array(5);
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  Array_ptr result = filter( number_list , is_even_address);
  assert(result->length == 3);
  assert(result->array[0] == 0);
  assert(result->array[1] == 2);
  assert(result->array[2] == 4);
  
  printf("Should map an empty list\n");
  number_list = create_array(0);
  result = filter( number_list , is_even_address);
  assert(result->length == 0);
  printf("Test passed\n\n");
}

void test_reduce(){
  Array_ptr number_list = create_array(5);
  printf("Testing reduce\n");
  printf("Should reduce the given list\n");
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  Reducer sum_address = &sum;
  int total = reduce(number_list, 0, sum_address);
  assert(total == 10);

  printf("Should reduce the given list with initial value\n");
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  total = reduce(number_list, 100, sum_address);
  assert(total == 110);

  printf("Should give initial value for empty list\n");
  number_list = create_array(0);
  total = reduce(number_list, 0, sum_address);
  assert(total == 0);
  printf("Test passed\n\n");
}

int main(void) {
  test_map();
  test_filter();
  test_reduce();
  return 0;
}