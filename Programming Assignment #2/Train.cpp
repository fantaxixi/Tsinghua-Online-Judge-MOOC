#include<iostream>
#include<string>
using namespace std;

template<typename T>
class stack
{
private:
	int _size;
	int capacity;
	T* elem;
public:
	stack(int NUM)
	{
		_size = 0;
		capacity = NUM;
		elem = new T[NUM];
	}
	~stack()
	{
		if(elem)
			delete []elem;
	}
	int size()
	{
		return _size;
	}
	T* push(T& a);
	T pop();
	T front();
};

template<typename T>
T* stack<T>::push(T& a)
{
	T* tmp = elem + _size;
	*tmp = a;
	_size++;
	return tmp;
}
template<typename T>
T stack<T>::pop()
{
	T tmp = *(elem + _size - 1);
	_size--;
	return tmp;
}
template<typename T>
T stack<T>::front()
{
	if(_size !=0)
	return *(elem + _size - 1);
	return 0;
}

template<typename T>
class vector
{
	private:
		int _size;
		int capacity;
		T* elem;
	public:
		vector():_size(0),capacity(100)
		{
			elem = new T[100];
		}
		~vector()
		{
			if(elem)
				delete []elem;
		}
		T& operator[](int i);
		T* push(T c);
		void expand();
		int size()
		{
			return _size;
		}
};
template<typename T>
T& vector<T>::operator[](int i)
{
	return *(elem + i);
}
template<typename T>
T* vector<T>::push(T c)
{
	expand();
	elem[_size] = c;
	_size++;
	return elem + _size - 1 ;
}
template<typename T>
void vector<T>::expand()
{
	if(_size<capacity) return;
	T* old = elem;
	elem = new T[capacity*=2];
	for(int i = 0; i < _size; i++)
	elem[i] = old[i];
	delete []old;
}

int main()
{
	int n, m;
	cin >> n >> m;
	stack<int> num(n);
	vector<int> c;
	int j = 1;
	for(int i = 0; i < n; i++)
	{
		int k;
		int flag = 0;
		cin >> k;
		for(; j<= n; )
		{
			if(num.size() != 0)
			{
				if(num.front() ==k)
				{
					num.pop();
					flag = 1;
//					cout << "pop" << endl;
					c.push(1);
					break;
				}
			}
			num.push(j);
			j++;
//			cout << "push" << endl;
			c.push(0);
			if(num.front() == k)
			{
				num.pop();
				flag = 1;
//				cout << "pop" << endl;
				c.push(1);
				break;
			}
			if((num.size() == m) && num.front() != k)
			{
				cout << "No" << endl;
				return 0;
			}
		}
		if(j>n && flag == 0)
		{
			if(num.front() == k)
			{
				num.pop();
//				cout << "pop" << endl;
				c.push(1);
			}
			else 
			{
				cout << "No" << endl;
				return 0;
			}
		}

	}
	for(int i = 0; i < c.size(); i++)
	{
		if(c[i]==0)
		cout << "push" << endl;
		else 
		cout << "pop" << endl;
	}

}