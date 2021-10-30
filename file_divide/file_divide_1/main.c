#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// データベースに登録できる学生の最大数
#define MAX_STUDENT 10
// 学生の名前の最大の長さ
#define LENGTH 50
// エラーメッセージの文字列の最大の長さ
#define MESSAGE_LENGTH 256

enum ERROR
{
  MESSAGE_OK,
  MESSAGE_ERROR
};

typedef struct
{
  int id;
  char name[LENGTH];
} student;

int num = 0;
student student_database[MAX_STUDENT];
int Error;

void initDatabase();
int add(int, char *);
student *get(int);
void showStudentData(student *);
void showError();

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

void initDatabase()
{
  int i;
  for (i = 0; i < MAX_STUDENT; i++)
  {
    student_database[i].id = -1;
    strcpy(student_database[i].name, "");
  }
  Error = MESSAGE_OK;
  num = 0;
}

int add(int id, char *name)
{
  if (get(id) == NULL && num < MAX_STUDENT)
  {
    student_database[num].id = id;
    strcpy(student_database[num].name, name);
    num++;
    Error = MESSAGE_OK;
    return 1;
  }
  Error = MESSAGE_ERROR;
  return 0;
}

student *get(int id)
{
  int i;
  for (i = 0; i < num; i++)
  {
    if (student_database[i].id == id)
    {
      return &student_database[i];
    }
    return NULL;
  }
}

void showStudentData(student *data)
{
  if (data != NULL)
  {
    printf("学籍番号 : %d 名前 : %s\n", data->id, data->name);
  }
  else
  {
    printf("データが登録されていません\n");
  }
}

void showError()
{
  switch (Error)
  {
  case MESSAGE_OK:
    printf("OK\n");
    break;
  case MESSAGE_ERROR:
    printf("ERROR\n");
    break;
  }
}