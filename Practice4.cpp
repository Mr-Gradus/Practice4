#include <iostream>
#include <vector>
#include <locale>
#include <set>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

//=================Task_1=====================

#include "ArrayInt.h"


//=================Task_2=====================




//=================Task_3=====================

int main()
{
	setlocale(0, "rus");

	//=================Task_1=================

	cout << "==========Task 1==========" << ".\n" << endl;
	/*
	vector<int> v{ 13, 23, 456, -567 };
	v.push_back(7);
	v.pop_back();
	cout << v.empty() << endl;
	print(v);

	vector<int>::iterator it;
	it = v.begin();
	cout << *(it+1) << endl;

	sort(v.begin(), v.end());
	print(v);
	*/
	
	ArrayInt arr(5);
	arr[0] = -13;
	arr[1] = 38;
	arr[2] = 9;
	arr[3] = 2;
	arr[4] = 13;
	arr.sort();
	arr.pop_back();
	arr.pop_front();
	arr.print();
	
	//=================Task_2=====================

	cout << endl << "==========Task 2==========" << ".\n" << endl;

	vector<int> val = { 13, 7, 13, 13, 13, 13, 13, 63, 13, 13, 13, 13, 38, 13 };
	set<int> dif(val.begin(), val.end());
	cout << dif.size() << " различных значений из " << val.size() << endl;
	
	
}

