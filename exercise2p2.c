#include <stdio.h>

void fool(int xval){
     int x;
     x = xval;

     printf("Address of x in fool: %p, Value of x: %d\n", (void*)&x, x);
}

void foo2(int dummy){
    int y;
    
    printf("Address of y in foo2: %p, Value of y: %d\n", (void*)&y, y);
}

int main (){
    fool(7);
    foo2(11);
    return 0;
}
