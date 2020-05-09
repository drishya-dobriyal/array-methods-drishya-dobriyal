#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;
typedef void (*DisplayData)(Object);

void display_char( Object);
void display_num( Object num);

Object increment_void( Object number);
Object to_lower_case( Object );
Bool is_even_void( Object );
Bool is_vowel( Object );

Object assign_char( char letter);
Object assign_int( int num);

void display_void( ArrayVoid_ptr src, DisplayData displayer);
ArrayVoid_ptr create_void_array( int);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

#endif