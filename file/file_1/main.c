#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *file;
  file = fopen("./sample.txt", "w");
  if (file == NULL)
  {
    printf("ファイルが開けません\n");
    exit(1);
  }
  fprintf(file, "Hello Wolrd.\r\n");
  fprintf(file, "ABCDEF\r\n");
  fclose(file);
}