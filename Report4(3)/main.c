#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a, r;
  int i,j;

  printf("intger number, row : ");
  scanf("%d%d", &a, &r);

  for (i = 1; i <= r; i++)
  {
	for (j = 1; j <= a; j++)
	{
	  printf("*");
	}
	printf("\n");
  }
  return 0;
}