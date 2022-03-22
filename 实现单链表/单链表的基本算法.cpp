#include<stdio.h>
#include<malloc.h>
typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode * next;     //ָ���̽ڵ�
}LinkNode;     //����������ڵ�����
void CreateListF(LinkNode *&L,ElemType a[],int n)  //ͷ�巨����������
{
	LinkNode *s;
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode)); //�����½ڵ�s
		s->data=a[i];
		s->next=L->next;                        //���ڵ�s����ԭ��ʼ�ڵ�֮ǰ��ͷ���֮��
		L->next=s;
	}
}
void CreateListR(LinkNode *&L,ElemType a[],int n)  //β�巨����������
{
	LinkNode *s,*r;
	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	L->next=NULL;
	r=L;             //rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for(int i=0;i<n;i++)
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
		s->data=a[i];
		r->next=s;  //�����s����r���֮��
		r=s;
	}
	r->next=NULL;  //β���next����ΪNULL
}
void InitList(LinkNode *&L)              //��ʼ�����Ա�
{
	L=(LinkNode *)malloc(sizeof(LinkNode)); //����ͷ���
	L->next=NULL;  //����������Ϊ�ձ�
}
void DestroyList(LinkNode *&L)         //�������Ա�
{
	LinkNode *pre=L,*p=pre->next;
	while(p!=NULL)
	{
		free(pre);
		pre=p;         //pre��pͬ������һ�����
		p=pre->next;
	}
	free(pre); //��ʱpΪNULL,preָ��β��㣬�ͷ���
}
bool ListEmpty(LinkNode *L) //�ж����Ա��Ƿ�Ϊ�ձ�
{
	return (L->next==NULL);
}
int ListLength(LinkNode *L) //�����Ա�ĳ���
{
	int i=0;
	LinkNode *p=L;    //pָ��ͷ��㣬i��Ϊ0��ͷ�������Ϊ0��
	while(p->next!=NULL)
	{
		i++;
		p=p->next;
	}
	return (i);   //ѭ��������pָ��β��㣬�����iΪ������
}
void DispList(LinkNode *L) //������Ա�
{
	LinkNode *p=L->next;  //pָ���׽��
	while(p!=NULL)  //p��ΪNULL�����P����data��
	{
		printf("%c",p->data);
		p=p->next;  //pָ����һ�����
	}
	printf("\n");
}
bool GetElem(LinkNode *L,int i,ElemType &e)  //�����Ա��е�i��Ԫ��ֵ
{
	int j=0;
	LinkNode *p=L;  //pָ��ͷ��㣬j��Ϊ0����ͷ�������Ϊ0��
	if(i<=0)
		return false;        //i���󷵻ؼ�
	while(j<i&&p!=NULL)   //�ҵ�i�����p
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false; //�����ڵ�i�����ݽ�㣬����false
	else   //���ڵ�i�����ݽ�㣬����true
	{
		e=p->data;
		return true;
	}    
}
int LocateElem(LinkNode *L,ElemType e) //���ҵ�һ��ֵ��Ϊe��Ԫ�����
{
	int i=1;
	LinkNode *p=L->next;  //pָ���׽�㣬i��Ϊ1�����׽������Ϊ1��
	while(p!=NULL&&p->data!=e) //����dataֵΪe�Ľ�㣬�����Ϊi
	{
		p=p->next;
		i++;
	}
	if(p==NULL)  //������ֵΪe�Ľ�㣬����0
		return (0);
	else 
		return (i); //����ֵΪe�Ľ�㣬�������߼����i	
}
bool ListInsert(LinkNode *&L,int i,ElemType e) //�����i��Ԫ��
{
	int j=0;
	LinkNode *p=L,*s; //pָ��ͷ��㣬j��Ϊ0����ͷ�������Ϊ0��
	if(i<=0)
		return false;
	while(j<i-1&&p!=NULL)  //���ҵ�i-1�����p
	{
		j++;
		p=p->next;
	}
	if(p==NULL)  //δ�ҵ���i-1����㣬����false
		return false;
	else   //�ҵ���i-1�����p�������½�㲢����true
	{
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
}
bool ListDelete(LinkNode *&L,int i,ElemType &e) //ɾ����i��Ԫ��
{
	int j=0;
	LinkNode *p=L,*q; // pָ��ͷ��㣬j��Ϊ0����ͷ�������Ϊ0��
	if(i<=0)
		return false;
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
		return false;
	else
	{
		q=p->next;
		if(q==NULL)
			return false;
		e=q->data;
		p->next=q->next;
		free(q);
		return true;		
	}
}
int main()
{
	LinkNode *h;
	ElemType e;
	printf("������Ļ����������£�\n");
    printf("(1)��ʼ��������h\n");
	InitList(h);
	printf("(2)���β�ȡβ�巨����a,b,c,d,eԪ��\n");
	ListInsert(h,1,'a');
    ListInsert(h,2,'b');
	ListInsert(h,3,'c');
	ListInsert(h,4,'d');
	ListInsert(h,5,'e');
	printf("(3)���������h��\n");
	DispList(h);
	printf("(4)������h���ȣ�%d\n",ListLength(h));
	printf("(5)������hΪ%s\n",(ListEmpty(h)?"��":"�ǿ�"));
	GetElem(h,3,e);
	printf("(6)������h�ĵ�����Ԫ�س��ȣ�%c\n",e);
	printf("(7)Ԫ��a��λ�ã�%d\n",LocateElem(h,'a'));
	printf("(8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h,4,'f');
	printf("(9)���������h:");DispList(h);
	printf("(10)ɾ��h�ĵ�3��Ԫ��\n");
	ListDelete(h,3,e);
    printf("(11)���������h:");DispList(h);
	printf("(12)�ͷŵ�����h\n");
	DestroyList(h);
	return 0;
}