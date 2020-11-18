#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
typedef struct

{
  int num;                  // 학번
  char name[20];            // 이름
  int kor, eng, mat;        // 3과목 점수
  int tot;                  // 총점
  double avg;               // 평균
  char grade;               // 학점
} Student;

void input(Student* pary);
void calc(Student* pary);
void sort(Student* pary);
void print(Student* pary);

int main(void)
{
  Student ary[5];           // 5명 학생의 성적
  input(ary);          // 학번, 이름, 3과목 점수 입력
  calc(ary);           // 총점, 평균, 학점 계산

  printf("# 정렬 전 데이터 : \n");
  print(ary);          // 정렬 전 출력
  sort(ary);           // 총점 순으로 내림차순 정렬
  printf("# 정렬 후 데이터 : \n");
  print(ary);          // 정렬 후 출력

  return 0;
}

void input(Student* pary)
{
  int i;

  for (i = 0; i < 5; i++)
  {
    printf("학번 : ");
    scanf("%d", &pary->num);

    printf("이름 : ");
    scanf("%s", pary->name);

    printf("국어, 영어, 수학 점수 : ");
    scanf("%d%d%d", &pary->kor, &pary->eng, &pary->mat);
    pary++;
  }
}

void calc(Student* pary)
{
  int i;
  for (i = 0; i < 5; i++)
  {
    pary->tot = pary->kor + pary->eng + pary->mat;
    pary->avg = pary->tot / 3.0;

    if (pary->avg >= 90.0) pary->grade = 'A';
    else if (pary->avg >= 80.0) pary->grade = 'B';
    else if (pary->avg >= 70.0) pary->grade = 'C';
    else pary->grade = 'F';
    pary++;
  }
}

void sort(Student* pary)
{
  Student temp;
  int i, j;
  int max;

  for (i = 0; i < 4; i++)
  {
    max = i;
    for (j = i + 1; j < 5; j++)
    {
      if (pary[max].tot < pary[j].tot)
      {
        max = j;
      }
    }

    if (max != i)
    {
      temp = pary[max];
      pary[max] = pary[i];

      pary[i] = temp;
    }
  }
}

void print(Student* pary)
{
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("%5d%7s%5d%5d%5d%5d%7.1lf%5c\n",
      pary->num, pary->name, pary->kor, pary->eng, pary->mat, pary->tot, pary->avg, pary->grade);
    pary++;
  }
}