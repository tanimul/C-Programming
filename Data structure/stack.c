#include<stdio.h>
#define SIZE 5      

int s[SIZE];        
int top = -1;      

void push(int elem) 
{
    if(isFull())
        printf("\n Stack is full ! \n");
    else {
        ++top;
        s[top] = elem;
    }
}

int pop()          
{
    int elem;
    if(isEmpty()) {
        printf("\n Stack is Empty ! \n");
        return -1;
    }
    else {
        elem = s[top];
        top--;
        return elem;
    }
}

int isFull()      
{
    if(top == SIZE - 1)
        return 1;
    return 0;
}

int isEmpty()      
{
    if(top == -1)
        return 1;
    return 0;
}

void display()  
{
    int i;
    if(isEmpty())
        printf(" \n Empty Stack \n ");
    else
    {
        for (i = 0; i <= top; i++)
            printf("%d\n", s[i]);
        printf("^Top");
    }
}

int main()  
{
    int opn, elem;
    do
    {
        printf(" \n Stack Operations \n ");
        printf(" \n Press 1-Push, 2-Pop,3-Display,4-Exit \n ");
        printf(" \n Your option ? ");
        scanf("%d", &opn);

        switch (opn)
        {
        case 1:
            printf(" \n Enter the element to be pushed ? ");
            scanf("%d", &elem);
            push(elem);
            break;
        case 2:
            elem = pop();
            if (elem != -1)
                printf(" \n Popped Element is %d \n ", elem);
            break;
        case 3:
            printf(" \n Status of Stack \n ");
            display();
            break;
        case 4:
            printf(" \n Terminating \n ");
            break;
        default:
            printf(" \n Invalid Option !!! Try Again !! \n ");
            break;
        }
        printf(" \n Press a Key to Continue . . . ");
    }
    while (opn != 4);
}

