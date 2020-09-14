#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  char ch;

  printf("Code : ");
  scanf("%c", &ch);
  printf("Code%c of Ascii code %d.\n", ch, ch);

  return 0;
}