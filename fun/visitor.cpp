#include <iostream>
#include <vector>

class A;
class B;

class Visitor {
public:
	virtual void visit(A*) = 0;
	virtual void visit(B*) = 0;
    virtual ~Visitor() {}
};

class Node {
public:
	virtual void accept(Visitor*) = 0;
    virtual ~Node() {}
};


class A: public Node {
public:
	std::string getAName() {
		return "A";
	}

	virtual void accept(Visitor* visitor) {
		visitor->visit(this);
	}
};

class B: public Node {
public:
	std::string getBName() {
		return "B";
	}

	virtual void accept(Visitor* visitor) {
		visitor->visit(this);
	}
};

//////
class CoolVisitor: public Visitor {
private:
	std::string str;

public:
	CoolVisitor() {
		this->str = "CoolVisitor";
	}

	void visit(A* a) {
		this->str += a->getAName();
	}

	void visit(B* b) {
		this->str += b->getBName();
	}

	std::string getState() {
		return this->str;
	}
};

int main() {
	CoolVisitor coolVisitor;
	A* a = new A();
	B* b = new B();
	
	std::vector<Node*> vec;
	vec.push_back(a);
	vec.push_back(b);

	for(std::vector<Node*>::iterator iter = vec.begin() ; iter != vec.end(); iter++) {
		(*iter)->accept(&coolVisitor);
	}

	std::cout<<"\n"<<coolVisitor.getState()<<"\n";

	return 0;
}
