#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printGrid(int grid[5][5]);

void addNeighbors(int grid[5][5], int x, int y);

void addSand(int grid[5][5], int x, int y);

int main(int argc, char *argv[]){
  //grid elements- x axis, y axis, height
  int x,y,h;

  //variables used to pass in as parameters for add sand
  int ux = 11, uy = 11;
  
  //incrementors
  int p, q, i, k, j;
  


  /**place will start iterations through cmdline arguments at place 1(right after the name)
     as long as there is no --fps tag(see line 15)*/
  int place = 1;
  //custom size of grid for testing smaller grids
  int gridSize = 5;
  int grid[gridSize][gridSize];
  
  int fps = 30;
  //initialize the grid
  for(int p = 0; p < 5; p++){
    for(int q = 0; q < 5; q++){
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

  

  
 
   while(1){
    /*
      1. print grid
      2. add sand
      3. repeat
     */
     printGrid(grid);
     addSand(grid, ux, uy);
  }


  

  return 0;

  
}


 void addSand(int grid[5][5], int x, int y){
    grid[x][y]++;
    if(grid[x][y] > 8){
	grid[x][y] = 0;
	addNeighbors(grid, x, y);
    }
  }

  void addNeighbors(int grid[5][5], int x, int y){
    for(int i = x -1; i < x + 1; i++){
      for(int j = y - 1; j < y + 1; j++){
	if(i < 5 && i >= 0 && j < 5 && j >= 0){
	  grid[i][j]++;
	  if(grid[i][j] > 8){
	    addSand(grid, i, j);
	  }
	}
      }
    }
   }

void printGrid(int grid[5][5]){
  int i, j;
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
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




