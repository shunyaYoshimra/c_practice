#include <stdio.h>

typedef struct
{
  int a;
  double d;
} num_data;

void dealData1(num_data data);
void dealData2(num_data *pData);

void main()
{
  num_data n1 = {1, 1.2}, n2 = {1, 1.2};
  printf("n1のアドレス:0x%x n2のアドレス:0x%x\n", (unsigned int)&n1, (unsigned int)&n2);
  dealData1(n1);
  dealData2(&n2);
  printf("n1.a = %d n1.d = %f\n", n1.a, n1.d);
  printf("n2.a = %d n2.d = %f\n", n2.a, n2.d);
}

void dealData1(num_data data)
{
  printf("a=%d d=%f\n", data.a, data.d);
  printf("dealData1に渡ってきたデータのアドレス0x%x\n", (unsigned int)&data);
  data.a = 2;
  data.d = 2.4;
}

void dealData2(num_data *pData)
{
  printf("a=%d d=%f\n", pData->a, pData->d);
  printf("dealData1に渡ってきたデータのアドレス0x%x\n", (unsigned int)&pData);
  pData->a = 2;
  pData->d = 2.4;
}
