#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
//---�ݹ��㷨--
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
	else 
	{
		Hanoi(n-1,a,c,b);
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,a,c);
		Hanoi(n-1,b,a,c);
	}

}
int main()
{
	int n=5;
	printf("�ݹ��㷨��%d����Ƭ�ƶ����̣�\n",n);
	Hanoi(n,'X','Y','Z');
	return 1;
}