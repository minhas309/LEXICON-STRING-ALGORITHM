//Header.h
#pragma once
#ifndef HEADER_H
#define HEADER_H
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
class Lexicon
{
public:

	//Constructor is working as the create function as it is initiallizing the obj as array
	//So there's no need to have a seprate Create function
	Lexicon(int n);	//Constructor
	~Lexicon();		//Destructor
	void Print();	//Printing the desiderd output from print function. Tested
	bool Empty();	//Tested
	bool Full();	//IF Full then double the array size. Tested
	void Insert(string);	//Tested
	bool Delete(string s, int&);	//Tested
	bool check(string, int);	//Tested
	bool Search(string s, int &index);	//Testing. Output formating is yet to maintain. 
	int hashfun(string);	//Use Quadratic probing to generate a hash index and return it. Tested
	void is_FUll(string);	//Tested
	void resize();	//resizing if A is full. Tested

private:
	int* T;		//Array for hash Indexes
	char* A;	//Words char Array
	int N;		//Total Strings/Words
	int count;	//Counter for Length of T
	int wordcount;	//Total space of A
	int tempWC;	//space used in A 
};
#endif // HEADER_H
