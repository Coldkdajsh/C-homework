#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define  SMAX  100			//三元组非零元素的最大个数
typedef struct  SPNode {				//定义三元组
   int i; 						//三元组非零元素的行、列和值
int j;
int v;
}SPNode;
typedef struct sparmatrix {				//定义稀疏矩阵
int rows;
int cols;
int terms;					//稀疏矩阵行、列和非零元素的个数
SPNode data[SMAX]; 		//三元组表
}sparmatrix;
sparmatrix CreateSparmatrix(){	//创建稀疏距阵
sparmatrix  A;
printf("请输入要创建稀疏矩阵的行，列，数量\n");//总的矩阵表，非零元素的个数

scanf("%d,%d,%d",&A.rows,&A.cols,&A.terms);

for(int c=1;c<=A.terms;c++)

{

printf("请输入所在行，所在列，以及其中的值\n");//非零元素的行，列，值?

scanf("%d,%d,%d",&A.data[c].i,&A.data[c].j,&A.data[c].v);

}

return  A;
}
sparmatrix Trans(sparmatrix A){        	 //将稀疏矩阵A转置
sparmatrix B;
B.cols=A.cols;
B.rows=A.rows;
B.terms=A.terms;
if(B.terms>0)
{
int j=1;
for(int c=1;c<=A.cols;c++)//按照A矩阵的列数从小到大排
{
    for(int i=1;i<=A.terms;i++)//在非零三元组中找
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
void ShowSparmatrix(sparmatrix A) {			//显示稀疏矩阵B
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
void  SearchSparmatrix(sparmatrix A,int s){		//查找稀疏矩阵中非零元素
int flag=0;
for(int c=1;c<=A.terms;c++)
{
if(A.data[c].v==s)
{
printf("找到了,所在行为%d,列为%d\n",A.data[c].i,A.data[c].j);
flag++;
}
}
if(flag<0)
{
printf("没找到\n");
}
}
void main(){						//稀疏矩阵的三元组存储
int ch=1,choice,s;
struct sparmatrix A,B;
A.terms=0;
B.terms=0;
while(ch){
printf("\n");
printf("\n\t\t稀疏矩阵的三元组存储\n");
printf("\n\t\t********************************");
printf("\n\t\t       1---------新建              ");
printf("\n\t\t       2---------转置              ");
printf("\n\t\t       3---------查找              ");
printf("\n\t\t       4---------显示              ");
printf("\n\t\t       0---------退出              ");
printf("\n\t\t********************************");
printf("\n\n\t\t     请输入选择(0-4):");
scanf("%d",&choice);
switch(choice){
case 1: A=CreateSparmatrix();
    				break;
case 2: if(A.terms==0)
      				printf("\n\t\t三元组为空! \n");
    			  else {
B=Trans(A);
printf("\n\t\t转置后的稀疏矩阵:\n");
ShowSparmatrix(B);
        			}
    			 break;
case 3:if (A.terms==0)
         		  printf("\n\t\t三元组为空! \n");
            	  else {
        			printf("\n\t\t输入要查找的非零元素: ");
          		scanf ("%d", &s) ;
        			SearchSparmatrix(A,s);
        			}
    			  break;
    		case 4:ShowSparmatrix(A);
        		  break;
    		case 0: ch=0;
               break;
default:system("cls");
printf("\n\t\t输入有误!请重新输入!\n");
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
