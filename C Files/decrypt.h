#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ENCRYPT
    #include "readFile.h"
    #include "writeFile.h"
    #include "helperFunction.h"
#endif

#define DECRYPT 1

int* arrayConversion(int* matrix, long dimension, long* sizeOfArray) {
    
    int flag = 0;
    long posI, posJ;

    for(long i = dimension-1; i >= 0; i--) {
        for(long j = dimension-1; j >= 0; j--) {
            if(matrix[i*dimension+j] == '^') {
                flag = 1;
                posJ = j;
                break;
            }
        }
        if(flag == 1) {
            posI = i;
            break;
        }
    }

    *sizeOfArray = (posI*dimension+posJ);
    
    int* asciiArray = (int*)malloc(sizeof(int)*(*sizeOfArray));
    if(asciiArray == NULL) {
        printf("\nCouldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    for(long i = posI, j = posJ, k = *sizeOfArray; i >= 0;) {
        asciiArray[k--] = matrix[i*dimension+j];
        j--;
        if(j == -1) {
            j = dimension-1;
            i--;
        }
    }

    return asciiArray;
}

int* reApplyKey1(int* array, long sizeOfArray, char* key) {

    long lengthOfkey = strlen(key);
    
    for(long i = 0, j = 0; i < sizeOfArray; i++, j++) {
        array[i] = 256 - array[i] - key[j % lengthOfkey];
    }

    return array;
}

int* reApplyKey2(int* array, long sizeOfArray, char* key){

}

int* decryption(int* asciiArray, long *sizeOfArray, char* key, long* dimension, char* choice) {

    *dimension = calculateDimensions(*sizeOfArray);

    int *decryptedArray = xorOperation(asciiArray, *dimension, key);
    decryptedArray = transpose(decryptedArray, *dimension);
    int* array = arrayConversion(decryptedArray, *dimension, sizeOfArray);

    if(*choice == '1')
        array = reApplyKey1(array, *sizeOfArray, key);
    else if(*choice == '2')
        array = reApplyKey2(array, *sizeOfArray, key);

    free(decryptedArray);
    return array;
}

void decrypt(char* sourceFile, char* destinationFile, char* choice, char* key) {
    
    long sizeOfArray;   
    long dimension;

    int* asciiArray = readFile(sourceFile, &sizeOfArray); 
    int* decryptedArray = decryption(asciiArray, &sizeOfArray, key, &dimension, choice);    
    writeFile(decryptedArray, sizeOfArray, DECRYPT, destinationFile);

    free(asciiArray);
    free(decryptedArray);

    return;
}