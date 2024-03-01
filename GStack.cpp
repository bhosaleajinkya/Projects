#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack
{
    private :
        struct node<T> *first;
    public :
        Stack();
        void Push(T no);
        T Pop();
        void Display();
};
 
template <class T>
Stack<T> :: Stack()
{
    first = NULL;    
}

template <class T>
void Stack<T>:: Push(T no)
{
    struct node<T> * newn = new (struct node<T>);

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }   
    else
    {
        newn->next = first;
        first = newn;
    }
}

template <class T>
T Stack<T>:: Pop()
{
    T value;
    struct node<T> * temp = first;

    if(first == NULL)
    {
        cout<<"Stack is Empty\n";
    }
    else
    {
        value = first->data;
        first = first->next;
        delete(temp);
    }
    return value;
}

template <class T>
void Stack<T>:: Display()
{
    cout<<"Nodes in the Linked List are :\n";
   
    struct node<T> * temp = first;

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | ->";
        temp = temp->next;
    }
    cout<<" NULL \n";
}

int main()
{
    Stack<int> iobj;
    Stack<float> fobj;
    Stack<double> dobj;
    Stack<char> cobj;
    int iRet = 0;
    float fRet = 0.0f;
    double dRet = 0.0;
    char cRet = '\0';

    iobj.Push(101);
    iobj.Push(51);
    iobj.Push(21);
    iobj.Push(11);

    cout<<"Stack of Integers : "<<"\n";
    iobj.Display();
    iRet = iobj.Pop();
    cout<<"Pop node are : "<<iRet<<"\n";

    iRet = iobj.Pop();
    cout<<"Pop node are : "<<iRet<<"\n";
    
    iRet = iobj.Pop();
    cout<<"Pop node are : "<<iRet<<"\n";
    
    iRet = iobj.Pop();
    cout<<"Pop node are : "<<iRet<<"\n";
    
    fobj.Push(101.99);
    fobj.Push(51.99);
    fobj.Push(21.99);
    fobj.Push(11.99);

    cout<<"Stack of Floats : "<<"\n";
    fobj.Display();
    fRet = fobj.Pop();
    cout<<"Pop node are : "<<fRet<<"\n";

    fRet = fobj.Pop();
    cout<<"Pop node are : "<<fRet<<"\n";
    
    fRet = fobj.Pop();
    cout<<"Pop node are : "<<fRet<<"\n";
    
    fRet = fobj.Pop();
    cout<<"Pop node are : "<<fRet<<"\n";
    
    dobj.Push(101.9980);
    dobj.Push(51.998);
    dobj.Push(21.998);
    dobj.Push(11.998);

    cout<<"Stack of Doubles : "<<"\n";
    dobj.Display();
    dRet = dobj.Pop();
    cout<<"Pop node are : "<<dRet<<"\n";

    dRet = dobj.Pop();
    cout<<"Pop node are : "<<dRet<<"\n";
    
    dRet = dobj.Pop();
    cout<<"Pop node are : "<<dRet<<"\n";
    
    dRet = dobj.Pop();
    cout<<"Pop node are : "<<dRet<<"\n";
        
    cobj.Push('D');
    cobj.Push('C');
    cobj.Push('B');
    cobj.Push('A');

    cout<<"Stack of Characters : "<<"\n";
    cobj.Display();
    cRet = cobj.Pop();
    cout<<"Pop node are : "<<cRet<<"\n";

    cRet = cobj.Pop();
    cout<<"Pop node are : "<<cRet<<"\n";
    
    cRet = cobj.Pop();
    cout<<"Pop node are : "<<cRet<<"\n";
    
    cRet = cobj.Pop();
    cout<<"Pop node are : "<<cRet<<"\n";
        
    return 0;
}