#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *file;
  int i;
  char wdata[] = {0x10, 0x1a, 0x1e, 0x1f};
  char rdata[4];
  file = fopen("./test.bin", "wb");
  if (file == NULL)
  {
    printf("ファイルが開けませんでした\n");
    exit(1);
  }
  fwrite(wdata, sizeof(char), sizeof(wdata), file);
  fclose(file);

  file = fopen("./test.bin", "rb");
  if (file == NULL)
  {
    printf("ファイルが開けませんでした\n");
    exit(1);
  }
  fread(rdata, sizeof(char), sizeof(rdata), file);
  fclose(file);

  for (i = 0; i < sizeof(rdata); i++)
  {
    printf("%x", rdata[i]);
  }
  printf("\n");
}