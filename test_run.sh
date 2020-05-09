#! /bin/bash
rm -rf *.o
if [[ ! -d bin ]]; then
mkdir bin
fi
gcc -c array_void.c test/test_array_void.c
gcc -o bin/out *.o
rm -rf *.o
./bin/out
rm -rf bin/