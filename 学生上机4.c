#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  SMAX  100			//��Ԫ�����Ԫ�ص�������
typedef struct  SPNode {				//������Ԫ��
   int i; 						//��Ԫ�����Ԫ�ص��С��к�ֵ
int j;
int v;
}SPNode;
typedef struct sparmatrix {				//����ϡ�����
int rows;
int cols;
int terms;					//ϡ������С��кͷ���Ԫ�صĸ���
SPNode data[SMAX]; 		//��Ԫ���
}sparmatrix;
sparmatrix CreateSparmatrix(){	//����ϡ�����
sparmatrix  A;
printf("������Ҫ����ϡ�������У��У�����\n");//�ܵľ��������Ԫ�صĸ���

scanf("%d,%d,%d",&A.rows,&A.cols,&A.terms);

for(int c=1;c<=A.terms;c++)

{

printf("�����������У������У��Լ����е�ֵ\n");//����Ԫ�ص��У��У�ֵ?

scanf("%d,%d,%d",&A.data[c].i,&A.data[c].j,&A.data[c].v);

}

return  A;
}
sparmatrix Trans(sparmatrix A){        	 //��ϡ�����Aת��
sparmatrix B;
B.cols=A.cols;
B.rows=A.rows;
B.terms=A.terms;
if(B.terms>0)
{
int j=1;
for(int c=1;c<=A.cols;c++)//����A�����������С������
{
    for(int i=1;i<=A.terms;i++)//�ڷ�����Ԫ������
    {
        if(A.data[i].j==c)
        {
            B.data[j].i=A.data[i].j;
            B.data[j].j=A.data[i].i;
            B.data[j].v=A.data[i].v;
            j++;
        }
    }
}
}
return B;
}
void ShowSparmatrix(sparmatrix A) {			//��ʾϡ�����B
int flag=1;
for(int i=1;i<=A.rows;i++)
{
	for(int j=1;j<=A.cols;j++)
	{
	if(A.data[flag].v!=0&&A.data[flag].i==i&&A.data[flag].j==j)
	{
	printf("%d ",A.data[flag].v);
	flag++;
	}
	else
	{
	printf("0 ");
	}
	}
printf("\n");
}
}
void  SearchSparmatrix(sparmatrix A,int s){		//����ϡ������з���Ԫ��
int flag=0;
for(int c=1;c<=A.terms;c++)
{
if(A.data[c].v==s)
{
printf("�ҵ���,������Ϊ%d,��Ϊ%d\n",A.data[c].i,A.data[c].j);
flag++;
}
}
if(flag<0)
{
printf("û�ҵ�\n");
}
}
void main(){						//ϡ��������Ԫ��洢
int ch=1,choice,s;
struct sparmatrix A,B;
A.terms=0;
B.terms=0;
while(ch){
printf("\n");
printf("\n\t\tϡ��������Ԫ��洢\n");
printf("\n\t\t********************************");
printf("\n\t\t       1---------�½�              ");
printf("\n\t\t       2---------ת��              ");
printf("\n\t\t       3---------����              ");
printf("\n\t\t       4---------��ʾ              ");
printf("\n\t\t       0---------�˳�              ");
printf("\n\t\t********************************");
printf("\n\n\t\t     ������ѡ��(0-4):");
scanf("%d",&choice);
switch(choice){
case 1: A=CreateSparmatrix();
    				break;
case 2: if(A.terms==0)
      				printf("\n\t\t��Ԫ��Ϊ��! \n");
    			  else {
B=Trans(A);
printf("\n\t\tת�ú��ϡ�����:\n");
ShowSparmatrix(B);
        			}
    			 break;
case 3:if (A.terms==0)
         		  printf("\n\t\t��Ԫ��Ϊ��! \n");
            	  else {
        			printf("\n\t\t����Ҫ���ҵķ���Ԫ��: ");
          		scanf ("%d", &s) ;
        			SearchSparmatrix(A,s);
        			}
    			  break;
    		case 4:ShowSparmatrix(A);
        		  break;
    		case 0: ch=0;
               break;
default:system("cls");
printf("\n\t\t��������!����������!\n");
break;
}
  			if (choice==1||choice==2||choice==3||choice==4){
  				printf("\n\t\t");
  				system("pause");
    			system("cls");
			}
else system("cls");
			}
		  }
