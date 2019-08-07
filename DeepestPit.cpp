#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int deepestPit(const vector<int> &A);
 
int main()
{
	vector<int> A ;

    A.push_back(0);A.push_back(1);A.push_back(3);A.push_back(-2);A.push_back(0);
    A.push_back(1);A.push_back(0);A.push_back(-3);A.push_back(2);A.push_back(3);
	
 
	cout << "The result is " << deepestPit(A) <<endl;
 
	return 0;
}
 
int deepestPit(const vector<int> &A)
{
	int N = A.size();
	if (N < 3)
		return -1;
 
	std::vector<int> pitstore;
	int P(0), Q(0), R(0);
 
	for (int i = 0; i < N - 2; ++i)
	{
		if (A[i] >= A[i + 1])
		{
			P = A[i];
			for (i; i < N - 2; ++i)
			{
				while (A[i + 1] < A[i])
				{
					Q = A[i + 1];
					i++;
				}
				break;
			}
			i++;
			R = A[i];
			pitstore.push_back(min(P - Q, R - Q));
			while (A[i] < A[i + 1])
			{
				R = A[i + 1];
				pitstore.push_back(min(P - Q, R - Q));
				i++;
				if (i == N - 1)
					break;
			}
			i--;
		}
		else
		{
			while (A[i] > A[i + 1])
			{
				P = A[i];
				i++;
			}
		}
	}
	sort(pitstore.begin(), pitstore.end());
 
	if (pitstore.empty())
		return -1;
 
	return pitstore.back();
}