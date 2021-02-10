
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
struct record
{
char id[10];
 char name[30];
 char age[6];
 char gender[10];
 char height[20];
 char weight[20];
 char crime[40];
struct record *next;
};
struct record *start=NULL;
struct record *addrecord(struct record *);
void viewrecord(struct record *);
struct record *searchrecord(struct record *);
struct record *deleterecord(struct record *);
int main()
{
 clrscr();
 int ch;
 printf("\n\n\t====================================\n");
 printf("\t -POLICE FIR RECORD MANAGEMENT-\n");
 printf("\t====================================");

 while(1)
 {
printf("\n\n\t\t::MAIN MENU::");
printf("\n\n\t\tADD FIR RECORD\t[ENTER-1]");
printf("\n\t\tSEARCH RECORD\t[ENTER-2]");
printf("\n\t\tLIST RECORD\t[ENTER-3]");
 printf("\n\t\tDELETE RECORD\t[ENTER-4]");
printf("\n\t\tEXIT\t\t[ENTER-5]");
printf("\n\n\t=> ENTER YOUR CHOICE:");
scanf("%d",&ch);
switch(ch)
{
case 1:
 start=addrecord(start);
 break;
case 2:
 start=searchrecord(start);
 break;
case 3:
 viewrecord(start);
 break;
case 4:
 start=deleterecord(start);
 break;
case 5:
 getch();
 exit(0);
default:
 printf("\nYOU ENTERED WRONG CHOICE.");
 printf("\nPRESS ANY KEY TO TRY AGAIN");
 getch();
 break;
}
system("cls");

 }
 return 0;
}
struct record *addrecord(struct record *start)
{
struct record *new_record,*ptr;
char a[10],z[10];
int c=0;
printf("enter the name of criminal whose record you want to add ");
scanf("%s",&a);
printf("énter the id of the criminal whose record you want to add");
scanf("%s",&z);
new_record=(struct record *)malloc(sizeof(struct record));
new_record->next=NULL;
ptr=start;
while(ptr!=NULL)
{
if((strcmp(a,ptr->name)==0)&&(strcmp(z,ptr->id)==0))
{
 printf("\nthe record already exist of the person with name %s",a);
c++;
}
ptr=ptr->next;
}
ptr=start;
if(start==NULL)
{
printf("\n enter the name of criminal ");
scanf("%s",new_record->name);
printf("\n enter the id of the criminal ");
scanf("%s",new_record->id);
printf("\nenter the age of the criminal ");
scanf("%s",new_record->age);
printf("\n enter the gender of the criminal ");
scanf("%s",new_record->gender);
printf("\n enter the height of the criminal(ft) ");
scanf("%s",new_record->height);
printf("\n enter the weight of the criminal(kg) ");
scanf("%s",new_record->weight);
printf("\nenter the crime of the criminal ");
scanf("%s",new_record->crime);
start=new_record;
}
else
{
while(ptr->next!=NULL)
{
if((strcmp(a,ptr->name)==0)&&(strcmp(z,ptr->id)==0))

{
 printf("\nthe record already exist of the person with name %s",a);
c++;
break;
 }
else
{
ptr=ptr->next;
}
}
if(c==0)
{
printf("\nenter the name of criminal");
scanf("%s",new_record->name);
printf("\n enter the id of the criminal");
scanf("%s",new_record->id);
printf("\nenter the age of the criminal");
scanf("%s",new_record->age);
printf("\n enter the gender of the criminal");
scanf("%s",new_record->gender);
printf("\n enter the height of the criminal(ft)");
scanf("%s",new_record->height);
printf("\n enter the weight of the criminal(kg)");
scanf("%s",new_record->weight);
printf("\nenter the crime of the criminal");
scanf("%s",new_record->crime);
ptr->next=new_record;
}
}
return start;
}
struct record *searchrecord(struct record *start)
{
struct record *ptr;
char a[10];
int e;
do
{
int d=0;
printf("\nenter the id of file to be search");
scanf("%s",&a);
ptr=start;
while(ptr!=NULL)
{
if(strcmp(a,ptr->id)==0)
{
printf("\n name of the criminal is %s",ptr->name);
printf("\n id of criminal is %s",ptr->id);

printf("\n age of criminal is %s",ptr->age);
printf("\n gender of criminal is %s",ptr->gender);
printf("\nheight of criminal is %s",ptr->height);
printf("\nweight of criminal is %s",ptr->weight);
printf("\n crime of criminal is %s",ptr->crime);
d++;
}
ptr=ptr->next;
}
if(d==0)
{
printf("the file does not exist");
}
printf("\nenter 1 to continue and -1 to exit to main menu");
scanf("%d",&e);
}while(e!=-1);
return start;
}
void viewrecord(struct record *start)
{
struct record *ptr;
int i=1;
ptr=start;
while(ptr!=NULL)
{
printf("\n%d.",i);
printf("\n name of criminal is %s",ptr->name);
printf("\n id of criminal is %s",ptr->id);
printf("\n age of criminal is %s",ptr->age);
printf("\n gender of criminal is %s",ptr->gender);
printf("\nheight of criminal is %s",ptr->height);
printf("\nweight of criminal is %s",ptr->weight);
printf("\n crime of criminal is %s",ptr->crime);
ptr=ptr->next;
i++;
}
getch();
}
struct record *deleterecord(struct record *start)
{
struct record *ptr,*pre_ptr;
char a[10];
int d=0,b;
do
{

printf("\nenter the id of file to be deleted");
scanf("%s",&a);
ptr=start;
while(ptr!=NULL)
{
pre_ptr=ptr;
ptr=ptr->next;
if(strcmp(a,ptr->id)==0)
{
printf("\nthe file deleted is %s",ptr->name);
pre_ptr->next=ptr->next;
free(ptr);
d++;
}
}
if(d==0)
{
printf("\nthe file does not exist");
}
printf("\nenter 1 to continue and -1 to exit to main menu");
scanf("%d",&b);
}while(b!=-1);
return start;
}
