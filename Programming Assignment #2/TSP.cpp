#include<iostream>
using namespace std;
#define NUM 1000000
template<typename T>
class stack
{
private:
	int _size;
	T* elem;
public:
	stack()
	{
		_size = 0;
		elem = new T[NUM];
	}
	~stack()
	{
		if(elem)
			delete []elem;
	}
	void push(T a);
	void pop();
	T top();
	int size()
	{
		return _size;
	}
};
template<typename T>
void stack<T>::push(T a)
{
	elem[_size] = a;
	_size++;
}
template<typename T>
void stack<T>::pop()
{
	_size--;
}
template<typename T>
T stack<T>::top()
{
	return elem[_size-1];
}

struct E_node
{
	int node;
	E_node* next;
};
struct V_node
{
	int data;
	int indegree;
	int length;
	E_node* first_edge;
};

struct gragh
{
	V_node nodes[NUM];
	int num_V = 0;
	int num_E = 0;
} g;

void T_sort(V_node& v)   //一定得用引用！！
{
	if(v.first_edge == NULL) return;
	for(E_node* e=v.first_edge; e; e=e->next)
	{
		int data = e->node;
		T_sort(g.nodes[data]);
		if(v.length<(g.nodes[data].length+1))
			v.length = g.nodes[data].length+1;
	}
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		g.nodes[i].data = i+1;
		g.nodes[i].indegree = 0;
		g.nodes[i].first_edge = NULL;
		g.nodes[i].length = 1;
		g.num_V++;
	}
	for(int i=0; i<m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		E_node* e = new E_node;
		e->node = v2-1;
		e->next = NULL;
		g.nodes[v2-1].indegree++;
		E_node* k = g.nodes[v1-1].first_edge;
		g.num_E++;
		if(k == NULL)
			g.nodes[v1-1].first_edge = e;    //不可以直接写k=e!!!这样会直接改k的值而没有改掉真正要改的first_edge的值
		else 
		{
			while(k->next != NULL)
				k = k->next;
			k->next = e;        ///同上！！
		}
	}
	stack<V_node> s;
	for(int i=0; i<n; i++)
	{
		if(g.nodes[i].indegree ==0)
			s.push(g.nodes[i]);
	}
	int max = 1;
	while(s.size()!=0)
	{
		V_node tmp = s.top();
		T_sort(tmp);
		s.pop();
		if(tmp.length > max)
			max = tmp.length;
	}
	cout << max;
}