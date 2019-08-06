#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool map_compare (map< ll,ll > const &lhs, map< ll,ll > const &rhs);
int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
       ll n,ip;
       cin>>n;
       vector<ll> C(n),H(n),level(n,0);
       map< ll,ll > mp,mp1;
       map< ll,ll > :: iterator itr1,itr2;
    
       for(ll i=0;i<n;i++)
       {
           cin>>ip;
           C[i] = ip;
       }
       for(ll i=0;i<n;i++)
       {
           cin>>ip;
           H[i] = ip;
           mp[ip]++;
       }
        for(ll i=0;i<n;i++)
       {
           /* Here Difference Array concept is used to update range query in O(1) 
            range(l , r , num) ==> arr[l] += num , arr[r+1] -= num;
            and then iterate over array 
            for i=0 to n
                arr[i] = arr[i] + arr[i-1];
           */
            ll d1 = (i+1) - C[i];
            if(d1 <= 0)
             {
                d1 = 0;
                level[d1]++;
             }
             else
             {
                d1 = d1-1;
                level[d1]++;
             }
             
            ll d2 = (i+1) + C[i];
            if(d2 < n)
            {
                level[d2]--;
            }       
       }
      
        for(ll i=0;i<n;i++)
        {
            if(i == 0)
                level[i] = level[0];
            else
            {
                level[i] = level[i] + level[i-1];
            }
            mp1[level[i]]++;
        }  
      
        
        bool flag = map_compare(mp1,mp);
        if(!flag)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
    
}

bool map_compare (map< ll,ll > const &lhs, map< ll,ll > const &rhs) {
    return lhs.size() == rhs.size()
        && equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}