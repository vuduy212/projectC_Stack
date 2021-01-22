#ifndef APP_DETAIL_CPP
#include<bits/stdc++.h>
#include<conio.h>
#include"application.cpp"
using namespace std;
void application::nhap()
{
	cout<<"\nNhap bieu thuc trung to: ";
	cin>>infix;
}
bool application::isoperator(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}
int application::uu_tien(char ch)
{
	switch (ch)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}
void application::infix_to_postfix(char infix[], char postfix[])
{
	arrStack <char> s1;
	s1.push('#');
	int i = 0, j = 0;
	while (infix[i] != '\0')
	{
		if ((infix[i] >= '0'&&infix[i] <= '9') || infix[i] == '.')
		{
			postfix[j++] = infix[i];
		}
		else if (infix[i] == '(')
		{
			s1.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (s1.top() != '(')
			{
				postfix[j++] = ' ';
				postfix[j++] = s1.top();
				s1.pop();
			}
			s1.pop();
		}
		else if (isoperator(infix[i]))
		{
			postfix[j++] = ' ';
			if (s1.empty())
			{
				s1.push(infix[i]);
			}
			else
			{
				while (uu_tien(infix[i]) <= uu_tien(s1.top()))
				{
					postfix[j++] = s1.top();
					postfix[j++] = ' ';
					s1.pop();
				}
				s1.push(infix[i]);
			}
		}
		i++;
	}
	while (s1.size())
	{
		postfix[j++] = ' ';
		postfix[j++] = s1.top();
		s1.pop();
	}
	postfix[j - 1] = '\0';
}
double application::getpostfix_value(char postfix[])
{
	arrStack<double> s1;
	int i = 0;
	double result = 0;
	double x1 = 0, x2 = 0;
	while (postfix[i] != '\0')
	{
		if (postfix[i] >= '0'&&postfix[i] <= '9')
		{
			double x = 0;
			int n = 0;
			while (postfix[i] >= '0'&&postfix[i] <= '9')
			{
				x = x * 10 + (postfix[i] - '0');
				i++;
			}
			if (postfix[i] == '.')
			{
				i++;
				while (postfix[i] >= '0'&&postfix[i] <= '9')
				{
					x = x * 10 + (postfix[i] - '0');
					i++;
					n++;
				}
			}
			while (n)
			{
				x /= 10;
				n--;
			}
			s1.push(x);
		}
		else if (postfix[i] == ' ')
		{
			i++;
		}
		else if (postfix[i] == '+')
		{
			x1 = s1.top();
			s1.pop(); 
			x2 = s1.top();
			s1.pop(); 
			double temp = x2 + x1; 
			s1.push(temp);
			i++;
		}
		else if (postfix[i] == '-')
		{
			x1 = s1.top();
			s1.pop();
			x2 = s1.top();
			s1.pop();
			double temp = x2 - x1;
			s1.push(temp);
			i++;
		}
		else if (postfix[i] == '*')
		{
			x1 = s1.top();
			s1.pop();
			x2 = s1.top();
			s1.pop();
			double temp = x2 * x1;
			s1.push(temp);
			i++;
		}
		else if (postfix[i] == '/')
		{
			x1 = s1.top();
			s1.pop();
			x2 = s1.top();
			s1.pop();
			double temp = x2 / x1;
			s1.push(temp);
			i++;
		}
	}
	result = s1.top();
	return result;
}
//---------------
int application::menu(){
	int mn;
menu :	do{	system	("CLS");
		cout<<"\tUNG DUNG STACK "<<endl;
		cout<<"1.Nhap vao bieu thuc trung to"<<endl;
		cout<<"2.Xem bieu thuc vua duoc chuyen tu trung to sang hau to"<<endl;
		cout<<"3.Xem gia tri bieu thuc vua nhap"<<endl;
		cout<<"Nhap tu 1-3 de chon chuc nang : ";
		cin>>mn;
		cin.ignore(1);
	}while(mn>3||mn<1);
	return mn;
}
void application::run(){
	int n;
menu:	do{
		system("cls");
		n = menu();
		system("cls");
		switch(n)
		{
			case 1:
				nhap();
				int gt;
				cout<<endl<<"Nhap 1 de tiep tuc chuong trinh hoac nhap phim bat ki de ket thuc : ";
				cin>>gt;
				if(gt==1) goto menu;
				else exit(0);
			case 2:
				infix_to_postfix(infix, postfix);
				cout<<"\nBieu thuc hau to: "<<postfix;
				cout<<endl<<"Nhap 1 de tiep tuc chuong trinh hoac nhap phim bat ki de ket thuc : ";
				cin>>gt;
				if(gt==1) goto menu;
				else exit(0);
			case 3:
				cout<<"\nGia tri bieu thuc = "<<getpostfix_value(postfix);
				cout<<endl<<"Nhap 1 de tiep tuc chuong trinh hoac nhap phim bat ki de ket thuc : ";
				cin>>gt;
				if(gt==1) goto menu;
				else exit(0);
		}
		getch();
	} while(n!=4);
}
#endif
