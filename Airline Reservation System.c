#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ticket{
	int age;
	char name[20];
	int seats[2];
	int timing;
}tp[10];
	int sum;
	
struct places{
	int from_to;
}pl;
	
struct trdatetime{
	int date;
	int month;
	int year;
	int todate;
	int tomonth;
	int toyear;
	int price;
	int time;
}trd;

int login(){
	int n;
	printf("\n\t\t1. Login\n\t\t2. Exit\n\tEnter your choice: ");
	scanf("%d",&n);
	if(n==2)
	   exit(0);
	printf("\n\n\t\tAIRTICKET LOGIN\n");
	char username[100],password[100];
    char a[]="picproject";
    char b[]="hello123";
    printf("\tUsername: ");
    scanf("%s",username);
    printf("\tPassword: ");  
    scanf("%s",password);
    
    if(strcmp(username,a)==0 && strcmp(password,b)==0){
        printf("\n\t\tlogin access granted. PROCEED\n");
        printf("\n\t#####################################################################################################\n\n");
    } else {
    	printf("\n\t\tInvalid credentials. Please try again\n\n");
    	return login();
	}
	printf("\n\n\t\tPress enter to display list of routes\n\n");
	getch();
}

int fromto(){
	printf("\n\t\tList of routes: \n\n");
    printf("\t1. Bangalore   -->  Hyderabad\n");
    printf("\t2. New Delhi   -->  Mumbai\n");
    printf("\t3. Kolkata     -->  Shimla\n");
    printf("\t4. Ahmedabad   -->  Chandigarh\n");
    printf("\t5. Bhopal      -->  Guwahati\n");
    printf("\t6. Bhubaneswar -->  Lucknow\n");
    printf("\t7. Kochi       -->  Chennai\n");
    printf("\n\t\tSelect the route: ");
    scanf("%d",&pl.from_to);
    if(pl.from_to<1 || pl.from_to>7){
        printf("\n\t\tInvalid Selection. Please select valid option\n");
        return fromto();
    }
    printf("\n\n\t\tPress enter to go to date selection\n\n");
	getch();
}

void date(){
	printf("\n\n\t######################################################################################################\n\n");
    printf("\n\t\tEnter today's date in the format dd-mm-yyyy:            ");
    scanf("%d-%d-%d",&trd.todate,&trd.tomonth,&trd.toyear);
    printf("\n\t\tEnter the date of travelling in the format dd-mm-yyyy:  ");
    scanf("%d-%d-%d",&trd.date,&trd.month,&trd.year);
    if(trd.date-trd.todate + 30*(trd.month-trd.tomonth) + 365*(trd.year-trd.toyear) < 12){
    	trd.price=1500;
	} else trd.price=100;
	printf("\n\n\t\tPress enter to go to display schedules\n\n");
	getch();
}

int time(){	
    printf("\n\n\n\t######################################################################################################\n\n");
    printf("\t\tSelect the time of departure:\n\n");
    printf("\t1. 02.30\n");
    printf("\t2. 06.00\n");
    printf("\t3. 09.30\n");
    printf("\t4. 13.00\n");
    printf("\t5. 16.30\n");
    printf("\t6. 20.00\n");
    printf("\t7. 23.15\n");
    printf("\t\tEnter your choice: ");  
    scanf("%d",&trd.time);
    if(trd.time>7)
       return time();
       
    printf("\n\n\t######################################################################################################\n\n");
    
	printf("\n\n\t\tPress enter to go to input passenger(s)' details\n\n");
	getch();
}

void ticketbooking(int p){
	
	for(int i=0;i<p;i++){
		printf("\tEnter passenger %d name: ",i+1);
		scanf("%s",tp[i].name);
		printf("\tEnter passenger %d age: ",i+1);
		scanf("%d",&tp[i].age);
	}
	printf("\t######################################################################################################\n\n\n");
	
	printf("\t\tSeats marked 'x' are booked \n\t\tSeats marked 'A' are available \n\n");
	
	printf("\tPlease choose %d seat(s)\n\n",p);
	printf("\t    0 1 2   3 4 5 6   7 8 9 \n");
	for(int i=0;i<21;i++){
		for(int j=0;j<12;j++){
			if(j==0){
				if(i>=10){
					printf("\t%d  ",i);
				} else printf("\t%d   ",i);
			}
			if(j==3 || j==8){
				printf("  ");
			} else if(i==5 || i>=7&&i<=10&&j>=0&&j<=4 || j==5&&i<16 || j==11&&i>9&&i<13) {
				printf("A ");
			} else {
				printf("x ");
			}
		}
		printf("\n");
	}
	printf("\t\tSelect the seats using coordinates (row no. <space> column no.):\n");
	int a[p],b[p];
	for(int i=0;i<p;i++){
		printf("\tCoordinates of seat %d: ",i+1);
		scanf("%d%d",&a[i],&b[i]);
		tp[i].seats[0]=a[i];
		tp[i].seats[1]=b[i];
		if(b[i]>=7)
		    b[i]+=2;
		if(b[i]>=3 && b[i]<=6)
		    b[i]+=1;
		if(a[i]==5 || a[i]>=7&&a[i]<=10&&b[i]>=0&&b[i]<=4 || b[i]==5&&a[i]<16 || b[i]==11&&a[i]>9&&a[i]<13){
			printf("\tseat chosen\n\n");
		} else {
			printf("\tseat unavailable, rechoose the seat\n\n");
			i--;
		}
	}
	
	printf("\n\n\t\tPress enter to go to display selected seeats\n\n");
	getch();
	
	int k=0;
	printf("\tSelected seats are marked 'B'\n\n");
	printf("\t\t    0 1 2   3 4 5 6   7 8 9 \n");
	for(int i=0;i<21;i++){
		for(int j=0;j<12;j++){
			if(j==0){
				if(i>=10){
					printf("\t\t%d  ",i);
				} else printf("\t\t%d   ",i);
			}
			if(j==3 || j==8){
				printf("  ");
			} else if(a[k]==i && b[k]==j){
				printf("B ");
				k++;
			} else {
				printf("x ");
			}
		}
		printf("\n");
	}
	printf("\n\n\t\tPress enter to go to payment\n");
	getch();
	
}

int payment(int p){
	printf("\n\t#####################################################################################################\n\n");
	int a;
	switch(pl.from_to){
		case 1:trd.price+=4250;
		  break;
		case 2:trd.price+=6000;
		  break;
		case 3:trd.price+=4750;
		  break;
		case 4:trd.price+=4000;
		  break;
		case 5:trd.price+=6500;
		  break;
		case 6:trd.price+=5250;
		  break;
		case 7:trd.price+=3500;
		  break;
	}
	sum=trd.price*p;
	printf("\n\tTotal amount: INR %d/- \n\n",sum);
	printf("\n\t1.Debit card\n\t2.Credit card\n\t3.Online\nChoose type of payment:  ");
	scanf("%d",&a);
	switch(a){
		case 1: printf("\t\tpayment successful through debit card\n\n");
		        break;
		case 2: printf("\t\tpayment successful through credit card\n\n");
		        break;
		case 3: printf("\t\tpayment successful through online banking\n\n");
		        break;
		default: printf("\t\tinvalid payment option. Please choose valid option\n");
		         return payment(p); 
	}
}

void ticketprinting(int p){
	printf("\n\tTicket booked successfully.\n\n\n");
	printf("\n\n\t\tPress enter to go to print the Ticket\n\n");
	getch();
	//char c;
	printf("\t#####################################################################################################\n\n\n");
	printf("\t\t\t\t\t\t Airline Ticket \n");
	printf("\n\n\t\tDate: %d-%d-%d",trd.todate,trd.tomonth,trd.toyear);
	printf("\n\n\t\t");
	switch(pl.from_to){
    	case 1:printf("Boarding: Kempegowda Int, Bangalore.\n\t\tDestination: Rajiv Gandhi Int, Hyderabad");
    	  break;
    	case 2:printf("Boarding: Indira Gandhi Int, New Delhi.\n\t\tDestination: Chhatrapati Shivaji Int, Mumbai");
    	  break;
    	case 3:printf("Boarding: Netaji Subhash Chandra Bose Int, Kolkata\n\t\tDestination: Shimla Airport, Shimla");
    	  break;
    	case 4:printf("Boarding: Sardar Vallabhai Patel Int, Ahmedabad\n\t\tDestination: Chandigarh Int, Chandigarh");
    	  break;
    	case 5:printf("Boarding: Raja Bhoj Airport, Bhopal\n\t\tDestination: Lokpriya Gopinath Bordoloi Int, Guwahati");
    	  break;
    	case 6:printf("Boarding: Biju Patnaik Int, Bhubaneswar\n\t\tDestination: Chaudhary Charan Singh Int, Lucknow");
    	  break;
    	case 7:printf("Boarding: Cochin Int, Kochi\n\t\tDestination: Chennai Int, Chennai");
    	  break;
	}
	printf("\n\n\n\t\tBoarding on %d-%d-%d at ",trd.date,trd.month,trd.year);
	switch(trd.time){
		case 1:printf("02.30");
		    break;
		case 2:printf("06.00");
		    break;
		case 3:printf("09.30");
		    break;
		case 4:printf("13.00");
		    break;
		case 5:printf("16.30");
		    break;
		case 6:printf("20.00");
		    break;
		case 7:printf("23.15");
		    break;
	}
	printf("\n\n\n\t\t\t\tPASSENGERS\n\n");
	for(int i=0;i<p;i++){
		printf("\t\t%d. name: %s\t\tage: %d\t\tticket cost: INR %d \t ",i+1,tp[i].name,tp[i].age,trd.price);
		printf("seat number: %d\n\n",9*tp[i].seats[0]+tp[i].seats[1]);
	}
	
	printf("\n\n\t\tPoints to be noted:\n\n");
	printf("\t1. Please check-in 30 minutes before the time of departure.\n");
	printf("\t2. Baggage weight limit is 20kgs per passenger.\n");
	printf("\t3. Do not carry items that are restricted from transportation on planes.\n");
	printf("\t4. Food and snacks can be purchased on board. Complementary meal will be provided\n");
	printf("\n\t\t\t\tHAPPY JOURNEY\n\n\n\n\t\t\t\t\t\tTHANK YOU");
	printf("\n\n\t######################################################################################################\n\n");
}

int main(){
	printf("\n\n\t\t\t\t\tASSIGNMENT PROJECT - Programming in C\n");
	printf("\t\t\t\t\t\t\t2019-20\n");
	printf("\n\n\t\t\t\t\tDone by: Tarun Srivatsa V S & Srihari C");
	printf("\n\t\t\t\t\t Information Science and Engineering\n\t\t\t\t\tR V College of Engineering, Bengaluru\n\n");
	printf("\n\n\t\t\t\t\tWelcome to AIRTICKET BOOKING DESK");
	
	login();
	fromto();
	date();
	time();
	int n;
	
	printf("\n\n\t\tEnter the number of passengers: ");
	scanf("%d",&n);
	ticketbooking(n);
	payment(n);
	ticketprinting(n);
	return 0;
}