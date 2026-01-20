#include <iostream>

// Declaring what I'll need
using std::cout;
using std::cin;
using std::endl;
using std::string;

// User class definition
class User {

// Here are the private attributes for the User class
// I wanted to try using private attributes with setters and getters
private:
	string name;
	int age = 0;
	double height = 0.0;
	double weight = 0.0;

public:
	// Constructor so that the class can be reused with different users
	// The constructor takes 4 parameters to initialize the user attributes
	User(string n, int a, double h, double w) {
		// I used setters to initialize the attribues 
		// This is mainly because some setters have validation logic and I didn't want to cram it all in the constructor
		setName(n);
		setAge(a);
		setHeight(h);
		setWeight(w);
	}

	// Setters 
	// These are all the setters for the private attributes of this Class
	void setName(string n) {
		name = n;
	}

	void setAge(int a) {

		// I used conditional statements to validate the age input
		// I did this in case someone tried to input a negative number or an unrealistically high age
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
		
		// I used conditional statements to stop negative height inputs
		if (h < 0) {
			height = 0.0;
		}
		else {
			height = h;
		}

	}

	void setWeight(double w) {
		
		// I used conditional statements to stop negative weight inputs
		if (w < 0) {
			weight = 0.0;
		}
		else {
			weight = w;
		}
	}

	// Getters 
	// These are all the getters so that I can access the private attributes of this Class
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
		// I wanted to make sure there was no division by zero
		// so if height is less than or equal to zero, I return a BMI of 0.0
		if (height <= 0) {
			return 0.0;
		}

		// BMI Formula calculation
		return weight / (height * height);
	}

	// Get the user's BMI category
	string getBMICategory() const {

		// Here I call the calculateBMI method to get the user's BMI value
		double bmi = calculateBMI();

		// Here I use conditional statements to determine the user's BMI category
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
	// This method takes an integer parameter for the grade
	string calculateGrade(int g) const {

		// Here I use conditional statements to determine the user's letter grade and return an appropriate message
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
	// This method takes an integer parameter for the grade so it will be able to call the calculateGrade method
	// I just created this method here to keep the main function cleaner
	void displayInfo(int g) const {

		cout << "Hey " << getName() << "!" << endl;
		cout << "You are " << getAge() << " years old." << endl;
		cout << "You have a BMI of " << calculateBMI() << " " << getBMICategory() << endl;
		cout << calculateGrade(g) << endl;
	}

};

int main() {

	// Here I define all the variables I'll need to get user input
	string name;
	int age;
	double height;
	double weight;
	int grade;

	// Here I prompt the user for their information
	// and then store that information in the variables defined above
	cout << "What is your name? ";
	cin >> name;
	cout << "How old are you? ";
	cin >> age;
	cout << "What is your height in meters? ";
	cin >> height;
	cout << "What is your weight in kilograms? ";
	cin >> weight;
	cout << "What grade did you get on your last test? (0-100) "; 
	cin >> grade;

	// Here I create an instance of the User class and pass in the user's inputs to the constructor
	User user(name, age, height, weight);

	// Here I call the displayInfo method to show the user's information
	// I have to pass in the grade variable so that the method can call calculateGrade
	user.displayInfo(grade);


	return 0;
}