#include<stdlib.h>
#include<stdio.h>
//print function only to print the sudoko board
int **saver;

void print(int arr[9][9]) {
  int i;
  int j;
  int number = 0;
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      number = arr[i][j];
      printf("%d\t", number);
    }
    printf("\n");
  }
}
int checks(int sboard[9][9]) {
  int i, j, x, y, number, a, b;
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      number = sboard[i][j];
      //takes care of rows
        for(a = 0; a < 9; a++) {
          if(a == i) {
            //this is the position of num
          } else {
            if(sboard[a][j] == 0) {

            } else {
              if(sboard[a][j] == number) {
                return 1;
              }
            }
          }
        }
      //takes care of cols
        for(b = 0; b < 9; b++) {
          if(b == j) {
            //this is the position of num
          } else {
            if(sboard[i][b] == 0) {

            } else {
              if(sboard[i][b] == number) {
                return 1;
              }
            }
          }
        }
    //takes care of subgrids (???)
      if(i >= 0 && i <=2) {
        if(j >= 0 && j <=2) {
          for(x = 0; x <= 2; x++) {
            for(y = 0; y <= 2; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }

        } else if( j >= 3 && j <= 5) {
          for(x = 0; x <= 2; x++) {
            for(y = 3; y <= 5; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        } else if(j >= 6 && j <= 8) {
          for(x = 0; x <= 2; x++) {
            for(y = 6; y <= 8; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        }
        //end of 0 < i < 2
      } else if(i >=3 && i <= 5) {
        if( j >= 0 && j <=2) {
          for(x = 3; x <= 5; x++) {
            for(y = 0; y <=2; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }

        } else if( j >= 3 && j <= 5) {
          for(x = 3; x <= 5; x++) {
            for(y = 3; y <= 5; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        } else if(j >= 6 && j <= 8) {
          for(x = 3; x <= 5; x++) {
            for(y = 6; y <= 8; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        }
      } else if(i >= 6 && i <= 8) {
        if( j >= 0 && j <=2) {
          for(x = 6; x <= 8; x++) {
            for(y = 0; y <= 2; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        } else if( j >= 3 && j <= 5) {
          for(x = 6; x <= 8; x++) {
            for(y = 3; y <= 5; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        } else if(j >= 6 && j <= 8) {
          for(x = 6; x <= 8; x++) {
            for(y = 6; y <= 8; y++) {
              if(x == i && y == j) {

              } else {
                if(sboard[x][y] == 0) {

                } else {
                  if(sboard[x][y] == number) {
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
    }
}
return 2;
}

int recursive(int sboard[9][9]) {
int i, a, b, h, l;
char wyd = 'f';
//int count = 0;
for(a = 0; a < 9; a++) {
  for(b = 0; b < 9; b++) {
    if(sboard[a][b] == 0) {
      wyd = 't';
      break;
    }
  }
  if(wyd == 't') {
    break;
  }
}
//this finds the first number in the grid that is still a 0
if(wyd == 'f') {
    //print(sboard);
    for(h = 0; h < 9; h++) {
      for(l = 0; l < 9; l++) {
        saver[h][l] = sboard[h][l];
      }
    }

    return 0;
}
//printf("%d\n", i);
//fill the values in
for(i = 0; i < 9; i++) {
  sboard[a][b] = (i + 1);
  if((checks(sboard) == 2) && (recursive(sboard) == 1)) {
    return 1;
  }
}

//if this condition isn't true then reset the value:
sboard[a][b] = 0;

return 9;

}

  int main(int argc, char** argv) {
    //create the sudoko board
    int i;
    int j;
    int count;
    count = 0;
    int sboard[9][9];
    saver = (int**) malloc(9 * sizeof(int*));
    for(i = 0; i < 9; i ++) {
      saver[i] = (int*) malloc(9 * sizeof(int));
    }
    // int number; //this is for the numbers being read in from the board
    char c = 'n';
    FILE* theFile;
    theFile = fopen(argv[1], "r");

    if (argc < 2) {
  		printf("error\n");
  		return 0;
  	}
    //number = 0;
    for(i = 0; i < 9; i++) {
      for(j = 0; j < 9; j++) {
        
        fscanf(theFile, "%c ", &c);
          if(c == '-') {
              sboard[i][j] = 0;
             
          } else {
              sboard[i][j] = c - '0';
        }

      }
    }
  //initialize saver
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      saver[i][j] = 0;
    }
  }
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      if(sboard[i][j] == 0) {
        count++;
      }
    }
  }
  if(count == 81) {
    printf("error\n");
    return 0;
  }
  recursive(sboard);
//print(sboard);
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      if(saver[i][j] == 0) {
        printf("no-solution\n");
        free(saver);
        return 0;
      }
    }
  }
  for(i = 0; i < 9; i++) {
    for(j = 0; j < 9; j++) {
      printf("%d\t", saver[i][j]);
    }
    printf("\n");
  }

return 0;
}
