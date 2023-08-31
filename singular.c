#include <stdio.h>
#include "singular.h"
extern int adjustedIndex;
extern int prec;
extern int *elementNumber;
extern int rowNum;
extern double **jaggedArray;
 void print(double adjustedArray[], size_t size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
            for (int j = 0; j < rowSize; j++) {
                printf("%.*f ", prec, adjustedArray[currentIndex]);
                currentIndex++;
            }
            printf("\n");
        } else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < size; k++) {
                    printf("%.*f ", prec, adjustedArray[currentIndex]);
                    currentIndex++;
                }
                printf("\n");
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    printf("%.*f ", prec, adjustedArray[currentIndex]);
                    currentIndex++;
                }
                printf("\n");
            }
        }
    }
}
size_t filter(double arr[],size_t count,enum filter_type t,double threshold){
    if(t==EQ){
       int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (count == 0) {
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]==threshold){
                    printf("%.*f ", prec,jaggedArray[i][j]);
                }
            }
            printf("\n");
        }else {
            int numChunks = rowSize / count;
            int remainingElements = rowSize % count;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < count; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement==threshold) {
                       printf("%.*f ", prec, currentElement);
                    }
                }
            printf("\n");
            
                currentIndex += count;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement==threshold) {
                        printf("%.*f ", prec, currentElement);
                    }
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
    }else if(t==NEQ){
         int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];
        if (count == 0) {
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]!=threshold){
                    printf("%.*f ", prec,jaggedArray[i][j]);
                }
            }
            printf("\n");
        }else {
            int numChunks = rowSize / count;
            int remainingElements = rowSize % count;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < count; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement!=threshold) {
                       printf("%.*f ", prec, currentElement);
                    }
                }
            printf("\n");
            
                currentIndex += count;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement!=threshold) {
                        printf("%.*f ", prec, currentElement);
                    }
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
    }else if(t==LEQ){
       int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];
        if (count == 0) {
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]<=threshold){
                    printf("%.*f ", prec,jaggedArray[i][j]);
                }
            }
            printf("\n");
        }else {
            int numChunks = rowSize / count;
            int remainingElements = rowSize % count;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < count; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement<=threshold) {
                       printf("%.*f ", prec, currentElement);
                    }
                }
            printf("\n");
            
                currentIndex += count;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement<=threshold) {
                        printf("%.*f ", prec, currentElement);
                    }
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
    }else if(t==GEQ){
       int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];
        if (count == 0) {
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]>=threshold){
                    printf("%.*f ", prec,jaggedArray[i][j]);
                }
            }
            printf("\n");
        }else {
            int numChunks = rowSize / count;
            int remainingElements = rowSize % count;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < count; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement>=threshold) {
                       printf("%.*f ", prec, currentElement);
                    }
                }
            printf("\n");
            
                currentIndex += count;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement>=threshold) {
                        printf("%.*f ", prec, currentElement);
                    }
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
    }else if(t==LESS){
        int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];
        if (count == 0) {
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]<threshold){
                    printf("%.*f ", prec,jaggedArray[i][j]);
                }
            }
            printf("\n");
        }else {
            int numChunks = rowSize / count;
            int remainingElements = rowSize % count;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < count; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement<threshold) {
                       printf("%.*f ", prec, currentElement);
                    }
                }
            printf("\n");
            
                currentIndex += count;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement<threshold) {
                        printf("%.*f ", prec, currentElement);
                    }
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
    }else if(t==GREATER){
       int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];
        if (count == 0) {
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]>threshold){
                    printf("%.*f ", prec,jaggedArray[i][j]);
                }
            }
            printf("\n");
        }else {
            int numChunks = rowSize / count;
            int remainingElements = rowSize % count;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < count; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement>threshold) {
                       printf("%.*f ", prec, currentElement);
                    }
                }
            printf("\n");
            
                currentIndex += count;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                    if (currentElement>threshold) {
                        printf("%.*f ", prec, currentElement);
                    }
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
}
}

void shift(double arr[],size_t size,double by){
        int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];
        if (size == 0) {
            for(int j=0;j<elementNumber[i];j++){
                jaggedArray[i][j]+=by;
                 printf("%.*f ",prec,jaggedArray[i][j]);
            }
            printf("\n");
        }else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                for (int k = 0; k < size; k++) {
                    double currentElement = arr[currentIndex + k];
                    currentElement+=by;
                     printf("%.*f ",prec,currentElement);
                }
            printf("\n");
            
                currentIndex += size;
            }

            if (remainingElements > 0) {
                for (int k = 0; k < remainingElements; k++) {
                    double currentElement = arr[currentIndex + k];
                   currentElement+=by;
                   printf("%.*f ",prec,currentElement);
                }
                printf("\n");
                currentIndex += remainingElements;
            }
        }
    }
}