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
	printf("�Ǽ��� �Է��ϼ���(���� �Է½� ����) : ");
	scanf("%lf", &num);
	if (num < 0)break; // ������ ����
	if (count == size)
	{
	  size += 5;// ũ�⸦ �÷��� ���Ҵ�
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