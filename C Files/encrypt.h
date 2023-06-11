#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "readFile.h"
#include "writeFile.h"
#include "helperFunction.h"

#define ENCRYPT 0
#define WITHOUT_SUBSTITUTION '1'
/* #define SUBSTITUTION '2' */

int *applyKey(int* asciiArray, long sizeOfArray, char* key){

    int lengthOfkey = strlen(key);

    for(int i = 0, j = 0; i < sizeOfArray; i++, j++) {
        asciiArray[i] = 256 - asciiArray[i] - key[j % lengthOfkey];
    }

    return asciiArray;
}

int *matrixConversion(int *encryptedArray, long sizeOfArray, long dimensions) {

    int *encryptedMatrix = mallocOrDie((dimensions)*(dimensions));

    long i = 0L,k = 0L;

    while(k < sizeOfArray) {
        *(encryptedMatrix+i) = *(encryptedArray+k);
        i++, k++;
    }

    if(i < dimensions*dimensions) {

        encryptedMatrix[i++] = '^';
    }

    while(i < dimensions*dimensions) {
        encryptedMatrix[i++] = (rand() % 93);
    }

    return encryptedMatrix;
}

/* int* substitution(int* asciiArray, long sizeOfArray){
    
    long start = 0L, end = 0L;

    while(end < sizeOfArray){

        while(asciiArray[end] != ' ' && asciiArray[end] != ',' && 
              asciiArray[end] != '?' && asciiArray[end] != ';' &&
              asciiArray[end] != '/' && asciiArray[end] != '-' && 
              asciiArray[end] != '.' && asciiArray[end] != '\0' && asciiArray[end] != '!'){
            end++;
        }

        int length = end-start;

        while(start!=end){
            
            int current = asciiArray[start] + length;
            
            if(current > 122){
                asciiArray[start] = current-122 + 64;
            }
            
            else{
                asciiArray[start] = current;
            }
            
            ++start;
            --length;
        }
        
        ++end;
        start=end;
    }

    return asciiArray;
} */

int* encryption(int* asciiArray, long sizeOfArray, char* key, long* dimension, char* choice) {

    int *encryptedArray;
    
    if(*choice == WITHOUT_SUBSTITUTION) {
        encryptedArray = applyKey(asciiArray, sizeOfArray, key);

        *dimension = calculateDimensions(sizeOfArray);

        int *encryptedMatrix = matrixConversion(encryptedArray, sizeOfArray, *dimension);

        encryptedMatrix = transpose(encryptedMatrix, *dimension);

        encryptedMatrix = xorOperation(encryptedMatrix, *dimension, key);

        *dimension = (*dimension)*(*dimension);

        return encryptedMatrix;
    }

    /* else if(*choice == SUBSTITUTION) {

        encryptedArray = substitution(asciiArray, sizeOfArray);
        
        encryptedArray = applyKey(encryptedArray, sizeOfArray, key);
        
        *dimension = sizeOfArray;

        return encryptedArray;
    } */
        
    else{
        printf("INVALID CHOICE!\n");
        exit(EXIT_FAILURE);
    }

    
}

void encrypt(char* sourceFile, char* destinationFile, char* choice,  char* key) {

    long sizeOfArray;
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray);
    printf("Executing Code...");
    int* encryptedArray = encryption(asciiArray, sizeOfArray, key, &dimension, choice);
    writeFile(encryptedArray, dimension, ENCRYPT, destinationFile);

    free(asciiArray);
    free(encryptedArray);

    return;
}