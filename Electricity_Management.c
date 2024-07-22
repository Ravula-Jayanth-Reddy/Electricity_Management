#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
	long unsrno;
	long serno;
	char name[100];
	char hmno[100];
	char street[100];
	char village[100];
	char town[100];
	char feedback[1000];
	int fb;
	long units;
	int pay;
	struct Node *prev;
	struct Node *next; 
};
struct Node *start;
struct Node *temp,*newnode,*ptr;
int h;
	long a=16362700;
	long b=1231409800;
void bill();
void newenrol();
void terminate();
void feedback();
void viewfeedback();
void create();
void reading();
void connections();
void employee();
void main()
{
	int id,ch;
	system("cls");
	printf("\n\t----------------------------------");
	printf("\n\t----------------------------------");
	printf("\n\t [1].NEW CONNECTION ENROLLMENT");
	printf("\n\t [2].TERMINATE CURRENT CONNECTION");
	printf("\n\t [3].PAYMENT AND BILLING");
	printf("\n\t [4].FEEDBACK");
	printf("\n\t [5].EMPLOYEE");
	printf("\n\t [6].EXIT");
	printf("\n\t----------------------------------");
	while(1){
		printf("\n\t Make your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				newenrol();
				break;
			case 2:
				terminate();
				break;
			case 3:
				bill();
				break;
			case 4:
				feedback();
				break;
			case 5:
				printf("\nPLEASE ENTER YOUR EMPLOYEE ID:");
				scanf("%d",&id);
				if(id==1435){
				employee();
				}
				else{
					printf("\nERROR! INVALID EMLOYEE ID");
				}
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\n Invalid choice");
				break;
		}
}
}
void create()
{
	struct Node *newnode,*temp;
	int total,index,item,h;
	system("cls");
	if(start==NULL)
	{	
		printf("\n Enter no.of connections:");
		scanf("%d",&total);
		if(total<=0)
		{
		printf("\n Total no.of connections need to be Positive");
		}
		else
		{
			temp = (struct Node*)malloc(sizeof(struct Node));
			printf("\n Enter the person details:");
			printf("\n NAME:");
			scanf("%s",temp->name);
			printf(" HOUSE NO:");
			scanf("%s",temp->hmno);
			printf(" STREET:");
			scanf("%s",temp->street);
			printf(" VILLAGE:");
			scanf("%s",temp->village);
			printf(" SUB-STATION:");
			scanf("%s",temp->town);
			printf(" UNIQUE SERVICE NO:");
			scanf("%ld",temp->unsrno);
			printf(" SERVICE NO:");
			scanf("%ld",temp->serno);
			temp->pay=1;
			temp->fb=0;
			temp->prev=NULL;
			temp->next=NULL;
			start = temp;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\nUNIQUE SERVICE NO (USCNO):%ld",temp->unsrno);
			printf("\nSERVICE NO (SCNO)	:%ld",temp->serno);
			for(index=2;index<=total;index++)
			{
				newnode = (struct Node*)malloc(sizeof(struct Node));
			printf("\n Enter the person details:");
			printf("\n NAME:");
			scanf("%s",newnode->name);
			printf(" HOUSE NO:");
			scanf("%s",newnode->hmno);
			printf(" STREET:");
			scanf("%s",newnode->street);
			printf(" VILLAGE:");
			scanf("%s",newnode->village);
			printf(" SUB-STATION:");
			scanf("%s",newnode->town);
			printf(" UNIQUE SERVICE NO:");
			scanf("%ld",newnode->unsrno);
			printf(" SERVICE NO:");
			scanf("%ld",newnode->serno);
			newnode->pay=1;
			newnode->fb=0;
				newnode->next = NULL;
				newnode->prev=temp;
				temp->next = newnode;
				temp=newnode;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\nUNIQUE SERVICE NO (USCNO):%ld",newnode->unsrno);
			printf("\nSERVICE NO (SCNO)	:%ld",newnode->serno);
			}
		}
	}
	else
	{
		printf("\n CONNECTIONS ALREADY REGISTERED");
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		employee();
	}
}
void bill()
{
	struct Node *temp;
	long int us;
	float bill;
	int a,i;
	if(start==NULL)
	{
	  printf("\n error! no enrolled connections");	
	}
	else
	{
		printf("ENTER YOUR UNIQUE SERVICE NUMBER:");
		scanf("%ld",&us);
		temp=start;
		system("cls");
		while(temp!=NULL)
		{
			if(us==temp->unsrno){
				if(temp->pay==0){
				if(temp->units<200){
					bill=temp->units*1.20;
				}
				else if(temp->units>=200||temp->units<500){
					bill=temp->units*1.50;
				}
				else{
					bill=temp->units*2;
				}
				printf("	       TSNPDCL					");
				printf("\n----------------------------------");
				      printf("\nUSCNO     :%ld",temp->unsrno);
				printf("\nNAME      :%s",temp->name);
				printf("\nSCNO      :%ld",temp->serno);
				printf("\nADDR      :%s",temp->hmno);
				printf("\nSUB STN   :%s",temp->town);
				printf("\n----------------------------------");
				printf("\nNO.OF UNITS        :%ld",temp->units);
				printf("\nENERGY CHARGES     :%f",bill);
				printf("\nFIXED CHARGES      :20");
				printf("\nCUST CHARGES       :40");
				printf("\nTOTAL BILL		 :%f",bill+60);
				printf("\n----------------------------------");
				printf("\n1.PAY NOW\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
					printf("\n BILL PAID SUCCESSFULLY");
					temp->pay=1;
				}
			}
			else{
				printf("\n BILL IS ALREADY PAID \n NO NEW BILL AS OF NOW");
			}	
		}
			temp=temp->next;
		}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		main();
	}
	}
}
void newenrol()
{
	struct Node *temp;
	struct Node *newnode;
	int item;
	newnode=(struct Node *)malloc(sizeof(struct Node));
        	newnode->unsrno=a;
			newnode->serno=b;
		printf("\n PLEASE FILL THE FOLLOWING DETAILS FOR NEW CONNECTION:");
	    	printf("\n NAME:");
			scanf("\n");
	   	    scanf("%[^\n]%*c",newnode->name);
			printf(" HOUSE NO:");
			scanf("%s",newnode->hmno);
			printf(" STREET:");
			scanf("\n");
			scanf("%[^\n]%*c",newnode->street);
			printf(" VILLAGE:");
			scanf("\n");
			scanf("%[^\n]%*c",newnode->village);
			printf(" SUB-STATION:");
			scanf("\n");
			scanf("%[^\n]%*c",newnode->town);
			newnode->pay=1;
			newnode->fb=0;
		newnode->next=NULL;
		newnode->prev=NULL;
	if(start==NULL){
	start=newnode;
	 newnode->unsrno=newnode->unsrno+1;
			newnode->serno=newnode->serno+1;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\nUNIQUE SERVICE NO (USCNO):%ld",newnode->unsrno);
			printf("\nSERVICE NO (SCNO)        :%ld",newnode->serno);
			a++;
			b++;
		}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
		    newnode->unsrno=newnode->unsrno+1;
			newnode->serno=newnode->serno+1;
			printf("\nCONNECTION SUCCESSFULLY REGISTERED WITH-");
			printf("\nUNIQUE SERVICE NO (USCNO):%ld",newnode->unsrno);
			printf("\nSERVICE NO (SCNO)        :%ld",newnode->serno);
			a++;
			b++;
	}
}
void terminate()
{
	int loc=1,count=1,i=0,h,a;
	long us;
	system("cls");
	if(start==NULL)
	{
	  printf("\n error! no enrolled connections");
	}
	else
	{
		printf("ENTER YOUR UNIQUE SERVICE NUMBER:");
		scanf("%ld",&us);
		temp=start;
		while(temp!=NULL)
		{
 			i++;
			temp=temp->next;
		}
		temp=start;
	while(temp!=NULL)
		{
			if(us==temp->unsrno){
				break;
			}
 			loc++;
			temp=temp->next;
		}
		if(loc==1){
		if(start->next==NULL)
		{
				printf("\n1.CONIFIRM DELETE\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
			printf("\n THE CONECTION WITH UNIQUE SERVICE NO %ld IS DELETED",start->unsrno);
			start=NULL;
		}
		}
		else{
				printf("\n1.PAY NOW\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
		temp=start;
		printf("\n THE CONECTION WITH UNIQUE SERVICE NO %ld IS DELETED",start->unsrno);
		//start = temp->next;
		start = start->next;
		start->prev=NULL;
	    free(temp);	
	    }
		}
		}
		else if(loc==i&&loc!=1){
				printf("\n1.PAY NOW\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
		temp=start;
		while(temp->next!=NULL)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=NULL;
		printf("\n THE CONECTION WITH UNIQUE SERVICE NO %ld IS DELETED",temp->unsrno);
		free(temp);
	    }
		}
		else{
			temp=start;
		   while(temp!=NULL&&count!=loc)
		    {
			   ptr=temp;
			    temp=temp->next;
			    count++;
		    }
		    if(temp==NULL)
		    {
		    	printf("\n NO CONNECTION IS PRESENT");
			}
			else
			{	
			    printf("\n1.PAY NOW\n2.SKIP\n");
				scanf("%d",&a);
				if(a==1){
					for(i=0;i<7;i++){
						printf(".\t");
						sleep(1);
					}
				ptr->next=temp->next;
				printf("\n THE CONECTION WITH UNIQUE SERVICE NO %d IS DELETED",temp->unsrno);
				free(temp);
			}
			}
		}
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		main();
	}
}
void feedback(){
	long us;
	system("cls");
	printf("\n ENTER YOUR UNIQUE SERVICE NO:");
	scanf("%ld",&us);
	temp=start;
	while(temp!=NULL){
	if(us==temp->unsrno){
	printf("ENTER YOUR FEEDBACK:");
    scanf("\n");
	scanf("%[^\n]%*c", temp->feedback);
	temp->fb=1;
	printf("\nTHANK YOU FOR YOUR FEEDBACK");
		}
		temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		main();
	}
}
void employee(){
	int ch;
		system("cls");
		printf("\n1.VIEW CONNECTIONS");
		printf("\n2.ENTER THE BILLS");
		printf("\n3. VIEW FEEDBACKS");
		printf("\n4.MAIN MENU");
		while(1){
			printf("\n enter your choice:");
			scanf("%d",&ch);
			switch(ch){
				case 1:
					connections();
					break;
				case 2:
					reading();
					break;
				case 3:
					viewfeedback();
					break;
				case 4:
					main();
					break;
			    case 9:
					create();
					break;
				default:printf("\n INVALID CHOICE");
			}
		}
}
void reading(){
	struct Node *temp;
	temp=start;
	if(temp==NULL){
		printf("NO CONNECTIONS ENROLLED");
	}
	else{
		system("cls");
	while(temp!=NULL){
		printf("ENTER NO.OF UNITS USED BY UNIQUE SERVICE NO %d:",temp->unsrno);
		scanf("%ld",&temp->units);
		temp->pay=0;
		temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		employee();
	}
}
}
void connections(){
	int i=1;
	float bill;
	temp=start;
	system("cls");
	printf("\n S.NO    NAME          UNSCNO         BILL AMOUNT         PAYMENT ");
	while(temp!=NULL){
		if(temp->units<200){
					bill=temp->units*1.20+60;
				}
				else if(temp->units>=200||temp->units<500){
					bill=temp->units*1.50+60;
				}
				else{
					bill=temp->units*2+60;
				}
	if(temp->pay==1){
	printf("\n %d      %s         %ld        %f             PAID",i,temp->name,temp->unsrno,bill);
	}
	else{
	printf("\n %d      %s         %ld        %f             NOT PAID",i,temp->name,temp->unsrno,bill);
	}
    temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		employee();
	}
}
void viewfeedback(){
	temp=start;
	system("cls");
	while(temp!=NULL){
		if(temp->fb==1){
			printf("\nUSCNO: %ld\n FEEDBACK: %s",temp->unsrno,temp->feedback);
		}
		temp=temp->next;
	}
	printf("\n PRESS 1 TO GO BACK");
	scanf("%d",&h);
	if(h==1){
		employee();
	}
}
