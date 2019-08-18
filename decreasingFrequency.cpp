#include <bits/stdc++.h>
using namespace std;

map<int, int> mp1;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return mp1[a.first] < mp1[b.first];

    return a.second > b.second;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<pair<int, int>> vec;
    map<int, int> mp;
    int ip;

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        mp[arr[i]]++;

        if (mp1[arr[i]] == 0)
            mp1[arr[i]] = i + 1;
    }

    copy(mp.begin(), mp.end(), back_inserter(vec));

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].second; j++)
        {
            cout << vec[i].first << " ";
        }
    }
}