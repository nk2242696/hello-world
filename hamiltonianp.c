#include <stdio.h>
#include <stdlib.h>
void scan(int *adj,int n)
{
	int source=0, destination;
	while(source!=-1)
	{
		scanf("%d%d",&source,&destination);
		adj[(source-1)*n+destination-1]=1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ",adj[i*n+j]);
		}
		printf("\n");
	}
}
int findnextposition(int path[],int n,int pathindex,int adj[])
{
	while(1)
	{
		path[pathindex]++;
		if (path[pathindex]==n)
		{
			path[pathindex]=-1;
			return 0;
		}
		if (adj[path[pathindex-1]*n + path[pathindex]])
		{
			int i;
			for (i = 0; i < pathindex; ++i)
			{
				if (path[i]==path[pathindex])
				{
					break;
				}
			}
			if (i==pathindex)
			{
				if (pathindex<n-1 || (pathindex==n-1)&&adj[path[pathindex]*n+path[0]])
				{
					return 1;
				}
			}
		}

	}
}
void printsolution(int path[],int n,int count)
{
	printf("Solution Number %d\n",count);
	for (int i = 0; i < n; ++i)
		printf("%d ",path[i]+1);
	printf("%d\n\n",path[0]+1);

}

void recursive(int pathindex,int path[],int adj[],int n,int *all,int *count)
{
	if(*all==-1)
		return;  //backtrack;
	while(1)
	{
		if(findnextposition(path,n,pathindex,adj))
		{
			if(pathindex==n-1)
			{
				printsolution(path,n,*count);
				if(*all==0)*all=-1;
				(*count)++;
			}
			else
				recursive(pathindex+1,path,adj,n,all,count);
		}
		else
			return ; // backtrack 
	}
}
void iterative(int pathindex,int path[],int *adj,int n,int *all,int *count)
{
	while(pathindex > 0)
	{
		if(findnextposition(path,n,pathindex,adj))
		{
			if (pathindex==n-1)
			{
				printsolution(path,n,*count);
				(*count)++;
				if(*all==0)return;
			}
			else
			pathindex++;
		}
		else
			pathindex--;
	}
}
int main()
{
	 while(1)
	 {
	 	int T,n,all,count,t;
	 	int *path,*adj;
	 	printf("1)Enter Number of vertices \n2)recursive\n3)iterative\n");
	 	scanf("%d",&T);
	 	switch(T)
	 	{
	 		case 1:
	 		scanf("%d",&n);
	 		path = (int *)malloc(sizeof(int)*n);
	 		adj =  (int *)malloc(sizeof(int)*n*n);
	 		scan(adj,n);
	 		break;
	 		case 2:
	 			
	 			printf("1)One solution \n2)all solution\n");
	 			scanf("%d",&t);
	 			path[0]=0;
	 			for (int i = 1; i < n; ++i)
	 					path[i]=-1;
	 			switch(t)
	 			{
	 				case 1:
	 				all=0;
	 				recursive(1,path,adj,n,&all,&count);
	 				case 2:
	 				all=1,count=1;
	 				recursive(1,path,adj,n,&all,&count);
	 				//printf("Total Number of solutions %d\n",count);
	 			}
	 			break;
	 		case 3:
	 			printf("1)One solution \n2)all solution\n");
	 			scanf("%d",&t);
	 			path[0]=0;
	 			for (int i = 1; i < n; ++i)
	 					path[i]=-1;
	 			switch(t)
	 			{
	 				case 1:
	 				all=0;
	 				iterative(1,path,adj,n,&all,&count);
	 				case 2:
	 				all=1,count=0;
	 				iterative(1,path,adj,n,&all,&count);
	 				printf("Total Number of solutions %d\n",count);
	 			}
	 			break;
	 	}

	 }
}
