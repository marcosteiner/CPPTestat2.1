//============================================================================
// Name        : LastHope.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "kwic.h"
#include <iostream>
using namespace std;

int main() {
	kwic::Kwic test{};

	cout << "Eingabe: ";

	test.addTextLine(std::cin);
	cout << "Sentence added, printing now!" << endl;
	test.print(std::cout);


	return 0;
}
