//This struct can stor one entry which Date, Time and Routine
typedef struct Entry {
	Date date;
	Time time;
	char person[25];
	char note[100];
}Entry;

//write a entry on the file
void WriteEntryFile(Entry *e)
{
	Entry wr = *e;
	FILE *out;
	out = fopen("files/entry.bin", "ab");
	
	fwrite(&wr, sizeof(Entry), 1, out);
	
	fclose(out);
}

//Take Entries
void TakeEntry(Entry *e)
{
	printf("Enter Date : "); TakeDate(&(e->date));
	printf("Enter Time : "); TakeTime(&(e->time));
	printf("Enter Person : "); scanf(" %[^\n]s", e->person);
	printf("Enter Note :\n"); scanf(" %[^\n]s", e->note);
	WriteEntryFile(e);
}

//Show Entries
void ShowEntry(Entry e)
{
	printf("Date and Time : ");
	ShowDateTime(e.date,e.time);
	printf("\nPerson : %s\n", e.person);
	printf("Note :\n"); printf("%s", e.note);
}

//Show all entries from the file
void ShowAllEntry()
{
	system("cls");

	printf("**************ALL ENTRIES************\n\n");
		
	Entry e;
	FILE *in;
	in = fopen("files/entry.bin", "rb");
	
	if(in == NULL)
	{
		printf("FILE NOT FOUND........");
		getch();
	}
	else
	{
		fseek(in, 0, SEEK_SET);
		while( !feof(in) ) {
			fread(&e, sizeof(Entry), 1, in);
			ShowEntry(e);
			printf("\n-----------------------------------\n");
		}
	}
	
	getch();
	
	fclose(in);
}

//search a entry in the file
void SearchEntry(Date d)
{
	Entry e;
	FILE *in;
	in = fopen("files/entry.bin", "rb");
	
	if(in == NULL)
	{
		printf("FILE NOT FOUND........");
		getch();
	}
	else
	{
		fseek(in, 0, SEEK_SET);
		do {
			fread(&e, sizeof(Entry), 1, in);
			
			if(DateCmp(d, e.date))
			{
				ShowEntry(e);
				printf("\n--------------------------------------\n");
			}
		} while ( !feof(in) );
	}
	
	fclose(in);
}
