#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef ENCRYPT
    #include "readFile.h"
    #include "writeFile.h"
    #include "helperFunction.h"
#endif

#define DECRYPT 1

#define WITHOUT_SUBSTITUTION '1'
#define SUBSTITUTION '2'

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
    
    int* asciiArray = mallocOrDie((*sizeOfArray)*(*sizeOfArray));

    for(long i = posI, j = posJ, k = *sizeOfArray; i >= 0; ) {
        asciiArray[k--] = matrix[i*dimension+j];
        j--;
        if(j == -1) {
            j = dimension-1;
            i--;
        }
    }

    return asciiArray;
}

int* reApplyKey(int* array, long sizeOfArray, char* key) {

    long lengthOfkey = strlen(key);
    
    for(long i = 0, j = 0; i < sizeOfArray; i++, j++) {
        array[i] = 256 - array[i] - key[j % lengthOfkey];
    }

    return array;
}

int* desubstitution(int* asciiArray, long sizeOfArray){
    
    long start = 0L, end = 0L;
    
    while(end < sizeOfArray){
        
        while(asciiArray[end] != ' ' && asciiArray[end] != ',' && 
              asciiArray[end] != '?' && asciiArray[end] != ';' &&
              asciiArray[end] != '/' && asciiArray[end] != '-' && 
              asciiArray[end] != '.' && asciiArray[end] != '\0' && asciiArray[end] != '!'){
            end++;
        }

        int length = end-start;
        
        while(start != end){
            
            int current = asciiArray[start] - length;
            
            if(current < 65){
                asciiArray[start] = 122+(current-64);
            }
            
            else{
                asciiArray[start] = current;
            }
            
            ++start;
            --length;
        }
        
        ++end;
        start = end;
    }
    
    return asciiArray;
}


int* decryption(int* asciiArray, long *sizeOfArray, char* key, long* dimension, char* choice) {

    if(*choice == WITHOUT_SUBSTITUTION) {

        *dimension = calculateDimensions(*sizeOfArray);

        int *decryptedArray = xorOperation(asciiArray, *dimension, key);
        
        decryptedArray = transpose(decryptedArray, *dimension);
    
        int* array = arrayConversion(decryptedArray, *dimension, sizeOfArray);

        array = reApplyKey(array, *sizeOfArray, key);

        free(decryptedArray);

        return array;
    }

    else if(*choice == SUBSTITUTION) {
        
        int* array = reApplyKey(asciiArray, *sizeOfArray, key);
        array = desubstitution(array, *sizeOfArray);
        
        return array;
    }
    else {
        printf("INVALID CHOICE !!!");
        exit(EXIT_FAILURE);
    }
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