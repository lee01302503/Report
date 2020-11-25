#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/

int main(void)
{
  FILE* afp, * bfp;
  int cnt = 0;;

  afp = fopen("a.txt", "r");
  if (afp == NULL)
  {
	printf("파일이 열리지 않습니다.\n");

	return 1;
  }

  bfp = fopen("b.txt", "r");
  if (bfp == NULL)
  {
	printf("파일이 열리지 않습니다.\n");

	return 1;
  }

  while (1)
  {
	int c1 = fgetc(afp);
	int c2 = fgetc(bfp);

	if (c1 == EOF && c2 == EOF)
	{
	  break;
	}
	if (c1 != c2)
	{
	  printf("두 파일은 다릅니다.");
	  fclose(afp);
	  fclose(bfp);
	  return 0;
	}
  }
  printf("두 파일은 일치 합니다.");
  fclose(afp);
  fclose(bfp);

  return 0;
}