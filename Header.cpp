//Header.cpp
#include<iostream>
#include<string>
#include<string.h>
#include <cstring>
#include"Header.h"
using namespace std;

Lexicon::Lexicon(int n) {
	N = n;
	count = N;
	wordcount = N * 15;
	tempWC = 0;
	T = new int[N];
	A = new char[wordcount];
	for (int i = 0; i < wordcount; i++) {
		if (i < N)
			T[i] = -1;
		A[i] = ' ';
	}
}

Lexicon::~Lexicon()
{
	delete[] T;
	delete[] A;
}

void Lexicon::Print() {
	cout << "   T   \tA: ";
	//Linear Printing Array A
	for (int i = 0; i < wordcount; i++) {
		if (A[i] != ' ')
			if (A[i] != '\0')
				cout << A[i];
			else
				cout << "\\";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << i << ": ";
		if (T[i] != -1)
			cout << T[i];
		cout << endl;
	}
}

bool Lexicon::Empty()
{
	if (count == N)
		return true;
	return false;
}

bool Lexicon::Full()
{
	if (count == 0)
		return true;
	return false;
}

void Lexicon::Insert(string s) {
	
	int index = hashfun(s);
	count--;	//counter updated for T length
	is_FUll(s);
	T[index] = tempWC;
	for (int i = 0; i < s.length(); i++) {
		A[tempWC] = s[i];
		tempWC++;
	}
	A[tempWC] = '\0';
	tempWC++;
		
}

bool Lexicon::Delete(string s, int &temp) {
	int Tindex, Aindex;
	if (Search(s, Tindex)) {
		temp = Tindex;
		Aindex = T[Tindex];
		T[Tindex] = -1;
		for (int i = 0; i < s.length(); i++) {
			A[Aindex] = '*';
			Aindex++;
		}
		return true;
	}
	return false;
}

bool Lexicon::check(string s, int Aindex) {
	for (int i = 0; i < s.length(); i++) {
		if (A[Aindex] != s[i])
			return false;
		Aindex++;
	}
	if (A[Aindex] == '\0')
		return true;
	return false;
}

bool Lexicon::Search(string s, int& Aindex)
{
	//num is T's index of string s
	int num = 0; //varible to convert string through ASCII
	for (int i = 0; i < s.length(); i++)
		num += s[i];
	num = (num - 2) % N; //Hash Algorithm
	Aindex = num;
	if (check(s, T[num]))
		return true;
	int i = 0;
	while (1) {
		if (T[num] == -1) {
			return false;
		}
		else {
			num += (i * i) % N;
			Aindex = num;
			if (check(s, T[num]))
				return true;
			i++;
		}
		if (i == N * 2)
			break;
	}
	return false;
}

int Lexicon::hashfun(string s)
{
	int num = 0;
	for (int i = 0; i < s.length(); i++)
		num += s[i];
	num = (num - 2) % N;
	int i = 0;
	while (1) {
		if (T[num] == -1) {
			T[num] = 0;
			return num;
		}
		else {
			num += (i * i) % N;
			i++;
		}
	}
}

void Lexicon::is_FUll(string s) {
	if ((wordcount - tempWC) < s.length())
		resize();
}

void Lexicon::resize()
{
	//doubling the size of word array A
	char* newArr = new char[wordcount * 2]; 
	memcpy(newArr, T, wordcount * sizeof(char));
	A = newArr;
	wordcount *= 2;
	for (int i = tempWC; i < wordcount; i++)
		A[i] = ' ';
}
