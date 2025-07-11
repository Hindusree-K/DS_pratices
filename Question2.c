//TREASURE HUNT
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char hint[100];
    struct Node *next;
};
//head pointer to NULL
struct Node* head=NULL;
struct Node* createNode(char hint[])
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->hint, hint);
    newNode->next=NULL;
    return newNode;
}
void inserthint(char hint[])
{
    struct Node* newNode=createNode(hint);
    newNode->next=NULL;
    head=newNode;
    printf("given hint:%s",hint);
}
void display()
{
    if(head==NULL)
    {
        printf("\n No hint is given");
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%s->",temp->hint);
        
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    char hint[100];
    int ch;
    while(1)
    {
    printf("\nchoice1: add a hint\nchoice2::display a hint\nchoice3:exit\nenter your choice:");
    scanf("%d",&ch);
    getchar();
        switch (ch)
        {
            case 1:
                printf("Enter hint: ");
                fgets(hint, 100, stdin);
                hint[strcspn(hint, "\n")] = '\0'; // remove newline
                inserthint(hint);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting game. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
        return 0;
    
}
