#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
//---递归算法--
void Hanoi(int n,char a,char b,char c)
{
	if(n==1)
		printf("\t将第%d个盘片从%c移动到%c\n",n,a,c);
	else 
	{
		Hanoi(n-1,a,c,b);
		printf("\t将第%d个盘片从%c移动到%c\n",n,a,c);
		Hanoi(n-1,b,a,c);
	}

}
int main()
{
	int n=5;
	printf("递归算法：%d个盘片移动过程：\n",n);
	Hanoi(n,'X','Y','Z');
	return 1;
}