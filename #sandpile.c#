#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  //grid elements- x axis, y axis, height
  int x,y,h;

  //variables used to pass in as parameters for add sand
  int ux = 11, uy = 11;
  
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
  
  int fps = 30;
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
     
    if(h<0 && x != 11 && y != 11){
      grid[x][y] = '#';
    }else{
      grid[x][y] = *s;
    }
  }

  //print initial grid
  for(int k = 0; k < 5; k++){
    for(int j = 0; j < 5; j++){
      printf("%c", grid[k][j]);
    }
    printf("\n");
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

 void addSand(int grid[][], int x, int y){
    grid[x][y]++;
    if(grid[x][y] > 8){
	grid[x][y] = 0;
	addNeighbors(grid, x, y);
    }
  }

  void addNeighbors(int grid[][], int x, int y){
    for(int i = x -1; i < x + 1; i++){
      for(int j = y - 1; j < y + 1; j++){
	if(i < gridSize && i >= 0 && j < gridSize && j >= 0){
	  grid[i][j]++;
	  if(grid[i][j] > 8){
	    addSand(grid, i, j);
	  }
	}
      }
    }
   }

void printGrid(int grid[][]){
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



