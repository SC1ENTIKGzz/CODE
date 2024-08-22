#include<bits/stdc++.h>
#include<queue>
using namespace std ;
struct Queue
{
    int front , rear , capacity ;
    int* array ;
    Queue(int c)
    {
        front = rear = 0 ;
        capacity = c ;
        array = new int ;
    }
    ~Queue()
    {
        delete[] array ;
    }
    void enQueue(int x)
    {
        if ( capacity == rear )
        {
            cout << "Queue is full" << endl ;
            return ;
        }
        else
        {
            array[rear] = x ;
            rear++ ;
        }
        return ;
    }
    void deQueue()
    {
        if ( front == rear )
        {
            cout << "Queue is empty" << endl ;
            return ;
        }
        else
        {
            for ( int i = 0 ; i < rear - 1 ; i++ )
            {
                array[i] = array[i+1] ;
            }
            rear-- ;
        }
        return ;
    }
    void display()
    {
        if ( front == rear )
        {
            cout << "Queue is empty" << endl ;
            return ;
        }
        for ( int i = front ; i < rear ; i++ )
        {
            cout << array[i] << " " ;
        }
        cout << endl ;
        return ;
    }
    int size()
    {
        return rear - front ;
    }
    bool isEmpty()
    {
        return ( front == rear ) ;
    }
    int getFront()
    {
        if ( front == rear )
        {
            cout << "Queue is empty" << endl ;
            return -1 ;
        }
        return array[front] ;
    }
    int getRear()
    {
        if ( front == rear )
        {
            cout << "Queue is empty" << endl ;
            return -1 ;
        }
        return array[rear-1] ;
    }
};

int main()
{
    Queue q(4) ;
    q.enQueue(10) ;
    q.enQueue(20) ;
    q.enQueue(30) ;
    q.enQueue(40) ;
    q.display() ;
    cout << q.size() << endl ;
    cout << q.getFront() << endl ;
    cout << q.getRear() << endl ;
    q.deQueue() ;
    q.display() ;
    cout << q.size() << endl ;
    cout << q.getFront() << endl ;
    cout << q.getRear() << endl ;
    return 0 ;

}
