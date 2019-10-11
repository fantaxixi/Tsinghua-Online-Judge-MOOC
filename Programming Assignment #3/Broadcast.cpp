#include<iostream>

using namespace std;
#define NUM 10001
enum status {undiscovered, discovered, visited};
struct E_node
{
	E_node* next;
	int data;
};
struct V_node
{
	int data;
	int fm;
	E_node* first_edge;
	status s;
};

struct gragh
{
	V_node nodes[NUM];
	int e_num;
	int v_num;
} g;

struct queue_node
{
	queue_node* suc;
	queue_node* pre;
	V_node data;
};

class queue
{
	queue_node* head;
	queue_node* tail;
	int _size;
	public:
		queue()
		{
			head = new queue_node;
			tail = new queue_node;
			head->suc = tail;
			head->pre = NULL;
			tail->pre = head;
			tail->suc = NULL;
			_size = 0;
		}
		~queue(){}
		void push(V_node a);
		V_node pop();
		int size()
		{
			return _size;
		}
} q;
void queue::push(V_node a)
{
	queue_node* tmp = new queue_node;
	tmp->data = a;
	tmp->suc = tail;
	tmp->pre = tail->pre;
	tail->pre->suc = tmp;
	tail->pre = tmp;
	_size++;
}
V_node queue::pop()
{
	queue_node* tmp = head->suc;
	tmp->suc->pre = head;
	head->suc = tmp->suc;
	_size--;
	return tmp->data;
}

int BFS()
{
	q.push(g.nodes[0]);
	g.nodes[0].s = discovered;
//	cout << "push" << g.nodes[0].data << endl;
	while(q.size()!=0)
	{
		V_node root = q.pop();
//		cout << "pop" << root.data << endl;
		for(E_node* e=root.first_edge; e; e=e->next)
		{
			if(g.nodes[e->data-1].s==undiscovered)                     //判断语句里不能加(g.nodes[e->data-1].fm==root.fm)，不然会漏掉没被访问过且fm不等于root的节点
			{
				g.nodes[e->data-1].fm = !root.fm;
				g.nodes[e->data-1].s = discovered;
				q.push(g.nodes[e->data-1]);
//				cout << "push" << g.nodes[e->data-1].data << endl;
			}
			if((g.nodes[e->data-1].fm==root.fm) && (g.nodes[e->data-1].s!=undiscovered))
			{
				return -1;
			}
		}
		root.s = visited;
	}
	return 1;
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.e_num = m;
	g.v_num = n;
	for(int i=0; i<n; i++)
	{
		g.nodes[i].data = i+1;
		g.nodes[i].fm = 0;
		g.nodes[i].first_edge = NULL;
		g.nodes[i].s = undiscovered;
	}
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		E_node* e = new E_node;
		e->data = b;
		e->next = g.nodes[a-1].first_edge;
		g.nodes[a-1].first_edge = e;
		E_node* k = new E_node;
		k->data = a;
		k->next = g.nodes[b-1].first_edge;
		g.nodes[b-1].first_edge = k;		
	}
	cout << BFS() << endl;
	return 0;
}