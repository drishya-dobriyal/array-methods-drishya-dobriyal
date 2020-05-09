#include "array.h"

int main(void){
  Array_ptr number_list = create_array(5);
  for( int i = 0; i < number_list->length; i++){
    number_list->array[i] = i * 10;
  }
  Mapper increment_address = &increment;
  Array_ptr result = map( number_list , increment_address);
  display(result);
  return 0;
}