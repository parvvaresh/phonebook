#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct student
{
    char fname[50];
    char lname[50];
    char hnum[50];
    char pnum[50];
    char gender[50];
    char mil_num[100];
    char stu_num[50];
    char address[100];
    char Major[50];
};
int Correct_the_hnumber(char hname[50])
{
	int a=0;
    for(int i=0;i<strlen(hname);i++)
    {
        a=isalpha(hname[i])?1:0;
        if(a==1)
        {
            break;
        }
    }
    if(strlen(hname)!=8&&a==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Correct_the_pnumber(char pname[50])
{
	int a=0;
    for(int i=0;i<strlen(pname);i++)
    {
        a=isalpha(pname[i])?1:0;
        if(a==1)
        {
            break;
        }
    }
    if(strlen(pname)!=11&&a==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Check_student_number(char stu_num[50])
{
	int a=0;
    for(int i=0;i<strlen(stu_num);i++)
    {
        a=isalpha(stu_num[i])?1:0;
        if(a==1)
        {
            break;
        }
    }
    if(strlen(stu_num)!=7&&a==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Check_the_military_number(char mil_num[50])
{
	int a=0;
    for(int i=0;i<strlen(mil_num);i++)
    {
        a=isalpha(mil_num[i])?1:0;
        if(a==1)
        {
            break;
        }
    }
    if(strlen(mil_num)!=9&&a==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Check_the_str(char str[50])
{
	int a;
    for(int i=0;i<strlen(str);i++)
    {
        a=isdigit(str[i])?1:0;
        if(a==1)
        {
            return 0;
        }
    }
    return 1;
}
int main(void)
{
    char fnamet[50];
    char lnamet[50];
    char hnumt[50];
    char pnumt[50];
    char gendert[50];
    char mil_numt[50];
    char stu_numt[50];
    char user[50];
    char Majorrt[50];
    int number;
    struct student stu[1000],copy[1000];
    FILE *fp;
    printf("What do you want to do?\n");
    printf("****Choose one of the phrases****\n");
    printf("***************************************************************\n");
    printf("** for Add user Enter the number zero**\n");
    printf("***************************************************************\n");
    printf("**for serach by first name Enter the number one**\n");
    printf("***************************************************************\n");
    printf("**for serach by last name Enter the number two**\n");
    printf("***************************************************************\n");
    printf("**for serach bye student number Enter the number three**\n");
    printf("***************************************************************\n");
    printf("**for Delete student Enter the number four**\n");
    printf("***************************************************************\n");
    printf("**for Delete individual student information Enter the number five**\n");
    printf("***************************************************************\n");
    printf("**edit Enter the number six**\n");
    printf("***************************************************************\n");
    printf("**for sort by fname Enter the number seven**\n");
    printf("***************************************************************\n");
    printf("**for sort by lname Enter the number eight**\n");
    printf("***************************************************************\n");
    printf("**for sort by stu_num Enter the number nine**\n");
    printf("***********************************Let's go***********************************\n");
    printf("for exit Enter the number nine\n");
    int x;
    scanf("%d",&x);
    while((x!=-1))
    {
if(x==0)
  {
    fp=fopen("phone number.txt","w");
    int n;
    printf("How many people do you want to add?\n");
    scanf("%d\n",&n);
    number=n;
    for(int i=0;i<number;i++)
    {
    	printf("lotfan name ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].fname);
        strcpy(fnamet,stu[i].fname);
        if(Check_the_str(fnamet)==0)
        {
            printf("The format entered is incorrect please try againe \n");
            while(Check_the_str(fnamet)!=1)
            {
            	printf("lotfan name ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].fname);
                strcpy(fnamet,stu[i].fname);
                if(Check_the_str(fnamet)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }

        }
        printf("lotfan name khanevadegi ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].lname);
        strcpy(lnamet,stu[i].lname);
        if(Check_the_str(lnamet)==0)
        {
            printf("The format entered is incorrect\n");
            while(Check_the_str(lnamet)!=1)
            {
            	printf("lotfan name khanevadegi ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].lname);
                strcpy(lnamet,stu[i].lname);
                if(Check_the_str(lnamet)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }
        printf("lotfan  mobile ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].pnum);
        strcpy(pnumt,stu[i].pnum);
        if(Correct_the_pnumber(pnumt)==0)
        {
            printf("The format entered is incorrect\n");
            while(Correct_the_pnumber(pnumt)!=1)
            {
            	printf("lotfan  mobile ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].pnum);
                strcpy(pnumt,stu[i].pnum);
                if(Correct_the_pnumber(pnumt)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }
        printf("lotfan telephone ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].hnum);
        strcpy(hnumt,stu[i].hnum);
        if(Correct_the_hnumber(hnumt)==0)
        {
            printf("The format entered is incorrect\n");
            while(Correct_the_hnumber(hnumt)!=1)
            {
            	printf("lotfan  telephone ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].hnum);
                strcpy(hnumt,stu[i].hnum);
                if(Correct_the_hnumber(hnumt)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }
        printf("lotfan  shomare daneshjooe ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].stu_num);
        strcpy(stu_numt,stu[i].stu_num);
        if(Check_student_number(stu_numt)==0)
        {
            printf("The format entered is incorrect\n");
            while(Check_student_number(stu_numt)!=1)
            {
            	printf("lotfan  telephone ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].stu_num);
                strcpy(stu_numt,stu[i].stu_num);
                if(Check_student_number(stu_numt)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }
        printf("lotfan  jensiat ra vared konid\n");

        scanf("%[^\n]%*c",stu[i].gender);
        strcpy(gendert,stu[i].gender);
        if(Check_the_str(gendert)==0)
        {
            printf("The format entered is incorrect\n");
            while(Check_the_str(gendert)!=1)
            {
            	 printf("lotfan  jensiat ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].gender);
                strcpy(gendert,stu[i].gender);
                if(Check_the_str(gendert)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }

        if(strcmp(stu[i].gender,"")==0||(strcmp(stu[i].gender,"Maile")==0))
        {
        	printf("lotfan code sarbazi ra vared konid\n");
           scanf("%[^\n]%*c",stu[i].mil_num);
           strcpy(mil_numt,stu[i].mil_num);
        if(Check_the_military_number(mil_numt)==0)
        {
            printf("The format entered is incorrect\n");
            while(Check_the_military_number(mil_numt)!=1)
            {
            	printf("lotfan code sarbazi ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].mil_num);
                strcpy(mil_numt,stu[i].mil_num);
                if(Check_the_military_number(mil_numt)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }
        }
         else
        {
           strcpy(stu[i].mil_num,"Not required for the desired gender");
        }
        printf("lotfan reshte ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].Major);
        strcpy(Majorrt,stu[i].Major);
        if(Check_the_str(Majorrt)==0)
        {
            printf("The format entered is incorrect\n");
            while(Check_the_str(Majorrt)!=1)
            {
            	printf("lotfan reshte ra vared konid\n");
                scanf("%[^\n]%*c",stu[i].Major);
                strcpy(Majorrt,stu[i].Major);
                if(Check_the_str(Majorrt)==0)
                {
                    printf("The format entered is incorrect\n");
                }
            }
        }
        printf("lotfan reshte ra vared konid\n");
        scanf("%[^\n]%*c",stu[i].address);
       
        }
    
        for(int i=0;i<number;i++)
        {
             fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
    
    fclose(fp);
}
else if(x==1)
{
    fp=fopen("phone number.txt","a");
    int check=0,j=0;
    printf("Please enter a first name\n");
    char testfn[50];
    scanf("%[^\n]%*c",testfn);
    for(int i=0;i<number;i++)
    {
        if(strcmp(stu[i].fname,testfn)==0)
        {
            check++;
            j=i;
        }
    }
    if(check==1)
    {
          printf("%s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[j].fname,stu[j].lname,stu[j].pnum,stu[j].hnum,stu[j].stu_num,stu[j].gender,stu[j].mil_num,stu[j].Major,stu[j].address);
    }
    if(check==0)
    {
        printf("User not found\n");
    }
}
else if (x==2)
    {
        int check=0,j=0;
        char testln[50];
        printf("Please enter a first name\n");
        scanf("%[^\n]%*c",testln);
        for(int i=0;i<number;i++)
        {
            if(strcmp(testln,stu[i].lname))
            j=i;
            check++;
        }
        if(check==1)
        {
             
			 
			  printf("%s  %s  %s  %s  %s  %s  %s  %s  %s %s\n",stu[j].fname,stu[j].lname,stu[j].pnum,stu[j].hnum,stu[j].stu_num,stu[j].gender,stu[j].mil_num,stu[j].mil_num,stu[j].Major,stu[j].address);
        }
		if(check==0)
        {
            printf("User not found\n");
        }
    }
else if(x==3)
{
    int check=0;
    printf("Please enter a student number\n");
    char testsn[50];
    scanf("%[^\n]%*c",testsn);
    int j = 0;
    for(int i=0;i<number;i++)
    {
        if(strcmp(stu[i].stu_num,testsn)==0)
        {
            j=i;
            check++;
        }
    }
    if(check==1)
    {
         printf("%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[j].fname,stu[j].lname,stu[j].pnum,stu[j].hnum,stu[j].stu_num,stu[j].gender,stu[j].mil_num,stu[j].mil_num,stu[j].Major,stu[j].address);
    }
    if(check==0)
    {
        printf("User not found\n");
    }
}
else if(x==4)
{
    fp=fopen("phone number.txt","w");
    int n;
    int j=0,q=0,check=0;
    char test[50];
    printf("Please enter the student name\n");
    scanf("%[^\n]%*c",test);
    for(int i=0;i<number;i++)
    {
        if(strcmp(stu[i].lname,"test")==0)
        {
            j=i;
            check++;
        }
    }
    if(check==1)
    {
    for(int i=0;i<number;i++)
     {
        if(i==j)
        {
            continue;
            q++;
        }
        else
        {
            copy[q]=stu[i];
            q++;
        }
     }
    }
    if(check==0)
    {
         printf("User not found\n");
    }
    for(int i=0;i<number;i++)
        {
             fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
    fclose(fp);
}
else if(x==5)
{
    fp=fopen("phone number.txt","w");
    char name[50];
    char part[50];
    int j=0,check=0;
    printf("Please enter the student name\n");
    scanf("%[^\n]%*c",name);
    printf("which part???\n");
    scanf("%[^\n]%*c",part);
    for(int i=0;i<number;i++)
    {
        if(strcmp(name,stu[i].lname)==0)
        {
            j=i;
            check++;
        }
    }
    if(check==0)
    {
      printf("User not found\n");
    }
    if(check==1)
    {
      if(strcmp(part,"lname")==0)
      {
          strcpy(stu[j].lname,"deleted");
      }
      if(strcmp(part,"hnum")==0)
      {
          strcpy(stu[j].hnum,"deleted");
      }
      if(strcmp(part,"pnum")==0)
      {
          strcpy(stu[j].pnum,"deleted");
      }
      if(strcmp(part,"gender")==0)
      {
          strcpy(stu[j].gender,"deleted");
      }
      if(strcmp(part,"mil_num")==0)
      {
          strcpy(stu[j].mil_num,"deleted");
      }
      if(strcmp(part,"stu_num")==0)
      {
          strcpy(stu[j].stu_num,"deleted");
      }
      if(strcmp(part,"fname")==0)
      {
          strcpy(stu[j].fname,"deleted");
      }
    }
    for(int i=0;i<number;i++)
        {
           fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
    fclose(fp);
}
else if(x==6)
{
    fp=fopen("phone number.txt","w");
    char name[50];
    char part[50];
    char newpart[50];
    int j=0,check=0;
    printf("Please enter the student name\n");
    scanf("%[^\n]%*c",name);
    printf("which part???\n");
    scanf("%[^\n]%*c",part);
    printf("Enter a new part\n");
    scanf("%[^\n]%*c",newpart);
    for(int i=0;i<number;i++)
    {
        if(strcmp(name,stu[i].lname)==0)
        {
            j=i;
            check++;
        }
    }
    if(check==0)
    {
      printf("User not found\n");
    }
    if(check==1)
    {
      if(strcmp(part,"lname")==0)
      {
          strcpy(stu[j].lname,newpart);
      }
      if(strcmp(part,"hnum")==0)
      {
          strcpy(stu[j].hnum,newpart);
      }
      if(strcmp(part,"pnum")==0)
      {
          strcpy(stu[j].pnum,newpart);
      }
      if(strcmp(part,"gender")==0)
      {
          strcpy(stu[j].gender,newpart);
      }
      if(strcmp(part,"mil_num")==0)
      {
          strcpy(stu[j].mil_num,newpart);
      }
      if(strcmp(part,"stu_num")==0)
      {
          strcpy(stu[j].stu_num,newpart);
      }
      if(strcmp(part,"fname")==0)
      {
          strcpy(stu[j].fname,newpart);
      }
    }
    for(int i=0;i<number;i++)
        {
            fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
    fclose(fp);
}
else if(x==7)
{
    fp=fopen("phone number.txt","w");
    struct student sort[1000];
    for(int j=0;j<number;j++)
    {
        for(int i=0;i<number-j;i++)
        {
            if(strcmp(stu[i].fname,stu[j].fname)>0)
            {
                 sort[0]=stu[i];
                 stu[i]=stu[j];
                 stu[j]=sort[0];
            }
        }
    }
    for(int i=0;i<number;i++)
        {
              fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
    fclose(fp);
}
else if(x==8)
{
    fp=fopen("phone number.txt","w");
    struct student sort[1000];
    for(int j=0;j<number;j++)
    {
        for(int i=0;i<number-j;i++)
        {
            if(strcmp(stu[i].lname,stu[i+1].lname)>0)
            {
                 sort[0]=stu[i];
                 stu[i]=stu[i+1];
                 stu[i+1]=sort[0];
            }
        }
    }
    for(int i=0;i<number;i++)
        {
             fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
    fclose(fp);
}
else if(x==9)
{
    fp=fopen("phone number.txt","w");
    struct student sort[1000];
    for(int j=1;j<number;j++)
    {
        for(int i=0;j<number-j;i++)
        {
            int a=atoi(stu[i].stu_num);
            int b=atoi(stu[i+1].stu_num);
            if(a>b)
            {
                 sort[0]=stu[i];
                 stu[i]=stu[i+1];
                 stu[i+1]=sort[0];
            }
        }
    }
    for(int i=0;i<number;i++)
        {
          fprintf(fp,"%s  %s  %s  %s  %s  %s  %s  %s  %s  %s\n",stu[i].fname,stu[i].lname,stu[i].pnum,stu[i].hnum,stu[i].stu_num,stu[i].gender,stu[i].mil_num,stu[i].mil_num,stu[i].Major,stu[i].address);
        }
	fclose(fp);
}
printf("You have nothing to do?!");
scanf("%d\n",&x);
    }
}
