#include<stdio.h>
#include<stdlib.h>
 typedef struct Node
{
    int  number;
    struct Node *next;
}node;

void insert(node *point, int number){
    while(point->next!=NULL){
        point = point -> next;
    }
    point->next = (node *)malloc(sizeof(node));
    point = point->next;
    point->number = number;
    point->next = NULL;
    printf("stored");
}

int find(node *point, int key){
    point = point -> next;
    while(point!=NULL){
        if(point->number == key){
            return 1;
        }
    point = point-> next;
    }
    return 0;
}

void delete(node *point, int number){
    while(point->next!=NULL && (point->next)->number != number){
        point= point -> next;
    }
    if(point->next==NULL){
        printf("Element %d is not present in the list\n",number);
        return;
    }

    node *temp;
    temp = point -> next;
    point->next = temp->next;
    free(temp);
    return;
}

void print(node *point){
    if(point==NULL){
    return;
}

    printf("%d ",point->number);
    print(point->next);
    }
int main(){
    node *start,*temp;

    start = (node *)malloc(sizeof(node));

    temp = start;
    temp -> next = NULL;

    printf("press 1 to get Insert\n");
    printf("press 2 to get Delete\n");
    printf("press 3 to get Print\n");
    printf("press 4 to get Find\n");

    while(1){
        int value, number;
        scanf("%d",&value);

        switch(value){
            case 1:
            scanf("%d",&number);
            insert(start,number);
            break;

            case 2:
            scanf("%d",&number);
            delete(start,number);
            break;

            case 3:
            printf("The list is ");
            print(start->next);
            printf("\n");
            break;

            case 4:
            scanf("%d",&number);
            int status = find(start,number);

                if(status)
                    printf(" Found\n");
                else
                    printf("Not Found\n");
        }
    }
}
