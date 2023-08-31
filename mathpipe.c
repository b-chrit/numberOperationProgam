#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aggregate.h"
#include "singular.h"
#define INITIAL_CAPACITY 256
int prec;
int rowNum;
int *elementNumber;
double **jaggedArray;
int adjustedIndex = 0;
double *adjustedArray;
int main(int argc, char *argv[]) {
    double num;
    rowNum = 0;
    elementNumber = (int *)malloc(sizeof(int) * INITIAL_CAPACITY);
    jaggedArray = (double **)malloc(sizeof(double *) * INITIAL_CAPACITY);

    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        elementNumber[i] = 0;
        jaggedArray[i] = (double *)malloc(sizeof(double) * INITIAL_CAPACITY);
    }

    while (scanf("%lf", &num) == 1) {
        jaggedArray[rowNum][elementNumber[rowNum]] = num;
        elementNumber[rowNum]++;

        if (getchar() == '\n') {
            rowNum++;
        }
    }
    adjustedArray = (double *)malloc(sizeof(double) * INITIAL_CAPACITY);
    adjustedIndex = 0;
    for (int i = 0; i <elementNumber[i]; i++) {
        for (int j = 0; j < elementNumber[i]; j++) {
            adjustedArray[adjustedIndex++] = jaggedArray[i][j];
             if (adjustedIndex >= INITIAL_CAPACITY) {
                adjustedIndex =INITIAL_CAPACITY*2 ;
                adjustedArray = (double *)realloc(adjustedArray, sizeof(double) * adjustedIndex);
            }
        }
    }
    // for(int i=0;i<rowNum;i++){
    //     printf("%d ",elementNumber[i]);

    adjustedArray = (double *)realloc(adjustedArray, sizeof(double) * adjustedIndex);
   if (argc == 1) {
        fprintf(stderr,"You need at least one mandatory command line argument representing the name of the function,valid functions are [max,min,cout,avg,pavg,sum] and [print,shift,filter].\n");
        return 1;
    }

    char func[20] = "";
    prec = -1;
    int size = 0;
    double threshold;
    enum filter_type filterType;
    double by;
    for (int i = 1; i < argc; i++) {
        if (strcasecmp(argv[i], "sum") == 0 ||
            strcasecmp(argv[i], "min") == 0 ||
            strcasecmp(argv[i], "max") == 0 ||
            strcasecmp(argv[i], "count") == 0 ||
            strcasecmp(argv[i], "avg") == 0 ||
            strcasecmp(argv[i], "pavg") == 0 || 
            strcasecmp(argv[i],"print")==0) {
            strcpy(func, argv[i]);
        }else if(strcasecmp(argv[i],"filter")==0){
            if((strcasecmp(argv[i+1],"EQ")==0)&&sscanf(argv[i+2],"%f",&threshold)==1){
                strcpy(func,argv[i]);
                filterType=EQ;
                threshold=strtod(argv[i+2],NULL);
            }else if((strcasecmp(argv[i+1],"NEQ")==0)&&sscanf(argv[i+2],"%f",&threshold)==1){
                strcpy(func,argv[i]);
                filterType=NEQ;
                threshold=strtod(argv[i+2],NULL);
            }else if((strcasecmp(argv[i+1],"LEQ")==0)&&sscanf(argv[i+2],"%f",&threshold)==1){
                strcpy(func,argv[i]);
                filterType=LEQ;
                threshold=strtod(argv[i+2],NULL);
            }else if((strcasecmp(argv[i+1],"GEQ")==0)&&sscanf(argv[i+2],"%f",&threshold)==1){
                strcpy(func,argv[i]);
                filterType=GEQ;
                threshold=strtod(argv[i+2],NULL);
            }else if((strcasecmp(argv[i+1],"LESS")==0)&&sscanf(argv[i+2],"%f",&threshold)==1){
                 strcpy(func,argv[i]);
                filterType=LESS;
                threshold=strtod(argv[i+2],NULL);
            }else if((strcasecmp(argv[i+1],"GREATER")==0)&&sscanf(argv[i+2],"%f",&threshold)==1){
                 strcpy(func,argv[i]);
                filterType=GREATER;
                threshold=strtod(argv[i+2],NULL);
            }else{
                fprintf(stderr,"the singular function filter should be followed by a valid filter type and a valid *threshold* please try again,program will terminate abnormally");
                return 1;
            }
        }else if(strcasecmp(argv[i],"shift")==0){
            strcpy(func,argv[i]);
            if(i+1<argc){
            if(sscanf(argv[i+1],"%f",&by)==1){
                by=strtod(argv[i+1],NULL);
            }else{
                fprintf(stderr,"the singular function shift should be followed by a valid *by* please try again,program will terminate abnormally");
                return 1;
            }
            }else{
                fprintf(stderr,"the singular function shift should be followed by a valid *by* please try again,program will terminate abnormally");
                return 1;
            }
        }
        else if (strncasecmp(argv[i], "-size=", 6) == 0) {
            size = atoi(argv[i] + 6);
        } else if (strncasecmp(argv[i], "-prec=", 6) == 0) {
            prec = atoi(argv[i] + 6);
        }
    }
    if (strcmp(func, "") == 0) {
        fprintf(stderr,"No valid function was passed, please try again with a valid function. valid aggregate functions are [min,max,count.avg,pavg,sum] and valid singular functions are [print,shift,filter] program will terminate abnormally");
        return 1;
    }
    if(size<0 || prec<-1){
        if(size<0){
            fprintf(stderr,"Invalid size,size can't be negative,program will terminate abnormally");
            return 1;
        }else{
            fprintf(stderr,"Invalid precision,precision can't be negative,program will terminate abnormally");
            return 1;
        }
    }
    printf("Function: %s\n", func);
    printf("Size: %d\n", size);
    printf("Precision: %d\n", prec);
    // for(int i=0;i<adjustedIndex;i++){
    //     printf("%f ",adjustedArray[i]);
    // }
    //   printf("\n");
    if(size!=0){
    adjustedIndex=adjustedIndex/size;
    }
    if(strcasecmp(func, "sum") == 0 ||
        strcasecmp(func, "min") == 0 ||
        strcasecmp(func, "max") == 0 ||
        strcasecmp(func, "count") == 0 ||
        strcasecmp(func, "avg") == 0 ||
        strcasecmp(func, "pavg") == 0 ){
        aggregate(func,adjustedArray,size);
    }else if(strcasecmp(func,"print")==0){
        print(adjustedArray,size);
    }else if(strcasecmp(func,"filter")==0){
      filter(adjustedArray,size,filterType,threshold);
    }else if(strcasecmp(func,"shift")==0){
        shift(adjustedArray,size,by);
    }
    printf("\n");
    free(adjustedArray);

    // Clean up dynamically allocated memory
    for (int i = 0; i < INITIAL_CAPACITY; i++) {
        free(jaggedArray[i]);
    }
    free(jaggedArray);
    free(elementNumber);

    return 0;
}

