#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a, b;
  printf("Intger number : ");
  scanf("%d%d", &a, &b);

  if ((a > 0))
  {
	if ((a % 2) == 0)
	{
	  printf("%d = even number\n", a);
	}
	else
	{
	  printf("%d = odd number\n", a);
	}
  }
  else
  {
	printf("The value entered is 0\n");
  }

   if ((b > 0))
  {
	if ((b % 2) == 0)
	{
	  printf("%d = even number\n", b);
	}
	else
	{
	  printf("%d = odd number\n", b);
	}
  }
  else
  {
	printf("The value entered is 0\n");
  }

  return 0;
}