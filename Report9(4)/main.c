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
  scanf_s("%[^\n]s", str, 100);//���������ؼ� ���� �Է� �ޱ�

  for (i = 0; i < 26; i++)//���ĺ� ���� 26��
  {
    alpha[i] = 'a' + i;
  }

  for (i = 0; str[i] != 0; i++)//���ڿ� ���� �ִ� NULL ���ڰ� ���ö����� �ݺ�
  {
    if (('a' <= str[i]) && (str[i] <= 'z'))// �ҹ������� üũ
    {
      cnt[str[i] - 'a']++;//�ҹ����� ��� !
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
    printf("'%c' : %d��, ", alpha[i], cnt[i]);// �������� ����
  }

  printf("\n");
  return 0;
}