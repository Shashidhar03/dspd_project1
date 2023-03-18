#include<stdio.h>
#define size 4
int main()
{
	struct std_info
	{
		int x; 			 //serial no and pref list
		char ch;		//department
		int year;		//year of study
	}list[size][size],dept[size],year[size];
	
	for(int i=1;i<=size;i++)
	{
		printf("enter student id and preferencre list\n");
		for(int j=1;j<=size;j++)
		{
			if(j==1)
			{
				printf("enter id:\n");
				scanf("%d",&list[i][j].x);             /*in location (i,j)=(1,1) , student id is stored and in location (i,j)=(1,j) preference list of i=1
															is stored*/
				printf("enter preference:\n");
			}
			else
			{
				scanf("%d",&list[i][j].x);
			}	
		}
		printf("enter depeartment : \n");
		scanf(" %c",&dept[i].ch);
		printf("enter year:\n");
		scanf(" %d",&year[i].year);
		printf("\n");
	} 
	
	
	int match[size],k=0,j_count=1,m=0,n=0;
	for(int i=0;i<size;i++)                   /*match is another new array, it is created because if match is found between student and his preference list, it stores
												student serial number and matched student serial nmber in continuos locations, and value of k(iteration used to store
												matched pairs in match array) is increased by 2*/
	{
		match[i]=0;                          //all matched pairs are initialised to zero
	}
	
	int flag=0,flag1=0,flag2=0;
	for(int i=1;i<=size;i++)
	{
		for(int j=2;j<=size;j++)
		{
			if(year[i].year==year[list[i][j].x].year)
			{
				if(dept[i].ch==dept[list[i][j].x].ch)   //same dept and same year
				{
					n=0;
					while(n<size)                  /*here while loop is used because, if after 1st iteration if a match is found and get stored in match array,
													then in 2nd iteration if match is found then while loop checks with previous matched pairs for not to repeate.
													if 2nd iterated matched pair matches with 1st iterated matched pair then it will not store 2nd iterated matched 
													pair in match array and moves to next in preference list*/
					{
						if(match[n]!=list[i][j].x)
						{
							flag1=1;
							match[k]=list[i][j_count].x;
							match[k+1]=list[i][j].x;
						}
						n++;
					}	
				}
				else if(flag1==0)                    //different dept and same year
				{
					n=0;
					while(n<size)
					{
						if(match[n]!=list[i][j].x)
						{
							flag1=1;
							match[k]=list[i][j_count].x;
							match[k+1]=list[i][j].x;
						}
						n++;
					}	
				}
			}	
		}
		
		if(flag1==1)
		{
			k=k+2;
		}
				
		for(int j=2;j<=size;j++)
		{
			if((year[list[i][j].x].year)<(year[i].year))        //junior of any dept
			{
				if(flag1==0)
				{
					n=0;
					while(n<size)
					{
						if(match[n]!=list[i][j].x)
						{
							flag1=1;
							flag=1;
							match[k]=list[i][j_count].x;
							match[k+1]=list[i][j].x;
						}
						n++;
					}	
				}
			}
		}
		
		if(flag==1)
		{
			k=k+2;
		}
		
		for(int j=2;j<=size;j++)
		{
			if((year[list[i][j].x].year)>(year[i].year))
			{
				if(dept[i].ch==dept[list[i][j].x].ch)          //senior but same dept
				{
					if(flag==0&&flag1==0)
					{
						n=0;
					while(n<size)
					{
						if(match[n]!=list[i][j].x)
						{
							flag2=1;
							match[k]=list[i][j_count].x;
							match[k+1]=list[i][j].x;
						}
						n++;
					}	
					}
				}
				else if(flag2==0)          //other dept senior
				{
					if(flag==0&&flag1==0)
					{
						n=0;
						while(n<size)
						{
							if(match[n]!=list[i][j].x)
							{
								flag2=1;
								match[k]=list[i][j_count].x;
								match[k+1]=list[i][j].x;
							}
							n++;
						}
					}	
				}
				
			}
		}
		if(flag2==1)
		{
			k=k+2;
		}
	
	}
	while(m<size)
	{
		if(match[m]!=0&&match[m+1]!=0)
		{
			printf("%d and %d are paried\n",match[m],match[m+1]);
		}
		
		m=m+2;
		
	}
	return 0;
}