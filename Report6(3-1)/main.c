#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);
int main(void)
{
  int lotto_nums[6];

  input_nums(lotto_nums);
  print_nums(lotto_nums);
  return 0;

}

void input_nums(int* lotto_nums)
{
  int num;
  int i, j;
  int dup;

  for (i = 0; i < 6; i++)
  {
    printf("input number : ");
    scanf("%d", &num);
    dup = 0;
    for (j = 0; j < i; j++)
    {
      if (num == lotto_nums[j])
      {
        dup = 1;
        break;
      }
    }
    if (!dup)
    {
      lotto_nums[i] = num;
    }
    else
    {
      printf("exist same number.\n");
      i--;
    }
  }
}

void print_nums(int* lotto_nums)
{
  int i;

  printf("lotto number :");
  for (i = 0; i < 6; i++)
  {
    printf("%3d", lotto_nums[i]);
  }
}