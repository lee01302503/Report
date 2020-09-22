#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define divisor 0
/* made by Prof. Lee
*/
int main(void)
{
  int a, b, res;

  printf("intger number : ");
  scanf("%d%d", &a, &b);
  res = (b % a);

  switch (res)
  {
  case divisor:
	printf("%d is a factor of %d\n", a, b);
	break;
  default:
	printf("%d is not a factor of %d\n", a, b);
  }
  return 0;
}