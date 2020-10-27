#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
void func(void);

int a = 10;

int main(void)
{
  a = 20;
  func();
  printf("%d", a);
  return 0;
}

void func(void)
{
  a = 30;
}