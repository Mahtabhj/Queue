#include <stdio.h>
#include<stdlib.h>
#define max 5

int front=-1,rear=-1;
int queue[max];

void insert()
{
    int number;
    if(rear == max-1)
    {
        printf("\nQueue is full !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }
    printf("\nEnter a number to Insert :");
    scanf("%d",&number);
    if(front==-1)
        front=front+1;

    rear=rear+1;
        queue[rear]=number;
}

int delete()
{
    int e;
    if(front==-1)
    {
        printf("\nQueue is empty !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }
    e=queue[front];

    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else front=front+1;
    printf("\n%d was deleted !\n",e);
    return e;

}

void display()
{
    int i,j;

    if(front==-1)
    {
        printf("\nQueue is Empty !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }
    i=front;
    j=i;
    printf("\nQueue      :   ");
    if(j!=0)
    {

      for(j=0;j<i;j++)
      {
          printf("__\t");
      }
    }


        for(;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n\n");

}

int main()
{
    int choice,no;
    for(;;)
    {
        printf("\nPress 1 for Insert");
        printf("\nPress 2 for Delete");
        printf("\nPress 3 for Display");
        printf("\nPress 4 for EXIT");
        printf("\nEnter what you want :");
        scanf("%d",&choice);


        if(choice==1){

            insert();
        }
        else if(choice==2){

            delete();
        }
        else if(choice==3)  {
                            display();
                            }
        else if(choice==4)
            {
                exit(1);
        }
        else{
            printf("\nInvalid Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }


    }
}

    return e;

}

void display()
{
    int i;

    if(front==-1)
    {
        printf("\nQueue is Empty !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        return;
    }
    i=front;

    printf("\nQueue      :   ");

        while(i<=rear){
            printf("%d \t",queue[i]);
            i++;
        }
        printf("\n\n");

}

int main()
{
    int choice,no;
    for(;;)
    {
        printf("\nPress 1 for Insert");
        printf("\nPress 2 for Delete");
        printf("\nPress 3 for Display");
        printf("\nPress 4 for EXIT");
        printf("\nEnter what you want :");
        scanf("%d",&choice);


        if(choice==1){

            insert();
        }
        else if(choice==2){

            delete();
        }
        else if(choice==3)  {
                            display();
                            }
        else if(choice==4)
            {
                exit(1);
        }
        else{
            printf("\nInvalid Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }


    }
}
