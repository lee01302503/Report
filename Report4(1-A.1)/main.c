#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a;

  do
  {
	printf("Enter number : ");
	scanf("%d", &a);
  } while (a < 0);

  return 0;
}