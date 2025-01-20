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
    if (strlen(argv[1]) > MAX_ADDRESS_LENGTH) {
        fprintf(stderr, "File path is too long!\n");
        return -2;
    }
    if (!file_exists(argv[1])) {
        fprintf(stderr, "File does not exist!\n");
        return -3;
    }
    
    char cmd[BUFSIZE] = "wc -c < ";
    strcat(cmd, argv[1]);
    system(cmd);
}