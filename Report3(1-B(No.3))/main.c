#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  int age = 25, chest = 95;
  char size;
  if (age < 20)
  {
	if (chest < 85)
	{
	  size = 'S';
	}
	else if ((85 <= chest) && (chest < 95))
	{
	  size = 'M';
	}
	else
	{
	  size = 'L';
	}
  }
  else
  {
	if (chest < 90)
	{
	  size = 'S';
	}
	else if ((90 <= chest) && (chest < 100))
	{
	  size = 'M';
	}
	else
	{
	  size = 'L';
	}
  }
  printf("size : %c\n", size);
}