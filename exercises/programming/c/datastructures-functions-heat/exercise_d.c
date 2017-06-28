#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float create_array(x,y,z){
  for(i=0;i<259;i++){
    for(j=0;j<259;j++){
      if(i == 0){
        array[i][j] = 85;

      } else if (i == 257){
        array[i][j] = 5;

      } else if (j == 0){
        array[i][j] = 20;
      
      } else if (j == 257){
        array[i][j] = 70;
      
      } else {
        array[i][j] = 0;
      }
    }
  }
}


float laplace(array){
  for(i = 1; j < 258; i++)
    for(j = 1; j < 258; j++)
      array[i][j] = (array[i-1][j] - 2*array[i
      
      
    }
  }



}




int main(void){

  struct T_field {
    int nx = 256;
    int ny = 256;
    float dx = 0.01;
    float dy = 0.01;
    float dx2 = 0.01*0.01;
    float dx2 = 0.01*0.01;
    float array[258][258];

}
