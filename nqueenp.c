#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
int count;
////////////////////////////////////////////////////////////////////////////////////
                                           //  chacking safe place for new queen
////////////////////////////////////////////////////////////////////////////////////
int check(int row , int col,int *a)

{
	for(int i=0;i<row;i++)
	{
		int a_row=i;
		int a_col=a[i];

		if(abs(col-a_col)==abs(row-a_row) || a_col==col)
		{
			return 0;
		}
	}
	return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////
                                           // print 
//////////////////////////////////////////////////////////////////////////////////////////
void print(int n ,int *a)
{
	for(int i=0;i<n;i++)
	{
		printf("                                     ");
		for(int j=0;j<n;j++)
		{

		   if(j==a[i])
		   		printf("|Q ");
		   else
		   		printf("|  ");

		}
		printf("\n");
		printf("                                     ");
		for(int j=0;j<n;j++)
			printf("---");
		

			
		printf("\n");
	}
}


///////////////////////////////////////////////////////////////////////////////
                                           // n queen function
/////////////////////////////////////////////////////////////////////////////
void r_queen(int row ,int n, int *a)
{
	for(int i=0;i<n;i++)
	{
		
		if(check(row,i,a))
		{
			a[row]=i;
			
			if(row==n-1)
			{
				
				printf("\nsolution is \n");
				print(n,a);
			}
			else
			r_queen(row+1,n,a);
		}
	}
}


///////////////////////////////////////////////////////////////////////
                                           // n queen function
////////////////////////////////////////////////////////////////////
void i_queen(int row ,int n, int *a)
{
	while(row>=0)
	{
		a[row]=a[row]+1;     // this will increment coloumn 0 t0 n-1
		if(a[row]<=n-1)     // this will increment column ( a[row] ) till less than n-1
		{
			if(check(row,a[row],a))  // if position is not right then row wil reamin same coloum a[row]=will increment
			{	
				if(row==n-1)
				{			
					printf("\nsolution is \n");
					print(n,a);
				}
				else
				row=row+1;
			}
			
		}
		else // if coloun is full then do back track go back 
		{
			a[row]=-1;  // set last column -1 
			row=row-1;  // decriment the row;
		}
	}
}
int main()
{
	int n,choice;
	do
	{
		printf("1: enter the no of queen\n2: solution by itrattive backtraking\n");
		printf("3: solution by recarsive backtraking\n4:exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					printf("enter the no of queen : = ");
					scanf("%d",&n);
					if(n<4)
					{
						printf("Number of queens must be greater than 3\n");			
					}
					break;
			case 2:
					if(n==0)
					{
						printf("enter the no of queen first");
						break;
					}
					else
					{	
						int *a=(int *)malloc(sizeof(int)*n);

						for(int i=0;i<n;i++)
							a[i]=-1;

						i_queen(0,n,a);
						free(a);
					}
					
					break;
			case 3:
					if(n==0)
					{
						printf("enter the no of queen first");
						break;
					}
					else
					{	
						int *a=(int *)malloc(sizeof(int)*n);
						r_queen(0,n,a);
						free(a);
					}
					
					break;
			case 4:
			    break;

		}
	}while(choice!=4);
	
}
