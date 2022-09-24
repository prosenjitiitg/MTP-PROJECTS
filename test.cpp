#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	cin>>t>>n;
	while(t--)
	{
		for(int i = 0 ; i < n; i++)
		{
			cout<<rand()%500<<" ";
		}
		cout<<endl;	
	}
}