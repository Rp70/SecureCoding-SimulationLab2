#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>    // bool type
#include <sys/stat.h>   // stat

#define BUFSIZE 256
#define MAX_ADDRESS_LENGTH 260 // This length is for Windows, but I think that's okay with Linux too

bool file_exists (char *filename) {
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    struct stat st;
    if (stat(argv[1], &st) == 0) {
        printf("File size: %ld\n", st.st_size);

        return 0;
    }

    fprintf(stderr, "Error! File not found or inaccessible.\n");

    return -2;
}