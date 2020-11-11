#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* made by Prof. Lee
*/
int main(void)
{
  char str[100];
  char alpha[26] = { 0, };
  int cnt[26] = { 0, }, i, j;
  int temp = 0;
  char temp1;

  printf("input word : ");
  scanf_s("%[^\n]s", str, 100);//공백포함해서 문자 입력 받기

  for (i = 0; i < 26; i++)//알파벳 개수 26개
  {
    alpha[i] = 'a' + i;
  }

  for (i = 0; str[i] != 0; i++)//문자열 끝에 있는 NULL 문자가 나올때까지 반복
  {
    if (('a' <= str[i]) && (str[i] <= 'z'))// 소문자인지 체크
    {
      cnt[str[i] - 'a']++;//소문자인 경우 !
    }
  }

  for (i = 26 - 1; i > 0; i--) 
  {
    for (j = 0; j < i; j++) 
    {
      if (cnt[j] > cnt[j + 1]) 
      {
        temp = cnt[j];
        cnt[j] = cnt[j + 1];
        cnt[j + 1] = temp;

        temp1 = alpha[j];
        alpha[j] = alpha[j + 1];
        alpha[j + 1] = temp1;


      }
    }
    printf("'%c' : %d번, ", alpha[i], cnt[i]);// 오름차순 정렬
  }

  printf("\n");
  return 0;
}