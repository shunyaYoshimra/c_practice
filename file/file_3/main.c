#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *file;
  int c;
  file = fopen("./sample.txt", "r");
  if (file == NULL)
  {
    printf("ファイルが開けません\n");
    exit(1);
  }
  while ((c = fgetc(file)) != EOF)
  {
    printf("%c", (char)c);
  }
  fclose(file);
}