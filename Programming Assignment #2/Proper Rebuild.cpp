#include<iostream>

#define NUM 100
using namespace std;
template<typename T>
class vector
{
	private:
		int _size;
		int capacity;
		T* elem;
	public:
		vector():_size(0), capacity(NUM)
		{
			elem = new T[NUM];
		}
		~vector()
		{
			if(elem)
				delete []elem;
		}
		int size(){return _size;}
		void expand();
		T insert(T a);
		int find(int lo, int hi, T a);
		T operator[](int a)
		{
			return elem[a];
		}

};
template<typename T>
void vector<T>::expand()
{
	if(_size < capacity) return;
	T* tmp = elem;
	elem = new T[capacity=capacity*2];
	for(int i=0; i<_size; i++)
		elem[i] = tmp[i];
	delete []tmp;
}

template<typename T>
T vector<T>::insert(T a)
{
	expand();
	elem[_size] = a;
	_size++;
	return a;
}
template<typename T>
int vector<T>::find(int lo, int hi, T a)
{
	for(int i=lo; i<hi; i++)
	{
		if(elem[i]==a) return i;
	}
	return _size;
}

vector<int> pre;
vector<int> suc;
vector<int> result;

struct node
 {
 	int data;
 	node* lchild;
 	node* rchild;
 }; 

node* buildtree(int pre_lo, int pre_hi, int suc_lo, int suc_hi)
{
	node* root = new node;
	root->data = pre[pre_lo];
	root->lchild = NULL;
	root->rchild = NULL;
	if (pre_hi-pre_lo ==0) return root;
	int lo_size = suc.find(suc_lo, suc_hi, pre[pre_lo+1])-suc_lo+1; //因为递归，suc_lo和suc_hi在减小，所以find在这个区间内查找而不是在suc的所有范围内查找
    root->lchild = buildtree(pre_lo+1, pre_lo+lo_size, suc_lo, suc_lo+lo_size-1);
    root->rchild = buildtree(pre_lo+1+lo_size, pre_hi, suc_lo+lo_size, suc_hi-1);
    return root;
}

void InTraverse(node* root)
{
	if(root->lchild) InTraverse(root->lchild);
	cout << root->data << " ";
	if(root->rchild) InTraverse(root->rchild);
}

int main()
{

	int n;
	cin >> n;
	for(int i =0; i < n; i++)
	{
		int a;
		cin >> a; 
		pre.insert(a);
	}
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		suc.insert(a);
	}
	node* root = buildtree(0, n-1, 0, n-1);
	InTraverse(root);
		
	return 0;
}