// The following program tries to stress test the precision of floating point numbers and how it affects computation in unexpected ways. 
// Here we can clearly see the program breaks down after a specific number of zeros, and prints the value 11 times instead of 10. 

#include <stdio.h>

int main(void){
    for (float x = 0.0; x < 0.00000000000000000010; x += 0.00000000000000000001)
        printf("Random text\n");
}


