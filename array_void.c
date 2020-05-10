#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

void display_char( Object letter){
  printf("%c\n",*(char *)letter);
}

void display_num( Object num){
  printf("%d\n",*(int *)num);
}

void display_void( ArrayVoid_ptr src, DisplayData displayer){
  for (int i = 0; i < src->length; i++)
    (*displayer)( src->array[i]);
}

Object to_lower_case( Object letter ){
  char *result = malloc(sizeof(char));
  *result = tolower(*(char *)letter);
  return result;
}

Object assign_char( char letter){
  char *result = malloc(sizeof(char));
  *result = letter;
  return result;
}

Object assign_int( int num){
  char *result = malloc(sizeof(int));
  *result = num;
  return result;
}

Bool is_even_void( Object number){
  return *(int *)number % 2 == 0;
}

Bool is_vowel( Object letter ){
  char ch = tolower(*(char *)letter);
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate){
  Object temp[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if((*predicate)(src->array[i])) {
      temp[count] = malloc(sizeof(Object));
      memcpy(temp[count], src->array[i], sizeof(Object));
      count++;
    }
  }
  ArrayVoid_ptr result = create_void_array(count);
  for (int i = 0; i < count; i++)
    result->array[i] = temp[i];
  return result;
}

Object sum_void( Object number1, Object number2 ){
  int sum = *(int *)number1 + *(int *)number2;
  return assign_int(sum);
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer){
  for( int i = 0; i < src->length; i++){
    init = (*reducer)(init, src->array[i]);
  }
  return init;
}
