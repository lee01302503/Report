#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
/* made by Prof. Lee
*/

void game(int c, int difficulty)
{
  int p;
  int i, j, yes = 0;
  int player[3][4] = { 0 };
  int strike = 0, ball = 0, count = 1;

  do
  {
    yes = 0;

    if (c == 1) // 1P game
    {
      srand((unsigned int)time(NULL));

      for (i = 0; i < 4; i++)
      {
        player[1][i] = (rand() % 10);// ������ ������ 0~9���� ���

        for (j = 0; j < i; j++)
        {
          if (player[1][i] == player[1][j])// �ߺ� ���� �ľ��ϱ�
          {
            i--;
            break;
          }
        }
      }
    }
    else if (c == 2) // 2P game
    {
      for (i = 0; i < 2; i++)
      {
        j = 0;
        printf("\ninput %dP's number (ex. 1357) :", i + 1);//�����Է�
        while (j < 4)
        {
          if (_kbhit())//��� �Է��� ���� true�� �ν�
          {
            player[i][j] = _getch() - 48;//�ƽ�Ű�ڵ� ���̱⶧���� -48�� ����
            j++;
            printf("*");
          }
        }
      }
    }


    while (1)
    {
      if (strike == 4)//�̹� �¸��� ���
      {
        strike = 0;
        break;
      }
      else if (count == 13 - 2 * difficulty)//�̹� �й��� ���
      {
        count = 0;
        break;
      }

      printf("\n\n%dȸ�� ���ھ߱�\n", count);
      for (p = 0; p < c; p++)
      {
        if (c == 2)
          printf("\n<%dP ����>\n", p + 1);
        printf("1���� 9���� ���ڸ� �Է��ϼ��� : ");
        scanf("%d%d%d%d", &player[2][0], &player[2][1], &player[2][2], &player[2][3]);

        if (player[2][0] < 0 || player[2][0]>9 || player[2][1] < 0 || player[2][1]>9 || player[2][2] < 0 || player[2][2]>9 || player[2][3] < 0 || player[2][3]>9)
        {
          printf("������ ������ϴ�\n");
          p--;
          continue;
        }

        else if (player[2][0] == player[2][1] || player[2][0] == player[2][2] || player[2][0] == player[2][3] || player[2][1] == player[2][2] || player[2][1] == player[2][3] || player[2][2] == player[2][3])
        {
          printf("�ߺ����ڸ� �Է��߽��ϴ�.\n");
          p--;
          continue;
        }


        ball = 0;
        strike = 0;

        for (i = 0; i < 4; i++)
        {
          for (j = 0; j < 4; j++)
          {
            if (player[2][j] == player[!p][i])
            {
              if (i == j)// ������ �Է��� ���ڿ� ��ġ�� ���� ���
              {
                strike++;
              }
              else
              {
                ball++;// ������ �Է��� ���� ���ڴ� ������ ��ġ�� �ٸ� ���
              }
            }
          }
        }
        if (strike == 0 && ball == 0)//������ �Է��� ���ڰ� ���� ���� ���
        {
          printf("out!!!\n");
        }
        else
        {
          printf("strike : %d, ball : %d\n", strike, ball);
        }
        if (strike == 4)// ��ġ�� ���ڰ� ��� ���� ��� �¸�
        {
          printf("�¸��Ͽ����ϴ�!!\n");
          break;
        }
        if (count == 13 - 2 * difficulty)// ���� ���̵����� 11ȸ�� �Ǿ����� �й�
        {
          printf("�й��Ͽ����ϴ�....\n");
          break;
        }
      }
      count++;
    }
    printf("����Ͻðڽ��ϱ�?\n");
    printf("���� ���̵��� �ٽ��Ϸ��� 1��, ���̵� �����Ϸ��� �ƹ����ڳ� �����ּ���\n");//���̵� ����
    scanf_s("%d", &yes);

    strike = 0;
    ball = 0;
    count = 1;// ��� �� �ʱ�ȭ
    if (yes != 1)
    {
      break;// ���̵� ����
    }
  } while (yes == 1);// ���� ���̵� ���
}


int main(void)
{
  // int i, j;
  int a = 0, b = 0, c = 0;

  printf("1�ο�??, 2�ο�??\n");
  printf("1�ο��̸� 1�� 2�ο��̸� 2���� �Է����ּ���\n");
  scanf_s("%d", &c);

  do
  {
    printf("���̵� ����(1.����, 2.����, 3.�����, 4.�ſ�����) : "); // ���̵� ����
    scanf("%d", &a);

    game(c, a);

    b = 0;
    printf("���̵� ���� �Ͻðڽ��ϱ�??\n");
    printf("���̵������Ͻ÷��� 1��, �׸��ν÷��� �ƹ�Ű�� �����ּ���\n");// ���̵� ���� �� ���α׷� ����
    scanf_s("%d", &b);
    if (b != 1)
    {
      break;// ���α׷� ����
    }
  } while (b == 1);

  return 0;
}