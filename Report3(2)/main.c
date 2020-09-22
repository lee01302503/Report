#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Sum '+'
#define Min '-'
#define Mul '*'
#define Inv '/'
#define Re '%'
/* made by Prof. Lee
*/
int main(void)
{
  int a, b, res;
  char Cal;
  printf("Calculation : ");
  scanf("%d%c%d", &a, &Cal, &b);

  switch (Cal)
  {
  case Sum:
	res = a + b;
	printf("%d%c%d = %d\n", a, Cal, b, res);
	break;
  case Min:
	res = a - b;
	printf("%d%c%d = %d\n", a, Cal, b, res);
	break;
  case Mul:
	res = a * b;
	printf("%d%c%d = %d\n", a, Cal, b, res);
  case Inv:
	res = a / b;
	printf("%d%c%d = %d", a, Cal, b, res);
	break;
  case Re:
	res = a % b;
	printf("%d%c%d = %d\n", a, Cal, b, res);
	break;
  default:
	printf("Entered it incorrectly!!");
  }

  return 0;
}