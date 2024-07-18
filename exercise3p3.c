#include <stdio.h>

int main() {
    //Question 2 of Exercise 3
    int numInt = 5;            // Declare an integer variable
    int *ptr = &numInt;        // Create a pointer pointing to the address of num

    printf("Size of an int BEFORE: %lu bytes\n", sizeof(*ptr));  // Size of int before

    ptr++;                  // Increment the pointer by 1

    printf("Size of an int AFTER: %lu bytes\n", sizeof(*ptr));  // Size of int after

    //Question 3 of Exercise 3
    double numDouble = 5.5;       // Declare a double variable
    double *ptrDouble = &numDouble;     // Create a pointer pointing to the address of num

    printf("Size of a double BEFORE: %lu bytes\n", sizeof(*ptrDouble)); // Size of double before

    ptrDouble++;                  // Increment the pointer by 1

    printf("Size of a double AFTER: %lu bytes\n", sizeof(*ptr)); // Size of double after

    return 0;
}
