#include <stdio.h>

int main() {

printf("\nHello World!\n");

int a = 1;
int b = 2;
float  c;
float  d;
float *p;

a += b;

c = (float) a / (float) b;

d = c*c;

p = &d;

printf("Value of a is %d\n",a);
printf("Value of c us %.2f\n",c);
printf("Value of d is %.4f\n",d);
printf("Value of var pointed by p is %.2f\n",*p);
printf("Location of d in memory is %d\n",p);

}
