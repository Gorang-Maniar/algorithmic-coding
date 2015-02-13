#include<iostream.h>
#include<conio.h>

class First
{
	public:
	void display(int);
};

void First::display(int a)
{
	cout<<endl<<a;
}
void main()
{
	First var;
	var.display(2);
	getch();
}
