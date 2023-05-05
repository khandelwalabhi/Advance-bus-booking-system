#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buses[10][300] = {"The Vantare Express", "Country Coach Express", "Unicat Amerigo Express", "Monaco dynasty Express", "Newmar King Express"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int num1[32] = {0};
int busNo;

void bus();//for list of bus
void booking();//for booking the tickets
void name_number(int booking, char numstr[100]); //for adding passenger details in the file
int read_number(int busNo);//for reading the number from the file
void read_name(int busNo);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int busNo);//for printing the status while booking ticket
void cancel(); //for canceling the bookings.
void login(); //for login into the system


int main()
{
	login();
	int num;
	do {
		system("cls");
		printf("\n\n\n");
		printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
		printf("\t\t\t\t\t[1]=> View Bus List\n");
		printf("\n");
		printf("\t\t\t\t\t[2]=> Book Tickets\n");
		printf("\n");
		printf("\t\t\t\t\t[3]=> cancel Booking\n");
		printf("\n");
		printf("\t\t\t\t\t[4]=> Bus Status Board\n");
		printf("\n");
		printf("\t\t\t\t\t[5]=> Exit\n\n");
		printf("===============================================================================================================\n\n");
		printf("\t\t\tEnter Your Choice:: ");
		scanf("%d", &num);
		switch (num) {
		case 1:
			bus();//for list of bus
			break;
		case 2:
			booking();//for booking the tickets
			break;
		case 3:
			cancel();
			break;
		case 4:
			status();
			break;
		}
		getch(); //for getting an char from screen
	} while (num != 5);
	system("CLS"); //for clean the screen
	printf("\t----------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\tThank You For Using Our System\t\t\t\t\t\t\n");
	printf("\t----------------------------------------------------------------------------------------------------------\n");
	getch();  //holds the screen
	return 0;
}

//for list of bus
void bus()
{
	system("cls"); //for clean the screen
	printf("\n\n\n");
	printf("=========================================== ADVANCE BUS BOOKING SYSTEM ============================================\n\n\n");
	printf("\t\t\t\t\t[1]  =>  %s\n", buses[0]);
	printf("\n");
	printf("\t\t\t\t\t[2]  =>  %s\n", buses[1]);
	printf("\n");
	printf("\t\t\t\t\t[3]  =>  %s\n", buses[2]);
	printf("\n");
	printf("\t\t\t\t\t[4]  =>  %s\n", buses[3]);
	printf("\n");
	printf("\t\t\t\t\t[5]  =>  %s\n", buses[4]);
}

//for booking the tickets
void booking()
{
	int i = 0;
	char numstr[100]; //for bus number
	system("cls");
	printf("=========================================== ADVANCE BUS BOOKING SYSTEM ============================================\n\n\n");//for entering train number
	bus(); //for seeing train least
	printf("Enter the Bus number:--->");
	scanf("%d", &busNo);
	system("cls");
	printf("=========================================== ADVANCE BUS BOOKING SYSTEM ============================================\n\n\n");//for selecting coach
	printf("Your Bus Number is %d ********** %s", busNo, buses[busNo - 1]);
	status_1(busNo);
	FILE *f1, *fopen(); //for reading the seats from the user.
	char str1[80] = "32";
	int seat1, seat2, booking = 0;
	if (busNo == 1){
		f1 = fopen("tr1.txt", "r+");
		fgets(str1, 80, f1);  //reads a text line from the file
		fclose(f1);
	} 
	else if (busNo == 2){
		f1 = fopen("tr2.txt", "r+");
		fgets(str1, 80, f1);
		fclose(f1);
	} 
	else if (busNo == 3){
		f1 = fopen("tr3.txt", "r+");
		fgets(str1, 80, f1);
		fclose(f1);
	}
	else if (busNo == 4){
		f1 = fopen("tr4.txt", "r+");
		fgets(str1, 80, f1);
		fclose(f1);
	}
	else if (busNo == 5){
		f1 = fopen("tr5.txt", "r+");
		fgets(str1, 80, f1);
		fclose(f1);
	}
	seat1 = atoi(str1); //covert the string into number
	if (seat1 <= 0){
		printf("There is no blank seat in this bus ");
	} 
	else{
		printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n", seat1);
		printf("\n\t\t\t\tNumber of Tickets:----->");
		scanf("%d", &booking);
		printf("\n");

		seat1 = seat1 - booking;
		itoa(busNo, numstr, 10);  //convert this integer to string
		name_number(booking, numstr);
		
		printf("\n\t\t\t\tThe Total booking amount is %d", 150 * booking);
		itoa(seat1, str1, 10);
		
		//for reading the seats from the user.
		if (busNo == 1)
		{
			f1 = fopen("tr1.txt", "w"); //open file in write mode and put reamaning seats
			fputs(str1, f1);
			fclose(f1);
		}
		else if (busNo == 2)
		{
			f1 = fopen("tr2.txt", "w");
			fputs(str1, f1);
			fclose(f1);
		}
		else if (busNo == 3)
		{
			f1 = fopen("tr3.txt", "w");
			fputs(str1, f1);
			fclose(f1);
		}
		else if (busNo == 4)
		{
			f1 = fopen("tr4.txt", "w");
			fputs(str1, f1);
			fclose(f1);
		}
		else if (busNo == 5)
		{
			f1 = fopen("tr5.txt", "w");
			fputs(str1, f1);
			fclose(f1);
		}
	}
}


//for adding passenger details in the file
void name_number(int booking, char numstr[100])
{
	char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
	int number;
	FILE *a, *b;
	int i = 0;
	strcat(numstr, ".txt");
	strcat(tempstr1, numstr);
	strcat(tempstr2, numstr);
	a = fopen(tempstr1, "a"); //for open the file to write the name in the file
	b = fopen(tempstr2, "a"); //for open the file for writing the number in the file
	for (i = 0; i < booking; i++) //for entering the person name and seat number in the file
	{
		printf("============================Enter the details for ticket no %d============================\n\n\n", i + 1);
		printf("\t\t\t\tEnter the seat number:--->");
		scanf("%d", &number);
		printf("\t\t\t\tEnter the name of person:--->");
		scanf("%s", name[number - 1]);
		printf("\n======================================================================================================\n\n");
		printf("\n");
		itoa(number, tempstr, 10);
		fprintf(a, "%s ", name[number - 1]);
		fprintf(b, "%s ", tempstr);

	}
	fclose(a);
	fclose(b);
}


//for reading the number from the file
int read_number(int busNo)
{
	char tempstr[100], tempstr2[12] = "number";
	FILE *a;
	char numstr[100];
	int i = 0, j = 0, k;
	itoa(busNo, numstr, 10);
	strcat(numstr, ".txt");
	strcat(tempstr2, numstr);
	a = fopen(tempstr2, "a+"); //for open the file to write the name in the file open file in apend mode
	//runing a while loop till end of the file
	while (!feof(a))
	{
		number[i][j] = fgetc(a); //get an character from the file
		//if the char is blank then we encouter a new word so increse i and set j is equal to zero
		if (number[i][j] == ' ')
		{
			j = 0;
			i++;
		}
		else
		{
			j++;
		}
	}
	k = i;
	for (i = 0; i < k; i++)
	{
		num1[i] = atoi(number[i]);
	}
	fclose(a);
	return k;
}

//for reading the name from the file
void read_name(int busNo)
{
	char tempstr1[12] = "status";
	FILE *b;
	char numstr[100];
	int i = 0, j = 0, k = 0;
	itoa(busNo, numstr, 10);
	strcat(numstr, ".txt");
	strcat(tempstr1, numstr);
	b = fopen(tempstr1, "a+"); //for open the file to write the name in the file
	while (!feof(b))
	{
		name[i][j] = fgetc(b);
		if (name[i][j] == ' ')
		{
			j = 0;
			i++;
		}
		else
		{
			j++;
		}
	}
	name[i][j] = '\0'; //for the termination
	k = i;
	fclose(b);
}

//for printing the status by user input
void status()
{
	system("cls");
	printf("=========================================== ADVANCE BUS BOOKING SYSTEM ============================================\n\n\n");
	int i, busNo, index = 0, j;
	printf("Enter the number of bus:---->");
	scanf("%d", &busNo);
	j = read_number(busNo);
	read_name(busNo);
	printf("____________________________________________________________________________________________________________________\n");
	printf("                                      Bus.no-->%d---->%s                                                            \n", busNo, buses[busNo - 1]);
	printf("____________________________________________________________________________________________________________________\n");
	char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
	for (i = 0; i < j; i++)
	{
		strcpy(tempname[num1[i]], name[i]);  //Copying The  names in this 2-d array
	}
	for (i = 0; i < 8; i++)
	{
		printf("\t\t\t\t");
		for (j = 0; j < 4; j++)
		{
			printf("%d.%s\t", index + 1, tempname[index + 1]);
			index++;
		}
		printf("\n");
	}
}

//for printing the status while booking ticket
void status_1(int busNo)
{
	printf("Your Bus Number is %d ********** %s", busNo, buses[busNo - 1]);
	system("cls");
	printf("=========================================== ADVANCE BUS BOOKING SYSTEM ============================================\n\n\n");
	int i, index = 0, j;
	j = read_number(busNo);
	read_name(busNo);
	char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
	for (i = 0; i < j; i++)
	{
		strcpy(tempname[num1[i]], name[i]);
	}
	for (i = 0; i < 8; i++)
	{
		printf("\t\t\t\t");
		for (j = 0; j < 4; j++)
		{
			printf("%d.%s\t", index + 1, tempname[index + 1]);
			index++;
		}
		printf("\n");
	}
}

//for canceling the bookings.
void cancel()
{
	int seat_no, i, j;
	char numstr[100], tempstr1[15] = "status",tempstr2[15] = "number";
	printf("Enter the bus number:---->");
	scanf("%d", &busNo);
	itoa(busNo, numstr, 10);
	strcat(numstr, ".txt");
	strcat(tempstr1, numstr);
	strcat(tempstr2, numstr);
	read_number(busNo);
	read_name(busNo);
	status_1(busNo);
	printf("Enter the seat number:--->");
	scanf("%d", &seat_no);
	FILE *a, *b;
	a = fopen(tempstr1, "w+");
	b = fopen(tempstr2, "w+");
	for (i = 0; i < 32; i++)
	{
		if (num1[i] == seat_no)
		{
			for (j = 0; j < 32; j++)
			{
				if (num1[j] != seat_no && num1[j] != 0)
				{
					fprintf(b, "%d ", num1[j]);
					fprintf(a, "%s", name[j]);
				}
				else if (num1[j] == seat_no && num1[j] != 0)
				{
					strcpy(name[j], "Empty ");
				}
			}
		}
	}
	fclose(a);
	fclose(b);
	printf("\n\n");
	printf("======================================================================================================\n");
	printf("\t\t\t\tYour 150 rupees has been Returned\t\t\t\n");
	printf("======================================================================================================\n");
}

//for login into the system
void login()
{
	int count = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "busbook";
	char pass[10] = "busbook";
	do
	{
		system("cls");

		printf("\n  =========================  LOGIN FORM  =========================  ");
		printf(" \n                       ENTER USERNAME:-");
		scanf("%s", &uname);
		printf(" \n                       ENTER PASSWORD:-");
		while (i < 10)
		{
			pword[i] = getch();
			c = pword[i];
			if (c == 13) break;
			else printf("*");
			i++;
		}
		pword[i] = '\0';
		//char code=pword;
		i = 0;
		//scanf("%s",&pword);
		if (strcmp(uname, "busbook") == 0 && strcmp(pword, "busbook") == 0)
		{
			printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
			printf("\n\n\n\t\t\t\tPress any key to continue...");
			getch();//holds the screen
			break;
		}
		else
		{
			printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
			count++;
			getch();//holds the screen
		}
	}
	while (count <= 3);
	if (count > 3)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
	}
	system("cls");
}
