#include <stdio.h>   // to use printf, FILE, fopen, fgets, fclose, sscanf
#include <stdlib.h>  // to use malloc, free

typedef struct {                // define new struct type for storing
  char c;                       // a char and an int
  int n;
} entry_t;

typedef entry_t *row_t;         // define row type
typedef row_t *table_t;         // define table type

table_t t;

int main()
{
  int num_rows = 3;
  int num_columns = 4;
  int i, j;
 
  // create and initialize 2-D table                   
  // create rows
  t = (row_t*) malloc(sizeof(row_t) * num_rows);
  
  // create cells / colums for rows
  for (i=0; i<num_rows; i++){
    t[i]=(entry_t*) malloc(sizeof(entry_t) * num_columns);
    for (j=0; j<num_columns; j++){
      t[i][j].n = 0;
      t[i][j].c = 0;
    }
  }
  
  // Print the values of each cell in table t
  for (i=0; i<num_rows; i++){
    for (j=0; j<num_columns; j++)
      printf("(%d, %u) ", t[i][j].c, t[i][j].n);
      printf("\n");
  }
  printf("\n");
  
  // Open and store file in an array
  char filename[] = "data.txt";
  FILE *file = fopen ( filename, "r" );
  
  char row;
  char column;
  char cValue;
  char nValue;
  char conversionVal = '0';
    
  if (file != NULL) {
  char line [1000];
  while(fgets(line,sizeof line,file) != NULL) /* read a line from a file */ {
    fprintf(stdout,"%s \n",line); 

    // print tests for wanted values in each row
    printf("line[1]: %c\n", line[1]);
    row = line[1];
    printf("row: %c\n", row);
   
    printf("line[3]: %c\n", line[3]);  
    column = line[3];
    printf("column: %c\n", column);
    
    printf("line[7]: %c\n", line[7]);  
    cValue = line[7];
    printf("cValue: %c\n", cValue);  
      
    printf("line[9]: %c\n", line[9]);  
    nValue = line[9];
    printf("nValue: %c\n", nValue);
      
    i = row - conversionVal;
    j = column - conversionVal;
    
    if ((i < 0) || (j < 0))
        break;
      
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    t[i][j].c = cValue;
    t[i][j].n = nValue;
    
    printf("t[%d][%d].c: %c\n", i, j, t[i][j].c);
    printf("t[%d][%d].n: %c\n", i, j, t[i][j].n);
    printf("\n");
      
    i = 0;
    j = 0;
    } 
    fclose(file);
  }
  else {
    perror(filename); //print the error message on stderr.
  }
  printf("\n"); 

  // print updated table
  for (i=0; i<num_rows; i++){
    for (j=0; j<num_columns; j++) {
        if (t[i][j].n == 0)
            printf("(%d, %d) ", t[i][j].c, t[i][j].n);
        else
            printf("(%c, %c) ", t[i][j].c, t[i][j].n);
    }
  printf("\n");
  }
  printf("\n");
  
  // free the dynammically allocated space before terminating
  for (i=0; i<num_rows; i++){
    free(t[i]);
  }
  free(t);

  return 0;
}

