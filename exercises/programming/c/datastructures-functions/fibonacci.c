#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
   // declare array and loop variable
   int f[20];
   int i;

   // initialize necessary array elements and write the for loop

   printf("First 20 Fibonacci numbers are:\n");
   
   
   f[0] = 1;

   for (i=1; i < 21; i++) {
       

       f[i] = f[i-1]+i;
       
       printf("%d ", f[i-1]);
   }

   printf("\n"); 

   return 0;
}
