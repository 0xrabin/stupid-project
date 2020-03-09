#include <stdio.h>
#include <stdlib.h>

struct prisoner
{
    int PrisonerId;
    char Prisoner_FName[25];
    char Prisoner_LName[25];
    char Prisoner_Cell[10];
    int age;

    struct birthdetails
    {
    int day;
    char month[3];
    int year;
    }birth;
     
    struct releasedetails
    {
    int day;
    char month[3];
    int year;
    }release;

    char crime[25];

    }pri;

void Padd();
void Pread ();
void Psearch();
void Pdelete();
void Pedit();
void banner();
void export();

FILE *fp;
FILE *fpcsv;
void main()
{   
    int choice;
    system("cls");
    banner();
    printf("\nEnter \n[1] to add data \n[2] to view entire data \n[3] to search for a record \n[4] to edit/modify a record\n[5] to delete a record\n[6] to export entire data in csv format\n[7] exit\n");
    printf(">>");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        Padd();
        break;

        case 2:
        Pread();
        break;

        case 3:
        Psearch();
        break;

        case 4:
        Pdelete();
        break;

        case 5:
        Pedit();
        break;

        case 6:
        export();
        break;

        case 7:
        exit(0);

    }
}

void Padd()
{
char x;
fp = fopen("prisoners.txt","a+");


printf("Enter prisoner id:");
scanf("%d",&pri.PrisonerId);
fflush(stdin);
printf("Enter prisoner's name\n");
printf("Enter first name:");
scanf("%s",pri.Prisoner_FName);
printf("Enter last name:");
scanf("%s",pri.Prisoner_LName);
fflush(stdin);
printf("Enter prisoner cell no:");
scanf("%s",pri.Prisoner_Cell);
printf("Enter prisoner age:");
scanf("%d",&pri.age);
printf("Enter crime committed:");
scanf("%s",pri.crime);
printf("Enter release year:");
scanf("%d",&pri.release.year);
printf("Enter release month:");
scanf("%s",&pri.release.month);
printf("Enter release day:");
scanf("%d",&pri.release.day);
fflush(stdin);

fprintf(fp,"%d %s %s %s %d %s %d-%s-%d\n",pri.PrisonerId,pri.Prisoner_FName,pri.Prisoner_LName,pri.Prisoner_Cell,pri.age,pri.crime,pri.release.year,pri.release.month,pri.release.day);


fclose(fp);
printf("Do you want to add another data?\nEnter Y or N\n>>");
scanf("%c",&x);
if(x=='Y')
{
    Padd();
}
else if(x=='N')
{
    system("cls");
    main();
}
else
{
    printf("\nInvalid option");
}


}

void Pread()
{
char road;
system("cls");
banner();

        printf("\n\n\n");
        fp = fopen("prisoners.txt","r");
        //printf("ID Prisoner_Name Cell_no Age Crime Release Day\n");
        while((road=fgetc(fp))!=EOF)
        {
            printf("%c",road);
        }
        printf("\n");
        fclose(fp);


}


void Psearch()
{
int choice;
system("cls");
banner();
printf("\nEnter \n[1] to search by id \n[2] to search by name\n[3] to search by crime\n[4] to return to menu\n");
    printf(">>");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("2");
        break;

        case 2:
        printf("2");
        break;

        case 3:
        printf("3");
        break;

        case 4:
        main();
        break;
    }

}

void Pedit()
{
system("cls");
banner();
printf("Hello");
}

void Pdelete()
{
system("cls");
banner();
printf("Hello");
}

void export()
{       char road;
        fp = fopen("prisoners.txt","r");
        fpcsv = fopen("prisoners.csv","w+");
        while((road=fgetc(fp))!=EOF)
        {   if(road==' ')
            fputc(',',fpcsv);
            else
            fputc(road,fpcsv);
        }
        printf("\n");
        fclose(fp);
        fclose(fpcsv);

//fpcsv = fopen("prisoners.csv","a+");
//fclose(fpcsv);
//fputs("PrisonerID Prisoner_Names Prisoner_Cell_no Age Crime Release Day",fp);
//fprintf(fpcsv,"S.N,Name,Cell,Age,Crime,Release Date\n");
//fprintf(fpcsv,"%d,%s %s,%s,%d,%s,%d-%s-%d\n",pri.PrisonerId,pri.Prisoner_FName,pri.Prisoner_LName,pri.Prisoner_Cell,pri.age,pri.crime,pri.release.year,pri.release.month,pri.release.day);

}

void banner()
{
printf("        ########   ########   ##     ##   ######  \n");
printf("        ##     ##  ##     ##  ###   ###  ##    ## \n");
printf("        ##     ##  ##     ##  #### ####  ##       \n");
printf("        ########   ########   ## ### ##   ######  \n");
printf("        ##         ##   ##    ##     ##        ## \n");
printf("        ##         ##    ##   ##     ##  ##    ## \n");
printf("        ##         ##     ##  ##     ##   ######  \n\n\n");
printf("      }----------------------------------------------{\n");
printf("}-------------Prisoner Record Management System-------------{\n");
printf("      }----------------------------------------------{\n\n");

}
