#include <bits/stdc++.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Head = NULL;

struct node *insertBeg(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        std::cout << "Memory allocation error." << std::endl;
        exit(1);
    }
    newNode->data = val;
    newNode->next = Head;
    Head = newNode;
    return newNode;
}

int lengthLL()
{
    int count = 0;
    if (Head == NULL)
    {
        return 0;
    }
    struct node *i = Head;
    while (i != NULL)
    {
        ++count;
        i = i->next;
    }
    return count;
}

void printLL()
{
    if (Head == NULL)
    {
        std::cout << "The linked list is empty." << std::endl;
    }
    struct node *i;
    std::cout << "Length of the linked list is: " << lengthLL() << std::endl;
    for (i = Head; i != NULL; i = i->next)
    {
        std::cout << i->data << " -> ";
    }
    if (i == NULL)
    {
        std::cout << "X";
    }
    std::cout << std::endl;
}

void deleteVal(int val)
{
    struct node *temp, *i = Head;
    while ((i->next)->data != val)
    {
        i = i->next;
    }
    temp = i->next;
    i->next = i->next->next;
    free(temp);
}

void deleteHead()
{
    if (Head == NULL)
    {
        std::cout << "The linked list is already empty!" << std::endl;
    }
    struct node *temp = Head;
    Head = Head->next;
    free(temp);
}

void deleteTail()
{
    struct node *temp, *i = Head;
    if (Head == NULL)
    {
        std::cout << "The linked list is already empty!" << std::endl;
    }
    while ((i->next)->next != NULL)
    {
        i = i->next;
    }
    temp = i->next;
    i->next = NULL;
    free(temp);
}

void deallocate()
{
    std::cout << "Deallocating Memory..." << std::endl;
    struct node *current = Head;
    struct node *next;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    std::cout << "Deallocation Successful. Exiting..." << std::endl;
}

int main()
{
    insertBeg(3);
    insertBeg(2);
    insertBeg(1);
    insertBeg(100);
    printLL();
    deleteVal(2);
    printLL();
    deleteHead();
    printLL();
    deleteTail();
    printLL();
    deallocate();
    return 0;
}