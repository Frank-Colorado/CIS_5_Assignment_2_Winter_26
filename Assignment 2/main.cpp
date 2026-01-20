#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class User {

private:
	string name;
	int age = 0;
	double height = 0.0;
	double weight = 0.0;

public:
	// Constructor
	User(string n, int a, double h, double w) {

	}

	// Setters 

	void setName(string n) {
		name = n;
	}

	void setAge(int a) {

		if (a < 0) {
			age = 0;
		}
		else if (a > 100) {
			age = 100;
		}
		else {
			age = a;
		}

	}

	void setHeight(double h) {
		
		if (h < 0) {
			height = 0.0;
		}
		else {
			height = h;
		}

	}

	void setWeight(double w) {
		
		if (w < 0) {
			weight = 0.0;
		}
		else {
			weight = w;
		}
	}




};

int main() {

	return 0;
}