// Singly Circular Link List in Generic way in C++.

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;
    public:
        SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no, int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

template <class T>
void SinglyCL<T>:: InsertFirst(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else 
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    Count++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    newn = new struct node<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else 
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    Count++;
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of linked list are : \n";

    do
    {
        cout<<"| "<<first->data<<" | =>";
        first = first->next;   
    } while (first != last->next);
        
    cout<<"Address of First node\n";
}

template <class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete(last->next);
        last->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        while (temp->next != last)
        {
            temp = temp->next;
        }
        delete(last);
        last = temp;
        last->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = NULL;
        newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = first;
        struct node<T> * targatednode = NULL;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp->next;
        }
        targatednode = temp->next;
        temp->next = temp->next->next;
        delete(targatednode);

        Count--;
    }
}
    
int main()
{
    SinglyCL<int> iobj;
    SinglyCL<float> fobj;
    SinglyCL<double> dobj;
    SinglyCL<char> cobj;
    int iRet = 0;
    float fRet = 0.0f;
    double dRet = 0.0;
    int cRet = 0;

    iobj.InsertLast(11);
    iobj.InsertLast(21);
    iobj.InsertLast(51);
    iobj.InsertLast(101);

    cout<<"LinkedList of Integers : "<<"\n";
    iobj.Display();

    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    iobj.InsertAtPos(81, 4);

    iobj.Display();

    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    iobj.DeleteAtPos(4);

    iobj.Display();

    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();

    iRet = iobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    

    fobj.InsertLast(11.99);
    fobj.InsertLast(21.99);
    fobj.InsertLast(51.99);
    fobj.InsertLast(101.99);

    cout<<"\nLinkedList of Floats : "<<"\n";
    fobj.Display();

    fRet = fobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<fRet<<"\n";

    fobj.InsertAtPos(81.99, 4);

    fobj.Display();

    fRet = fobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<fRet<<"\n";

    fobj.DeleteAtPos(4);

    fobj.Display();

    fRet = fobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<fRet<<"\n";

    fobj.DeleteFirst();
    fobj.DeleteLast();

    fobj.Display();

    fRet = fobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<fRet<<"\n";


    dobj.InsertLast(11.9999);
    dobj.InsertLast(21.9999);
    dobj.InsertLast(51.9999);
    dobj.InsertLast(101.9999);

    cout<<"\nLinkedList of Doubles : "<<"\n";
    dobj.Display();

    dRet = dobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<dRet<<"\n";

    dobj.InsertAtPos(81.9999, 4);

    dobj.Display();

    dRet = dobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<dRet<<"\n";

    dobj.DeleteAtPos(4);

    dobj.Display();

    dRet = dobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<dRet<<"\n";

    dobj.DeleteFirst();
    dobj.DeleteLast();

    dobj.Display();

    dRet = dobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<dRet<<"\n";


    cobj.InsertLast('A');
    cobj.InsertLast('B');
    cobj.InsertLast('C');
    cobj.InsertLast('D');

    cout<<"\nLinkedList of Characters : "<<"\n";
    cobj.Display();

    cRet = cobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<cRet<<"\n";

    cobj.InsertAtPos('E', 5);

    cobj.Display();

    cRet = cobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<cRet<<"\n";

    cobj.DeleteAtPos(5);

    cobj.Display();

    cRet = cobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<cRet<<"\n";

    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();

    cRet = cobj.CountNode();
    cout<<"Number of elements in the linked list are : "<<cRet<<"\n";

    return 0;
}