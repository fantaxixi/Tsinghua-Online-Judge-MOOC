#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#define NUM 4000001
const int SIZE = 1 << 21;        //缓存区大小

/*快速输入输出缓存区设置*/
struct FastIO {
    char inbuf[SIZE];
    char outbuf[SIZE];
    FastIO() {
        setvbuf(stdin,inbuf,_IOFBF,SIZE);
        setvbuf(stdout,outbuf,_IOFBF,SIZE);
    }
}IO;

struct node
{
	long long prior;
	string s;
	bool operator > (node& tmp)
	{
		return (prior < tmp.prior) || ((prior==tmp.prior) && (s<tmp.s));
	}
} data[NUM];

bool hasLChild(int i, int n)
{
	if(2*i+1 < n) return true;
	else return false;
}
bool hasRChild(int i, int n)
{
	if(2*i+2 < n) return true;
	else return false;
}
int PRIOR(int n, int m)
{
	if(data[n] > data[m])
		return n;
	else return m;
}
int properparent(int i, int n)
{
	int tmp=i;
	if(hasRChild(i, n))
	{
		tmp = PRIOR(i, PRIOR(2*i+1, 2*i+2));
	}
	else if(hasLChild(i, n))
	{
		tmp = PRIOR(i, 2*i+1);
	}
	return tmp;
}
/*   这一段会出错，不知为何
void percolateDown(int x, int n)
{
	while(properparent(x, n) !=x)
	{
		swap(data[x], data[properparent(x,n)]);
		x = properparent(x, n);
	}
}
*/
void percolateDown(int x, int n)
{
    int rp = properparent(x, n);
    while (rp != x) {
        swap(data[rp], data[x]);
        x = rp;
        rp = properparent(x, n);
    }
}
void heapify(int n)
{
	for(int i=n/2; i>=0; i--)
	{
		percolateDown(i, n);
	}
}

int main()
{
	int n, m;
	cin >> n >> m; //用cin会超时，用scanf不会
	for(int i=0; i<n; i++)
	{
		cin >> data[i].prior >> data[i].s;
	}
	heapify(n);
	for(int i=0; i<m && n>0; i++)
	{
		cout << data[0].s << endl;
		data[0].prior *=2;
		if(data[0].prior >= pow(2, 32))
		{
			data[0] = data[n-1];
			n--;
		}
		percolateDown(0, n);
	}
	return 0;
}