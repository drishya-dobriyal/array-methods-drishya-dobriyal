#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array_ptr create_array(int length){
  Array_ptr new_array = malloc(sizeof(Array));
  new_array->length = length;
  new_array->array = malloc(sizeof(int) * length);
  return new_array;
}

void display( Array_ptr numbers) {
  for (int i = 0; i < numbers->length; i++)
    printf("%d\n",numbers->array[i]);
}

int increment( int number){
  return number + 1;
}

Array_ptr map(Array_ptr src, Mapper mapper) {
  Array_ptr result = create_array(src->length);
  for (int i = 0; i < src->length; i++)
    result->array[i] = (*mapper)(src->array[i]);
  return result;
}

Bool is_even( int number) {
  return number % 2 == 0;
}

Array_ptr filter( Array_ptr src, Predicate predicate ){
  int temp[src->length];
  int count = 0;
  for(int i = 0; i < src->length; i++){
    Bool is_valid = (*predicate)(src->array[i]);
    if( is_valid ) {
      temp[count] = src->array[i];
      count++;
    } 
  }
  Array_ptr result = create_array(count);
  for(int i = 0; i < count; i++){
    result->array[i] = temp[i];
  }
  return result;
}