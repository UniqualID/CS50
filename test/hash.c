#include <stdio.h>
#include <stdlib.h>

typedef struct nodes
{
    int value;
    struct nodes* next;
}node;

int main()
{
    node* first = malloc(sizeof(node));
    int num = 0;
    first -> value = num;
    for(int i = 0; i < 25; i++)
    {
        //add new node to linked list
        node* newNode = malloc(sizeof(node));
        newNode -> value = num++;
        newNode -> next = first;
        first = newNode;
        printf("%d\t", newNode -> value);
    }

    //freeing memory
    node* cursor = first;
    while (first != NULL)
    {
        cursor = first;
        first = first->next;
        free(cursor);
    }
}