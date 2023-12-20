#include <bits/stdc++.h>

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }
};

class DLL
{
private:
    Node *Head;

public:
    Node *insertBegin(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = Head;
        Head = newnode;
        newnode->prev = nullptr;
        return newnode;
    }

    Node *insertAfter(int posEle, int val)
    {
        if (Head == nullptr)
        {
            insertBegin(val);
        }
        Node *newnode = new Node(val);
        Node *i = Head;
        while (i != nullptr && i->data != posEle)
        {
            i = i->next;
        }
        if (i == nullptr)
        {
            return nullptr;
        }
        newnode->next = i->next;
        i->next = newnode;
        newnode->prev = i;
        newnode->next->prev = newnode;
        return newnode;
    }

    Node *insertEnd(int val)
    {
        if (Head == nullptr)
        {
            insertBegin(val);
        }
        Node *newnode = new Node(val);
        Node *i = Head;
        while (i->next != nullptr)
        {
            i = i->next;
        }
        newnode->next = nullptr;
        newnode->prev = i;
        i->next = newnode;
        return newnode;
    }

    void dropHead()
    {
        if (Head == nullptr)
        {
            std::cout << "The list is already empty." << std::endl;
            return;
        }
        Node *temp = Head;
        Head = Head->next;
        Head->prev = nullptr;
        delete (temp);
    }

    void dropVal(int val)
    {
        if (Head == nullptr)
        {
            std::cout << "The list is already empty." << std::endl;
            return;
        }
        if (Head->data == val)
        {
            dropHead();
            return;
        }
        Node *temp = Head;
        while (temp != nullptr && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            std::cout << "Value not found in the list." << std::endl;
            return;
        }
        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void dropTail()
    {
        if (Head == nullptr)
        {
            std::cout << "The list is already empty." << std::endl;
            return;
        }
        Node *temp = Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete (temp);
    }

    void printLL()
    {
        if (Head == nullptr)
        {
            std::cout << "The linked list is empty." << std::endl;
            return;
        }
        Node *i = Head;
        std::cout << "X ";
        while (i != nullptr)
        {
            std::cout << " <-> " << i->data << " <-> ";
            i = i->next;
        }
        std::cout << " X" << std::endl;
    }
};

int main()
{
    DLL myList;
    myList.printLL();
    myList.insertBegin(10);
    myList.insertBegin(20);
    myList.insertBegin(30);
    myList.printLL();
    myList.insertEnd(100);
    myList.printLL();
    myList.insertAfter(20, 2000);
    myList.printLL();
    myList.dropHead();
    myList.printLL();
    myList.dropTail();
    myList.printLL();
    myList.dropVal(2000);
    myList.printLL();
    return 0;
}