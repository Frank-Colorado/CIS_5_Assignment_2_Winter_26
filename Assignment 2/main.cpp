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
		setName(n);
		setAge(a);
		setHeight(h);
		setWeight(w);
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

	// Getters 
	string getName() const {
		return name;
	}

	int getAge() const {
		return age;
	}

	double getHeight() const {
		return height;
	}

	double getWeight() const {
		return weight;
	}

	// Calculate BMI
	double calculateBMI() const {
		if (height <= 0) {
			return 0.0;
		}
		return weight / (height * height);
	}

	// Get the user's BMI category
	string getBMICategory() const {

		double bmi = calculateBMI();

		if (bmi < 18.5) {
			return "(Underweight)";
		}
		else if (bmi < 24.9) {
			return "(Normal weight)";
		}
		else if (bmi < 29.9) {
			return "(Overweight)";
		}
		else {
			return "(Obese)";
		}
	}

	// Calculate the user's grade
	string calculateGrade(int g) const {

		if (g >= 90) {
			return "You also got an A on the test! Great Job!";
		}
		else if (g >= 80) {
			return "You also got a B on the test! Keep it up!";
		}
		else if (g >= 70) {
			return "You also got a C on the test! You can do better!";
		}
		else if (g >= 60) {
			return "You also got a D on the test! Study a little more!";
		}
		else {
			return "You also got an F on the test! You need to work harder!";
		}
	}

	// Display user information
	void displayInfo(int g) const {

		cout << "Hey " << getName() << "!" << endl;
		cout << "You are " << getAge() << " years old." << endl;
		cout << "You have a BMI of " << calculateBMI() << " " << getBMICategory() << endl;
		cout << calculateGrade(g) << endl;
	}



};

int main() {

	string name;
	int age;
	double height;
	double weight;
	int grade;

	cout << "What is your name? ";
	cin >> name;
	cout << "How old are you? ";
	cin >> age;
	cout << "What is your height in meters? ";
	cin >> height;
	cout << "What is your weight in kilograms? ";
	cin >> weight;
	cout << "What grade did you get on your last test? ";
	cin >> grade;

	User user(name, age, height, weight);

	user.displayInfo(grade);


	return 0;
}