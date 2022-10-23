#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "D:\PROJECT_SEM1\cryptography\C Files\encrypt.h"
#include "D:\PROJECT_SEM1\cryptography\C Files\decrypt.h"


int main(int argc, char** argv) {

    if(argc < 4) {
        printf("\nArguments expected\n");
        return EXIT_FAILURE;
    } 
    else if(argc > 4) {
        printf("\nToo many arguments supplied\n");
        return EXIT_FAILURE;
    }

    char key[] = "AgnideeptaArkajeetBiplawBismay";

    if(!strcasecmp(argv[3], "ENCRYPT")) {
        encrypt(argv[1], argv[2], key);
    }
    else if(!strcasecmp(argv[3], "DECRYPT")) {
        decrypt(argv[1], argv[2], key);
    }
    else {
        printf("\nWrong Input\n");
    } 

    return EXIT_SUCCESS;
}