//this will store username and password and will be used in main program
extern char typeUser[20];
extern char realUser[20];
extern char typePass[5];
extern char realPass[5];

//This will OverWrite the Username and Password and store it in realUser and realPass respectively
void writePass(char user[], char pass[])
{
	FILE *ofp;
	
	ofp = fopen("files/pass.txt", "w");
	fprintf(ofp, "%s %s ", user, pass);
	fclose(ofp);
}

//This will Read the Username and Password and store it in realUser and realPass respectively
void readPass()
{
	FILE *ifp;
	
	ifp = fopen("files/pass.txt", "r");
	fscanf(ifp, "%s %s ", realUser, realPass);
	fclose(ifp);
}

//This will check username and password
int PassCmp()
{
	if((strcmp(typePass,realPass) == 0) && strcmp(typeUser,realUser) == 0)
		return 1;
	else
		return 0;
}

//Password Screen
int takingPass(char str[])
{
	int x;
	
	do{
		printf("***%s***\n\n", str);
		printf("Username : ");
		scanf("%s", typeUser);
		printf("Password : ");
		scanf("%s", typePass);
		
		x = PassCmp();
		if(x)
		{
			printf("\nAccess GRANTED!!!!!\n\n(^__^)\n\n");
			printf("Press any key to CONTINUE.....");
		}
		else
		{
			printf("\nAccess DENIED!!!!!\n\n(-__-)\n\n");
			printf("Press any key to TRY AGAIN.....");
		}
		getch();
		system("cls");
	}while(!x);
	
	return x;
}

//Changing Password Function
void changePass()
{
	char newPass[5];
	char newUser[20];
	char oldPass[5];
	char oldUser[20];
	int flag;
	
	do
	{
		system("cls");
		
		printf("************CHANGE PASSWORD************\n");
		
		printf("Enter Old Username : ");
		scanf("%s", oldUser);
		printf("Enter Old Password : ");
		scanf("%s", oldPass);
	
		if(strcmp(oldUser,realUser)==0 && strcmp(oldPass,realPass)==0)
		{
			printf("\nEnter New Username : ");
			scanf("%s", newUser);
			strcpy(realUser, newUser);
			
			printf("\nEnter 4-characters for new password.\n");
			printf("Enter New Password : ");
			scanf("%s", newPass);
			strcpy(realPass, newPass);
			
			writePass(newUser,newPass);
			flag = 1;
			
			printf("\nYour Username and Password Successfully Changed.");
			printf("\nReturning To MAIN MENU.");
		}
		else
		{
			printf("Old Username or Password is now correct.....TRY AGAIN.");
			flag = 0;
		}
		getch();getch();
	}while(!flag);
}
