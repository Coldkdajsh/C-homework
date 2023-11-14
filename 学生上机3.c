#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<process.h>
#define MaxSize  100					//���Ԫ�ظ���
typedef  int  ElemType;
typedef struct  							//˳��ջ�����Ͷ���
{
    ElemType data[MaxSize];	 		//ջԪ�ش洢�ռ�
    int top; 							//ջ��ָ��
}SeqStack;
typedef struct  							//ѭ��˳��ӵ����Ͷ���
{
    ElemType data[MaxSize];		//����Ԫ�ش洢�ռ�
    int front;					 	//��ͷָ��
    int rear; 						//��βָ��
}CircSeqQueue;
void StackInitial(SeqStack *pS) 			//����һ����ָ��pS��ָ��Ŀ�ջ
{
    pS->top= -1;
}
int isEmpty(SeqStack *pS) 				//˳��ջΪ��ʱ����1�����򷵻ء�
{
    return pS->top== -1;
}
int isFull (SeqStack * pS) 				//ջΪ��ʱ����1�����򷵻�0
{
    return pS->top >=MaxSize-1;
}
void Push(SeqStack *pS, ElemType e) 	//��ջ��������Ԫ��e��ջ
{
   if(pS->top == MaxSize-1)
   {
    return 0;
   }
   else
   {
    pS->top++;
    pS->data[pS->top]=e;
   }
}
ElemType Pop(SeqStack *pS) 	//��ջ��Ϊ�գ���ɾ��ջ��Ԫ�أ�����������ֵ
{
    int i;
    if(pS->top== -1)
        return 0;
    else
    {
        i=pS->data[pS->top];
        pS->top--;
        return i;
    }
    
}
ElemType GetTop(SeqStack  *pS) 	//��ջ��Ϊ�գ��򷵻�ջ��Ԫ�ص�ֵ
{
    if(pS->top == -1)
        return 0;
    else
    {
        return pS->data[pS->top];
    }
}
void MakeEmpty(SeqStack *pS) 		//����ָ��pS��ָ���ջ��Ϊ��ջ
{
    pS->top=-1;
}
void QueueInitial(CircSeqQueue *pQ)
{
//����һ����ָ��PQ��ָ��Ŀ�˳��ѭ������
    pQ->front=pQ->rear=0;
}
int IsEmpty(CircSeqQueue *pQ) 	//ѭ��˳�����Ϊ��ʱ����1�����򷵻�0
{
    return pQ->front==pQ->rear;
}
int IsFull(CircSeqQueue *pQ)     	//ѭ������Ϊ��ʱ����1�����򷵻ء�
{
    return(pQ->rear+1) %MaxSize==pQ->front;
}
void EnQueue(CircSeqQueue *pQ,ElemType e)//�����в�������Ԫ��e����
{
    if((pQ->rear+1) %MaxSize==pQ->front)
    {
        return 0;
    }
    else{
        pQ->data[pQ->rear]=e;
        pQ->rear=(pQ->rear+1)%MaxSize;
        return 1;
    }

   
}
ElemType DeQueue(CircSeqQueue *pQ)//��ѭ�����в�Ϊ�գ���ɾ����ͷԪ�أ�����������ֵ
{   int i;
        if(pQ->front==pQ->rear)
    {
        return 0;
    }
    else
    {i=pQ->data[pQ->front];
    pQ->front=(pQ->front+1)%MaxSize;
    return i;     
    }
}
ElemType GetFront(CircSeqQueue *pQ)  //�����в�Ϊ�գ��򷵻ض�ͷԪ��ֵ
{   
    if(pQ->front==pQ->rear)
    {
        return 0;
    }
    return pQ->data[pQ->front];
}
void MakeEmpty2(CircSeqQueue *pQ) 	//��ָ��pQ��ָ��Ķ��б�Ϊ��
{
   pQ->front=pQ->rear;
}
void output()
{
    int i;
    for (i=0;i<10; i++)
        printf(" ");
    for (i=0; i< 32; i++)
        printf("*");
    printf("\n");
}
void main1()
{
    int i;
    output();
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("1.��ջһ��Ԫ��");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("2.��ջһ��Ԫ��");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("3.��ջ��Ԫ��");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("4.��ջ��");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("5.���һ��Ԫ��");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("6.����һ��Ԫ��");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("7.������Ԫ��");
    for (i=0; i< 14; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("8.�öӿ�");
    for (i=0; i< 18; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("0.��      ��");
    for (i=0; i< 8; i++) printf("  ");
    printf("*");
    printf("\n");
    output();
}
void main () 				//������
{
    SeqStack *pS;
    CircSeqQueue*pQ;
    ElemType e;
    int k=1,m,i,n,c,d;
    pS=(SeqStack *)malloc(sizeof(SeqStack));
    StackInitial(pS);
    pQ=(CircSeqQueue *)malloc(sizeof(CircSeqQueue));
    QueueInitial(pQ);
    main1();
    while (k)
    {
        printf("��ѡ��0һ8:");
        scanf ("%d", &m);
        switch (m)
        {
        case 0:
            return;
        case 1:
        {
            printf("������n,������n��Ԫ��,��ջ:");
            scanf ("%d", &n);
            for (i=0;i<n;i++)
            {
                scanf ("%d", &e);
                Push(pS,e);
            }
            break;
        }
        case 2:
        {
            e=Pop(pS);
            printf("%d\n", e);
            printf("\n");
            break;
        }
        case 3:
        {
            printf ("ȡ��ջ��Ԫ��:  ");
            e=GetTop(pS);
            printf("%d\n", e);
            printf ("\n");
            break;
        }
        case 4:
        {
            printf("��ջ�գ�\n");
            MakeEmpty(pS);
            printf ("\n");
            break;
        }
        case 5:
        {
            printf("�������Ԫ�ظ�����");
            scanf ("%d", &c);
            printf("�������Ԫ�أ�\n");
            for (i=0;i<c;i++)
            {
                scanf ("%d", &e);
                EnQueue(pQ,e);
            }
            break;
        }
        case 6:
        {
            printf("���������Ԫ�صĸ�����");
            scanf ("%d", &c);
            for (i=0;i<c;i++)
            {
                e=DeQueue (pQ);
                printf("%d\n", e);
            }
            break;
        }
        case 7:
        {
            printf ("ȡ������Ԫ�أ�\n");
            e=GetFront(pQ);
            printf ("%d\n",e);
            break;
        }
        case 8:
        {
            printf("�öӿգ�\n");
            MakeEmpty2(pQ);
            printf ("\n");
            break;
        }
        default:
            return;
        }
        printf ("����������Y /N");
        scanf("%d",&k);
        if (k=='n'||k=='N') return;
        fflush(stdin);
        main1();

    }
}