#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  double* pi;
  int size = 5;
  int count = 0;
  double num;
  double sum = 0;
  int i;

  pi = (double*)calloc(size, sizeof(double));
  while (1)
  {
	printf("실수를 입력하세요(음수 입력시 종료) : ");
	scanf("%lf", &num);
	if (num < 0)break; // 음수면 종료
	if (count == size)
	{
	  size += 5;// 크기를 늘려서 재할당
	  pi = (double*)realloc(pi, size * sizeof(double));
	}
	pi[count++] = num;
  }

  for (i = 0; i < count; i++)
  {
	sum += pi[i];
  }
  printf("Total : %.2lf", sum);

  return 0;
}  