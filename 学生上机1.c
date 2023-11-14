#define MAXSIZE 100     		//MAXSIZE为线性表可能的最大长度
#include<stdio.h>

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;					// length为线性表的长度
}SqList;						//线性表定义
void InitList(SqList *L)			//初始化操作，将线性表L置空
{
    L->length=-1;
}
void CreatSqlist(SqList *L,int n)//建立顺序表---------1
{
if(!n)
{
    return;
}
for(int i=0;i<n;i++)
{printf("输入第%d号元素\n",i);
    scanf("%d",&L->data[i]);
}
return L->length=n-1;
}
void Output(SqList *L)				//输出顺序表L--------2
{
    int i;
    for (i=0;i<=L->length;i++)
        printf("%5d",L->data[i]);		//每个数据占5列
    printf("\n");
}
int IsEmpty(SqList *L)  //判断表是否为空，如L是空表，返回1，否则返回0
{if(!L->length)
	return 0;
}
int GetElem(SqList *L,int i) //取表中第i元素--------6
{if(i<0||i>L->length||L->length==MAXSIZE)
    return 0;
else
    return L->data[i];
}
int LocateElem(SqList *L,ElemType x)//定位函数，返回L中第1个与x相等的数据元素的位置(从0算起)，否则返回值为0--------3
{
    for(int i=0;i<=L->length;i++)
    {
        if(x==L->data[i])
        return i;
    }
	return 0;

}
int Insert(SqList *L,ElemType x,int i)//在线性表L中第i个数据元素之前插入一个数据元素x--------4
{if(i<0||i>L->length||L->length==MAXSIZE)
	return 0;
else
{
   int k=L->length+1;
    L->length=k;
    for(k;k>i;k--)
    {
        L->data[k]=L->data[k-1];
    }
    L->data[i]=x;
    return 1;
}
}
int Delete(SqList *L, int i)		//删除线性表L中第i个数据元素---------5
{if(i<0||i>L->length)
    return 0;
else
{
int k=i;
for(k;k<L->length;k++)
{
    L->data[k]=L->data[k+1];
}
L->length--;
}
	return 1;

}
void Clear(SqList *L)			//置空线性表L
{
L->length=0;
}
void MergeList(SqList *La,SqList *Lb,SqList *Lc)//合并有序表La和Lb到表Lc中，使得表Lc依然有序----------7
{
    int i,j,k,a,b;
    i=0,j=0,k=0;
    a=La->length;
    b=Lb->length;
    while (i<=a&&j<=b)
        if(La->data[i]<Lb->data[j])
        {
            Lc->data[k]=La->data[i];
            k++;
            i++;
        }
        else
        {
            Lc->data[k]=Lb->data[j];
            k++;
            j++;
        }
        while (i<=a)
        {
            Lc->data[k]=La->data[i];
            k++;
            i++;
        }
        while (j<=b)
        {
            Lc->data[k]=Lb->data[j];
            k++;
            j++;
        }
        Lc->length=k-1;
        
    }
    
void Output1 ( )
{
    int i;
    for (i=0;i<10;i++)
        printf("  ");
    for (i=0; i< 32; i++)
        printf("*");
    printf("\n");
}
void main1()
{
    int i;
    Output1();
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("1.建立一个顺序表");
    for (i=0; i< 10; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("2.输出一个顺序表");
    for (i=0; i< 10; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("3.在顺序表中查找");
    for (i=0; i< 10; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("4.向顺序表插入一个元素");
    for (i=0; i< 2; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("5.删除顺序表的一个元素");
    for (i=0; i< 2; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("6.读取顺序表中的元素");
    for (i=0; i< 2; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("7.合并顺序表");
    for (i=0; i< 8; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("0.退          出");
    for (i=0; i< 8; i++) printf("  ");
    printf("*");
    printf("\n");
    Output1();
}
void main()					//主函数
{
    int n, i, k=1, m, x;
    SqList L,La,Lc;
    InitList (&L);
    main1();
    while (k)
    {
        printf("请选择0--- 7:       ");
        scanf ("%d", &m);
        getchar();
        switch (m)
        {
        case 0:
            return;
        case 1:
        {
            printf ("构建顺序表:\n");
            printf("请输人顺序表元素的个数:");
            scanf ("%d", &n);
            CreatSqlist(&L,n);				//建立长度为n的顺序表L
            Output(&L);					//输出表L
            break;
        }
        case 2:
            Output(&L);
            printf("\n");
            break;
        case 3:
        {
            printf("请输入要查找的元素值: ");
            scanf ("%d", &x);
            k= LocateElem(&L,x);
            printf ("要查找的元素的定位:%d\n", k );
            printf("\n");
            break;
        }
        case 4:
        {
            printf ("输入要插入元素的位置和值: " );
            fflush(stdin);
            scanf ("%d",&i);
            scanf ("%d",&x);
            Insert (&L, x,i);
            Output(&L);
            printf("\n");
            break;
        }
        case 5:
        {
            printf ("输入要删除元素的位置: ");
            fflush(stdin);
            scanf ("%d",&i);
            Delete(&L,i);
            Output(&L);
            break;
        }
        case 6:
        {
            printf ("请输入要取出的元素的序号: ");
            fflush(stdin);
            scanf ("%d",&i);
            k=GetElem(&L,i);				//取表中第i个元素
            printf("取出的第%d个元素为:%d\n", i, k) ;
            break;
        }
        case 7:
        {
            InitList(&La);
            printf ("请输入第2个顺序表元素的个数: ");
            scanf ("%d", &m);
            CreatSqlist(&La,m);			//建立长度为m的顺序表L
            Output(&La);					//输出表La
            MergeList(&L,&La,&Lc);
            printf ("输出合并后的顺序表中的元素:\n");
            Output(&Lc);					//输出表Lc
            break;
        }
        default:
            return;
        }
        printf("继续运行吗Y /N:");
        fflush(stdin);
        scanf("%c",&k);
        if (k=='n'||k=='N') return;
        fflush(stdin);
        main1();
    }
}
