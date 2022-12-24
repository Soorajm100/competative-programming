//these are the bit manipu;ation  basic tempalte required for practise

#include<bits/stdc++.h>
using namespace std; 
int getithbit(int  n, int i)
{
    int mask = (1<<i);
    return (n&mask) > 0 ? 1:0;

}
int clearbit(int  n ,  int i )
{
    int mask = ~(1<<i);
    int final = (n&mask);
    return final;
}

int setithbit(int n , int i)
{

    n = (1<<i)|n;
    return n ;

}

int updatebit(int n , int i , int v)
{
    n = clearbit( n ,i);
    int  mask = (v<<i);
    n = n|mask;
    return n;

}

int clearLastBits(int n , int i )
{
    int mask = (-1<<i);
    n = n&mask;
    return n ;

}

int clearbitsRange(int n ,  int i  ,  int j )
{
    int a = (~0)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    n = n&mask;

    return n;


}


int main()
{
    uint32_t n;
     n =31;
    int  i = 1;
    int j = 3;
     cout<<getithbit(n ,i)<<endl;
     cout<<clearbit(n , i )<<endl;
     cout<<setithbit(n,i)<<endl;
     cout<<updatebit(n , i , 1 )<<endl;
     cout<<clearLastBits(n,i)<<endl;
     cout<<clearbitsRange(n , i , j)<<endl;
    return 0;
}
