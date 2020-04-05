#include<stdio.h>
int arr_time1[20],arr_time2[20],priority[20],process[20],arr_time3[20];
int brst_t1[30],brst_t2[30],brst_t3[30];
int Total=0,t1=0,t2=0,t3=0;
int a,i,at[20],bt[30],pr[20],j=0,s=0,m=0;
int total,b,var[20],counter=0;
float average_waiting_time1=0.0,average_turnaround_time1=0.0;
int q,waiting_time3[20],turnaround_time3[20];
float average_waiting_time3=0.0,average_turnaround_time3=0.0;
int pos,p,var1,sum=0,waiting_time2[20],turnaround_time2[20];
float average_waiting_time2=0.0,average_turnaround_time2=0.0;
void ROUND_ROBIN()
{
	printf("time quantum for queue1 is 4\n");
	for(i=0;i<j;i++)
	{
		var[i]=brst_t1[i];
	}
		printf("\nProcess ID\tBrst Time\t Turnaround Time\t Waiting Time\n");
	b=j;
    for(i=0,total=0;b!=0;) 
    { 
    	if(var[i]<=4&&var[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for %d units",i+1,var[i]); 
            total=total+var[i]; 
            var[i]=0; 
            counter=1; 
        } 
        else if(var[i]>0) 
        {
			printf("\nProcess[%d] of Queue1 is running for 4 units",i+1); 
            var[i]=var[i]-4; 
            total=total+4; 
        } 
        if(var[i]==0&&counter==1) 
        { 
            b--; 
            printf("\nProcess[%d]\t%d\t%d\t%d",i+1,brst_t1[i],total-arr_time1[i],total-arr_time1[i]-brst_t1[i]);
            average_waiting_time1=average_waiting_time1+total-arr_time1[i]-brst_t1[i]; 
            average_turnaround_time1=average_turnaround_time1+total-arr_time1[i]; 
            counter = 0; 
        } 
        if(i==j-1) 
        {
            i=0; 
        }
        else if(arr_time1[i+1]<=total) 
        {
            i++;
        }
        else 
        {
            i=0;
        }
    } 
    average_waiting_time1=average_waiting_time1/j;
    average_turnaround_time1=average_turnaround_time1/j;
    printf("\nAverage Waiting Time:%f",average_waiting_time1); 
    printf("\nAverage Turnaround Time:%f\n",average_turnaround_time1); 
}

void PRIORITY()

{
	for(i=0;i<s;i++)
    {
        pos=i;
        for(p=i+1;p<s;p++)
        {
            if(priority[p]<priority[pos])
            {
                pos=p;
            }
        }
        var1=priority[i];
        priority[i]=priority[pos];
        priority[pos]=var1; 
        
        var1=brst_t2[i];
        brst_t2[i]=brst_t2[pos];
        brst_t2[pos]=var1;
        
        var1=process[i];
        process[i]=process[pos];
        process[pos]=var1;
    }
    waiting_time2[0]=0;
    for(i=1;i<s;i++)
    {
        waiting_time2[i]=0;
        for(p=0;p<i;p++)
        {
            waiting_time2[i]=waiting_time2[i]+brst_t2[j];
        }
        sum=sum+waiting_time2[i];
    }
    average_waiting_time2=sum/s;
    sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<s;i++)
    {
    	turnaround_time2[i]=brst_t2[i]+waiting_time2[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",process[i],brst_t2[i],waiting_time2[i],turnaround_time2[i]);
    }
    average_turnaround_time2=sum/s;
    printf("\nAverage Waiting Time:\t%f",average_waiting_time2);
    printf("\nAverage Turnaround Time:\t%f\n",average_turnaround_time2);
    
    for(i=0;i<s;i++)
    {
    	while(brst_t2[i]!=0)
    	{
    		if(brst_t2[i]>10)
    		{
				printf("\nProcess[%d] of Queue2 is running for 10 units",i+1);
				brst_t2[i]=brst_t2[i]-10;
			}
			else if(brst_t2[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,brst_t2[i]);
				brst_t2[i]=0;
			}
		}
	}

}
void FIRST_COME_FIRST_SERVE()
{

	waiting_time3[0] = 0;   
    for(i=m;i<m;i++)
    {
        waiting_time3[i] = 0;
        for(q=0;q<m;q++)
        {
            waiting_time3[i]=waiting_time3[i]+brst_t3[q];
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<m;i++)
    {
        turnaround_time3[i]=brst_t3[i]+waiting_time3[i];
        average_waiting_time3=average_waiting_time3+waiting_time3[i];
        average_turnaround_time3=average_turnaround_time3+turnaround_time3[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,brst_t3[i],waiting_time3[i],turnaround_time3[i]);
    }
    average_waiting_time3=average_waiting_time3/m;
    average_turnaround_time3=average_turnaround_time3/m;
    printf("\nAverage Waiting Time=%f",average_waiting_time3);
    printf("\nAverage Turnaround Time=%f",average_turnaround_time3);
    for(i=0;i<m;i++)
    {
    	while(brst_t3[i]!=0)
    	{
    		if(brst_t3[i]>10)
    		{
				printf("\nProcess[%d] of Queue3 is running for 10 units",i+1);
				brst_t3[i]=brst_t3[i]-10;
			}
			else if(brst_t3[i]<=10)
			{
				printf("\nProcess[%d] of Queue2 is running for %d units",i+1,brst_t3[i]);
				brst_t3[i]=0;
			}
		}
	}
}
void ROUND_ROBIN1()
{
	printf("Time Quantum between the 3 queues is 10\n");
	for(i=1;i<Total;i=i+10)
	{
		if(t1>10)
		{
			printf("Queue1 is running for 10 units\n");
			t1=t1-10;
		}
		else if(t1<=10&&t1!=0)
		{
			printf("Queue1 is running for %d units\n",t1);
			t1=0;
		}
		if(t2>10)
		{
			printf("Queue2 is running for 10 units\n");
			t2=t2-10;
		}
		else if(t2<=10&&t2!=0)
		{
			printf("Queue2 is running for %d units\n",t2);
			t2=0;
		}
		if(t3>10)
		{
			printf("Queue3 is running for 10 units\n");
			t3=t3-10;
		}
		else if(t3<=10&&t3!=0)
		{
			printf("Queue3 is running for %d units\n",t3);
			t3=0;
		}
	}
}
int main()
{
	printf("ENTER THE NUMBER OF PROCESSES\n");
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		printf("ENTER THE DETAILS OF THE PROCESSES[%d]\n",i+1);
		printf("ARRIVAL TIME:");
		scanf("%d",&at[i]);
		printf("BURST TIME:");
		scanf("%d",&bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d",&pr[i]);
		Total=Total+bt[i];
	}
	for(i=0;i<a;i++)
	{
		if(pr[i]>=1&&pr[i]<=5)
		{
			printf("\n\nProcess[%d] belongs to Queue 1\n",i+1);
			arr_time1[j]=at[i];
			brst_t1[j]=bt[i];
			j++;
			t1=t1+bt[i];
		}
		
		else if(pr[i]>=6&&pr[i]<=10)
		{
			printf("PROCESSES[%d] BELONGS TO QUEUE 2\n",i+1);
			arr_time2[s]=at[i];
			brst_t2[s]=bt[i];
			priority[s]=pr[i];
			process[s]=s+1;
			s++;
			t2=t2+bt[i];
		}
		
		else if(pr[i]>=11&&pr[i]<=15)
		{
			printf("PROCESSES[%d] BELONGS TO QUEUE 3\n\n\n\n",i+1);
			arr_time3[m]=at[i];
			brst_t3[m]=bt[i];
			m++;
			t3=t3+bt[i];
		}
	}
	
    ROUND_ROBIN1();
	ROUND_ROBIN();
	FIRST_COME_FIRST_SERVE();
	PRIORITY();
	
	return 0;
}


