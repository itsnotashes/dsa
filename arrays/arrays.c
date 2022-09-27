#include<stdio.h>

void main(){
    // One way to declare static arrays in c. 
    int randNums[5] = {1, 2, 3, 4, 5};
    printf("%d\n", randNums[1]);

    int justANum = 5;
    int *ptrNum, justAnotherNum;

    ptrNum = &justANum;

    printf("Location of justANum is: %d\n", ptrNum);

    // A cooler way to make arrays in c. 
    int *array_num;

    array_num = (int *)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("Locaition of no. %d element in array_num: %d\n", i+1, &array_num[i]);
    }
}