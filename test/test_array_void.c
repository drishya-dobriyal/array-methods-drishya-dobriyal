#include <stdio.h>
#include <assert.h>
#include "../array_void.h"

void test_map_void() {
  printf("Testing map\n");
  MapperVoid mapper[] = { &increment_void, &to_lower_case};
  printf("Should increment the given list \n");
  ArrayVoid_ptr src = create_void_array(5);
  for( int i = 0; i < src->length; i++)
    src->array[i] = assign_int(i );
  ArrayVoid_ptr result = map_void( src, mapper[0]);
  assert(result->length == 5);
  assert(*( int *)result->array[0] == 1);
  assert(*( int *)result->array[1] == 2);
  assert(*( int *)result->array[2] == 3);
  assert(*( int *)result->array[3] == 4);
  assert(*( int *)result->array[4] == 5);
  
  printf("Should map to lower case\n");
  src = create_void_array(3);
  src->array[0] = assign_char('A');
  src->array[1] = assign_char('B');
  src->array[2] = assign_char('c');
  result = map_void(src, mapper[1]);
  assert(*( char *)result->array[0] == 'a');
  assert(*( char *)result->array[1] == 'b');
  assert(*( char *)result->array[2] == 'c');
  printf("Test passed\n\n");
}

void test_filter_void( void ){
  printf("Testing filter\n");
  PredicateVoid predicate[] = { &is_even_void, &is_vowel };
  
  printf("Should filter even number from list\n");
  ArrayVoid_ptr src = create_void_array(5);
  for( int i = 0; i < src->length; i++)
    src->array[i] = assign_int(i);
  ArrayVoid_ptr result = filter_void( src, predicate[0]);
  assert(result->length == 3);
  assert(*( int *)result->array[0] == 0);
  assert(*( int *)result->array[1] == 2);
  assert(*( int *)result->array[2] == 4);

  printf("should filter vowels in list\n");
  src = create_void_array(3);
  src->array[0] = assign_char('A');
  src->array[1] = assign_char('B');
  src->array[2] = assign_char('c');
  result = filter_void(src, predicate[1]);
  assert(result->length == 1);
  assert(*( int *)result->array[0] == 'A');

  printf("Test passed\n\n");
}

void test_reduce_void( void ){
  printf("Testing filter\n");
  printf("Should return sum of the list");
  ReducerVoid reducer[] = { &sum_void };
  ArrayVoid_ptr src = create_void_array(5);
  for( int i = 0; i < src->length; i++)
    src->array[i] = assign_int(i);
  Object init = assign_int(0); 
  Object total = reduce_void( src, init, reducer[0]);
  assert(*( int *)total == 10);
  printf("Test passed\n\n");
}

int main(void) {
  test_map_void();
  test_filter_void();
  test_reduce_void();
  return 0;
}