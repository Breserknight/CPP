#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int x,y,z,n=0,p;
    cout<<"Enter the number of seats"<<endl;
    cin>>x;

     for(n;(1<<n)<=x;n++)
     {
     }
     z = x-(1<<(n-1));
     p=2*z+1;
     cout<<"You'll be safe in seat number "<<p;

}
