#include<stdio.h>
#define n 12
#define appln 20
int main()
{
	struct std_info{
		int x;		//serial no
		int pf1;	//preference
		char ch;	//new student or not
	}sno[appln][3],new_std[appln];
	printf("preference 1 is floor choice\n");
	printf("preference 2 is partner choice\n");
	printf("\n");
	int new_std_count=0;
	for(int i=0;i<appln;i++)
	{
		printf("enter serial.no: \n");
		scanf("%d",&sno[i][0].x);
		
		printf("new student or not(y or n):\n");
		scanf(" %c",&new_std[i].ch);
		
		if(new_std[i].ch=='y')               /* here if student is 1st year, 1st preference(floor choice) option is not avaliable to them and
												 directly 2nd preference is avaliable to them*/													
		{
			new_std_count++;
			sno[i][1].pf1=0;
			printf("enter preference 2 : \n");
			scanf("%d",&sno[i][2].pf1);
		}
		else if(new_std[i].ch=='n')
		{
			for(int j=1;j<=2;j++)
			{
				printf("enter preference %d : \n",j);
				scanf("%d",&sno[i][j].pf1);
			}
		}
		printf("\n");
	}
	printf("\n");
	
	int floor[5];
	for(int i=0;i<=4;i++)          //here histogram of marks algorithm is used 
	{
		floor[i]=0;
	}
	for(int i=0;i<appln;i++)
	{
		for(int j=1;j<=2;j++)
		{
			floor[sno[i][j].pf1]=floor[sno[i][j].pf1]+1;
		}
	}
	
	int first_pref_count=0;
	
	printf("NO.OF SEATS FILLED\n");           //no.of seats
	printf("\n");
	if(new_std_count<=(((2*n)/4)-4))
	{
		first_pref_count=first_pref_count+new_std_count;
		printf("no.of seats filled in 1st floor is %d\n",new_std_count);
	}
	else
	{
		first_pref_count=first_pref_count+(((2*n)/4)-4);
		printf("all seats are filled in 1st floor\n");
	}
		
	for(int i=2;i<=4;i++)
	{
		
		if(floor[i]<=((2*n)/4))
		{
			first_pref_count=first_pref_count+floor[i];
			printf("no.of seats filled in %d floor is %d\n",i,floor[i]);
		}
		else if(floor[i]>((2*n)/4))
		{
			first_pref_count=first_pref_count+((2*n)/4);
			printf("all seats are filled in %d floor\n",i);
		}
	}
	printf("\n");
	
	printf("1ST PREFERENCE\n");             //1st preference
	printf("\n");
	printf("%d seates are filled in 1st preference\n",first_pref_count);
	printf("\n");
	
	printf("VACANT SEATS\n");             //vacant seats
	printf("\n");
	
	if(new_std_count<=(((2*n)/4)-4))
	{
		printf("no.of vacant seats in 1st floor is %d\n",(((2*n)/4)-4)-new_std_count);
	}
	else
	{
		printf("no vacancy in 1st floor\n");
	}
	
	for(int i=2;i<=4;i++)
	{
		if(floor[i]<=((2*n)/4))
		{
			printf("no.of vacant seats in %d floor is %d\n",i,((2*n)/4)-floor[i]);
		}
		else
		{
			printf("no vacancy in %d floor\n",i);
		}
	}
	
	return 0;	
}