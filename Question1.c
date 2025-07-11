//AUDIO_PLAYLIST
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char song[100];
    struct Node *next;
};
//head pointer to NULL
struct Node* head=NULL;
struct Node* createNode(char song[])
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->next=NULL;
    return newNode;
}
void insertsong(char song[])
{
    struct Node* newNode=createNode(song);
    newNode->next=head;
    head=newNode;
    printf("%s added to playlist:",song);
}
void display()
{
    if(head==NULL)
    {
        printf("\n No song to play");
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%s->",temp->song);
        
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    int ch;
    char song[100];
    printf("choice1: add a song\nchoice2::display a song\nchoice3:exit\nenter your choice:");
    scanf("%d",&ch);
    getchar();
        switch (ch)
        {
            case 1:
                printf("Enter song name: ");
                fgets(song, 100, stdin);
                song[strcspn(song, "\n")] = '\0'; // remove newline
                insertsong(song);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting player. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
        return 0;
    
}
