#include <stdio.h>
int N, r, c;
int len = 1, space = 1;
int x,y,answer;

void z(int num, int space, int len)
{
	answer = num;

	if (len == 1)
		return;


	if (r < len / 2  && c < len / 2 )	//좌상단
	{	
		z(num, space / 4, len / 2);	//작은 네모랑 포커스 이미 동일
	}
	else if (r < len / 2 && c >= len / 2)	//우상단
	{
		c = c - len / 2;	//작은 곳으로 포커스 바꾸기
		z(num + space, space / 4, len / 2);
	}
	else if (r >= len / 2 && c < len / 2)	//좌하단
	{
		r = r - len / 2;	//작은 곳으로 포커스 바꾸기
		z(num + 2* space, space / 4, len / 2);
	}
	else if (r >= len / 2 && c >= len / 2)	//우하단
	{
		r = r - len / 2;
		c = c - len / 2;	//작은 곳으로 포커스 바꾸기
		z(num + 3 * space, space / 4, len / 2);
	}
	return;
}

int main()
{
	scanf_s("%d %d %d", &N, &r, &c);
	

	for (int i = 1; i <= N; i++) {
		len = len * 2;		//power(2, N);
	}

	for (int i = 1; i <= N-1; i++) {
		space = space * 4;	//power(2*2, N)/4;
	}

	z(0, space, len);

	printf("%d\n", answer);
	return 0;

}