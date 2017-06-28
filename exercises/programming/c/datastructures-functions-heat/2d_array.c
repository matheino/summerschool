#include <stdio.h>
#include <stdlib.h>

#define NX 258
#define NY 258

int main(void)
{
    int i, j;
    // Add here the definition for array with name 'array'
    // of size NX times NY (258x258)
    double array[258][258];
  
    for (i=0; i < 258; i++){
      for (j=0; j < 258; j++){
        printf("%d %d\n",i,j);
        if (i == 0){
          array[i][j] = 85;
         
        } else if (i == 257){
          array[i][j] = 5;
          
        } else if (j == 0){
          array[i][j] = 20;
          
        } else if (j == 257){
          array[i][j] = 70;
         
        } else{
          array[i][j] = 0;
          
        }
      } 
    }
    printf("right: %f, left: %f, upper: %f, lower: %f\n",array[10][257],array[10][0],array[0][10],array[257][10]);
    return 0;
}


