#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
/* made by Prof. Lee
*/
void create_random_nums(int* lotto_nums);
void input_nums(int* lotto_nums);
int get_rank_of_lotto(int* c_lotto, int* i_lotto);
void print_result(int* c_lotto, int* i_lotto);

int main(void)
{
  int create_lotto_nums[7];
  int input_lotto_nums[6];

  create_random_nums(create_lotto_nums); //   Lotto number generation
  input_nums(input_lotto_nums); // Enter lotto number
  print_result(create_lotto_nums, input_lotto_nums); // Calculation

  return 0;
}

// Lotto random generation function
void create_random_nums(int* lotto_nums)
{
  int num;
  int i, j;
  int dup;

  for (i = 0; i < 7; i++)
  {
    srand(GetTickCount());
    num = rand() % 45 + 1;
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
      lotto_nums[i] = num;
    else
      i--;
  }
}

// Lotto user input function
void input_nums(int* lotto_nums)
{
  int num;
  int i, j;
  int dup;

  for (i = 0; i < 6; i++)
  {
    printf("Enter the %dth lotto number. : ", i + 1);
    scanf("%d", &num);

    if (num < 1 || num>45)
    {
      printf("Lotto is out of range.\n");
      i--;
      continue;
    }

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
      printf("I have the same number.\n");
      i--;
    }
  }
}

// Lotto ranking function
int get_rank_of_lotto(int* c_lotto, int* i_lotto)
{
  int i, j;
  int rank = 0, count = 0, bonus = 0;

  for (i = 0; i < 6; i++)
  {
    for (j = 0; j < 6; j++)
    {
      //If the bonus number is correct
      if (i_lotto[i] == c_lotto[6])
        bonus++;

      // If the number is correct
      if (i_lotto[i] == c_lotto[j])
      {
        count++; // Increase the number of matches
      }
    }
  }

  if (count == 6) rank = 1;
  else if (count == 5 && bonus != 0) rank = 2;
  else if (count == 5) rank = 3;
  else if (count == 4) rank = 4;
  else if (count == 3) rank = 5;
  else rank = 999; // In case of dropout

  return rank;
}

// Results output function
void print_result(int* c_lotto, int* i_lotto)
{
  int i, rank;
  printf("\n\n--Lotto number--\n");

  for (i = 0; i < 6; i++)
    printf("%4d", c_lotto[i]);
  printf("    Bonus number: %4d", c_lotto[6]);

  printf("\n\n--My number--\n");
  for (i = 0; i < 6; i++)
    printf("%4d", i_lotto[i]);

  rank = get_rank_of_lotto(c_lotto, i_lotto);

  if (rank < 6)
    printf("\n\nCongratulations! You have won the lottery %d.", rank);
  else
    printf("\n\nUnfortunately you didn't win the lottery.\n");
}