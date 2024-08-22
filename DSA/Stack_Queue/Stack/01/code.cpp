#include<iostream>
#include<bits/stdc++.h>
using namespace std ;
#define max 300
struct Stack 
{
    int top ;
    int a[max] ;
    Stack()
    {
        top = -1 ;
    }
    void createStack( Stack &s)
    {
       s.top= -1 ;
    }
    int isFull( Stack s )
    {
       if ( s.top >= max )
       return 1 ;
    else return 0 ;
    }
    int isEmpty( Stack s )
    {
       if ( s.top == -1 )
       return 1 ;
    else return 0 ;
    }
    int push ( Stack &s , int x )
    {
        if( isFull(s) == 0 )
        {
            s.top++ ;
            s.a[s.top] = x ;
            return 1 ; 

        }
        else return 0 ;
    }
    void pop()
    {
        if( top < 0 )
        {
            cout << "Stack is empty" << endl ;
            return ;
        }
        top-- ;
    }
    int peek()
    {
        if( top < 0 )
        {
            cout << "Stack is empty" << endl ;
            return -1 ;
        }
        return a[top] ;
    }
    bool isEmpty()
    {
        return top < 0 ;
    }
    void print()
    {
        for( int i = 0 ; i <= top ; i++ )
        {
            cout << a[i] << " " ;
        }
        cout << endl ;
    }
    int size()
    {
        return top + 1 ;
    }
    

   
    void DectoBin( int n )
    {
        stack<int> s ;
        while ( n > 0 )
        {
            s.push(n%2) ;
            n = n/2 ;
        }
        while ( !s.empty() )
        {
            cout << s.top() ;
            s.pop() ;
        }
    }
    void printReverse( string s )
    {
        stack<char> st ;
        for( int i = 0 ; i < s.length() ; i++ )
        {
            st.push(s[i]) ;
        }
        while( !st.empty() )
        {
            cout << st.top() ;
            st.pop() ;
        }
    }
    bool isValidLatex( string s )
    {
        stack<char> st ;
        for( int i = 0 ; i < s.length() ; i++ )
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{' )
            {
                st.push(s[i]) ;
            }
            else
            {
                if( st.empty() )
                {
                    return false ;
                }
                if( s[i] == ')' && st.top() != '(' )
                {
                    return false ;
                }
                if( s[i] == ']' && st.top() != '[' )
                {
                    return false ;
                }
                if( s[i] == '}' && st.top() != '{' )
                {
                    return false ;
                }
                st.pop() ;
            }
        }
        return st.empty() ;
    }
    
    void nextGreaterElement( int arr[] , int n )
    {
        stack<int> s ;
        s.push(arr[0]) ;
        for( int i = 1 ; i < n ; i++ )
        {
            if( s.empty() )
            {
                s.push(arr[i]) ;
                continue ;
            }
            while( !s.empty() && s.top() < arr[i] )
            {
                cout << s.top() << " --> " << arr[i] << endl ;
                s.pop() ;
            }
            s.push(arr[i]) ;
        }
        while( !s.empty() )
        {
            cout << s.top() << " --> " << -1 << endl ;
            s.pop() ;
        }
    }
    

} ;
int main()
{
    Stack s ;
    s.createStack(s) ;
    s.push(s, 10) ;
    s.push(s, 20) ;
    s.push(s, 30) ;
    s.push(s, 40) ;
    s.push(s, 50) ;
    s.print() ;
    s.pop() ;
    s.print() ;
    cout << s.peek() << endl ;
    cout << s.isEmpty() << endl ;
    cout << s.size() << endl ;
    s.DectoBin(63) ;
    cout << endl ;
    s.printReverse("I am a student") ;
    cout << endl ;
    cout << s.isValidLatex("{[()]}") << endl ;
    int arr[] = { 4 , 5 , 2 , 10 , 6 , 7 , 99 } ;
    s.nextGreaterElement(arr, 4) ;
    return 0 ;
}

