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
