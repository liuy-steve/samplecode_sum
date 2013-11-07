gcc -c -fno-builtin TinyHelloWorld.c
ld -static -e nomain -o TinyHelloWorld TinyHelloWorld.o
