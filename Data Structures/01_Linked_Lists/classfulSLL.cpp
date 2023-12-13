#include <bits/stdc++.h>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SLL
{
private:
    Node *Head;

public:
    SLL()
    {
        Head = nullptr;
    }

    Node *insertBeg(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = Head;
        Head = newNode;
        return newNode;
    }

    Node *insertBefore(int posEle, int val)
    {
        if (Head == nullptr)
        {
            insertBeg(val);
        }
        Node *newNode = new Node(val);
        Node *i = Head;
        while ((i->next)->data == posEle)
        {
            i = i->next;
        }
        newNode->next = i->next;
        i->next = newNode;
        return newNode;
    }

    Node *insertAfter(int posEle, int val)
    {
        if (Head == nullptr)
        {
            insertBeg(val);
        }
        Node *newNode = new Node(val);
        Node *i = Head;
        while (i->data != posEle)
        {
            i = i->next;
        }
        newNode->next = i->next;
        i->next = newNode;
        return newNode;
    }

    Node *insertEnd(int val)
    {
        if (Head == nullptr)
        {
            insertBeg(val);
        }
        Node *newNode = new Node(val);
        Node *temp = Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        return newNode;
    }

    void deleteHead()
    {
        if (Head == nullptr)
        {
            std::cout << "The linked list is already empty!" << std::endl;
        }
        Node *temp = Head;
        Head = Head->next;
        delete temp;
    }

    void deleteVal(int val)
    {
        if (Head == nullptr)
        {
            std::cout << "The linked list is already empty!" << std::endl;
        }
        if (Head->data == val)
        {
            deleteHead();
            return;
        }
        Node *i = Head;
        while ((i->next)->data != val)
        {
            i = i->next;
        }
        Node *temp = i->next;
        i->next = i->next->next;
        delete temp;
    }

    void deleteTail()
    {
        if (Head == nullptr)
        {
            std::cout << "The linked list is already empty!" << std::endl;
        }
        Node *i = Head;
        while ((i->next)->next != nullptr)
        {
            i = i->next;
        }
        Node *temp = i->next;
        i->next = nullptr;
        delete temp;
    }

    int lengthLL()
    {
        if (Head == nullptr)
        {
            return 0;
        }
        Node *i = Head;
        int count = 0;
        while (i != nullptr)
        {
            ++count;
            i = i->next;
        }
        return count;
    }

    int search(int val)
    {
        if (Head == nullptr)
        {
            std::cout << "The linked list is empty!" << std::endl;
        }
        int flag = 0, count = 0;
        for (Node *i = Head; i != nullptr; i = i->next)
        {
            ++count;
            if (i->data == val)
            {
                flag = 1;
                return count;
            }
        }
        return -1;
    }

    void printLL()
    {
        if (Head == nullptr)
        {
            std::cout << "Empty Linked List" << std::endl;
        }
        std::cout << "Length of the linked list is: " << lengthLL() << std::endl;
        Node *i = Head;
        while (i != nullptr)
        {
            std::cout << i->data << " -> ";
            i = i->next;
        }
        std::cout << "X" << std::endl;
    }
};

int main()
{
    SLL myList;
    myList.insertBeg(10);
    myList.insertBeg(20);
    myList.insertBeg(30);
    myList.printLL();
    myList.insertEnd(100);
    myList.printLL();
    myList.insertAfter(30, 69);
    myList.printLL();
    myList.deleteHead();
    myList.printLL();
    myList.deleteTail();
    myList.printLL();
    myList.deleteVal(69);
    myList.printLL();
    std::cout << "Position of 10 in the linked list is: " << myList.search(10) << std::endl;
    std::cout << "Position of 1 in the linked list is: " << myList.search(1) << std::endl;
    return 0;
}