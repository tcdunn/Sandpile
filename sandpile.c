#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
  int x,y,h;
  int place = 3;
  int grid[5][5];

  if(argv[1] == "--fps"){
    place = 1;
  }

  //fellas

  for(int i = place; i < argc; i+=3){
    sscanf(argv[i], "%d", &y);
    sscanf(argv[i+1], "%d", &x);
    sscanf(argv[i+2], "%d", &h);

    if(h<0){
      grid[x][y] = 4;
    }else{
      grid[x][y] = h;
    }
  }

  for(int k = 0; k < 5; k++){
    for(int j = 0; j < 5; j++){
      printf("%d", grid[k][j]);
    }
    printf("\n");
  }

  return 0;
  
}


