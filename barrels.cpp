#include <bits/stdc++.h>
using namespace std;
#define ll long long


void calc(ll start , vector<ll> &barrel ,ll sum , ll capacity , vector< vector<ll> > &vec,vector<ll> &list)
{
    if(sum > capacity)
    {
        return;
    }

    if(sum == capacity)
    {
        vec.push_back(list);
        return;
    }

    for(ll i = start;i<barrel.size();i++)
    {
       
        list.push_back(barrel[i]);
        calc(i,barrel,sum + barrel[i],capacity,vec,list);
        list.pop_back();
    }

}

int main()
{

   ll n , capacity;
   cin>>n>>capacity;

   vector<ll> barrel(n),list;
   vector< vector<ll> > vec;

    for(ll i=0;i<n;i++)
        cin>>barrel[i];

    calc(0,barrel,0,capacity,vec,list);

    for(ll i = 0;i < vec.size();i++)
    {
        vector<ll> curr = vec[i];

        for(ll j=0; j< curr.size();j++)
        {
            cout<<curr[j]<<" ";
        }
        
        cout<<"\n";
    }
   
    
}

