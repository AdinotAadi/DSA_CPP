#include <bits/stdc++.h>
#define MAX 10

class Stack
{
public:
    int arr[MAX];
    int top;

    void init()
    {
        top = -1;
    }

    int isFull()
    {
        if (top == MAX - 1)
            return 1;
        return 0;
    }

    int isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }

    void push(int val)
    {
        if (isFull())
        {
            std::cout << "The stack is already full." << std::endl;
            return;
        }
        arr[++top] = val;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "The stack is already empty." << std::endl;
            return;
        }
        std::cout << "Popped value: " << arr[top--] << std::endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -9999;
        }
        return arr[top];
    }

    int length()
    {
        if (!isEmpty())
        {
            return top + 1;
        }
        return -1;
    }

    void display()
    {
        if (!isEmpty())
        {
            std::cout << "->";
            for (int i = top; i >= 0; i--)
            {
                std::cout << "\t" << arr[i] << std::endl
                          << "\t--" << std::endl;
            }
            std::cout << std::endl;
            std::cout << "xxxxxxxxxxxxxxxxxxx" << std::endl;
            return;
        }
        std::cout << "The stack is empty." << std::endl;
    }
};

int main()
{
    Stack S;
    S.init();
    S.display();
    S.pop();
    S.push(10);
    S.display();
    S.push(20);
    S.push(30);
    S.display();
    S.push(40);
    S.push(50);
    S.push(60);
    S.push(70);
    std::cout << "Length of the stack: " << S.length() << std::endl;
    S.display();
    std::cout << "Topmost element is: " << S.peek() << std::endl;
    while (S.top != -1)
    {
        S.pop();
    }
    std::cout << "Length of the stack: " << S.length() << std::endl;
    return 0;
}