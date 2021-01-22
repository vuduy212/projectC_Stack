//Cai dat stack bang mang
#include<bits/stdc++.h>
using namespace std;
#ifndef NGANXEP_CPP
#define NGANXEP_CPP 1
template <class T>
class arrStack
{
	private:
		int t;
		int cap;
		T *a;
	public:
		arrStack();
		~arrStack();
		int size();
		T top();
		void pop();
		void push(T x);
		bool empty();
};
template <class T>
arrStack<T>::arrStack()
{
	cap=100;
	a=new T[cap];
	t=-1; //khoi tao t=-1 vi stack dang trong
}
template <class T>
arrStack<T>::~arrStack()
{
	delete []a;
}
template <class T>
int arrStack<T>::size()
{
	return t+1;
}
template <class T>
T arrStack<T>::top()
{
	return a[t];
}
template <class T>
void arrStack<T>::pop()
{
	if(t>=0) t--;
}
template <class T>
void arrStack<T>::push(T x){
	if(t==cap-1)
	{
		cap=2*cap+10;
		T *b=new T[cap];
		for(int i=0;i<t;i++) b[i]=a[i];
		delete []a;
		a=b;
	}
	a[++t]=x;
}
template <class T>
bool arrStack<T>::empty()
{
	return t+1==0;
}
#endif
