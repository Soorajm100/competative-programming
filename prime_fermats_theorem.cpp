#include <bits/stdc++.h>
using namespace std; 
long long int fac[1000000+1]; 
long long int power(long long int x, long long int y,  
                                   long long int p) 
{ 
    long long int res = 1; 
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 
long long int modInverse(long long int  n, long long int p) 
{ 
    return power(n, p-2, p); 
} 

long long int nCrModPFermat(long long int n, long long int r, long long int p) 
{ 
   if (r==0) 
      return 1; 
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
int main()
{
	 
    long long int t;
    cin>>t;
    long long int mod = 1000000009;
    fac[0] = 1; 
    for (long long int i=1 ; i<=1000000; i++) 
        fac[i] = fac[i-1]*i%mod; 
    while(t--)
    {
       long long int l,k;
       cin>>l>>k;
       
       long long int x = power(5,k,mod);
       long long int y = power(21,l-k,mod);
       long long combination = nCrModPFermat(l, k, mod);
       long long int answer = (((combination%mod)*(x%mod)%mod)*(y%mod))%mod;
       cout<<answer<<"\n";
       
    }
    return 0;
}
