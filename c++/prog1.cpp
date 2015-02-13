#include<iostream.h>
//#include<conio>

class First
{
	int temp;
	public:
	void display()
	{
		cin>>temp;
		cout<<endl<<"C++ begins here"<<temp;
	}
};
void main()
{
	First var;
	var.display();
	getch();
}
