#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll row, col;

    cout << "Enter the no of rows : ";
    cin >> row;

    cout << "Enter the no of columns : ";
    cin >> col;

    map<pair<ll, ll>, ll> mp, ans;

    cout << "Enter the values : \n";
    for (ll i = 0; i < row; i++)
    {
        for (ll j = 0; j < col; j++)
        {
            ll ip;
            cin >> ip;
            mp[{i, j}] = ip;
        }
    }

    for (ll i = 0; i < col; i++)
        ans[{0, i}] = mp[{0, i}];

    for (ll j = 0; j < row; j++)
        ans[{j, 0}] = mp[{j, 0}];

    for (ll i = 1; i < row; i++)
    {
        for (ll j = 1; j < col; j++)
        {
            if (mp[{i, j}] == 1)
                ans[{i, j}] = min(mp[{i - 1, j - 1}], min(mp[{i, j - 1}], mp[{i - 1, j}])) + 1;
            else
                ans[{i, j}] = 0;
        }
    }

    ll maxValue = ans[{0, 0}], max_I = 0, max_J = 0;

    for (ll i = 0; i < row; i++)
    {
        for (ll j = 0; j < col; j++)
        {
            if (maxValue < ans[{i, j}])
            {
                maxValue = ans[{i, j}];
                max_I = i;
                max_J = j;
            }
        }
    }

    cout << "Maximum size square sub matrix : \n";

    for (ll i = max_I; i > max_I - maxValue; i--)
    {
        for (ll j = max_J; j > max_J - maxValue; j--)
        {
            cout << mp[{i, j}] << " ";
        }
        cout << "\n";
    }
}
