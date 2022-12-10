#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void w(vector<ll> &arr)
{
     ll size = arr.size();
      nth_element(begin(arr), begin(arr) + size / 2, end(arr));
    ll m = *(begin(arr) + size / 2);
    #define A(i) arr[(1 + 2 * (i)) % (size | 1)]
     ll l = 0, r = size - 1;
      for (ll i = 0; i <= r;){
         if (A(i) > m) swap(A(i++), A(l++));
        else if (A(i) < m) swap(A(i), A(r--));
        else i++;
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
         ll n;
        cin >> n;
        vector<ll> a;
        for (ll i = 0; i < n; i++)
        {
             ll x;
             cin >> x;
             a.push_back(x);
            
        }
         w(a);
         ll pl = 0;
         for (ll i = 0; i < n - 2; i++)
        {
           if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
            {
                 pl = 1;
            } 
             if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
            {
                 pl = 1;
            }
        }
         if (pl == 0)
        {
             for (ll i = 0; i < n; i++){

               cout << a[i] << " ";
            }
        
        }
        else
        {
             cout << "-1";
            
        }
         cout << endl;
    
    }
}