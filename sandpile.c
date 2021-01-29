#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
  
  //grid elements- x axis, y axis, height
  int x,y,h;
  //incrementors
  int i, j, k, l, m, n;
  //fps variable
  int fps;
  /**place will start iterations through cmdline arguments at place 1(right after the name)
     as long as there is no --fps tag(see line 15)*/
  int place = 1;
  //custom size of grid for testing smaller grids
  int gridSize = 5;
  int grid[gridSize][gridSize];

  //initialize grid
  for(l = 0; l < gridSize; l++){
    for(m = 0; m < gridSize; m++){
      grid[i][j] = 0;
    }
  }

  /**if there are more than 2 arguments passed(besides the name) && the first arg after
     the name is the --fps tag, then set place to after the fps value*/
  if(argc > 2 && strcmp(argv[1], "--fps")){
    place = 3;
    fps = atoi(argv[2]);
  }

  //somewhere in this for loop lies our segmentation fault(s)...
  for(int i = place; i < argc; i+=3){
    //sscanf(argv[i], "%d", &y);
    //sscanf(argv[i+1], "%d", &x);
    //sscanf(argv[i+2], "%d", &h);
    y = atoi(&argv[i]);
    x = atoi(&argv[i+1]);
    h = atoi(&argv[i+2]);

    //testing line
    printf("Y: %d, X: %d, H: %d", y, x, h);

    if(h < 0 && x != 11 && y != 11){
      //below line works
      grid[x][y] = (char)grid[x][y];
      grid[x][y] = '#';
    }else{
      grid[x][y] = h;
    }
  }

  //print the grid
  for(int k = 0; k < gridSize; k++){
    for(int j = 0; j < gridSize; j++){
      printf("%d", grid[k][j]);
    }
    printf("\n");
  }

  return 0;
  
}



