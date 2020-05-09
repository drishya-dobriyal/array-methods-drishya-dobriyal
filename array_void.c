#include <stdio.h>
#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr create_void_array( int length){
  ArrayVoid_ptr list = malloc(sizeof(ArrayVoid));
  list->array = malloc(sizeof(Object) * length);
  list->length = length;
  return list;
}

Object increment_void( Object number){
  int *result = malloc(sizeof(int));
  *result = *(int *)number + 1;
  return result;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper){
  ArrayVoid_ptr result = create_void_array(src->length);
  for(int i = 0; i < src->length; i++){
    result->array[i] = (*mapper)(src->array[i]);
  }
  return result;
}

void display_num( Object num){
  printf("%d\n",*(int *)num);
}

void display_void( ArrayVoid_ptr src, DisplayData displayer){
  for (int i = 0; i < src->length; i++)
  {
   (*display_num)( src->array[i]);
  }
}