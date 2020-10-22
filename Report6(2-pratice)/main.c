#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include<time.h>


/* made by Prof. Lee
*/
void swap(int* pa, int* pb);//Declare the swap function
void line_up(int a[]);//line up function declaration

int main(void)
{
  int a[10];
  int i;

  printf("\nRandom number :\t");
  for (i = 0; i < 10; i++)
  {
    a[i] = rand()%10;//Generate random function
    printf("%3d", a[i]);
  }
  line_up(a);


  printf("\n\nSorted numbers :\t");
  for (i = 0; i < 10; i++)
  {
    printf("%3d", a[i]);//Random number sort
  }


  return 0;
}


void swap(int* pa, int* pb)
{
  int temp;

  temp = *pa;
  *pa = *pb;
  *pb = temp;
}

void line_up(int a[])
{
  int i, j;

  for (i = 10 - 1; i > 0; i--)//Bubble sort
  {
    for (j = 0; j < i; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(&a[j], &a[j + 1]);
      }
    }
  }
}