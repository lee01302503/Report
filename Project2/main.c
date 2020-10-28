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
        player[1][i] = (rand() % 10);// 나머지 연산자 0~9까지 계산

        for (j = 0; j < i; j++)
        {
          if (player[1][i] == player[1][j])// 중복 난수 파악하기
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
        printf("\ninput %dP's number (ex. 1357) :", i + 1);//숫자입력
        while (j < 4)
        {
          if (_kbhit())//모든 입력한 것을 true로 인식
          {
            player[i][j] = _getch() - 48;//아스키코드 값이기때문에 -48를 해줌
            j++;
            printf("*");
          }
        }
      }
    }


    while (1)
    {
      if (strike == 4)//이미 승리한 경우
      {
        strike = 0;
        break;
      }
      else if (count == 13 - 2 * difficulty)//이미 패배한 경우
      {
        count = 0;
        break;
      }

      printf("\n\n%d회차 숫자야구\n", count);
      for (p = 0; p < c; p++)
      {
        if (c == 2)
          printf("\n<%dP 차례>\n", p + 1);
        printf("1부터 9까지 숫자를 입력하세요 : ");
        scanf("%d%d%d%d", &player[2][0], &player[2][1], &player[2][2], &player[2][3]);

        if (player[2][0] < 0 || player[2][0]>9 || player[2][1] < 0 || player[2][1]>9 || player[2][2] < 0 || player[2][2]>9 || player[2][3] < 0 || player[2][3]>9)
        {
          printf("범위를 벗어났습니다\n");
          p--;
          continue;
        }

        else if (player[2][0] == player[2][1] || player[2][0] == player[2][2] || player[2][0] == player[2][3] || player[2][1] == player[2][2] || player[2][1] == player[2][3] || player[2][2] == player[2][3])
        {
          printf("중복숫자를 입력했습니다.\n");
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
              if (i == j)// 난수와 입력한 숫자와 위치가 맞은 경우
              {
                strike++;
              }
              else
              {
                ball++;// 난수와 입력한 수가 숫자는 맞으나 위치가 다른 경우
              }
            }
          }
        }
        if (strike == 0 && ball == 0)//난수와 입력한 숫자가 맞지 않은 경우
        {
          printf("out!!!\n");
        }
        else
        {
          printf("strike : %d, ball : %d\n", strike, ball);
        }
        if (strike == 4)// 위치와 숫자가 모든 맞은 경우 승리
        {
          printf("승리하였습니다!!\n");
          break;
        }
        if (count == 13 - 2 * difficulty)// 쉬움 난이도에서 11회가 되었을시 패배
        {
          printf("패배하였습니다....\n");
          break;
        }
      }
      count++;
    }
    printf("계속하시겠습니까?\n");
    printf("현재 난이도로 다시하려면 1번, 난이도 변경하려면 아무숫자나 눌러주세요\n");//난이도 변경
    scanf_s("%d", &yes);

    strike = 0;
    ball = 0;
    count = 1;// 모든 값 초기화
    if (yes != 1)
    {
      break;// 난이도 변경
    }
  } while (yes == 1);// 현재 난이도 계속
}


int main(void)
{
  // int i, j;
  int a = 0, b = 0, c = 0;

  printf("1인용??, 2인용??\n");
  printf("1인용이면 1번 2인용이면 2번을 입력해주세요\n");
  scanf_s("%d", &c);

  do
  {
    printf("난이도 설정(1.쉬움, 2.보통, 3.어려움, 4.매우어려움) : "); // 난이도 설정
    scanf("%d", &a);

    game(c, a);

    b = 0;
    printf("난이도 변경 하시겠습니까??\n");
    printf("난이도변경하시려면 1번, 그만두시려면 아무키나 눌러주세요\n");// 난이도 변경 및 프로그램 종료
    scanf_s("%d", &b);
    if (b != 1)
    {
      break;// 프로그램 종료
    }
  } while (b == 1);

  return 0;
}