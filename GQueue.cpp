#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue
{
    public :
        struct node<T> * first;
    public :
        Queue();
        void Enqueue(T no);
        T Dequeue();
        void Display();
};

template <class T>
Queue<T> :: Queue()
{
    first = NULL;
}

template <class T>
void Queue<T>:: Enqueue(T no)
{
    struct node<T> * newn = new (struct node<T>);
    struct node<T> * temp = first;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }   
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

template <class T>
T Queue<T>:: Dequeue()
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
void Queue<T>:: Display()
{
    cout<<"Nodes in the Linked List are :\n";

    struct node<T> * temp = first;

    while (temp != NULL)
    {
        cout<<" | "<<temp->data<<" | ->";
        temp = temp->next;
    }
    cout<<" NULL \n";
    
}

int main()
{
    Queue<int> iobj;
    Queue<float> fobj;
    Queue<double> dobj;
    Queue<char> cobj;
    int iRet = 0;
    float fRet = 0.0f;
    double dRet = 0.0;
    char cRet = '\0';

    iobj.Enqueue(11);
    iobj.Enqueue(21);
    iobj.Enqueue(51);
    iobj.Enqueue(101);
    iobj.Enqueue(111);

    cout<<"Queue of Integers : "<<"\n";
    iobj.Display();
    iRet = iobj.Dequeue();
    cout<<"Dequeue node are : "<<iRet<<"\n";
    
    iRet = iobj.Dequeue();
    cout<<"Dequeue node are : "<<iRet<<"\n";
    
    iRet = iobj.Dequeue();
    cout<<"Dequeue node are : "<<iRet<<"\n";
    
    iRet = iobj.Dequeue();
    cout<<"Dequeue node are : "<<iRet<<"\n";
    
    iRet = iobj.Dequeue();
    cout<<"Dequeue node are : "<<iRet<<"\n";
        
    fobj.Enqueue(11.99);
    fobj.Enqueue(21.99);
    fobj.Enqueue(51.99);
    fobj.Enqueue(101.99);
    fobj.Enqueue(111.99);

    cout<<"\nQueue of Floats : "<<"\n";
    fobj.Display();
    fRet = fobj.Dequeue();
    cout<<"Dequeue node are : "<<fRet<<"\n";
    
    fRet = fobj.Dequeue();
    cout<<"Dequeue node are : "<<fRet<<"\n";
    
    fRet = fobj.Dequeue();
    cout<<"Dequeue node are : "<<fRet<<"\n";
    
    fRet = fobj.Dequeue();
    cout<<"Dequeue node are : "<<fRet<<"\n";
    
    fRet = fobj.Dequeue();
    cout<<"Dequeue node are : "<<fRet<<"\n";
        
    dobj.Enqueue(11.5555);
    dobj.Enqueue(21.5555);
    dobj.Enqueue(51.5555);
    dobj.Enqueue(101.5555);
    dobj.Enqueue(111.5555);

    cout<<"\nQueue of Doubles : "<<"\n";
    dobj.Display();
    dRet = dobj.Dequeue();
    cout<<"Dequeue node are : "<<dRet<<"\n";
    
    dRet = dobj.Dequeue();
    cout<<"Dequeue node are : "<<dRet<<"\n";
    
    dRet = dobj.Dequeue();
    cout<<"Dequeue node are : "<<dRet<<"\n";
    
    dRet = dobj.Dequeue();
    cout<<"Dequeue node are : "<<dRet<<"\n";
    
    dRet = dobj.Dequeue();
    cout<<"Dequeue node are : "<<dRet<<"\n";
        
    cobj.Enqueue('A');
    cobj.Enqueue('B');
    cobj.Enqueue('C');
    cobj.Enqueue('D');
    cobj.Enqueue('E');

    cout<<"\nQueue of Characters : "<<"\n";
    cobj.Display();
    cRet = cobj.Dequeue();
    cout<<"Dequeue node are : "<<cRet<<"\n";
    
    cRet = cobj.Dequeue();
    cout<<"Dequeue node are : "<<cRet<<"\n";
    
    cRet = cobj.Dequeue();
    cout<<"Dequeue node are : "<<cRet<<"\n";
    
    cRet = cobj.Dequeue();
    cout<<"Dequeue node are : "<<cRet<<"\n";
    
    cRet = cobj.Dequeue();
    cout<<"Dequeue node are : "<<cRet<<"\n";
        
    return 0;
}