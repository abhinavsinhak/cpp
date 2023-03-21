#include <iostream>
using namespace std;

template <class T>
class Stack
{
private:
    T *arr;
    int capacity;
    int top;

public:
    Stack(int size)
    {
        arr = new T[size];
        capacity = size;
        top = -1;
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(T x)
    {
        if (isFull())
        {
            cout << "Stack overflow\n";
            exit(EXIT_FAILURE);
        }
        cout << "Inserting " << x << "\n";
        arr[++top] = x;
    }
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            exit(EXIT_FAILURE);
        }
        cout << "Removing " << peek() << "\n";
        return arr[top--];
    }
    T peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }
};

int main()
{
    Stack<int> integer_stack(3);

    integer_stack.push(1);
    integer_stack.push(2);

    integer_stack.pop();

    integer_stack.push(3);

    cout << "The top element is " << integer_stack.peek() << endl;

    return 0;
}