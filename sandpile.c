#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  //grid elements- x axis, y axis, height
  int x,y,h;
  //incrementors
  int p, q, i, k, j;
  //pointer for the values to go inside the initial grid
  char* s;
  /**place will start iterations through cmdline arguments at place 1(right after the name)
     as long as there is no --fps tag(see line 15)*/
  int place = 1;
  //custom size of grid for testing smaller grids
  int gridSize = 5;
  char grid[gridSize][gridSize];
  
  int fps = 1;
  //initialize the grid
  for(int p = 0; p < 5; p++){
    for(int q = 0; q < 5; q++){
      grid[p][q] = '0';
    }
  }

  /**if there are more than 2 arguments passed(besides the name) && the first arg after
     the name is the --fps tag, then set place to after the fps value*/
  if(argv[1] == "--fps"){
    place = 3;
    fps = atoi(argv[2]);
  }

   for(int i = place; i < argc; i+=3){
     
     x = atoi(argv[i]);
     y = atoi(argv[i+1]);
     h = atoi(argv[i+2]);
     s = argv[i+2];
     
    if(h<0){
      grid[x][y] = '#';
    }else{
      grid[x][y] = *s;
    }
    }

 
  for(int k = 0; k < 5; k++){
    for(int j = 0; j < 5; j++){
      printf("%c", grid[k][j]);
    }
    printf("\n");
    }

  return 0;

  
}
