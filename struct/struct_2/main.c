#include <stdio.h>
#include <string.h>

struct student
{
  int id;
  char name[256];
  int age;
};

typedef struct student student_data;

void main()
{
  int i;
  student_data data[] = {
      {1, "山田太郎", 18},
      {2, "佐藤善子", 19},
      {3, "太田たかし", 18},
      {4, "中田裕子", 18},
  };
  for (i = 0; i < 4; i++)
  {
    printf("学籍番号:%d 名前 %s　年齢: %d\n", data[i].id, data[i].name, data[i].age);
  }
}
