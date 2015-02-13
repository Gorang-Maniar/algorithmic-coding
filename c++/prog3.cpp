#include<iostream.h>
#include<conio.h>

class First;

class Sec
{
	int a;
	public:
	void display()
	{
		cin<<a;
		cout<<a<<endl<<"one";
	}
	friend void func(Sec,First);
};

class First{
	int b;
	public:
	void disp()
	{
		cin>>b;
		cout<<b<<endl<<"Sec";
	}
	friend void func(Sec,First);
};

void func(Sec s,First f)
{
	int c;
	c = s.a+f.b;
	cout<<endl<<c;
}

void main()
{
	Sec sn;
	First fn;
	sn.display();
	fn.display();
	func(sn,fn);
	getch();
}


