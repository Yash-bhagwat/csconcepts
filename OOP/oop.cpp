#include <iostream> 
using namespace std;

class AbstractEmployee{
	virtual void AskforPromotion() = 0; //abstract function
};

class Employee : AbstractEmployee{
	//members of the class: attributes and behaviours
private:
	string Company;
	int Age;
protected:
	string Name;
public:
	//class  method is basically a function
	void IntroduceYourself(){
		cout << "Hi, I am " << Name << ". What's up dawg?\n";
		if(Company == "Student") cout << "I am a student\n";
		else cout << "I work at " << Company << "\n";
		cout << "I am a " << (Age >= 21 ? "major" : "minor") << "\n"; 
	}
	//This is how we expose public properties our private properties
	void setName(string name){
		Name = name;
	}
	string getName(){
		return Name;
	}
	void setCompany(string company){
		Company = company;
	}
	string getCompany(){
		return Company;
	}
	void setAge(int age){
		if(age >= 18)
			Age = age;	
	}
	int getAge(){
		return Age;
	}
	Employee(string name, string company, int age){
		Name = name;
		Company = company;
		Age = age;
	}
	
	void AskforPromotion(){
		if(Age > 30) 
			cout << Name << " got promoted!\n";
		else 
			cout << "Sorry, No promotion for you\n";
	}
	
	virtual void Work(){
		cout << Name << " is doing company work which is basically petty stuff" << endl;
	}
};

class Developer: public Employee{
public:
	string FavProgrammingLanguage;
	Developer(string name, string company, int age, string favProgrammingLanguage)
		:Employee(name, company, age)
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	void FixBug(){
		cout << Name << " fixed bug using " << FavProgrammingLanguage << endl;
	}
	void Work(){
		cout << Name << " is writing code using " << FavProgrammingLanguage << endl;
	}
};

class Teacher : public Employee{
public:
	string Subject;
	void PrepareLesson(){
		cout << Name << " is preparing for a lesson on " << Subject << "\n";
	}
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	{
		Subject = subject;
	}
	void Work(){
		cout << Name << " is teaching stupid kids " << Subject << endl;
	}
};

int main(){
	/*
	 * Since we have createed our own consrtuctor, we can on longer define Employees as such
	 * 
	Employee employee1; //user defined type
	//How to access attribute
	//employee1.Age //but the program here is that everything is private by default in C++
	//There are a total of 3 access modifiers i.e. private, public and protected
	//private -> cannot be accessible /hidden
	//public -> anyone outside the class can access the variables
	employee1.Name = "Yash";
	employee1.Company = "Student";
	employee1.Age = 19;
	for(int i = 0; i < 5; i++){
		employee1.IntroduceYourself();
	}
	*/
	//A constructor is a special type of method which is invoked everytime when we create a object of a class
	//If I comment out all the lines in which i mentioned the specifications of the employee, you will get the values of what we call as a default constructor
	//Let's create our own constructors
	//Constructor does not have a return type and need to be public(atleast at this level of experience)
	
	Employee employee1 = Employee("Yash","Student",19);
	Employee employee2 = Employee("Anish","Unemployed",16);
	
	employee1.IntroduceYourself();
	
	//Encapsulation
	//Idea of bundling or tying together data and operators that work on the data and the methods that work on the data such that they are grouped together within a class  , purpose is preventing anyone or anything outside of our class to be *directly* be able to access our data and interact with it and modify it. So we allow them only some amount of public functions that they can access
	
	employee1.setAge(21);
	employee1.IntroduceYourself();
	
	//Abstraction: Basically hiding complicated stuff from the user
	//Basically what I understand is that class Employee is signing the class of Abstract employee which means that it has to provide implementation for the AskforPromotion class
	employee1.AskforPromotion();
	employee2.AskforPromotion();
	
	//Inheritance
	//Base class or parent class -> Child class or derived class
	
	//Say Base class -> Car and the derived car is like Electric car and Gas car
	Developer d = Developer("Saldina", "YT",25,"C++");
	//Now here we understand the use of the protected class, basically if you use the private class then the child of the original class also cannot access the properties of the original class, but if we use protected as the access modifier, the child / derived class can access the property
	
	d.FixBug();
	//Now basically one problem is that if I want to ask for promotion as a Developer class then we cannot do so, because the inheritance is private by default, to change this we have to include the public keyword in your class
	
	d.AskforPromotion();
	
	Teacher t = Teacher("Jack", "Cool School", 35, "History");
	t.PrepareLesson();
	t.AskforPromotion();
	
	//Polymorphism -- Ability of an object to have many forms(Greek)
	employee1.Work();
	d.Work();
	t.Work();
	
	Employee* e = &d;
	Employee* e2 = &t;
	
	e ->Work();
	e2 ->Work();
	
	//Basically when I had used to void Work keyword, the employees here just recited the work that they had been given to as an employee, 
	//But when I make that object virtual, it checks for the implementation for the particular function in the original derived class
	
	/*Some more points
	what is a virtual function:
	Basically it is a function which is defined in the base class and then redefined in the derived class
	virtual function will allow you to execute the most derived version of your object
	If you do not want to have the implementation of the function by yourself but force the derived classes to have their own implemenation then do something like what i did at the top for the Abstract employee
	*/ 
	
	
}
