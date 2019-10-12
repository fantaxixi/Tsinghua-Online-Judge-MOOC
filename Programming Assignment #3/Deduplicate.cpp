#include<iostream>
#include<string>
using namespace std;
#define HASHSIZE 600001
struct Slot
{
	string s;
	Slot* suc = NULL;
	bool repeat;
} input[HASHSIZE];
void put(int key, string s)
{
	Slot* tmp = new Slot;
	tmp->s = s;
	tmp->suc = input[key].suc;           //为了保证接下来插入的格式相同，所以input[key]第一个值空出来，补充的是suc的值。
	tmp->repeat = false;
	input[key].suc = tmp;
}
unsigned int hashCode(string s)
{
	int h = 0;
	for(int n=s.size(), i=0; i<n; i++)
	{
		h = (h<<5) | (h>>27);
		h+=(unsigned int)s[i];
	}
	return h;
}

int main()
{
	int n;
	string s;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> s;
		int key = hashCode(s) % HASHSIZE;
		if(!input[key].suc)
			put(key, s);
		else
		{
			Slot* tmp = input[key].suc;
			while(tmp)
			{
				if(tmp->s==s && tmp->repeat==false)
				{
					cout << s << endl;
					tmp->repeat = true;
					break;
				}
				if(tmp->s==s && tmp->repeat==true)
				{
					break;
				}
				if(!tmp->suc)
					put(key,s);
				tmp = tmp->suc;
			}
		}
	}
	return 0;
}