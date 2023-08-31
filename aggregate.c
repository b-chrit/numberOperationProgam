#include <stdio.h>
#include "aggregate.h"
#include <string.h>
static double min(double* arr, int size);
static double max(double* arr, int size);
static double count(double* arr, int size);
static double sum(double* arr, int size);
static double avg(double* arr, int size);
static double pavg(double* arr, int size);
extern int prec;
double sumVariable;
double countVariable;
double maxVariable;
double minVariable;
extern int adjustedIndex;
extern int *elementNumber;
extern int rowNum;
extern double **jaggedArray;
double aggregate(const char* func, double* arr, int size) {
    if (strcasecmp(func, "SUM") == 0) {
        return sum(arr, size);
    } else if (strcasecmp(func, "COUNT") == 0) {
        return count(arr, size);
    } else if (strcasecmp(func, "MAX") == 0) {
        return max(arr, size);
    } else if (strcasecmp(func, "MIN") == 0) {
        return min(arr, size);
    } else if (strcasecmp(func, "AVG") == 0) {
        return avg(arr, size);
    } else if (strcasecmp(func, "PAVG") == 0) {
        return pavg(arr, size);
    } else {
        printf("No such aggregate function: %s\n", func);
        return 0.0;
    }
}
static double max(double* adjustedArray, int size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
             maxVariable = jaggedArray[i][0];
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]>maxVariable){
                    maxVariable=jaggedArray[i][j];
                }
            }
            printf("%.*f ", prec,maxVariable);
        }else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                double maxVariable = adjustedArray[currentIndex];

                for (int k = 1; k < size; k++) {
                    double currentElement = adjustedArray[currentIndex + k];
                    if (currentElement > maxVariable) {
                        maxVariable = currentElement;
                    }
                }

                printf("%.*f ", prec, maxVariable);

                currentIndex += size;
            }

            if (remainingElements > 0) {
                double maxVariable = adjustedArray[currentIndex];

                for (int k = 1; k < remainingElements; k++) {
                    double currentElement = adjustedArray[currentIndex + k];
                    if (currentElement > maxVariable) {
                        maxVariable = currentElement;
                    }
                }

                printf("%.*f ", prec, maxVariable);

                currentIndex += remainingElements;
            }
        }
    }

    printf("\n");
}
static double min(double* adjustedArray, int size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
            minVariable = jaggedArray[i][0];
            for(int j=0;j<elementNumber[i];j++){
                if(jaggedArray[i][j]<minVariable){
                    minVariable=jaggedArray[i][j];
                }
            }
            printf("%.*f ", prec,minVariable);
        }else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                double minVariable = adjustedArray[currentIndex];

                for (int k = 1; k < size; k++) {
                    double currentElement = adjustedArray[currentIndex + k];
                    if (currentElement < minVariable) {
                        minVariable = currentElement;
                    }
                }

                printf("%.*f ", prec, minVariable);

                currentIndex += size;
            }

            if (remainingElements > 0) {
                double minVariable = adjustedArray[currentIndex];

                for (int k = 1; k < remainingElements; k++) {
                    double currentElement = adjustedArray[currentIndex + k];
                    if (currentElement < minVariable) {
                        minVariable = currentElement;
                    }
                }

                printf("%.*f ", prec, minVariable);

                currentIndex += remainingElements;
            }
        }
    }

    printf("\n");
}

static double avg(double* adjustedArray, int size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
             double sum = 0;
            for (int j = 0; j < elementNumber[i]; j++) {
                sum += jaggedArray[i][j];
            }
            double avgVariable = sum / elementNumber[i];
            printf("%.*f ", prec, avgVariable);
        }else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                double sum = 0;
                for (int k = 0; k < size; k++) {
                    sum += adjustedArray[currentIndex + k];
                }
                double avgVariable = sum / size;
                printf("%.*f ", prec, avgVariable);

                currentIndex += size;
            }

            if (remainingElements > 0) {
                double sum = 0;
                for (int k = 0; k < remainingElements; k++) {
                    sum += adjustedArray[currentIndex + k];
                }
                double avgVariable = sum / remainingElements;
                printf("%.*f ", prec, avgVariable);

                currentIndex += remainingElements;
            }
        }
    }

    printf("\n");
}

static double pavg(double* adjustedArray, int size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
            double min = jaggedArray[i][0];
            double max = jaggedArray[i][0];
            for (int j = 1; j < elementNumber[i]; j++) {
                if (jaggedArray[i][j] > max) {
                    max = jaggedArray[i][j];
                }
                if (jaggedArray[i][j] < min) {
                    min = jaggedArray[i][j];
                }
            }
            double pavgVariable = (min + max) / 2;
            printf("%.*f ", prec, pavgVariable);
        }else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                double min = adjustedArray[currentIndex];
                double max = adjustedArray[currentIndex];

                for (int k = 1; k < size; k++) {
                    double currentElement = adjustedArray[currentIndex + k];
                    if (currentElement < min) {
                        min = currentElement;
                    }
                    if (currentElement > max) {
                        max = currentElement;
                    }
                }

                double pavgVariable = (min + max) / 2;
                printf("%.*f ", prec, pavgVariable);

                currentIndex += size;
            }

            if (remainingElements > 0) {
                double min = adjustedArray[currentIndex];
                double max = adjustedArray[currentIndex];

                for (int k = 1; k < remainingElements; k++) {
                    double currentElement = adjustedArray[currentIndex + k];
                    if (currentElement < min) {
                        min = currentElement;
                    }
                    if (currentElement > max) {
                        max = currentElement;
                    }
                }

                double pavgVariable = (min + max) / 2;
                printf("%.*f ", prec, pavgVariable);

                currentIndex += remainingElements;
            }
        }
    }
    
    printf("\n");
}
extern int* elementNumber;
extern int rowNum;
extern int prec;

static double sum(double* adjustedArray, int size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
            sumVariable=0;
            for(int j=0;j<elementNumber[i];j++){
                sumVariable+=jaggedArray[i][j];
            }
            printf("%.*f ", prec, sumVariable);
        } else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                double sumVariable = 0;

                for (int k = 0; k < size; k++) {
                    sumVariable += adjustedArray[currentIndex + k];
                }

                printf("%.*f ", prec, sumVariable);

                currentIndex += size;
            }

            if (remainingElements > 0) {
                double sumVariable = 0;

                for (int k = 0; k < remainingElements; k++) {
                    sumVariable += adjustedArray[currentIndex + k];
                }

                printf("%.*f ", prec, sumVariable);

                currentIndex += remainingElements;
            }
        }
    }

    printf("\n");
}

static double count(double* adjustedArray, int size) {
    int currentIndex = 0;

    for (int i = 0; i < rowNum; i++) {
        int rowSize = elementNumber[i];

        if (size == 0) {
             countVariable=0;
            for(int j=0;j<elementNumber[i];j++){
                countVariable++;
            }
            printf("%.*f ",prec,countVariable);
        }else {
            int numChunks = rowSize / size;
            int remainingElements = rowSize % size;

            for (int j = 0; j < numChunks; j++) {
                double countVariable = size;
                printf("%.*f ", prec, countVariable);

                currentIndex += size;
            }

            if (remainingElements > 0) {
                double countVariable = remainingElements;
                printf("%.*f ", prec, countVariable);

                currentIndex += remainingElements;
            }
        }
    }

    printf("\n");
}

// static double sum(double* arr, int size) {
//     sumVariable = 0;
//     for (int i = 0; i < size; i++) {
//         sumVariable += arr[i];
//     }
//     printf("\n%lf", sumVariable);
//     return sumVariable;
// }