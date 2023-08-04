//Structure for storing Date
typedef struct Date {
	int d;
	int m;
	int y;
}Date;

//Structure for storing Time
typedef struct Time {
	int h;
	int m;
	char ap[3];
}Time;

//This take Date as input
void TakeDate(Date *d)
{
	scanf("%d %d %d", &d->d, &d->m, &d->y);
}

//This will show Date
void ShowDate(Date d)
{
	printf("%d-%d-%d", d.d, d.m, d.y);
}

//This take Time as input
void TakeTime(Time *t)
{
	scanf("%d:%d %s", &t->h, &t->m, t->ap);
}

//This will show Time
void ShowTime(Time t)
{
	printf("%d:%02d %s", t.h, t.m, t.ap);
}

//This will show Date and Time together
void ShowDateTime(Date d, Time t)
{
	printf("%d-%d-%d %d:%02d %s", d.d, d.m, d.y, t.h, t.m, t.ap);
}

//This will compare two dates
int DateCmp(Date d1, Date d2)
{
	if((d1.d == d2.d) && (d1.m == d2.m) && (d1.y == d2.y))
		return 1;
	else
		return 0;
}

//This will compare two times
int TimeCmp(Time d1, Time d2)
{
	if((d1.h == d2.h) && (d1.m == d2.m) && (strcmp(d1.ap,d1.ap) == 0))
		return 1;
	else
		return 0;
}
