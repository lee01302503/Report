#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define False 0
#define True 1
/* made by Prof. Lee
*/
int main(void)
{
  int n;
  printf("intger number :");
  scanf("%d", &n);
  switch (n % 3)
  {
  case False:
	printf("false!!");
	break;
  default:
	printf("True!!!");
	break;
  }

  return 0;
}