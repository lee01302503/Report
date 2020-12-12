#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COUNT 50//�ִ� ���� �л� ��
#define MAX_NAME_LEN 20// �ִ� �̸� ����
/* made by Prof. Lee
*/
typedef struct studentdata
{
  int num; // �й�
  char name[MAX_NAME_LEN]; // �̸�
  unsigned int kor, eng, math, total;//���� ���� ���� ����
}S_data;
void showdata(S_data* ap_data, unsigned int a_count);
int ReadData(const char* ap_file_name, S_data* ap_data, unsigned int* ap_data_count);


int main(void)
{
  S_data data[MAX_COUNT];
  unsigned int data_count = 0, select = 0;

  if (ReadData("data.csv", data, &data_count))
  {
	while (select != 2)
	{
	  printf("1.��������\n");
	  printf("2.���α׷� ����\n");
	  
	  printf("���� : ");
	  if (1 == scanf_s("%u", &select))
	  {
		printf("\n\n");
		if (select == 1)showdata(data, data_count);
	  }
	  else
	  {
		printf("\n�߸��Ȱ�.........\n\n");
		rewind(stdin);
	  }
	}
  }
  else
  {
	printf("data.csv ������ ���� �����ϴ�. ���� ��θ� Ȯ�� �ϼ���!!\n");
  }
  return 0;
}

char* GetNextString(char* ap_src_str, char a_delimiter, char* ap_buffer)
{
  while (*ap_src_str && *ap_src_str != a_delimiter) *ap_buffer++ = *ap_src_str++;
  if (*(ap_buffer - 1) == '\n')*(ap_buffer - 1) = 0;
  else*ap_buffer = 0;

  if (*ap_src_str == a_delimiter)ap_src_str++;

  return ap_src_str;
}

int ReadData(const char* ap_file_name, S_data* ap_data, unsigned int* ap_data_count)
{
  S_data* p_start = ap_data;// �о�帰 �������� ������ ����ϱ� ���� ���� �ּ� ����

  FILE* p_file = NULL;

  if (0 == fopen_s(&p_file, ap_file_name, "rt"))
  {
	char one_line_string[128], str[32], * p_pos;
	if (NULL != fgets(one_line_string, 128, p_file))
	{
	  while (NULL != fgets(one_line_string, 128, p_file))
	  {
		p_pos = GetNextString(one_line_string, ',', str);//�й��� ����
		ap_data->num = atoi(str);// �й��� ������ �����Ѵ�.
		p_pos = GetNextString(p_pos, ',', ap_data->name);
		p_pos = GetNextString(p_pos, ',', str);//���������� �д´�.
		ap_data->kor = atoi(str);//���������� ������ ����
		p_pos = GetNextString(p_pos, ',', str);
		ap_data->eng = atoi(str);
		p_pos = GetNextString(p_pos, ',', str);
		ap_data->math = atoi(str);

		ap_data->total = ap_data->kor + ap_data->eng + ap_data->math;
		ap_data++;
	  }
	  *ap_data_count = ap_data - p_start;
	}
	fclose(p_file);
	return 1;
  }
  return 0;
}

void showdata(S_data* ap_data, unsigned int a_count)
{
  printf("----------------------------------------------------------------\n");
  printf("        �й�      �̸�   ����  ����  ����  ����   ���\n");
  printf("----------------------------------------------------------------\n");

  unsigned int sum = 0;
  for (unsigned int i = 0; i < a_count; i++, ap_data++)
  {
	printf("  %08u %10s   %3d   %3d   %3d,     %3d   %.2lf\n", ap_data->num, ap_data->name, ap_data->kor, ap_data->eng, ap_data->math, ap_data->total, ap_data->total / 3.0);
	sum += ap_data->total;
  }
  printf("----------------------------------------------------\n");
  if (a_count > 0)
  {
	printf("   �� %d��, ��ü ��� %.2lf\n", a_count, sum / (a_count * 3.0));
	printf("-----------------------------------------------------------------\n");
  }
}