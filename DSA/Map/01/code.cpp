#include<bits/stdc++.h>
#include<set>
#include<map>
using namespace std;
int main()
{
    //map<datatype1 , datatype2 > mp;
    //key , value 
    //key : unique , value : not unique
    map < int , int > mp ;
    mp[100] = 200 ;
    mp[200]= 300 ;
    mp.insert({300, 400});
    mp.insert({400, 500}) ;
    cout <<mp.size()<<endl ;
    //xuat ra tat ca cac phan tu trong map
    for ( pair < int , int > x : mp )
    {
        cout << x.first << " " << x.second << endl ;
    }
    for ( auto x : mp )
    {
        cout << x.first << " " << x.second << endl ;
    }
    for ( map < int , int >:: iterator it = mp.begin() ; it != mp.end() ; it++ )
    {
        cout << it->first << " " << it->second << endl ;
    }
    //count 
    if ( mp.count(100) != 0 )
    {
        cout << "Found!" << endl ;
    }
    else
    {
        cout << "Not Found!" << endl ;
    }
    //find 
    if ( mp.find(100) != mp.end() )
    {
        cout << "Found!" << endl ;
    }
    else
    {
        cout << "Not Found!" << endl ;
    }
    //erase
    mp.erase(100) ;
    //Dem so lan xuat hien cua phan tu trong map , in ra so lan xuat hien cua phan tu do
    /* input : 8
                1 2 3 4 5 6 7 8 
       output : 1 1
                2 1
                3 1
                4 1
                5 1
                6 1
                7 1
                8 1 
     */
    /*  
    map< int , int> mp ;
    int n ; cin>> n ;
    int a[n] ;
    for ( int i = 0 ; i < n ; i++ )
    {
        int x ; cin >> x ;
        mp[a[i]]++ ;
    }
    for ( auto x : mp )
    {
        cout << x.first << " " << x.second << endl ;
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        if( mp[a[i]] != 0) 
        {
        cout << a[i] << " " << mp[a[i]] << endl ;
        mp[a[i]] = 0 ;
        }
    }

    */
  






}
