#include <stdio.h>
#include <stdlib.h>

void password();
void heading();
void mainMenu();
void addBook();
void viewBook();
void sarchbook();
void editbook ();
void deletbook();
void Help();
void Exit();

struct Book_info{
int id;
char name[10];

char author[10];

int quantity;

int rack;


};
struct Book_info a;
FILE *file, *file2;

int d=1;

int main()

{
   password();

}
void mainMenu()
{

    system("cls");
    int  n;
    printf("\n\n\t\t*******Main menu******");
    printf("\n\t\t \t 1. add book\n");
    printf("\n\t\t\t 2. view book\n");
    printf("\n\t\t\t 3. search book\n");
    printf("\n\t\t\t 4.edit book\n");
    printf("\n\t\t\t 5.delete book\n");
    printf("\n\t\t\t 6.Help\n");
    printf("\n\t\t\t 7.exit\n\n");
    printf("\t\t******************\n");
    printf("Enter your choice :");
    scanf("%d",&n );
    if(n==1){
       addBook();
       }
       else if (n==2){
         viewBook();
       }
       else if (n==3){
       sarchbook ();
       }
       else if (n==4){
        editbook ();
       }
       else if (n==5){
        deletbook();
       }
       else if (n==6){
        Help();
       }
       else if (n==7){
        Exit();
       }
       else {
        printf(" \n\n\t\t  your choice is wrong \n\t\t Try again ..... .  ");

        fflush(stdin);
        getchar();
        mainMenu();
       }


}
void addBook(){
 system("cls");
 int d, count=0;
 printf("\n\n\t\t **********Add book ******** ");
  file = fopen("books.dat","ab+");

  printf(" \n\t\t Enter ID: ");
  scanf("%d",&d);


  rewind(file);
  while(fread(&a,sizeof(a),1, file) == 1){

    if(d == a.id){
        printf("\n\n\t\t This book is already in Library.... ");
  count= 1;
     }
  }
  if (count ==1){
  fflush(stdin);
  getchar();
  mainMenu();
  }



  a.id =d;

  printf("\n\n\t\t Enter Name:");
  fflush(stdin);
  scanf("%s",a.name);
  printf("\n\n\t\t Enter Author:");
  fflush(stdin);
    scanf("%s",&a.author);
    printf("\n\n\t\t Enter quantity:");
    fflush(stdin);
    scanf("%d",&a.quantity);

   printf("\n\t\tEnter rack:");
   fflush(stdin);
   scanf("%d",&a.rack);

   fseek(file,0,SEEK_END);
   fwrite(&a,sizeof(a), 1, file);
   fclose(file);


   printf("\n\t\t Add book successfully :");
   fflush(stdin);
getchar();
mainMenu();
}

void viewBook()
{
system("cls");
int count =0;

printf("\n\n\t\t****** view book list********\n\n ");
printf("\t ID \t Name \t Author\t Quantity\tRack\n\n");

file = fopen("books.dat","rb");
while( fread(&a,sizeof(a),1,file) == 1)

{
printf("\n\t%d",a.id);
printf("\t%s",a.name);
printf("\t%s",a.author);
printf("\t\t%d",a.quantity);
printf("\t%d",a.rack);


count = count + a.quantity;


}

printf("\n\n\n\n\t\t Total Books:%d ",count );
printf("\n\n\t\t press any key....\n");
fflush(stdin);
getchar();
mainMenu();

}
void sarchbook(){
system("cls");
 int d, count=0;
 printf("\n\n\t\t **********search book is ******** ");
 printf("\n\t\t searching book");
  file = fopen("books.dat","rb");
  printf(" \n\t\t Enter ID: ");
  scanf("%d",&d);
while(fread(&a,sizeof(a),1, file) ==1){

    if(d == a.id){
      printf("\n\n\t\t Book is found...");
       printf("\t%d",a.id);
 printf("\t%s",a.name);
 printf("\t%s",a.author);
 printf("\t%d",a.quantity);
 printf("\n\t%d",a.rack );
    count =  1;
    }
}
if(count==0){
    printf("\n\n Book is not found..");
}
    printf("\n\t\t press any key....\n");

fflush(stdin);
getchar();
mainMenu();
}

void editbook()
{
 system("cls");
 int d, count=0;
 printf("\n\n\t\t **********edit book ******** ");

  file = fopen("books.dat","rb+");
  printf(" \n\t\t Enter ID: ");
  scanf("%d",&d);
   while(fread(&a,sizeof(a),1, file) ==1){

    if(d == a.id){
     printf("\n\t\t Book is availble \n");
    printf("\t%d",a.id);
     printf("Enter New Name");
     fflush(stdin);
 scanf("\t%s",a.name);
printf("Enter New author");
fflush(stdin);
 scanf("\t%s",a.author);
  printf("Enter New quantity ");
  fflush(stdin);
 scanf("\t%d",&a.quantity);
 printf("Enter New rack ");
 fflush(stdin);
 scanf("\n\t%d",&a.rack );


 fseek(file,ftell(file)-sizeof(a),0);
 fwrite(&a,sizeof(a),1,file);
  fclose(file);
  count=1;
    }
    if(count==0){
    printf("\n\n Book is not found..");
    }

     printf("\n\t\t press any key....\n");

fflush(stdin);
getchar();

   }


}

void deletbook()
{
  system("cls");
 int d,count = 0;

 printf("\n\n\t\t **********delete book ******** ");

  printf(" \n\t\t Enter ID for delete book  ");
  scanf("%d",&d);
  file = fopen("books.dat","rb+");
  rewind(file);
   while(fread(&a,sizeof(a),1, file) ==1)
    {

   if(d==a.id){

    printf(" \n\t\t  book is Availble !");
    printf(" \n\t\t Book name is :%s ",a.name);
    printf(" \n\t\t Rack no %d ",a.rack);
    count=1;

   }


   }

  if(count == 0){


    printf(" \n\t\t book is not Available ");
  }
  else{

   file2 = fopen("books.dat","wb") ;
   rewind(file);
   while(fread(&a,sizeof(a),1,file) == 1){

    if(d !=a.id){
     fseek(file2,ftell(file2)-sizeof(a),0);
     fwrite(&a,sizeof(a),1, file2);

    }

   }

    fclose(file);
     fclose(file2);
     remove("books.dat");
     rename("books.dat","books.dat");
     file = fopen("books.dat","rb");
     fclose(file);
      }

  printf("\n\t\t press any key");
  fflush(stdin);
getchar();

 mainMenu();


}
void Help()
{
   system("cls");

   printf("\n\n\t\t*********Help section **********\n\n");

    printf("\n\n\t\t 1.This is simple Library project \n");
   printf("\n\n\t\t 2.password is  201311022 \n");
   printf("\n\n\t\t 3.You can add book in  Library  \n");
    printf("\n\n\t\t 4.See all Feature main menu \n");

    printf("\n\n\t\t 5.can use all of them \n");
    printf("\n\n\t\t 6.press any key.... to back main manue \n");
    printf("\n\t\t\tThank you !\n\n");

    printf("\n\t\t press any key");
   fflush(stdin);
   getchar();

   mainMenu();


}
void Exit()
{
system("cls");
int i;
printf("\n\n\t\t 1.This is simple Library project \n");
printf("\n\t\t\tThank you !\n\n");
printf("\n\t\t\t wait....\n\n");

   fflush(stdin);
   getchar();
   for(i=1;1<1e8;i++){

   }
  exit(0);

}


void heading()
{
system("cls");
printf("\n\t\t\t##########################################################\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t#########################################################\n");

fflush(stdin);
getchar();

}

void password()
{

heading();
char pwd1[10]= {"201311022"};
char pwd2[10];
printf("\n \t\t\t Enter password: ");
scanf("%s",pwd2);
if(strcmp(pwd1,pwd2) == 0)
{
    printf("\n\n\t Match password!\n");
     printf("\n\t\t press any key....\n");

}
else{

if(d==3)
{
    exit(0);
}

 printf("\n\n\t wrong password!\n");
     printf("\n\t\t Try again ....\n");
     d++;
     fflush(stdin);
     getchar();

      password();

}
fflush(stdin);
getchar();
mainMenu();
}

