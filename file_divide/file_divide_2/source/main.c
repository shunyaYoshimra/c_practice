#include <stdio.h>
#include "../header/studentDatabase.h"
#include "../header/dataOutput.h"

void main()
{
  int i;
  char names[][LENGTH] = {"山田太郎", "太田美智子", "大山二郎", "山口さやか"};
  int ids[] = {1, 2, 2, 4};
  initDatabase();
  for (i = 0; i < 4; i++)
  {
    add(ids[i], names[i]);
    printf("登録: %d %s\n", ids[i], names[i]);
    showError();
  }
  for (i = 0; i < 3; i++)
  {
    showStudentData(get(i + 1));
  }
}