//Main.cpp
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include"Header.h"
using namespace std;


void batch(string s) {
	int init_val = 0;
	int choice;
	ifstream myfile;
	myfile.open(s);
	if (myfile.is_open()) {
		string s;
		do {
			myfile >> choice >> init_val;
			if (choice != 14)
				cout << "You need to initialize the array first" << endl;
		} while (choice != 14 && !myfile.eof());

		Lexicon obj(init_val);
		int temp;
		bool loop = true;
		while (!myfile.eof()) {
			myfile >> choice;
			if (choice != 13)
				myfile >> s;
			switch (choice) {
			case 10:
				obj.Insert(s);
				break;
			case 11:
				if (obj.Delete(s, temp))
					cout << "\t" << s << "\tDeleted from slot " << temp << endl;
				break;
			case 12:

				if (obj.Search(s, temp)) {
					cout << "\t" << s << "\tfound at slot " << temp << endl;
				}
				else
					cout <<"\t" << s << "\tnot found" << endl;
				break;
			case 13:
				obj.Print();
				cout << endl;
				break;
			case 15:
				cout << "";
				break;
			default:
				cout << "Not a valid command" << endl;
				loop = false; //need to change it to eof
				break;
			}

		}
	}
	else
		cout << "File not found!!!" << endl;
	myfile.close();
}

int main(int argc, char *args[]) {

	
	if (argc == 1)
		cout << "Enter a file name as an argument" << endl;
	else
		batch(args[1]);
	return 0;
}