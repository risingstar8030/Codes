#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s1,s2;
    cout<<"Enter first String : ";
    cin>>s1;
    cout<<"Enter second String : ";
    cin>>s2;

    ll m = s1.size();ll n = s2.size();

    ll lcs[m+1][n+1];

    for(ll i=0;i<=m;i++)
    {
        for(ll j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                lcs[i][j] = 0;
            
            else if(s1[i-1] == s2[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            
            else
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }
    }

    string seq = "";

    ll i = m , j = n;

    while( i > 0 && j > 0 )
    {
        if(s1[i-1] == s2[j-1])
        {
            seq += s1[i-1];
            i--;
            j--;
        }
        else if(lcs[i-1][j] > lcs[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }    
    }
    reverse(seq.begin(),seq.end());

    cout<<"Count : "<<lcs[m][n]<<"\tSequence : "<<seq<<"\n";


}