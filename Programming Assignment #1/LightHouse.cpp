#include<iostream>
using namespace std;
#define NUM 100
struct node
{
	long long x;
	long long y;
};

template<typename T>
class vector
{
	private:
		int size;
		int capacity;
		T* elem;
	public:
		long long sorted;  //题目提示int不一定能容纳本体输出
		vector(int k)
		{
			sorted = 0;
			size = 0;
			capacity = k;
			elem = new T[k];
		}
		~vector()
		{
			if(elem)
				delete []elem;
		}
		T& operator [](int i)
		{
			return *(elem+i);
		}
		void expand();
		T* push_back(T& a); 
		void merge_sort(int lo, int hi, char c);
		void merge(int lo, int mi, int hi, char c);

};
template<typename T>
void vector<T>::expand()
{
	if(size<capacity) return;
	capacity = capacity*2;
	T* tmp = elem;
	elem = new T[capacity];
	for(int i=0; i<size; i++)
	{
		elem[i] = tmp[i];
	}
	delete []tmp;
}
template<typename T>
T* vector<T>::push_back(T& a)
{
	expand();
	elem[size] = a;
	size++;
	return elem+size;
}
template<typename T>
void vector<T>::merge_sort(int lo, int hi, char c)
{
	if(hi-lo<2) return;
	int mi = (hi + lo)/2;
	merge_sort(lo, mi, c);
	merge_sort(mi, hi, c);
	merge(lo, mi, hi, c);
}
template<typename T>
void vector<T>::merge(int lo, int mi, int hi, char c)
{
	int length_lo = mi - lo;
	int length_hi = hi - mi;
	T* beg = elem + lo;
	T* new_lo = new T[length_lo];
	T* new_hi = beg + length_lo;
	for(int i = 0; i < length_lo; i++)
	{
		new_lo[i] = beg[i];
	}
	if(c == 'x')
	for(int i = 0, j = 0, k = 0; (i < length_lo) || (j < length_hi); )
	{
		if((i < length_lo) && ((j >= length_hi) || (new_lo[i].x < new_hi[j].x)))
		{
			beg[k] = new_lo[i];
			k++;
			i++;
		}
		if((j < length_hi) && ((i >= length_lo) || (new_lo[i].x > new_hi[j].x)))
		{
			beg[k] = new_hi[j];
			k++;
			j++;
		}
	}
	if(c =='y')
	for(int i = 0, j = 0, k = 0; (i < length_lo) || (j < length_hi); )
	{
		if((i < length_lo) && ((j >= length_hi) || (new_lo[i].y < new_hi[j].y)))
		{
			beg[k] = new_lo[i];
			k++;
			i++;
			sorted += length_hi - j;
		}
		if((j < length_hi) && ((i >= length_lo) || (new_lo[i].y > new_hi[j].y)))
		{
			beg[k] = new_hi[j];
			k++;
			j++;
		}
	}
	
	delete []new_lo;
}

//只要下xi<xj并且yi<yj即构成一个顺序对。
//归并排序先对x坐标进行排序，然后在排序基础上再对y坐标进行排序，在排序过程中可以计算顺序对个数
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<node> Light(NUM);
	for(int i=0; i<n; i++)
	{
		node Node;
		cin >> Node.x >> Node.y;
		Light.push_back(Node);
	}
	Light.merge_sort(0, n, 'x');
	Light.merge_sort(0, n, 'y');
//	for(int i = 0; i < n; i++)
//		cout << Light[i].x <<endl;
	cout << Light.sorted << endl;
	return 0;
}
