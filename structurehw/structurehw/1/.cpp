#include<iostream>
#include<string>
using namespace std;

struct VIDEO_STORE {
    string FilmName;
    string Director;
    string Genre;
    string Popularity;
    string Price;
};

//struct Person
//{
//	string name;
//	string surname;
//	int age{};
//	string gender;
//	string email;
//	string isMarried;
//};
//
//
//
//
//int main() {
//
//	Person person1;
//	int choice;
//	cout << "Enter the name: ";
//	getline(cin, person1.name);
//	cout << "Enter the surname: ";
//	getline(cin, person1.surname);
//	cout << "Enter the age: ";
//	cin >> person1.age;
//	cout << "Choose your gender:\n1.Male\n2.Female" << endl;
//	cin >> choice;
//	if (choice == 1) person1.gender = "Male";
//	else if (choice == 2) person1.gender = "Female";
//	cin.ignore();
//	cout << "Enter the email: ";
//	getline(cin, person1.email);
//	cout << "You are married? ";
//	getline(cin, person1.isMarried);
//
//
//	cout << person1.name << endl;
//	cout << person1.surname << endl;
//	cout << person1.age << endl;
//	cout << person1.gender << endl;
//	cout << person1.email << endl;
//	cout << person1.isMarried << endl;
//
//
//
//}