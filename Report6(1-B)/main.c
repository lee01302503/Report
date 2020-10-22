#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int a = 10;
  int* p = &a;
  *p = 20;

  printf("%d", a);

  return 0;
}