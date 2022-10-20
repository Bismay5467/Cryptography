#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ENCRYPT 0
#define DECRYPT 1

int* inputContent(char* fileName, long* fileSize) {
    FILE *filePtr = fopen(fileName, "r");
    
    if(filePtr == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return NULL;
    }

    fseek(filePtr, 0, SEEK_END);
    long size = ftell(filePtr);
    *fileSize = size;
    rewind(filePtr);

    int* asciiArray = (int*)malloc(sizeof(int)*size);
    if(asciiArray == NULL) {
        fprintf(stderr, "Couldn't allocate memory for ascii array");
        *fileSize = 0;
        return NULL;
    }

    long i = 0;

    while(!feof(filePtr)) {
        
        if(ferror(filePtr)) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            *fileSize = 0;
            return NULL;
        }

        asciiArray[i++] = fgetc(filePtr);
    }

    fclose(filePtr);

    return asciiArray;
}
void displayContent(int* contentArray, long* sizeOfArray, int mode) {

    FILE* filePtr;

    if(mode == ENCRYPT) {
        filePtr = fopen("encrypt.txt", "w");
    }
    else if(mode == DECRYPT) {
        filePtr = fopen("decrypt.txt", "w");
    }

    if(filePtr == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return;
    }
    
    for(long i = 0; i < *sizeOfArray; i++) {
        if(fputc((char)contentArray[i], filePtr) != contentArray[i]) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            return;
        } 
    }

    mode == DECRYPT ? fprintf(stderr, "\nData successfully decrypted\n") : fprintf(stderr, "\nData successfully encrypted\n");

    fclose(filePtr);

    return;
}
int main(int argc, char** argv) {

    if(argc < 3) {
        printf("\nArguments expected\n");
        return EXIT_FAILURE;
    } 
    else if(argc > 3) {
        printf("\nToo many arguments supplied\n");
        return EXIT_FAILURE;
    }

    int *array, *encryptedArray;
    long sizeOfArray;
    char key[] = "AgnideeptaArkajeetBiplawBismay";
    
    array = inputContent(argv[1], &sizeOfArray);

    if(!strcasecmp(argv[2], "ENCRYPT")) {
        displayContent(array, &sizeOfArray, ENCRYPT);
    }
    else if(!strcasecmp(argv[2], "DECRYPT")) {
        displayContent(array, &sizeOfArray, DECRYPT);
    }
    else {
        printf("\nWrong Input\n");
    }    

    free(array);
    free(encryptedArray);

    return EXIT_SUCCESS;
}