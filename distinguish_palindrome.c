#define _CRT_SECURE_NO_WARNINGS                      

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct node
{
    char data;
    struct node* link;
};

typedef struct node* Node;

struct node* CreateNode()
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    return newNode;
}


void Push(Node* qu, char word)
{
    Node temp = *qu;
    *qu = CreateNode();
    (*qu)->data = word;
    (*qu)->link = temp;
}

char POP(Node* stack)
{
    char word = 0;
    Node temp = *stack;
    if (temp == NULL)
    {
        printf("스택이 비었습니다!");
        return word;
    }
    else
    {
        word = temp->data;
        *stack = temp->link;
        return word;
    }
}

char Dequeue(Node* qu)
{
    Node temp = *qu;
    char word = 0;
    if (temp == NULL)
    {
        printf("큐가 비었습니다!");
        return word;
    }

    if (temp->link == NULL)
    {
        word = temp->data;
        *qu = NULL;
        return word;
    }

    else
    {
        while ((temp->link)->link != NULL)

            //   while(temp->link != NULL) //임시
        {
            temp = temp->link;
        }
        word = (temp->link)->data;
        temp->link = NULL;
        free(temp->link);
        return word;
    }
}


int main()
{
    while(1){
    Node Queue;
    Node Stack;
    char word[MAX_SIZE];

    printf("단어 입력 :");
    scanf("%s", word);
    Queue = 0;
    Stack = 0;

    char s_ch, q_ch;
    for (size_t i = 0; i < strlen(word); i++)
    {
        Push(&Stack, word[i]);
        Push(&Queue, word[i]);
    }


    int num = 1;
    s_ch = 1;
    q_ch = 1;

    while (s_ch != 0 && q_ch != 0 && num == 1)
    {
        s_ch = POP(&Stack);
        q_ch = Dequeue(&Queue);
        if (s_ch != q_ch)
        {
            num = 0;
        }
        if (num == 0) {
            printf("회문이 아닙니다.\n");
            break;
        }
        else {

            printf("회문입니다.\n");
            break;
        }

    }
    }
    return 0;
}













