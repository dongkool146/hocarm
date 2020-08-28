#include<bits/stdc++.h>
using namespace std;
int x[100],n,k;
bool test=true;
void print()
{
	cout<<"(";
	for(int i=1;i<k;i++)
		cout<<x[i]<<" ";
	cout<<x[k]<<") ";
}
void next_division()
{
	int i=k,j,D,R,S;
	while(i>0 && x[i]==1)	i--;
	if(i>0)
	{
		x[i]--;
		D=k-i+1;
		R=D/x[i];
		S=D%x[i];
		k=i;
		if(R>0)
		{
			for(j=i+1;j<=i+R;j++)
				x[j]=x[i];
			k+=R;
		}
		if(S>0)
		{
			k++;
			x[k]=S;
		}
	}
	else	test=false;
}
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		k=1;	x[k]=n;
		while(test)
		{
			print();
			next_division();
		}
		test=true;	cout<<endl;
	}
}
