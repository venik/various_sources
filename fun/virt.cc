#include <iostream>

using namespace std;

struct B {
	virtual void f() const {cout<<"B::f ";}		// i'm virtual
	void g() {cout<<"B::g ";}
};

struct D : B {
	void f() const {cout<<"D::f ";}			// yup, replace it
	void g() {cout<<"D::g ";}
};

struct DD : D {
	void f() {cout<<"DD::f ";}			// without const!!! 
	void g() {cout<<"DD::g ";}
};

void call(const B& b)
{
	b.f();
	b.g();
}

int main()
{
	B b;
	D d;
	DD dd;

	call(b);
	call(d);
	call(dd);

	b.f();
	b.g();
	
	d.f();
	d.g();
	
	dd.f();
	dd.g();
}
