#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/

int main(void)
{
  char str[80];
  char str1[80];
  char* star = "**********";
  int a;

  printf("단어입력 : ");
  scanf("%s", str);
  a = strlen(str);

  if (a <= 5)
  {
	strcpy(str1, str);
  }
  else
  {
	strncpy(str1, str, 5);
	str1[5] = '\0';
	strncat(str1, star, a - 5);
  }

  printf("입력한 단어 : %s, 생략된 단어 : %s\n", str, str1);


  return 0;
}