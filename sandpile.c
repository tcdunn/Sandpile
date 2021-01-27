#include <stdio.h>
int main(int argc, char *argv[]){
  int x,y,h;
  int place = 3;
  String grid[5][5];

  if(argv[1] == "--fps"){
    place = 1;
  }

  for(int i = place; i < argc; i+=3){
    sscanf(argv[i], "%d", &y);
    sscanf(argv[i+1], "%d", &x);
    sscanf(argv[i+2], "%d", &h);

    if(h<0){
      grid[x][y] = "#";
    }else{
      grid[x][y] = h;
    }
  }

  for(int k = 0; k < 23; k++){
    for(int j = 0; j < 23; j++){
      printf("%S", grid[k][j]);
    }
    printf("\n");
  }
  
}
