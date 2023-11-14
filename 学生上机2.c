#include<stdio.h>
#include<stdlib.h>

typedef  struct  Lnode
{
    int data;
    struct  Lnode *next;
}joseph;

void  Create_List(joseph *L,int n)
{
   joseph *p,*q;
   q=L;
   for(int i=2;i<=n;i++)
   {
    p=(joseph*)malloc(sizeof(joseph));
    p->data=i;
    q->next=p;
    q=p;
   }
   p->data=n;
   p->next=L; 
}

void  Delete_List(joseph *p,joseph *q)
{
    q-> next= p-> next;
    free(p);
}


void josephus ( joseph *L, int s, int m,int n)
{       
 joseph* p, * q;
    q = L;

    for (int i = 2; i < s; i++)
    {
        q = q->next;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < m; i++)
        {
            q = q->next;
        }
        p = q->next;
        printf("%d ", p->data); 
        Delete_List(p, q);
    }
}


void main()
{
    joseph *L=NULL;
    int m,n,s;
    L=(joseph*)malloc(sizeof(joseph));
    L->data=1;
    printf ("请输入人数、约定编号数，出列值：\n");
    scanf ("%d%d%d", &n, &s, &m);
    if ((m> 1000) || (n> 1000))
        printf ("输入的人数m,n不合法\n");
    else
        if (s>n) printf ("输入数据不合法！\n");
        else
        {
            Create_List(L, n);
            printf ("\n");
            josephus(L,s,m,n);
        }
}
