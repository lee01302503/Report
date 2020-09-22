#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  double height = 179.5;
  double weight = 75.0;
  if ((height >= 187.5) && (weight < 80))
  {
	printf("ok\n");
  }
  else
  {
	printf("cancel\n");
  }

  return 0;
}