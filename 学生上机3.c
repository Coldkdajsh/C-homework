#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<process.h>
#define MaxSize  100					//最大元素个数
typedef  int  ElemType;
typedef struct  							//顺序栈的类型定义
{
    ElemType data[MaxSize];	 		//栈元素存储空间
    int top; 							//栈顶指针
}SeqStack;
typedef struct  							//循环顺序队的类型定义
{
    ElemType data[MaxSize];		//队列元素存储空间
    int front;					 	//队头指针
    int rear; 						//队尾指针
}CircSeqQueue;
void StackInitial(SeqStack *pS) 			//创建一个由指针pS所指向的空栈
{
    pS->top= -1;
}
int isEmpty(SeqStack *pS) 				//顺序栈为空时返回1，否则返回。
{
    return pS->top== -1;
}
int isFull (SeqStack * pS) 				//栈为满时返回1，否则返回0
{
    return pS->top >=MaxSize-1;
}
void Push(SeqStack *pS, ElemType e) 	//若栈不满，则元素e进栈
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
ElemType Pop(SeqStack *pS) 	//若栈不为空，则删除栈顶元素，并返回它的值
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
ElemType GetTop(SeqStack  *pS) 	//若栈不为空，则返回栈顶元素的值
{
    if(pS->top == -1)
        return 0;
    else
    {
        return pS->data[pS->top];
    }
}
void MakeEmpty(SeqStack *pS) 		//将由指针pS所指向的栈变为空栈
{
    pS->top=-1;
}
void QueueInitial(CircSeqQueue *pQ)
{
//创建一个由指针PQ所指向的空顺序循环队列
    pQ->front=pQ->rear=0;
}
int IsEmpty(CircSeqQueue *pQ) 	//循环顺序队列为空时返回1，否则返回0
{
    return pQ->front==pQ->rear;
}
int IsFull(CircSeqQueue *pQ)     	//循环队列为满时返回1，否则返回。
{
    return(pQ->rear+1) %MaxSize==pQ->front;
}
void EnQueue(CircSeqQueue *pQ,ElemType e)//若队列不满，则元素e进队
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
ElemType DeQueue(CircSeqQueue *pQ)//若循环队列不为空，则删除队头元素，并返回它的值
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
ElemType GetFront(CircSeqQueue *pQ)  //若队列不为空，则返回队头元素值
{   
    if(pQ->front==pQ->rear)
    {
        return 0;
    }
    return pQ->data[pQ->front];
}
void MakeEmpty2(CircSeqQueue *pQ) 	//将指针pQ所指向的队列变为空
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
    printf("1.入栈一个元素");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("2.出栈一个元素");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("3.读栈顶元素");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("4.置栈空");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("5.入队一个元素");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("6.出队一个元素");
    for (i=0; i< 16; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("7.读队首元素");
    for (i=0; i< 14; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("8.置队空");
    for (i=0; i< 18; i++) printf("  ");
    printf("*");
    printf("\n");
    for (i=0; i< 10; i++)printf("  ");
    printf("*     ");
    printf("0.退      出");
    for (i=0; i< 8; i++) printf("  ");
    printf("*");
    printf("\n");
    output();
}
void main () 				//主函数
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
        printf("请选择0一8:");
        scanf ("%d", &m);
        switch (m)
        {
        case 0:
            return;
        case 1:
        {
            printf("输入数n,再输入n个元素,入栈:");
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
            printf ("取出栈顶元素:  ");
            e=GetTop(pS);
            printf("%d\n", e);
            printf ("\n");
            break;
        }
        case 4:
        {
            printf("置栈空：\n");
            MakeEmpty(pS);
            printf ("\n");
            break;
        }
        case 5:
        {
            printf("输入入队元素个数：");
            scanf ("%d", &c);
            printf("输入入队元素：\n");
            for (i=0;i<c;i++)
            {
                scanf ("%d", &e);
                EnQueue(pQ,e);
            }
            break;
        }
        case 6:
        {
            printf("请输入出队元素的个数：");
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
            printf ("取出队首元素：\n");
            e=GetFront(pQ);
            printf ("%d\n",e);
            break;
        }
        case 8:
        {
            printf("置队空：\n");
            MakeEmpty2(pQ);
            printf ("\n");
            break;
        }
        default:
            return;
        }
        printf ("继续运行吗Y /N");
        scanf("%d",&k);
        if (k=='n'||k=='N') return;
        fflush(stdin);
        main1();

    }
}