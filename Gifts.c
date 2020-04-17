#include<stdio.h>
#include<conio.h>
#include<string.h>
void solve()
{

    char a[10][5],temp[5];
	int i,j,process_time[10],wt[10];
	int total_weight=0,gifts[10],temp1,n;
	float avg_weight;
	printf("Enter no of girls:");
	scanf("%d",&n);
	for(i=0;i<n;i++)   // taking the information via user
	{
		printf("enter the girl %d name:",i+1);
  		scanf("%s",&a[i]);
		printf("enter the process time:");
		scanf("%d",&process_time[i]);
		printf("enter no. of gifts:");
		scanf("%d",&gifts[i]);
	}
  	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(gifts[i]>gifts[j])
			{
				temp1=gifts[i];
				gifts[i]=gifts[j];
				gifts[j]=temp1;
				temp1=process_time[i];
				process_time[i]=process_time[j];
				process_time[j]=temp1;
				strcpy(temp,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],temp);
			}
		}
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+wt[i-1];
		total_weight=total_weight+wt[i];
	}
	avg_weight=(float)total_weight/n;
	printf("G_name\t P_time\t No.Gifts\tW_time\n");
	for(i=0;i<n;i++)
	{
	   printf(" %s\t %d\t %d\t \t%d\n" ,a[i],process_time[i],gifts[i],wt[i]);
	}
	printf("total waiting time=%d\navg waiting time=%f",total_weight,avg_weight);
	getch();
}
void main()
{
	solve();
}
