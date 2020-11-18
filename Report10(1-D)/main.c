#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
typedef enum {CYAN, MAGENTA, YRLLOW=5,BLACK}COLOR;
typedef enum{UP, DOWN,LEFT,RIGHT}ARROW;

int main(void)
{
  COLOR my_color = YRLLOW, c;
  ARROW direction = UP;

  for (c = CYAN; c < BLACK; c++)
  {
	direction++;
	direction = direction % 4;
	if (c == my_color)break;
  }

  switch (direction)
  {
  case UP:printf("������� : ��"); break;
  case DOWN:printf("������� : �Ʒ�"); break;
  case LEFT:printf("������� : ����"); break;
  case RIGHT:printf("������� : ������"); break;
  }
  return 0;
}