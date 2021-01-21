#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class ciag
{
	public:
	ifstream fIn;
	ofstream fOut;
	
	vector<int> liczby;
	
	int num_c, max, dl_c, diff, num;
	bool czy_ary;
	
	ciag()
	{
		fIn.open("ciagi.txt");
		fOut.open("wyniki.txt");
	}
	
	~ciag()
	{
		fIn.close();
		fOut.close();
	}
	
	void pob()
	{
		while(!fIn.eof())
		{
			fIn>>dl_c;
			
			for(int i=0; i<dl_c; i++)
			{
				fIn>>num;
				liczby.push_back(num);
				
			}
			
			diff=liczby[1]-liczby[0];
			
			czy_ary=true;
			
			for(int i=0; i+1<dl_c; i++)
			{
				if(diff!=liczby[i+1]-liczby[i])
				{
					czy_ary=false;
				}
			}
			
			if(czy_ary)
			{
				num_c++;
				if(max<diff)
				{
					max=diff;
				}
			}
			
			liczby.clear();
			
		}
		cout<<num_c<<endl;
		cout<<max;
	}
	
};

int main(int argc, char** argv) 
{
	
	ciag c1;
	c1.pob();
	
	
	return 0;
}
