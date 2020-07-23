#include<iostream>
using namespace std;
class Toy{
	public:
	void virtual createfirstpart()=0;
	void virtual createsecondpart()=0;

};
class Teddy:protected Toy{
	protected:
	void createfirstpart()
	{
		cout<<"\nThe first teddy part is created";
	}
	void createsecondpart()
	{
		cout<<"\nThe second teddy part is  created";
	}
	friend class Toyfactory;
	
};
class Car:protected Toy{
        protected:
        void createfirstpart()
        {
                cout<<"\nThe first car part is created";
        }
        void createsecondpart()
        {
                cout<<"\nThe second car part is  created";
        }
	friend class Toyfactory;

};

class Toyfactory
{
	Toy *toy;
	int p;
	public:
	Toyfactory(int n)
	{
	
	switch(n)
	{
		case 1:
			toy= new Car;
			break;
		case 2:
			toy= new Teddy;
			break;
	}
	}
	Toy *getToy()
	{
		return toy;
	}
	
};
int main()
{
	Toyfactory tf(2);
	Toy *t;
	t=tf.getToy();
	t->createfirstpart();
	t->createsecondpart();
}
