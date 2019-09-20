#include<stdio.h>
struct Node{
        int data;
        Node *prev,*next;

    };

Node *head,*tail;


void createLinkList()
{
    head=NULL;
    tail=NULL;
}

Node* createNode(int data)
{

    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    //newNode->next = NULL;
    (*newNode).next = NULL;
    return newNode;
}

void insertAtBeginning(Node *newNode){
    if(head==NULL && tail==NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next= head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(Node *newNode){
    if(head==NULL && tail==NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->prev= tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void insertafternode(Node *previous ,Node *newNode){

    newNode->next = previous->next;
    newNode->prev = previous;
    previous->next->prev = newNode;
    previous->next = newNode;

}
void insertbeforenode(Node *next,Node *newnode)
{
    newnode->prev = next->prev;
    newnode->next = next;
    next->prev->next=newnode;
    next->prev = newnode;
}
void traverse_Forward()
{
    printf("\nTraverse forward  :  ");
    for(Node *current=head;current!=NULL;current = current->next){
            printf("\t%d",current->data);

    }
}

void traverse_Backward()
{
    printf("\nTraverse backward  :  ");
    for(Node *current=tail;current!=NULL;current = current->prev){
            printf("\t%d",current->data);

    }
}
Node* searchnode(int value)
{
    for(Node *current=head;current!=NULL;current = current->next){
            if(current->data==value)
               return current ;
    }
    return NULL;
}

void deletefirstnode()
{
    if(head==NULL)
    {
        return;
    }
    Node* nodetodelete = head ;
    head = head->next;
    delete nodetodelete;
    if(head!=NULL)
    {
        head->prev = NULL;
    }
    else tail=NULL;
}
void deletemiddle(int value)
{
    Node* nodetodelete = searchnode(value);

    if(nodetodelete!=NULL)
    {
        if(nodetodelete->next==NULL)
    {
        nodetodelete->prev->next=NULL;
        tail = nodetodelete->prev;
        delete nodetodelete;
    }
        else{
        nodetodelete->prev->next=nodetodelete->next;
        nodetodelete->next->prev=nodetodelete->prev;
        delete nodetodelete;
    }
    }
}


int main()
{
    int i,choice;
    createLinkList();

        for(;;)
    {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert before node");
        printf("\n4. Insert after node");
        printf("\n5. Delete first node");
        printf("\n6. Delete exact node");
        printf("\n7. Exit");
        printf("\nEnter what you want :");
        scanf("%d",&choice);


        if(choice==1){

        printf("\nEnter number  = \n");
            int input;
        scanf("%d",&input);
        insertAtBeginning(createNode(input));

        traverse_Forward();
        traverse_Backward();
        }

        else if(choice==2){

            int input;
            printf("\nEnter number  = \n");
        scanf("%d",&input);
        insertAtEnd(createNode(input));
        traverse_Forward();
        traverse_Backward();
        }
        else if(choice==3)  {
                if(head==NULL)
                {
                    printf("\nLink list is empty\n");
                }
                else{

                            int input;
                            int val;
                            printf("\nEnter number  = \n");
        scanf("%d",&input);
        printf("\n Insert before what = ");
        scanf("%d",&val);
        if(searchnode(val)==NULL)
        {
            printf("\nInvalid node !!!!\n");
            continue ;
        }
        insertbeforenode(searchnode(val),createNode(input));
                }
                traverse_Forward();
        traverse_Backward();
                        }
        else if(choice==4)
            {
                if(head==NULL)
                {
                    printf("\nLink list is empty\n");
                }
                else{

                            int input;
                            int val;
                            printf("\nEnter number  = \n");
        scanf("%d",&input);
        printf("\n Insert after what = ");
        scanf("%d",&val);
        if(searchnode(val)==NULL)
        {
            printf("\nInvalid node !!!!\n");
            continue ;
        }
        insertafternode(searchnode(val),createNode(input));
                }
                traverse_Forward();
        traverse_Backward();
        }
         else if(choice==5){

            if(head==NULL)
            {
                printf("Link list is empty!!!\n");
                continue;
            }
            else{
                deletefirstnode();
            }
            traverse_Forward();
        traverse_Backward();
        }
        else if(choice==6){

        if(head==NULL)
            {
                printf("Link list is empty!!!\n");
                continue;
            }
            else{
                    int deltenode;
                printf("\nEnter value = ");
                scanf("%d",&deltenode);
            deletemiddle(deltenode);
            }
            traverse_Forward();
        traverse_Backward();
        }
        else if(choice==7)
        {
            return 0;
        }
        else{
            printf("\nInvalid Choice !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }
}
return 0;
}


