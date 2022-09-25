#include <stdio.h>

void main(){
    int x;
    int  *ptrX;

    x = 5;
    ptrX = &x;

    printf("The value of x is: %d\n", x);
    printf("The memory location of x is: %d\n", ptrX);

    *ptrX = 83;

    printf("The new value at location %d is: %d\n", ptrX, x);
}