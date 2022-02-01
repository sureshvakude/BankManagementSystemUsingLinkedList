#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include<windows.h>
struct Acc
{
    char acn[10];
    char Fname[50];
    char Lname[50];
    char atype[100];
    int bal;
    struct Acc *nextacc;
    char pass[5];
    char phone[11];
    char add[100];
};
struct Acc *root,*newrg,*temp;

void BankReg();
void show();
struct Acc* SearchAcc();
void withdrawal(struct Acc* (*p)());
void deposit(struct Acc* (*q)());
void AccDel();
void fordelay(int j)
{
    int i,k;
    for(i=0; i<j; i++)
        k=i;
}
int main()
{
    system("color b");
    int j;
    int choice,num;
    char user[25]="admin";
    char pass[25]="1111";
    char user_[25];
    char pass_[25];
    int i = 3; // No. of Attempts for Login
    printf("\n\t\t****WELCOME****\n");
    while(i>0)
    {
        printf("\nLogin    : ");
        scanf("%s",user_);
        printf("\n\nPassword :");
        scanf("%s",pass_);

        if(strcmp(user,user_)== 0 && strcmp(pass,pass_)==0)
        {
            printf("\n\t\t****LOGIN SUCCESSFUL****\n\t\tLOADING");

            break;
        }
        else
        {
            printf("\n\t\t****LOGIN FAILED****\n");
            printf("\n\t\tINVALID USERNAME OR PASSWORD !\n");
            printf("\n\t\tYou have  remain %d attempts/attempt !!!\n",--i);
        }
    }
    if(i==0)
    {

        printf("\n\t\tSystem is going OFF , Try again latter\n");
        return 0;
    }
    for(j=0; j<=6; j++)
    {
        fordelay(100000000);
        printf(".");
    }
    system("cls");

    printf("\n\t\t****WELCOME TO OUR BANK SERVICES****\n\n");
    printf("1.New Registration\n");
    printf("2.Withdrawal\n");
    printf("3.Deposit\n");
    printf("4.Display Account Details\n");
    printf("5.Search Account Details\n");
    printf("6.Account Deletion\n");
    printf("7.Exit\n");
    printf("Select Your Choice : ");
    scanf("%d",&choice);
    printf("\n");

    while(choice != 7)
    {
        switch(choice)
        {
        case 1:
            printf("\n\t\t\t\t****NEW_REGISTRATION****\n\n");
            BankReg();
            break;
        case 4:
            show();
            break;
        case 5:
            printf("\n\t\t\t\t****Search_Account_Details****\n\n");
            SearchAcc();
            break;
        case 2:
            printf("\n\t\t\t\t****Withdrawal****\n\n");
            withdrawal(SearchAcc);
            break;
        case 3:
            printf("\n\t\t\t\t****Deposit****\n\n");
            deposit(SearchAcc);
            break;
        case 6:
            printf("\n\t\t\t\t****Account_Deletion****\n\n");
            AccDel();
            break;

        default:
            printf("You have Entered Wrong Choice\n");
            break;
        }
        printf("\nPress ""1"" For Main Menu / Press ""0""  to exit\n");
        scanf("%d",&num);
        if(num == 0)
        {
            return 0;
        }
        system("cls");
        printf("\n\t\t****WELCOME TO OUR BANK SERVICES****\n\n");
        printf("\n1.New Registration\n2.Withdrawal\n3.Deposit\n4.Display Account Details\n5.Search Account Details\n6.Account Deletion\n7.Exit\nSelect Your Choice : ");
        scanf("%d",&choice);
    }




}





void BankReg()
{
    int i,k;
    int tacn,tpass;
    FILE *ptr = NULL;
    ptr = fopen("record.txt","a+");
    newrg = (struct Acc*)malloc(sizeof(struct Acc));

    getchar();

    //fprintf(ptr,"DATE : %s\n",__DATE__);
    //fprintf(ptr,"TIME : %s\n",__TIME__);
    printf("Enter Your First name & Last name : ");
    scanf("%s %s",newrg->Fname,newrg->Lname);
    //fprintf(ptr,"Name : %s\n",newrg->name);
    
    getchar();
    printf("Enter Address  : ");
    gets(newrg->add);
    //fprintf(ptr,"Address :%s\n",newrg->add);
o:
    printf("Enter mobile num. : ");
    scanf("%s",newrg->phone);
    while(!(strlen(newrg->phone)==10))
    {
        printf("please enter the only 10 digits!");
        printf("Enter mobile num. : ");
        scanf("%s",newrg->phone);
    }
    for( k=0; k<strlen(newrg->phone); k++)
    {
        if(!isdigit(newrg->phone[k]))
        {
            printf("invalid number!..");
            goto o;
        }
    }
    //fprintf(ptr,"Mobile Number : %s\n",newrg->phone);
    printf("Enter Account Type (Saving/Current) : ");
    scanf("%s",&newrg->atype);
    //fprintf(ptr,"Account Type : %s\n",newrg->atype);
    getchar();
    int accn;
    srand(time(NULL));
    tacn =(rand()%(99999-10000+1))+10000;
    itoa(tacn,newrg->acn,10);
    tpass = (rand()%(9999-1000+1))+1000;
    itoa(tpass,newrg->pass,10);
    //fprintf(ptr,"Account Number : %s\n",newrg->acn);
    //fprintf(ptr,"Password : %s\n",newrg->pass);

    newrg->nextacc = NULL;
    newrg->bal = 500;
    do
    {
        printf("Enter Amount : ");
        scanf("%d",&newrg->bal);
        if(newrg->bal<500)
            printf("Please Enter Amount Above 500\n");
    }
    while(newrg->bal<500);


    fprintf(ptr,"%s %s %s %s %s %s %s %s %s %d\n",__DATE__,__TIME__,newrg->Fname,newrg->Lname,newrg->add,newrg->phone,newrg->atype,newrg->acn,newrg->pass,newrg->bal);
    getchar();


    if(root==NULL)
    {
        root=temp=newrg;
    }
    else
    {
        temp ->nextacc =newrg;
        temp = newrg;
    }
    printf("\n\t\t****Congratulations Your Account has been Created Successfully****\n\n");
    printf("Your account number & password is generated....\n");
    printf("ACCOUNT NUMBER 	: %s\n",newrg->acn);
    printf("PASSWORD	: %s",newrg->pass);
    fclose(ptr);
}


void show()
{
    system("cls");
    int j = 0;
    int i=3;
    struct Acc tmp;
    char nam[10]="admin";
    char passw[5]="1111";
    char uname[10];
    char upass[5];
    int month,year;
    char DATE[30],TIME[30];

    FILE *p = fopen("record.txt","r");
    do
    {
        printf("\n\t\t\t*****LOGIN*****\n");
        printf("\tUSERNAME	:  ");
        scanf("%s",uname);
        printf("\tPASSWORD	:  ");
        scanf("%s",upass);
        if(!strcmp(uname,nam) && !strcmp(upass,passw))
        {
            system("cls");
            printf("\n\t\t\t\t****All_Existing_Accounts_Details****\n\n");





            while(fscanf(p,"%s %d %d %s %s %s %s %s %s %s %s %d\n",DATE,&month,&year,TIME,tmp.Fname,tmp.Lname,tmp.add,tmp.phone,tmp.atype,tmp.acn,tmp.pass,&tmp.bal) != EOF)
            {

                printf("\tCREATED ACCOUNT ON DATE  : %s %d %d AT %s\n",DATE,month,year,TIME);
                printf("\tNAME            : %s %s\n",tmp.Fname,tmp.Lname);
                printf("\tADDRESS         : %s\n",tmp.add);
                printf("\tPHONE NUMBER    : %s\n",tmp.phone);
                printf("\tACCOUNT TYPE    : %s\n",tmp.atype);
                printf("\tACCOUNT NUMBER  : %s\n",tmp.acn);
                printf("\tAccount Balance : %d\n\n",tmp.bal);
            }





            i=-1;
        }
        else
        {
            printf("\n\tLOGIN FAILED!");
            printf("\n\tyou have entered wrong username and password");
            printf("\nYou have only %d chance....",i-1 );
        }
        i--;

    }
    while(i>0);

    fclose(p);
}




struct Acc* SearchAcc()
{

    int i;
    char acnum[10];
    struct Acc *tmp = NULL;
    char passcode[5];
    if(root==NULL)
    {
        printf("\n\n\t\tNo Accounts Registered , Please Register First!\n");
        return tmp;
    }

r:
    tmp = root;
    printf("\nPlease Enter Your Account Number : ");
    scanf("%s",acnum);
    int flag = 0;

    while(tmp != NULL)
    {

        if(!(strcmp(tmp->acn,acnum)))
        {
            printf("\nMatch Found ! ...Processing .. \n\n");

            flag = 1;
            printf("\nEnter Your Password : ");
            scanf("%s",passcode);
            printf("%d",strcmp(passcode,tmp->pass));
            while((strcmp(passcode,tmp->pass)))
            {
                printf("\n Invalid Password Entered !\n");
                printf("\nPlease ReEnter Your Password : ");
                scanf("%s",passcode);
                printf("%d",strcmp(passcode,tmp->pass));
            }
            printf("\n\t\tWELCOME TO JANATA BANK \n\n");
            printf("\n\t\tYour Account Details :\n\n");
            break;

        }
        tmp = tmp->nextacc;
    }
    if(flag == 0)
    {
        printf("Your Account Number is Invalid !!! , Please Enter valid Account Number \n");
        goto r;
    }

    printf("\tAccount No. : %s\n",tmp->acn);
    printf("\tName        : %s %s\n",tmp->Fname,tmp->Lname);

    printf("\tAccount Type: %s\n",tmp->atype);
    printf("\tBalance     : %d\n\n",tmp->bal);
    return tmp;
}



void withdrawal(struct Acc* (*p)())
{
    int amount,num;
    if(root==NULL)
    {
        printf("\n\n\t\tNo Accounts Registered , Please Register First!\n");
        return;
    }
    struct Acc *tmp = p();
    printf("Enter Withdrawal Amount : ");
    scanf("%d",&amount);
    if(!(amount>0) || !(amount<tmp->bal) || !(amount>500) || !((tmp->bal-amount)>=500))
    {
        printf("\nInvalid Amount Entered , \ni) You can Transact only above RS 500  !!!\nii)Remaining Balance must be RS 500 after trasacting !!\n");
        return ;
    }
    tmp->bal = tmp->bal-amount;
    printf("\n\nTrasacting RS. %d",amount);
    printf("\n\nRemaining balance : %d\n\n",tmp->bal);

}



void deposit(struct Acc* (*q)())
{
    int amount;
    if(root==NULL)
    {
        printf("\n\n\t\tNo Accounts Registered , Please Register First!\n");
        return;
    }
    struct Acc *tmp = q();

    printf("\nEnter your amount which you want to deposit:  ");
    scanf("%d",&amount);
    if(!(amount>0) || !(amount>500))
    {
        printf("Invalid amount Entered !!!\n");
        printf("i)You can deposit amount above RS 500 only ! , please try again\n");
        return ;
    }
    printf("You have Successfully deposited RS. %d to your account\nThanks\n",amount);
    tmp->bal+=amount;
    printf("\nYour Account Balance after depositing the amount : %d\n",tmp->bal);
    printf("\nFor More information You can see your account details .\n");
}

void AccDel()
{
    int i;
    int user;
    struct Acc*pre = NULL;
    char acnum[5];
    struct Acc *tmp = NULL;
    char passcode[5];
    if(root==NULL)
    {
        printf("\n\n\t\tNo Accounts Registered , Please Register First!\n");
        return;
    }

r:
    tmp = root;
    printf("\nPlease Enter Your Account Number : ");
    scanf("%s",acnum);
    int flag = 0;
    if(!(strcmp(tmp->acn,acnum))) // for first node only
    {
        printf("\nMatch Found ! ...Processing .. \n\n");

        flag = 1;
        printf("\nEnter Your Password : ");
        scanf("%s",passcode);
        while((strcmp(passcode,tmp->pass)))
        {
            printf("\n Invalid Password Entered !\n");
            printf("\nPlease ReEnter Your Password : ");
            scanf("%s",passcode);
        }
        printf("\n\t\tWELCOME TO JANATA BANK \n\n");
        printf("\n\t\tYour Account Details :\n\n");

        printf("\tAccount No. : %s\n",tmp->acn);
        printf("\tName        : %s %s\n",tmp->Fname,tmp->Lname);
        printf("\tAccount Type: %s\n",tmp->atype);
        printf("\tBalance     : %d\n\n",tmp->bal);

        printf("Are you sure that you want to delete your account ? \nIf Yes then press 1 / press 0 for rejecting the deletion ...\n");
        scanf("%d",&user);

        if(user)
        {
            root = root->nextacc;
            free(tmp);
            printf("\n\n\t\tYou have Deleted your Account Successfully .\n");
        }
        else
        {
            return;
        }

    }
    else
    {
        while(tmp != NULL) // for other nodes
        {


            if(!(strcmp(tmp->acn,acnum)))
            {
                printf("\nMatch Found ! ...Processing .. \n\n");

                flag = 1;
                printf("\nEnter Your Password : ");
                scanf("%s",passcode);
                while((strcmp(passcode,tmp->pass)))
                {
                    printf("\n Invalid Password Entered !\n");
                    printf("\nPlease ReEnter Your Password : ");
                    scanf("%s",passcode);
                }
                printf("\n\t\tWELCOME TO JANATA BANK \n\n");
                printf("\n\t\tYour Account Details :\n\n");
                break;

            }
            pre = tmp;
            tmp = tmp->nextacc;
        }
        if(flag == 0)
        {
            printf("Your Account Number is Invalid !!! , Please Enter valid Account Number \n");
            goto r;
        }

        printf("\tAccount No. : %s\n",tmp->acn);
        printf("\tName        : %s %s\n",tmp->Fname,tmp->Lname);
        printf("\tAccount Type: %s\n",tmp->atype);
        printf("\tBalance     : %d\n\n",tmp->bal);

        printf("Are you sure that you want to delete your account ? \nIf Yes then press 1 / press 0 for rejecting the deletion ...\n");
        scanf("%d",&user);

        if(user)
        {
            pre->nextacc = tmp->nextacc;
            free(tmp);
            printf("\n\n\t\tYou have Deleted your Account Successfully .\n");
        }
        else
        {
            return;
        }
    }
}


