#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array_void.h"

int main(void){
  Array_ptr number_list = create_array(5);
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i;
  }
  Mapper increment_address = &increment;
  Array_ptr result = map( number_list , increment_address);
  display(result);

  Predicate is_even_address = &is_even;
  result = filter( number_list , is_even_address);
  display(result);

  Reducer sum_address = &sum;
  int total = reduce(number_list, 0, sum_address);
  printf("the sum is %d\n", total);
  DisplayData displayer = &display_num;
  ArrayVoid_ptr src = create_void_array(5);
  for( int i = 0; i < src->length; i++){
    int *num = malloc(sizeof(int));
    *num = i;
    src->array[i] = num;
  }
  display_void(src, displayer);
  MapperVoid increment_address = &increment_void;
  ArrayVoid_ptr result = map_void(src, increment_address);
  printf("Increment number list \n");
  display_void(result, displayer);
  return 0;
}