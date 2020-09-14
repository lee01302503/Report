#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  char fruit[20];
  int cnt;

  printf("Favorit fruit : ");
  scanf("%s", fruit);
  printf("How many : ");
  scanf("%d", &cnt);
  printf("I will give you %d %s", cnt, fruit);

  return 0;
}