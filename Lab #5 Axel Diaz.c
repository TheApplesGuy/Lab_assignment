// Axel Diaz Bringuez
// 2/08/2024
// COP 3502

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int counter = 0;
    while (head != NULL)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int leng = length(head);
    char* str = (char*)malloc((leng + 1) * sizeof(char)); 
    if (str == NULL)
    {
        printf("Failed to allocate memory");
    }

    int i = 0;
    while (head != NULL)
    {
        str[i++] = head->letter;
        head = head->next;
    }
    str[i] = '\0'; 
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* nNode = (node*)malloc(sizeof(node));
    if (nNode == NULL)
    {
        printf("Failed to allocate memory");
    }

    nNode->letter = c;
    nNode->next = NULL;

    if (*pHead == NULL)
    {
        *pHead = nNode;
    }
    else
    {
        node* holder = *pHead;
        while (holder->next != NULL)
        {
            holder = holder->next;
        }
        holder->next = nNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* holder = *pHead;
    node* next;
    while (holder != NULL)
    {
        next = holder->next;
        free(holder);
        holder = next;
    }
    *pHead = NULL;
}


int main(void) {

int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;

FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);

while (numInputs-->0) {
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)

{

fscanf(inFile," %c", &c);
insertChar(&head, c);

}

	str = toCString(head);
	printf("String is : %s\n", str);
		free(str);
		deleteList(&head);
if (head != NULL){
		printf("deleteList is not correct!");
	break;
}
}

fclose(inFile);
}