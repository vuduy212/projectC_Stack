#ifndef APPLICATION_CPP
#include<bits/stdc++.h>
#include"NGANXEP.cpp"
using namespace std;
class application{
	private:
		char infix[1024];
		char postfix[1024];
	public:
		void nhap();
		bool isoperator(char ch);
		int uu_tien(char ch);
		void infix_to_postfix(char infix[], char postfix[]);
		double getpostfix_value(char postfix[]);
		int menu();
		void run();
};
#endif
