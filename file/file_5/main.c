// バイナリファイルの大きさが分からない時にmallocを使って大きさを確保する

#include <stdio.h>
#include <stdlib.h>

void main()
{
  FILE *file;
  int i, size;
  char *rdata;
  file = fopen("./test.bin", "rb");
  if (file == NULL)
  {
    printf("ファイルが開けませんでした\n");
    exit(1);
  }
  // ファイルの最後まで探す
  fseek(file, 0, SEEK_END);
  // ファイルの大きさを取得
  size = ftell(file);
  // メモリのサイズだけ、配列を動的に生成
  rdata = (char *)malloc(sizeof(char) * size);
  // 最後までポインタを戻す
  fseek(file, 0, SEEK_SET);
  fread(rdata, sizeof(char), size, file);
  fclose(file);

  for (i = 0; i < size; i++)
  {
    printf("%x", rdata[i]);
  }
  free(rdata);
}