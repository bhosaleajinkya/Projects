// Singly Linear Link List in Generic way in C++.

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};


template <class T>
class SinglyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        T Sum();
        bool LinearSearch(T no);
        int Frequency(T no);
        int FirstOccurance(T no);
        int LastOccurance(T no);
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
SinglyLL<T> ::SinglyLL()
{
    //cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template <class T>
void SinglyLL<T> ::InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T> ::InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template <class T>
void SinglyLL<T> ::Display()
{
    struct node<T> * temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}
/*
template <class T>
T SinglyLL<T>:: Maximum()
{
    struct node<T>* temp = first;
    T Max = ;

    while(temp != NULL)
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp = temp -> next;
    }
    return Max;
}
*/

template <class T>
T SinglyLL<T>:: Sum()
{
    struct node<T>* temp = first;
    T Sum = 0;

    while(temp != NULL)
    {
        Sum = Sum + (temp -> data);
        temp = temp -> next;
    }
    return Sum;
}

template <class T>
bool SinglyLL<T>::LinearSearch(T no)
{
    struct node<T>* temp = first;
    bool bFlag = false;

    while(temp != NULL)
    {
        if((temp -> data) == no)
        {
           bFlag = true;
           break;
        }
        temp = temp -> next;
    }
    return bFlag;
}

template <class T>
int SinglyLL<T>::Frequency(T no)
{
    struct node<T>* temp = first;
    int iCnt = 0;

    while(temp != NULL)
    {
        if((temp -> data) == no)
        {
           iCnt++;
        }
        temp = temp -> next;
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>:: FirstOccurance(T no)
{
    struct node<T>* temp = first;
    int iPos = 1;

    while(temp != NULL)
    {
        if((temp -> data) == no)
        {
           break;
        }
        temp = temp -> next;
        iPos++;
    }
    if(temp == NULL)
    {
        return -1;
    }
    else
    {
    return iPos;
    }
}

template <class T>
int SinglyLL<T>:: LastOccurance(T no)
{
    struct node<T>* temp = first;
    int iPos = -1;
    int iCnt = 1;

    while(temp != NULL)
    {
        if((temp -> data) == no)
        {
           iPos = iCnt;
        }
        temp = temp -> next;
        iCnt++;
    }

    return iPos;
}

template <class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyLL<T> ::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}

template <class T>
void SinglyLL<T> ::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T> * temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template <class T>
void SinglyLL<T> ::InsertAtPos(T no,int ipos)
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
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T> * temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template <class T>
void SinglyLL<T> ::DeleteAtPos(int ipos)
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
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T> * targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}

int main()
{
    
    SinglyLL<int> iobj;
    SinglyLL<float> fobj;
    SinglyLL<double> dobj;
    SinglyLL<char> cobj;
    int iRet = 0;
    float fRet = 0.0f;
    double dRet = 0.0;
    int cRet = 0;
    bool bRet = false;

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

    iRet = iobj.Sum();
    cout<<"# Summation of all elements is "<<iRet<<".\n";
    bRet = iobj.LinearSearch(51);
    if(bRet == true)
    {
        cout<<"# Element 51 is present in the Linked List\n";
    }
    else
    {
        cout<<"# There is no such element in the Linked List\n";
    }
    iRet = iobj.Frequency(11);
    cout<<"# Frequency of 11 is "<<iRet<<".\n";
    iRet = iobj.FirstOccurance(21);
    cout<<"# FirstOccurance of 21 is "<<iRet<<".\n";
    iRet = iobj.LastOccurance(51);
    cout<<"# LastOccurance of 51.99 is "<<iRet<<".\n";
    
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

    fRet = fobj.Sum();
    cout<<"# Summation of all elements is "<<fRet<<".\n";
    bRet = fobj.LinearSearch(51.99);
    if(bRet == true)
    {
        cout<<"# Element 51.99 is present in the Linked List\n";
    }
    else
    {
        cout<<"# There is no such element in the Linked List\n";
    }
    iRet = fobj.Frequency(11.99);
    cout<<"# Frequency of 11.99 is "<<iRet<<".\n";
    iRet = fobj.FirstOccurance(21.99);
    cout<<"# FirstOccurance of 21.99 is "<<iRet<<".\n";
    iRet = fobj.LastOccurance(51.99);
    cout<<"# LastOccurance of 51.99 is "<<iRet<<".\n";

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

    dRet = dobj.Sum();
    cout<<"# Summation of all elements is "<<dRet<<".\n";
    bRet = dobj.LinearSearch(21.9999);
    if(bRet == true)
    {
        cout<<"# Element 51.9999 is present in the Linked List\n";
    }
    else
    {
        cout<<"# There is no such element in the Linked List\n";
    }
    iRet = dobj.Frequency(11.9999);
    cout<<"# Frequency of 11.9999 is "<<iRet<<".\n";
    iRet = dobj.FirstOccurance(21.9999);
    cout<<"# FirstOccurance of 21.9999 is "<<iRet<<".\n";
    iRet = dobj.LastOccurance(51.9999);
    cout<<"# LastOccurance of 51.9999 is "<<iRet<<".\n";

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
    bRet = cobj.LinearSearch('B');
    if(bRet == true)
    {
        cout<<"# Element 'B' is present in the Linked List\n";
    }
    else
    {
        cout<<"# There is no such element in the Linked List\n";
    }
    iRet = cobj.Frequency('A');
    cout<<"# Frequency of A is "<<iRet<<".\n";
    iRet = cobj.FirstOccurance('C');
    cout<<"# FirstOccurance of C is "<<iRet<<".\n";
    iRet = cobj.LastOccurance('D');
    cout<<"# LastOccurance of D is "<<iRet<<".\n";

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
    
