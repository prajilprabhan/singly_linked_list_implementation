

// PRODUCT CART USING SINGLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node {
    int product_id;
    char name[30];
    int rate;
    struct node *next;
    
}*newnode,*temp,*top=NULL;

void add_Product()
{
    printf("\n=================================");
    printf("\n\t ADD PRODUCT DETAILS");
    printf("\n=================================");
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Product ID : ");
    scanf("%d",&newnode->product_id);
    getchar();
    printf("Enter the Product name : ");
    fgets(newnode->name,sizeof(newnode->name),stdin);
    printf("Enter the Product Rate : ");
    scanf("%d",&newnode->rate);
    newnode->next=NULL;
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
    printf("\n---------------------------------");
}

void remove_data()
{
    printf("\n=================================");
    printf("\n REMOVING PRODUCT DETAILS");
    printf("\n=================================");
    if(top==NULL)
    {
        printf("\n\t NO DATA TO REMOVE");
    }
    else{
        temp=top;
        printf("\nProduct ID : %d",temp->product_id);
        printf("\nProduct Name : %s",temp->name);
        printf("Product Rate : %d ",temp->rate);
        top=top->next;
    }
    printf("\n---------------------------------");
}
void display()
{
    printf("\n=================================");
    printf("\n\t PRODUCT DETAILS");
    printf("\n=================================");
    temp=top;
    while (temp!=NULL)
    {
        printf("\nProduct ID : %d",temp->product_id);
        printf("\nProduct Name : %s",temp->name);
        printf("Product Rate : %d ",temp->rate);
        temp=temp->next;
        printf("\n---------------------------------");
    }
    if(top==NULL)
    {
        printf("\n\tNOT DATA");
        printf("\n---------------------------------");
    }
    
    
}
void search()
{
    int key,flag=0;
    printf("\n=================================");
    printf("\n\t SEARCH PRODUCT DETAILS");
    printf("\n=================================");
    printf("\nEnter the Product ID to search : ");
    scanf("%d",&key);
    temp=top;
    while(temp!=NULL)
    {
        if(temp->product_id==key)
        {
            flag=1;
            printf("\nProduct ID : %d",temp->product_id);
            printf("\nProduct Name : %s",temp->name);
            printf("\nProduct Rate : %d ",temp->rate);
            break;
        }
    }
    if(flag==1)
    {
        printf("\n\tDATA NOT FOUND");
    }
    printf("\n---------------------------------");
}
void main()
{
    int ch;
    while (1)
    {
        printf("\n---MENU---");
        printf("\n1.ADD PRODUCT DETAILS");
        printf("\n2.REMOVE PRODUCT");
        printf("\n3.DISPLAY DETAILS ");
        printf("\n4.SEARCH PRODUCT");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:add_Product();
            break;
        case 2 : remove_data();
                break;
        case 3 :display();
            break;
        case 4 :search();
            break;
        case 5 :printf("\n----------- EXITING ------------"); exit(0);
        default:printf("\nINVALID OPTION");
            break;
        }
    }
    
}
