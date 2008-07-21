#include<iostream>
#include<cstring>

using namespace std;

class str
{
	public:
		string list[10];
		int count;
	
		void inputstring();
	
		void sortstring();
};

void str::inputstring()
{
	int n=0;
	while(n!=count)
	{
		getline(cin, list[n]);
		n++;
	}
}

void str::sortstring()
{
	string temp;
	for(int i=0;i<count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(list[i]>list[j])
			{
				temp=list[i];
				list[i]=list[j];
				list[j]=temp;
			}
		}
	}
	for(int k=0;k<count;k++)
	{
		cout<<list[k];
	}

}

int main()
{
	str a;
	cin>>a.count;
	cin.ignore(10,'\n');
	a.inputstring();
	a.sortstring();
	return 0;
}		
