#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int check(char(*name)[21], char* name1, int cnt);

int main(void)
{
  FILE* ifp, * ofp, * xfp;
  char name[10][21];
  char name1[21];
  int i, cnt;

  ifp = fopen("a.txt", "r");
  if (ifp == NULL)
  {
	printf("파일이 열리지 않습니다.\n");

	return 1;
  }

  ofp = fopen("b.txt", "r");
  if (ofp == NULL)
  {
	printf("파일이 열리지 않습니다.\n");

	return 1;
  }

  xfp = fopen("c.txt", "w");
  if (xfp == NULL)
  {
	printf("파일이 열리지 않습니다.\n");

	return 1;
  }

  for (i = 0; i < 10; i++)
  {
	fscanf(ifp, "%s", name[i]);
	if (feof(ifp))
	{
	  break;
	}
  }
  cnt = i;

  while (fscanf(ofp, "%s", name1) != EOF)
  {
	if (!check(name, name1, cnt))
	{
	  fprintf(xfp, "%s\n", name1);
	}
  }

  fclose(ifp);
  fclose(ofp);
  fclose(xfp);
  return 0;
}

int check(char(*name)[21], char* name1, int cnt)
{
  int i;

  for (i = 0; i < cnt; i++)
  {
	if (strcmp(name[i], name1) == 0)
	{
	  return 1;
	}
  }

  return 0;
}