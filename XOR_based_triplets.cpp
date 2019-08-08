#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() { // Codechef LongChallenge August (Guddu and his mother)
	
	ll t;
	cin>>t;
	
	while(t--)
	{
	    ll n,ip,ans=0;
		cin>>n;

		map<ll,ll> mp1,mp2,mp3;
		vector<ll> vec(n),xorarr(n);

		mp1[0] = -1;
		mp3[0] = 1;

		for(ll i=0;i< n;i++)
		{
			cin>>ip;
			vec[i] = ip;
		}

		xorarr[0] = vec[0];

		for(ll i=1;i<n;i++)
			xorarr[i] = xorarr[i-1] ^ vec[i];
		
		for(ll i=0;i<n;i++)
		{
			if(mp3.count(xorarr[i])==1)
			{
			   ll temp  =  (( i - ( mp1[xorarr[i]]+1 )) * mp3[xorarr[i]]) + mp2[xorarr[i]] + (mp3[xorarr[i]] -1) ;
				ans = ans + temp;
				mp3[xorarr[i]]++;
				mp2[xorarr[i]] = temp;
			}
			else
			{
				mp3[xorarr[i]]++;
			}
			mp1[xorarr[i]] = i;
		}

		cout<<ans<<"\n";

	    
	}
	return 0;
}
