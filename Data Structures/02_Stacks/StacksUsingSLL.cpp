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

class SLLStack
{
private:
    Node *head;

public:
    SLLStack()
    {
        head = nullptr;
    }
    Node *push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return newNode;
    }

    int pop()
    {
        if (head == nullptr)
        {
            return -1;
        }
        Node *temp = head;
        head = head->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    int peek()
    {
        if (head == nullptr)
        {
            return -1;
        }
        return (head->data);
    }

    void display()
    {
        if (head != nullptr)
        {
            std::cout << "->";
            for (Node *i = head; i != nullptr; i = i->next)
            {
                std::cout << "\t" << i->data << std::endl
                          << "\t--" << std::endl;
            }
            std::cout << "--------------------" << std::endl;
            return;
        }
        std::cout << "The stack is empty." << std::endl;
    }
};

int main()
{
    SLLStack s;
    s.display();
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    std::cout << "Popped value: " << s.pop() << std::endl;
    std::cout << "Topmost value is: " << s.peek() << std::endl;
    std::cout << "Popped value: " << s.pop() << std::endl;
    std::cout << "Popped value: " << s.pop() << std::endl;
    std::cout << "Popped value: " << s.pop() << std::endl;
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.push(500);
    s.push(600);
    s.display();
    s.pop();
    s.display();
    while (true)
    {
        if (s.pop() == -1)
            break;
        s.display();
    }
    return 0;
}