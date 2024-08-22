#include<bits/stdc++.h>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    multimap < int , int > mp ;
    //key , value
    //key : not unique , value : not unique
    //multimap : key co the trung nhau
    //multimap : sap xep theo key
    //multimap : khong the truy cap den phan tu nhu vector , array
    //multimap : khong the truy cap den phan tu nhu map, set , unordered_map
    mp.insert({1, 2});
    mp.insert({1, 3});
    mp.insert({1, 4});
    mp.insert({1, 5});
    //xuat ra tat ca cac phan tu trong multimap
    for ( pair < int , int > x : mp )
    {
        cout << x.first << " " << x.second << endl ;
    }
    //find
    if ( mp.find(1) != mp.end() )
    {
        cout << "Found!" << endl ;
    }
    else
    {
        cout << "Not Found!" << endl ;
    }
    //count
    if ( mp.count(1) != 0 )
    {
        cout << "Found!" << endl ;
    }
    else
    {
        cout << "Not Found!" << endl ;
    }
    //erase
    mp.erase(1) ;
    //Dem so lan xuat hien cua phan tu trong multimap , in ra so lan xuat hien cua phan tu do
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
    */

    return 0;
}
 