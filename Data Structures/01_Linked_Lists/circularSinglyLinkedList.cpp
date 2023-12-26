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

class CSLL
{
private:
    Node *head, *tail;

public:
    CSLL()
    {
        head = tail = nullptr;
    }

    Node *insertBegin(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {

            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
        return newNode;
    }

    Node *insertAfter(int posEle, int val)
    {
        if (head == nullptr)
        {
            insertBegin(val);
        }
        Node *i = head;
        while (i->data != posEle)
        {
            i = i->next;
        }
        Node *newNode = new Node(val);
        newNode->next = i->next;
        i->next = newNode;
        return newNode;
    }

    Node *insertEnd(int val)
    {
        if (head == nullptr)
        {
            insertBegin(val);
        }
        Node *newNode = new Node(val);
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
        return newNode;
    }

    void dropHead()
    {
        if (head == nullptr)
        {
            std::cout << "The linked list is already empty." << std::endl;
            return;
        }
        std::cout << "Dropped the head of the linked list." << std::endl;
        Node *temp = head;
        head = head->next;
        tail->next = head;
    }

    void dropVal(int val)
    {
        if (head == nullptr)
        {
            std::cout << "The linked list is already empty." << std::endl;
            return;
        }
        if (head->data == val)
        {
            dropHead();
            return;
        }
        Node *current = head;
        Node *previous = tail;
        do
        {
            if (current->data == val)
            {
                previous->next = current->next;
                if (current == tail)
                {
                    tail = previous;
                }
                delete current;
                std::cout << "Dropped the first occurrence of " << val << "." << std::endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
        std::cout << "Value " << val << " not found in the linked list." << std::endl;
    }

    void dropTail()
    {
        if (head == nullptr)
        {
            std::cout << "The linked list is already empty." << std::endl;
            return;
        }
        std::cout << "Dropped the tail of the linked list." << std::endl;
        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *i = head;
        while (i->next != tail)
        {
            i = i->next;
        }
        i->next = head;
        delete tail;
        tail = i;
    }

    void display()
    {
        if (head == nullptr)
        {
            std::cout << "Empty Linked List" << std::endl;
            return;
        }
        Node *i = head;
        do
        {
            std::cout << i->data << " -> ";
            i = i->next;
        } while (i != head);
        std::cout << "-<" << std::endl;
    }
};

int main()
{
    CSLL c;
    c.insertBegin(10);
    c.insertBegin(20);
    c.insertBegin(30);
    c.display();
    c.insertEnd(100);
    c.insertEnd(200);
    c.insertEnd(300);
    c.insertAfter(10, 40);
    c.insertAfter(100, 105);
    c.display();
    c.dropHead();
    c.display();
    c.dropHead();
    c.display();
    c.dropTail();
    c.display();
    c.dropTail();
    c.display();
    c.dropVal(105);
    c.display();
    c.dropVal(40);
    c.display();
    return 0;
}