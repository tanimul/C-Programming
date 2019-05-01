#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int number;
    struct Node *next;
    struct Node *prev;
} node;
void insert(node *point, int number) {
    while (point->next != NULL) {
        point = point->next;
    }

    point->next = (node *) malloc(sizeof(node));
    (point->next)->prev = point;
    point = point->next;
    point->number = number;
    point->next = NULL;
}

int find(node *point, int key) {
    point = point->next;
    while (point != NULL) {
        if (point->number == key) {
            return 1;
        }
    point = point->next;
    }
return 0;
}

void delete_node(node *point, int number) {
    while(point->next !=NULL && (point->next)->number!=number)
    {
        point = point->next;
    }
    if (point->next == NULL) {
        printf("Element %d is not present in the list\n", number);
        return;
    }
    node *temp;
    temp = point->next;
    point->next = temp->next;
    temp->prev = point;
    free(temp);
    return;
}
void print(node *point) {
    if (point == NULL) {
        return;
    }
    printf("%d ", point->number);
    print(point->next);
}

int main() {
    node *start, *temp;
    start = (node *) malloc(sizeof(node));
    temp = start;
    temp->next = NULL;
    temp->prev = NULL;

  printf("press 1 to get Insert\n");
    printf("press 2 to get Delete\n");
    printf("press 3 to get Print\n");
    printf("press 4 to get Find\n");

    while (1) {
        int search;
        scanf("%d", &search);

        if (search == 1) {
            int number;
            scanf("%d", &number);
            insert(start, number);
        }
        else if (search == 2) {
            int number;
            scanf("%d", &number);
            delete_node(start, number);
        }
        else if (search == 3) {
            printf("The list is ");
            print(start->next);
            printf("\n");
        }
        else if (search == 4) {
            int number;
            scanf("%d", &number);
            int status = find(start, number);

            if (status) {
                printf(" Found\n");
            }
            else {
                printf(" Not Found\n");
            }
        }
    }
}
