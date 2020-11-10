#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/

void swap(char *a,void *b, void *c);

int main(void)
{
  int age1, age2 = 0;
  double height1, height2;

  printf("첫 번째 사람의 나이 와 키 입력 : \n");
  scanf("%d%lf", &age1, &height1);
  printf("두 번째 사람의 나이 와 키 입력 : \n");
  scanf("%d%lf", &age2, &height2);

  swap("int", &age1, &age2);
  swap("double", &height1, &height2);

  printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age1, height1);
  printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", age2, height2);

  return 0;
}

void swap(char* a, void* b, void* c)
{
  int temp;
  double temp1;


  if (a == "int")
  {
	temp = *(int *)b;
	*(int*)b = *(int*)c;
	*(int*)c = temp;
  }
  if (a == "double")
  {
	temp1 = *(double *)b;
	*(double*)b = *(double*)c;
	*(double*)c = temp1;

  }
}