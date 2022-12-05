#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "encrypt.h"
#include "decrypt.h"


int main(int argc, char** argv) {

    if(argc < 5) {
        printf("\nArguments expected\n");
        return EXIT_FAILURE;
    }
    else if(argc > 5) {
        printf("\nToo many arguments supplied\n");
        return EXIT_FAILURE;
    }

    char key[] = "AgnideeptaArkojeetBiplawBismay";

    if(!strcasecmp(argv[3], "ENCRYPT")) {
        encrypt(argv[1], argv[2], argv[4], key);
    }
    else if(!strcasecmp(argv[3], "DECRYPT")) {
        decrypt(argv[1], argv[2], argv[4], key);
    }
    else {
        printf("\nWrong Input\n");
    }

    return EXIT_SUCCESS;
}