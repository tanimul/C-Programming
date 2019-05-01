#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct Node
{
    char   name[10];
    char address[20];
    int phone;
    struct Node *next;
} node;

void insert(node *point, char name[],char address[],int phone)
{
    while(point->next!=NULL)
    {
        point = point -> next;
    }
    point->next = (node *)malloc(sizeof(node));
    point = point->next;
    strcpy(point->name, name);
    strcpy(point->address, address);
    point->phone = phone;
    point->next = NULL;
    printf("Store information!");
}

int find(node *point, char name[])
{
    point = point -> next;
    while(point!=NULL)
    {
        if(point->name == name)
        {
            return 1;
        }
        point = point-> next;
    }
    return 0;
}

void delete(node *point, char name[])
{
 while(point->next!=NULL && (point->next)->name != name){
        point= point -> next;
    }
    if(point->next==NULL){
        printf("Element not present");
        return;
    }

    node *temp;
    temp = point -> next;
    point->next = temp->next;
    free(temp);
     printf("Delete information");
    return;
}

void print(node *point)
{
    if(point==NULL)
    {
        return;
    }

    printf("Name: %s \n Address: %s \n Phone: %d ",point->name, point->address,point->phone);
    print(point->next);
}
int main()
{
    node *start,*temp;

    start = (node *)malloc(sizeof(node));
    temp = start;
    temp -> next = NULL;

    printf("press 1 to get Insert\n");
    printf("press 2 to get Delete\n");
    printf("press 3 to get Print\n");
    printf("press 4 to get Find\n");

    while(1)
    {
        int value;
        char name[10];
        char address[20];
        int phone;
        printf("\n\n what do you want:");
        scanf("%d",&value);

        switch(value)
        {
        case 1:
            printf("insert your name:");
            scanf("%s",name);
            printf("insert your address:");
            scanf("%s",address);
            printf("insert your Phone:");
            scanf("%d", &phone);
            insert(start,name,address, phone);
            break;

        case 2:
            scanf("%s",name);
            delete(start,name);

            break;

        case 3:
            printf("The list is ");
            print(start->next);
            printf("\n");
            break;

        case 4:
            scanf("%s",&name);
            int status = find(start,name);

            if(status)
                printf(" Found\n");
            else
                printf("Not Found\n");
        }
    }
}
