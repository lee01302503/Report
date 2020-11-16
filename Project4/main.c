#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sum 0
#define min 1
#define muiti 2
#define tra 3
#define inve 4
/* made by Prof. Lee
*/
void func(void (*fp)(double a[3][3], double b[3][3]));//함수 포인터를 매개변수로 갖는 함수 (3*3 행렬)
void arr(double a[3][3]);			//행렬 출력
void add(double a[3][3], double b[3][3]);	//덧셈
void sub(double a[3][3], double b[3][3]);	//뺄셈
void mul(double a[3][3], double b[3][3]);	//곱셈
void transpose(double a[3][3]); // 전치행렬
void inverse(double a[3][3]); // 역행렬
void func1(void (*fd)(double c[2][2], double d[2][2]));// 함수 포인터를 매개변수로 갖는 함수(2*2행렬)
void arr1(double c[2][2]);			//행렬 출력
void add1(double c[2][2], double d[2][2]);	//덧셈
void sub1(double c[2][2], double d[2][2]);	//뺄셈
void mul1(double c[2][2], double d[2][2]);	//곱셈
void transpose1(double c[2][2]);// 전치행렬
void inverse1(double c[2][2]);//역행렬

void main()
{
  int num;//2*2 또는 3*3행렬 번호 저장할 변수			

  printf("2*2행렬이면 1번, 3*3행렬이면 2번 : ");
  scanf("%d", &num);
  if (num == 1)
  {
	int sel;
	printf("0: 덧셈, 1 : 뺄셈, 2 : 곱셈, 3 : 전치행렬, 4 : 역행렬");
	scanf("%d", &sel);

	switch (sel)
	{
	case sum:func1(add1); break;//0이면 func1에 덧셈 기능 추가
	case min:func1(sub1); break;//1이면 func1에 뺄셈 기능 추가
	case muiti:func1(mul1); break;//2이면 func1에 곱셈 기능 추가
	case tra: func1(transpose1); break;//3이면 func1에 전치행렬 기능 추가
	case inve:func1(inverse1); break;//4이면 func1에 역행렬 기능 추가
	}
  }
  else if (num == 2)
  {
	int sel;
	printf("0: 덧셈, 1 : 뺄셈, 2 : 곱셈, 3 : 전치행렬, 4 : 역행렬");
	scanf("%d", &sel);

	switch (sel)
	{
	case sum:func(add); break;//0이면 func에 덧셈 기능 추가
	case min:func(sub); break;//1이면 func에 뺄셈 기능 추가
	case muiti:func(mul); break;//2이면 func에 곱셈 기능 추가
	case tra: func(transpose); break;//3이면 func에 전치행렬 기능 추가
	case inve:func(inverse); break;//4이면 func에 역행렬 기능 추가
	}
  }


}


void func(void (*fp)(double a[3][3], double b[3][3]))
{
  double a[3][3], b[3][3];
  int i, j, yn;
  printf("a행렬을 입력하시오\n"); //a행렬 입력

  while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
  {

	for (i = 0; i < 3; i++)
	{
	  printf("%d 행: \n", i + 1);
	  for (j = 0; j < 3; j++)
	  {
		scanf("%lf", &a[i][j]);
	  }
	}

	printf("a 행렬은 다음과 같습니다. \n");
	arr(a);

	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }


  printf("\n\n");


  printf("b행렬을 입력하시오\n"); //b행렬 입력

  while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
  {

	for (i = 0; i < 3; i++)
	{
	  printf("%d 행: \n", i + 1);
	  for (j = 0; j < 3; j++)
	  {
		scanf("%lf", &b[i][j]);
	  }
	}

	printf("b 행렬은 다음과 같습니다. \n");
	arr(b);

	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }

  fp(a, b);// 함수 포인터로 가리키는 함수를 호출
}

void arr(double a[3][3])
{
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  printf("%.4lf\t", a[i][j]);
	}
	printf("\n");
  }
}
void add(double a[3][3], double b[3][3])
{
  double c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  c[i][j] = a[i][j] + b[i][j];
	}
  }

  arr(c);
}
void sub(double a[3][3], double b[3][3])
{
  double c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  c[i][j] = a[i][j] - b[i][j];
	}
  }

  arr(c);
}
void mul(double a[3][3], double b[3][3])
{
  double c[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
	}
  }

  arr(c);
}
void transpose(double a[3][3])
{
  double transpose[3][3];
  int i, j;

  for (i = 0; i < 3; i++)
  {
	for (j = 0; j < 3; j++)
	{
	  transpose[i][j] = a[j][i];
	}
  }

  arr(transpose);
}

void inverse(double a[3][3])
{
  double inv[3][3];
  double determinant = 0;
  determinant = a[0][0] * (a[1][1] * a[2][2] - a[2][1] * a[1][2]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
  double idet = 1 / determinant;
  if (determinant == 0)
  {
	printf("No inverse matrix exists.\n");
  }
  else
  {
	inv[0][0] = (a[1][1] * a[2][2] - a[2][1] * a[1][2]) * idet;
	inv[0][1] = (a[0][2] * a[2][1] - a[0][1] * a[2][2]) * idet;
	inv[0][2] = (a[0][1] * a[1][2] - a[0][2] * a[1][1]) * idet;
	inv[1][0] = (a[1][2] * a[2][0] - a[1][0] * a[2][2]) * idet;
	inv[1][1] = (a[0][0] * a[2][2] - a[0][2] * a[2][0]) * idet;
	inv[1][2] = (a[1][0] * a[0][2] - a[0][0] * a[1][2]) * idet;
	inv[2][0] = (a[1][0] * a[2][1] - a[2][0] * a[1][1]) * idet;
	inv[2][1] = (a[2][0] * a[0][1] - a[0][0] * a[2][1]) * idet;
	inv[2][2] = (a[0][0] * a[1][1] - a[1][0] * a[0][1]) * idet;
  }

  arr(inv);
}

void func1(void (*fd)(double c[2][2], double d[2][2]))
{
  double c[2][2], d[2][2];	//배열 초기화
  int i, j, yn;
  printf("a행렬을 입력하시오\n"); //a행렬 입력

  while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
  {

	for (i = 0; i < 2; i++)
	{
	  printf("%d 행: \n", i + 1);
	  for (j = 0; j < 2; j++)
	  {
		scanf("%lf", &c[i][j]);
	  }
	}

	printf("a 행렬은 다음과 같습니다. \n");
	arr1(c);

	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }


  printf("\n\n");


  printf("b행렬을 입력하시오\n"); //b행렬 입력

  while (1)//무한 루프 - 행렬값 입력이 다를 시 다시 입력
  {

	for (i = 0; i < 2; i++)
	{
	  printf("%d 행: \n", i + 1);
	  for (j = 0; j < 2; j++)
	  {
		scanf("%lf", &d[i][j]);
	  }
	}

	printf("b 행렬은 다음과 같습니다. \n");
	arr1(d);

	printf("입력한 값이 맞습니까? YES[1], NO[2]");
	scanf("%d", &yn);

	if (yn == 1)				//맞을 시 break
	  break;
  }

  fd(c, d); //함수 포인터로 가리키는 함수를 호출
}

void arr1(double c[2][2])
{
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  printf("%.4lf\t", c[i][j]);
	}
	printf("\n");
  }
}
void add1(double c[2][2], double d[2][2])
{
  double e[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  e[i][j] = c[i][j] + d[i][j];
	}
  }

  arr1(e);
}
void sub1(double c[2][2], double d[2][2])
{
  double e[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  e[i][j] = c[i][j] - d[i][j];
	}
  }

  arr1(e);
}
void mul1(double c[2][2], double d[2][2])
{
  double e[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  e[i][j] = c[i][0] * d[0][j] + c[i][1] * d[1][j];
	}
  }

  arr1(e);
}

void transpose1(double c[2][2])
{
  double transpose[2][2];
  int i, j;

  for (i = 0; i < 2; i++)
  {
	for (j = 0; j < 2; j++)
	{
	  transpose[i][j] = c[j][i];
	}
  }

  arr1(transpose);
}

void inverse1(double c[2][2])
{
  double d;
  double inv[2][2];
  d = c[0][0] * c[1][1] - c[0][1] * c[1][0];
  if (d == 0)
  {
	printf("역행렬 존재하지 않음!!");
	return 0;
  }
  else
  {
	inv[0][0] = c[1][1] / d;
	inv[0][1] = -c[0][1] / d;
	inv[1][0] = -c[1][0] / d;
	inv[1][1] = c[0][0] / d;
  }

  arr1(inv);
}