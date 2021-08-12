#include <iostream>
using namespace std;

struct Smartphone{
	string name;
	int storageSpace;
	string color;
	float price;
};

void prrint(Smartphone smartphone){
	cout << "Name: " << smartphone.name << endl;
	cout << "Space: " << smartphone.storageSpace << endl;
	cout << "COlor: " << smartphone.color << endl;
	cout << "Price: " << smartphone.price << endl;
}

struct Person{
	string name;
	int age;
	Smartphone smartphone;
}

int main(){
	//string name = "Iphone 12";
	//int storage = 1024;
	//string color = "black";
	//float price = 999.99;
	
	string name2 = "Samsung Galaxy S21"
	int storage2 = 2048;
	string color2 = "gray";
	float price2 = 800.00;
	
	Smartphone smartphone;
	smartphone.name = "Iphone 12";
	smartphone.storageSpace = 1024;
	smartphone.color = "black";
	smartphone.price = 999.99;
	
		
}
