#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

int main(void){
  printf("int list\n");
  Array_ptr number_list = create_array(5);
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  printf("Incremented list\n");
  Mapper increment_address = &increment;
  Array_ptr  list  = map( number_list , increment_address);
  display( list );

  printf("Even numbers\n");
  Predicate is_even_address = &is_even;
  list = filter( number_list , is_even_address);
  display(list);

  Reducer sum_address = &sum;
  int sum = reduce(number_list, 0, sum_address);
  printf("the sum is %d\n\n", sum);

  printf("void List\n");
  DisplayData displayer[] = { &display_num, &display_char};
  MapperVoid mapper[] = { &increment_void, &to_lower_case};
  PredicateVoid predicate[] = { &is_even_void, &is_vowel };
  ReducerVoid reducer[] = { &sum_void };
  printf("char to lower case\n");
  ArrayVoid_ptr src = create_void_array(3);
  src->array[0] = assign_char('A');
  src->array[1] = assign_char('B');
  src->array[2] = assign_char('c');
  ArrayVoid_ptr result = map_void(src, mapper[1]);
  display_void( result, displayer[1]);

  printf("Increment number list \n");
  src = create_void_array(5);
  for( int i = 0; i < src->length; i++)
    src->array[i] = assign_int(i);
  result = map_void(src, mapper[0]);
  display_void(result, displayer[0]);

  printf("Sum of numbers : \n");
  Object init = assign_int(0); 
  Object total = reduce_void( src, init, reducer[0]);
  printf("->%d\n",*(int *)total);

  printf("filter even number list \n");
  result = filter_void(src, predicate[0]);
  display_void(result, displayer[0]);

  printf("vowels in list\n");
  src = create_void_array(3);
  src->array[0] = assign_char('A');
  src->array[1] = assign_char('B');
  src->array[2] = assign_char('c');
  result = filter_void(src, predicate[1]);
  display_void( result, displayer[1]);
  return 0;
}