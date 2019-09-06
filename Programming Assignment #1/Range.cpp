#include<iostream>
#define NUM 100
using namespace std;

template<typename T> 
class vector
{
	protected:
		int size,capacity;
		T* elem;
		void expand();
	public:
		vector()
		{
			size = 0;
			capacity = NUM;
			elem = new T[NUM];
		}
		~vector()
		{
			delete []elem;
		}
		int push_back(T x);
		T& operator[](int i);
		T* begin(){
			return &elem[0];
		}
		T* end(){
			return &elem[size];
		}
		int binary_search_lo(int e,int lo,int hi);
		int binary_search_up(int e,int lo,int hi);
		void sort(int lo, int hi);
		void merge(int lo, int mi, int hi);
};
template<typename T>
void vector<T>::expand()
{
	if(size<capacity) return;
	T* old = elem;
	elem = new T[capacity*=2];
	for(int i = 0; i < size; i++)
	elem[i] = old[i];
	delete []old;
}
template<typename T>
T& vector<T>::operator[](int i)
{
	return elem[i];
}
template<typename T>
int vector<T>::push_back(T x)
{
	expand();
	elem[size] = x;
	size++;
}
template<typename T>
int vector<T>::binary_search_lo(int e,int lo,int hi)
{
	while(lo<hi)
	{
		int mid = (lo+hi)/2;
		(elem[mid]<e)?lo=mid+1:hi=mid;
	}
	return hi;
}
template<typename T>
int vector<T>::binary_search_up(int e,int lo,int hi)
{
	while(lo<hi)
	{
		int mid = (lo+hi)/2;
		(e<elem[mid])?hi=mid:lo=mid+1;
	}
	return lo-1;
}
template<typename T>
void vector<T>::sort(int lo, int hi)
{
	if(hi-lo<=1) return;
	int mi;
	mi=(lo+hi)/2;
	sort(lo,mi);
	sort(mi,hi);
	merge(lo,mi,hi);
}
template<typename T>
void vector<T>::merge(int lo, int mi, int hi)
{
	T* A = elem + lo;
	int head = mi - lo;
	int tail = hi - mi;
	T* Lo = new T[head];
	T* Hi = A + head;
	for(int i=0; i<head; i++)
	{
		Lo[i] = A[i];
	}
	for(int i=0, j=0, k=0; (i<head)|| (j<tail);)
	{
		if((i<head)&&((j>=tail)||(Lo[i]<=Hi[j])))
		{
			A[k] = Lo[i];
			i++;
			k++;
		}
		if((j<tail)&&((i>=head)||(Hi[j]<Lo[i])))
		{
			A[k] = Hi[j];
			j++;
			k++;
		}
	}
}

int main()
{
	int n,m;
	int a,b;
	vector<int> num;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		int x;
		cin >> x;
		num.push_back(x);
	}
	num.sort(0,n);
	for(int i=0; i<m; i++)
	{
		cin >> a >> b;
		int beg,end;
		beg = num.binary_search_lo(a,0,n);
		end = num.binary_search_up(b,0,n);
		cout << (end-beg+1) <<endl;
	}
	return 0;
}
