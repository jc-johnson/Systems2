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
	char *temp;
    
  printf("Size of entry_t* row_t: %lu \n", sizeof(row_t));
  printf("Size of entry_t: %lu \n", sizeof(entry_t));
  printf("Size of table_t: %lu \n", sizeof(table_t));
  printf("\n");
 	
  // creates and initializes 2-D table                   
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
  
  // Print the value in table t, row by row
  for (i=0; i<num_rows; i++){
  	for (j=0; j<num_columns; j++)
      	printf("(%d, %u) ", t[i][j].c, t[i][j].n);
  		printf("\n");
  }
  printf("\n");
  printf("Character tests: \n");
  printf("( : , %d\n",  '(' );
    

  // TODO: open file data.txt, read it line by line, and
  // update table entries;
  
  // Open and store file in an array
  char filename[] = "data.txt";
  FILE *file = fopen ( filename, "r" );
  // to point 2D array back to 0, 0 
  i = 0;
  j = 0;
	
  int c;
  
  if (file != NULL) {
  char line [1000];
    while(fgets(line,sizeof line,file) != NULL) /* read a line from a file */ {
      fprintf(stdout,"%s \n",line); 
		
      /*while ((c = fgetc(file)) != EOF) {
		printf("Character: %c\n" , c);
	  }*/
		
		
      /* // parse line
      while (*temp != (long unsigned int) NULL) {
        // checks if *temp is an ASCii int or an uppcase or lowercase letter
        if (((int) *temp >= 48 && (int) *temp <= 57) || (((int) *temp >= 65 && (int) *temp <= 90)) 
             || ((int) *temp >= 97 && (int) *temp <=122)) {
          t[i][j].c = *temp;
          // temp++; 
          // t[i][j].n = *temp; 
          i++;
        }
        temp++;
      }
      // j++; // go to next row */
    
      } 
      fclose(file);
  }
  else {
    perror(filename); //print the error message on stderr.
  }
  printf("\n"); 

  // TO DO: print updated table
  for (i=0; i<num_rows; i++){
  	for (j=0; j<num_columns; j++)
      	printf("(%d, %u) ", t[i][j].c, t[i][j].n);
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

