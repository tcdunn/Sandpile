#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int grid[23][23];

void printGrid();

void addNeighbors(int x, int y);

void addSand(int x, int y);

int main(int argc, char *argv[]){
  //grid elements- x axis, y axis, height
  int x,y,h;

  //variables used to pass in as parameters for add sand
  //starts at the center for all non-recursive calls
  int ux = 11, uy = 11;
  
  //incrementors
  int p, q, i, k, j;

  /**place will start iterations through cmdline arguments at place 1(right after the name)
     as long as there is no --fps tag(see line 15)*/
  int place = 1;
  //custom size of grid for testing smaller grids
  
  
  int fps = 30;
  
  //initialize the grid
  for(int p = 0; p < 23; p++){
    for(int q = 0; q < 23; q++){
      grid[p][q] = 0;
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
     
    if(h<0 && x != 11 && y != 11){
      grid[x][y] = -1;
    }else{
      grid[x][y] = h;
    }
  }
  int z = 0;
   while(1){
    /*
      1. print grid
      2. add sand
      3. repeat
     */
     printGrid();
     addSand(ux, uy);
     z++;
  }
  return 0;
}

void addSand(int x, int y){
    grid[x][y]++;
    if(grid[x][y] > 8){
	grid[x][y] = 0;
	addNeighbors(x, y);
    }
  }

  void addNeighbors(int x, int y){
    for(int i = x - 1; i <= x + 1; i++){
      for(int j = y - 1; j <= y + 1; j++){
	if(i < 23  && i >= 0 && j < 23 && j >= 0 && grid[i][j] != -1){
	  grid[i][j] = grid[i][j] + 1;
	  if(grid[i][j] > 8){
	    addSand(i, j);
	}
      }
    }
   }
  }

void printGrid(){
  int i, j;
  for(i = 0; i < 23; i++){
    for(j = 0; j < 23; j++){
      if(grid[i][j] < 0){
	printf("#");
      }else{
	printf("%d", grid[i][j]);
      }
    }
    printf("\n");
  }

  printf("\n");
  
}




