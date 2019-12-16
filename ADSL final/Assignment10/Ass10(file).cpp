#include"pch.h"
#include<iostream>
#include<fstream>
using namespace std;

class Student {
	int admno;
	char name[50];
	char addr[50];

public:
	void setData() {
		cout << "\nEnter Roll no. ";
		cin >> admno;
		cout << "Enter name of student ";
		cin >> name;
		cout << "enter the address of the student";
		cin >> addr;
	}

	void showData() {
		cout << "\nAdmission no. : " << admno;
		cout << "\nStudent Name : " << name;
		cout << "\nAddress:" << addr;
	}

	int retAdmno() {
		return admno;
	}
};

void write_record() {
	ofstream outFile;
	outFile.open("student.dat", ios::binary | ios::app);
	Student obj;
	obj.setData();
	outFile.write((char*)&obj, sizeof(obj));
	outFile.close();
}

void display() {
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	Student obj;
	while (inFile.read((char*)&obj, sizeof(obj))) {
		obj.showData();
	}
	inFile.close();
}

void search(int n) {
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	Student obj;
	while (inFile.read((char*)&obj, sizeof(obj))) {
		if (obj.retAdmno() == n) {
			obj.showData();
			break;
		}
	}
	inFile.close();
}

void delete_record(int n) {
	Student obj;
	ifstream inFile;
	inFile.open("student.dat", ios::binary);
	ofstream outFile;
	outFile.open("temp.dat", ios::out | ios::binary);
	while (inFile.read((char*)&obj, sizeof(obj))) {
		if (obj.retAdmno() != n) {
			outFile.write((char*)&obj, sizeof(obj));
		}
	}

	inFile.close();
	outFile.close();
	remove("student.dat");
	rename("temp.dat", "student.dat");
}

void modify_record(int n) {
	fstream file;
	file.open("student.dat", ios::in | ios::out);
	Student obj;

	while (file.read((char*)&obj, sizeof(obj))) {
		if (obj.retAdmno() == n) {
			cout << "\nEnter the new details of student";
			obj.setData();
			 int pos = (-1) * (sizeof(obj));
			file.seekp(pos, ios::cur);
			file.write((char*)&obj, sizeof(obj));
		}
	}
	file.close();
}

int main() {
	int ch;
	do {
		cout << "\nMenu\n\t1.write\n2.display\n3.search\n4.delete\n5.modify";
		cout << "\nEnter your choice";
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "Enter number of records"; 
			int n;
			cin >> n;
			for (int i = 0; i < n; i++)
				write_record();
			break;

		case 2:
			cout << "\nList of records";
			display();
			break;

		case 3: 
			cout << "Enter admission no. to be searched";
			int s;
			cin >> s;
			search(s);
			break;

		case 4:
			cout << "enter no to be deleted";
			int d;
			cin >> d;
			delete_record(d);
			cout << "\nRecord Deleted";
			break;

		case 5:
			cout << "enter rno to be modified";
			int m;
			cin >> m;
			modify_record(m);
			break;

		case 6:
			return 0;
		}
	} while (ch != 6);
}
