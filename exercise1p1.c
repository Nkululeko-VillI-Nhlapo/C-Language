#include <stdio.h>

int main() {
    // Declare and initialize variables
    double myDouble = 3.14;
    int myInt = 42;
    char myChar = 'A';
    
    // Declare and initialize pointers to each variable
    double *doublePtr = &myDouble;
    int *intPtr = &myInt;
    char *charPtr = &myChar;

    // Print address, value, and size of each variable
   printf("Double - Address: %p, Value: %lf, Size: %lu bytes\n", (void*)doublePtr, *doublePtr, sizeof(double));


  printf("Int    - Address: %p, Value: %d,   Size: %lu bytes\n", (void*)intPtr, *intPtr, sizeof(int));

    printf("Char   - Address: %p, Value: %c,   Size: %lu bytes\n", (void*)charPtr, *charPtr, sizeof(char));

    return 0;

}