gcc --version >gcc.verion.txt

gcc -E ../preprocess_only.c

gcc -E ../preprocess_only.c -Wall  >stdout.txt
gcc -E ../preprocess_only.c -Wall -o output.txt
gcc -save-temps ../preprocess_only.c -Wall
