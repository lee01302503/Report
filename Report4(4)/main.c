#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a, b;
  int Sum = 0;

  printf("Sum a ~ b, please intger number a , b : ");
  scanf("%d%d", &a, &b);

  for (a; a <= b; a++)
  {
	Sum += a;
  }
  printf("%d", Sum);

  return 0;
}