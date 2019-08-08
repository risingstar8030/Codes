#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   //Count of Subarrays having XOR value K in O(n)

   ll n,k,ip,count=0;
   cin>>n>>k;

    vector<ll> vec(n),xorarr(n);
    map<ll,ll> mp;

   for(ll i=0;i<n;i++)
   {
       cin>>ip;
       vec[i] = ip;
   }

    xorarr[0] = vec[0];

    for(ll i=1;i<n;i++)
        xorarr[i]  = xorarr[i-1] ^ vec[i];

    for(ll i=0; i<n;i++)
    {
        ll temp = k ^ xorarr[i];

        count = count + mp[temp];

        if(xorarr[i] == k)
            count++;

        mp[xorarr[i]]++;
    }

    cout<<count<<"\n";

    
}

