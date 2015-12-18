/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

int main ()
{
    int local1 = 5;
    int local2 = 6;
    int size1 = 9;
    int size2 = 9;
    void *p = malloc(128);
    void *r = malloc(128);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local1 is %p\n", &local1);
    printf ("Address of local2 is %p\n", &local2);
    printf ("Address of p is %p\n", p);
    printf ("Address of r is %p\n", r);
    printf ("Address of size1 is %p\n", &size1);
    printf ("Address of size2 is %p\n", &size2);
    
    return 0;
}
