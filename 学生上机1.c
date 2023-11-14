#define MAXSIZE 100     		//MAXSIZEΪ���Ա���ܵ���󳤶�
#include<stdio.h>

typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int length;					// lengthΪ���Ա�ĳ���
}SqList;						//���Ա���
void InitList(SqList *L)			//��ʼ�������������Ա�L�ÿ�
{
    L->length=-1;
}
void CreatSqlist(SqList *L,int n)//����˳���---------1
{
if(!n)
{
    return;
}
for(int i=0;i<n;i++)
{printf("�����%d��Ԫ��\n",i);
    scanf("%d",&L->data[i]);
}
return L->length=n-1;
}
void Output(SqList *L)				//���˳���L--------2
{
    int i;
    for (i=0;i<=L->length;i++)
        printf("%5d",L->data[i]);		//ÿ������ռ5��
    printf("\n");
}
int IsEmpty(SqList *L)  //�жϱ��Ƿ�Ϊ�գ���L�ǿձ�����1�����򷵻�0
{if(!L->length)
	return 0;
}
int GetElem(SqList *L,int i) //ȡ���е�iԪ��--------6
{if(i<0||i>L->length||L->length==MAXSIZE)
    return 0;
else
    return L->data[i];
}
int LocateElem(SqList *L,ElemType x)//��λ����������L�е�1����x��ȵ�����Ԫ�ص�λ��(��0����)�����򷵻�ֵΪ0--------3
{
    for(int i=0;i<=L->length;i++)
    {
        if(x==L->data[i])
        return i;
    }
	return 0;

}
int Insert(SqList *L,ElemType x,int i)//�����Ա�L�е�i������Ԫ��֮ǰ����һ������Ԫ��x--------4
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
int Delete(SqList *L, int i)		//ɾ�����Ա�L�е�i������Ԫ��---------5
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
void Clear(SqList *L)			//�ÿ����Ա�L
{
L->length=0;
}
void MergeList(SqList *La,SqList *Lb,SqList *Lc)//�ϲ������La��Lb����Lc�У�ʹ�ñ�Lc��Ȼ����----------7
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
    printf("1.����һ��˳���");
    for (i=0; i< 10; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("2.���һ��˳���");
    for (i=0; i< 10; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("3.��˳����в���");
    for (i=0; i< 10; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("4.��˳������һ��Ԫ��");
    for (i=0; i< 2; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("5.ɾ��˳����һ��Ԫ��");
    for (i=0; i< 2; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("6.��ȡ˳����е�Ԫ��");
    for (i=0; i< 2; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("7.�ϲ�˳���");
    for (i=0; i< 8; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("0.��          ��");
    for (i=0; i< 8; i++) printf("  ");
    printf("*");
    printf("\n");
    Output1();
}
void main()					//������
{
    int n, i, k=1, m, x;
    SqList L,La,Lc;
    InitList (&L);
    main1();
    while (k)
    {
        printf("��ѡ��0--- 7:       ");
        scanf ("%d", &m);
        getchar();
        switch (m)
        {
        case 0:
            return;
        case 1:
        {
            printf ("����˳���:\n");
            printf("������˳���Ԫ�صĸ���:");
            scanf ("%d", &n);
            CreatSqlist(&L,n);				//��������Ϊn��˳���L
            Output(&L);					//�����L
            break;
        }
        case 2:
            Output(&L);
            printf("\n");
            break;
        case 3:
        {
            printf("������Ҫ���ҵ�Ԫ��ֵ: ");
            scanf ("%d", &x);
            k= LocateElem(&L,x);
            printf ("Ҫ���ҵ�Ԫ�صĶ�λ:%d\n", k );
            printf("\n");
            break;
        }
        case 4:
        {
            printf ("����Ҫ����Ԫ�ص�λ�ú�ֵ: " );
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
            printf ("����Ҫɾ��Ԫ�ص�λ��: ");
            fflush(stdin);
            scanf ("%d",&i);
            Delete(&L,i);
            Output(&L);
            break;
        }
        case 6:
        {
            printf ("������Ҫȡ����Ԫ�ص����: ");
            fflush(stdin);
            scanf ("%d",&i);
            k=GetElem(&L,i);				//ȡ���е�i��Ԫ��
            printf("ȡ���ĵ�%d��Ԫ��Ϊ:%d\n", i, k) ;
            break;
        }
        case 7:
        {
            InitList(&La);
            printf ("�������2��˳���Ԫ�صĸ���: ");
            scanf ("%d", &m);
            CreatSqlist(&La,m);			//��������Ϊm��˳���L
            Output(&La);					//�����La
            MergeList(&L,&La,&Lc);
            printf ("����ϲ����˳����е�Ԫ��:\n");
            Output(&Lc);					//�����Lc
            break;
        }
        default:
            return;
        }
        printf("����������Y /N:");
        fflush(stdin);
        scanf("%c",&k);
        if (k=='n'||k=='N') return;
        fflush(stdin);
        main1();
    }
}
