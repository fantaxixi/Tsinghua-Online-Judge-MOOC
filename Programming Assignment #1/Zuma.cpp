#include<iostream>
using namespace std;

#define ListNodePos ListNode<T>*

template<typename T>
class ListNode
{
	public:
		T data;
		ListNodePos pre;
		ListNodePos suc;
		ListNode()
		{
			pre = NULL;
			suc = NULL;
		}
		ListNode(T& e, ListNodePos p = NULL, ListNodePos s = NULL){
			data = e;
			pre = p;
			suc = s;
		}
		ListNodePos insertNodePre(T& e);
};
template<typename T>
ListNodePos ListNode<T>::insertNodePre(T& e)
{
	ListNodePos a = new ListNode<T>(e,this->pre,this);
	this->pre->suc = a;
	this->pre = a;
	return a;
}

template<typename T>
class list
{
	
		ListNodePos header;
		ListNodePos trailer;
	public:
		int size;
		list()
		{
			size = 0;
			header = new ListNode<T>;
			trailer = new ListNode<T>;
			header->suc = trailer;
			trailer->pre = header;
		}
		ListNodePos insertAtLast(T& e);
		ListNodePos insert(T& e, int r);
		ListNodePos firstNode();
		ListNodePos lastNode();
		T remove(ListNodePos& a);
		void output();
		void unique();//每次扫描只删除一次，O(n2)
		void unique_better(ListNodePos a);//每次扫描删除掉所有能满足条件的，以两个指针分别指向插入节点的前后，比对两个指针的数值是否相同，O(n)
};
template<typename T>
ListNodePos list<T>::insertAtLast(T& e)
{
	size++;
	return trailer->insertNodePre(e); 
}
template<typename T>
ListNodePos list<T>::firstNode()
{
	if(header->suc == trailer) return NULL;
	return header->suc;
}
template<typename T>
ListNodePos list<T>::lastNode()
{
	if(trailer->pre == header) return NULL;
	return trailer->pre;
}
template<typename T>
void list<T>::output()
{
	ListNodePos a = this->firstNode();
	while(a!=trailer)
	{
		cout << a->data;
		a = a->suc;
	}
	cout << endl;
}
template<typename T>
ListNodePos list<T>::insert(T& e, int r)
{
	size++;
	ListNodePos elem = header;
	for(int i=0; i<=r; i++)
	{
		elem = elem->suc;
	}
	return elem->insertNodePre(e);
}
template<typename T>
T list<T>::remove(ListNodePos& a)
{
	size--;
	T tmp = a->data;
	a->pre->suc = a->suc;
	a->suc->pre = a->pre;
	delete a;
	return tmp;
}
template<typename T>
void list<T>::unique()
{
	if (this->size<3)return;
	ListNodePos elem = this->lastNode();
	while((elem!=header)&&(elem!=header->suc))
	{
		if(elem->data == elem->pre->data)
		{
			int length = 2;
			ListNodePos end = elem;
			ListNodePos beg = elem->pre;
			if(beg->pre!=header)
			{
				while(beg->data == beg->pre->data)
				{
					length++;
					beg = beg->pre;
				}
			}
//			cout << "length:" << length << endl;
			if(length>2)
			{
				for(int i=0; i<length; i++)
				{
					ListNodePos tmp = end;
					end = end->pre;
//					cout << end->data;
					this->remove(tmp);
				}
				break;
			}
		}
		elem = elem->pre;
	}
}
template<typename T>
void list<T>::unique_better(ListNodePos a)
{
	ListNodePos lo = a->pre;
	ListNodePos hi = a->suc;
	int length = 1;
    while((lo->data == a->data) && lo != header)
    {
    	lo = lo->pre;
    	length++;
    }
    while((hi->data == a->data) && hi != trailer)
    {
    	hi = hi->suc;
    	length++;
    }
    if(length>2)
    {
    	ListNodePos tmp = hi->pre;
    	for(int i=0; i<length; i++)
    	{
    		ListNodePos elem = tmp;
    		tmp = elem->pre;
    		remove(elem);
    	}
    	hi = tmp;
    }
    else return;
    if(hi !=header)
    unique_better(hi);

}

int main()
{
	list<char> str;
	char c;
	while((c=cin.get())!=int('\n'))
	{
		str.insertAtLast(c);
	}
//	str.output();
	int num;
	cin >> num;
	for(int i=0; i<num; i++)
	{
		int a;
		char c;
		cin >> a >> c;
//		str.insert(c, a);
		str.unique_better(str.insert(c, a));
//		for(int i=0; i<str.size; i++)
//		{
//			cout << i <<endl;
//			str.unique();
//		}
		if(str.size ==0)
		cout << '-' << endl;
		else
		str.output();
	}
	return 0;
}

