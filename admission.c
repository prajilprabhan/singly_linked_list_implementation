#include<stdio.h>
#include<stdlib.h>

struct Node{
    int id;
    char name[40];
    int rank;
    struct Node *next;
}*head=NULL,*newnode,*temp;

void admission()
{
    printf("\n=================================================");
    printf("\n---------------- STUDENT ADMISSION --------------");
    printf("\n=================================================\n");
    newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Student ID : ");
    scanf("%d",&newnode->id);
    getchar();
    printf("Enter The Student Name : ");
    fgets(newnode->name,sizeof(newnode->name),stdin);
    printf("Enter the Student Rank : ");
    scanf("%d",&newnode->rank);

    if(head==NULL)
    {
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void delete_data()
{
    int id,flag;
    printf("\nEnter the Student ID to Remove Student Details : ");
    scanf("%d",&id);
    temp=head;
    struct Node *prev;
    while(temp!=NULL)
    {
        
         if(head->id==id)
        {
            head=head->next;
            flag=1;
            break;
        }
        else
        {
            if(temp->id ==id)
            {
                flag=1;
                prev->next=temp->next;
                break;
            }
            prev=temp;
            temp=temp->next;
         }
    }
    if(flag==1)
    {
        printf("\n-------------------------------------------------");
        printf("\n\tDELETED STUDENT DATA");
        printf("\n-------------------------------------------------");
        printf("\nStudent ID : %d",temp->id);
        printf("\nStudent Name : %s",temp->name);
        printf("\nStudent Rank : %d",temp->rank);
        printf("\n-------------------------------------------------");
        free(temp);
    }
    else{
        printf("\nSTUDENT ID NOT FOUND ! ");
    }

}

void display()
{
    temp=head;
    printf("\n=================================================");
    printf("\n-----------STUDENT ADMISSION DETAILS ------------");
    printf("\n=================================================\n");
    while(temp!=NULL)
    {
        printf("\n-------------------------------------------------");
        printf("\nSTUDENT ID   : %d",temp->id);
        printf("\nSTUDENT NAME : %s",temp->name);
        printf("\nSTUDENT RANK : %d",temp->rank);
        printf("\n-------------------------------------------------");
        temp=temp->next;
    }
    if(head==NULL)
    {
        printf("\n-------------------------------------------------");
        printf("\n------------------ NO DATA FOUND-------------------");
        printf("\n-------------------------------------------------\n");
    }

}

void search()
{
    int flag=0,id;
    printf("\n=================================================");
    printf("\n\tSEARCH ");
    printf("\n=================================================");
    printf("\nEnter the Student ID to search details : ");
    scanf("%d",&id);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            flag++;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        printf("\nEntered Student ID NOT FOUND !");
    }
    printf("\n-------------------------------------------------\n");
        
}

void main()
{
    int ch,num,id;
    printf("============= STUDENT ADMISSION PROCESS=============");
    while(1)
    {
        printf("\n------------- MENU --------------");
        printf("\n1. STUDENT ADMISSION ");
        printf("\n2. REMOVE STUDENT DATA ");
        printf("\n3. DISPLAY STUDENT ADMISSION DETAILS");
        printf("\n4. SEARCH STUDENT ADMISSION DETAILS");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1 :admission();
                    break;
            case 2 : delete_data();
                    break;
            case 3 : display();
                    break;
            case 4 : search();
                    break;
            case 5 :printf("\n----------- EXITING ------------");exit(0);
            default : printf("\nINVALID CHOICE ! ");
        }
    }

}