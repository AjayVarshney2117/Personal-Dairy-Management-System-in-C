/********************************************************

Project : Personal Diary Management System
Made by Ajay Varshney (2000290120016)
		B.Tech 2nd year student

********************************************************/

//Requird Headers
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "headers/DateTime.h"	// User....
#include "headers/Admin.h"		// Made....
#include "headers/Entry.h"		// Headers.

//Global Variables
char typeUser[20];
char realUser[20];
char typePass[5];
char realPass[5];

//Functions Declarations
void menu();
void search();

void main()
{	
	int start;
	
	//Starting Functions and Values
	readPass();
	
	//Password screen and MAIN MENU
	start = takingPass("WELCOME TO PERSONAL DIARY");
	if(start)
	{
		menu();
	}
}

//Function which will Show MAIN MENU
void menu()
{
	Entry e;
	char x;
	
	_menu:
	system("cls");
	printf("***PERSONAL DIARY MANAGEMENT SYSTEM***\n");
	printf("***********BY AJAY VARSHNEY***********\n");
	printf("\n\t    Hello, %s", realUser);
	printf("\n************MAIN MENU*****************\n");
	printf("\n\t[1] ADD ENTRY");
	printf("\n\t[2] SEARCH ENTRY");
	printf("\n\t[3] SHOW ALL ENTRY");
	printf("\n\t[4] CHANGE PASSWORD");
	printf("\n\t[5] EXIT");
	
	here:
	x = getch();
	
	switch(x)
	{
		case '1':
			system("cls");
			printf("************ADD ENTRY*****************\n\n");
			TakeEntry(&e);
			goto _menu;
			
		case '2':
			search();
			goto _menu;
			
		case'3':
			ShowAllEntry();
			goto _menu;
		
		case '4':
			changePass();
			goto _menu;
			
		case '5':
			break;
			
		default :
			printf("\n\nYOU TYPED : %c", x);
			printf("\nWRONG INPUT.....TRY AGAIN...");
			goto here;
			break;
	}
}

void search()
{
	Date d;
	
	system("cls");
	
	printf("**************SEARCH ENTRY**************\n\n");
	
	printf("Enter the date : ");
	TakeDate(&d);
	
	printf("\n--------------------------------------\n");
	
	SearchEntry(d);
	
	getch();
}
