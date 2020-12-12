#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COUNT 50//최대 관리 학생 수
#define MAX_NAME_LEN 20// 최대 이름 길이
/* made by Prof. Lee
*/
typedef struct studentdata
{
  int num; // 학번
  char name[MAX_NAME_LEN]; // 이름
  unsigned int kor, eng, math, total;//국어 영어 수학 총점
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
	  printf("1.성적보기\n");
	  printf("2.프로그램 종료\n");
	  
	  printf("선택 : ");
	  if (1 == scanf_s("%u", &select))
	  {
		printf("\n\n");
		if (select == 1)showdata(data, data_count);
	  }
	  else
	  {
		printf("\n잘못된값.........\n\n");
		rewind(stdin);
	  }
	}
  }
  else
  {
	printf("data.csv 파일을 열수 없습니다. 파일 경로를 확인 하세요!!\n");
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
  S_data* p_start = ap_data;// 읽어드린 데이터의 갯수를 계산하기 위해 시작 주소 저장

  FILE* p_file = NULL;

  if (0 == fopen_s(&p_file, ap_file_name, "rt"))
  {
	char one_line_string[128], str[32], * p_pos;
	if (NULL != fgets(one_line_string, 128, p_file))
	{
	  while (NULL != fgets(one_line_string, 128, p_file))
	  {
		p_pos = GetNextString(one_line_string, ',', str);//학번을 읽음
		ap_data->num = atoi(str);// 학번은 정수로 저장한다.
		p_pos = GetNextString(p_pos, ',', ap_data->name);
		p_pos = GetNextString(p_pos, ',', str);//국어점수를 읽는다.
		ap_data->kor = atoi(str);//국어점수는 정수로 저장
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
  printf("        학번      이름   국어  영어  수학  총점   평균\n");
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
	printf("   총 %d명, 전체 평균 %.2lf\n", a_count, sum / (a_count * 3.0));
	printf("-----------------------------------------------------------------\n");
  }
}