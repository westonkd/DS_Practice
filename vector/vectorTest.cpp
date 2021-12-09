#include <iostream>
#include <string>
#include "vector.h"
#include "../testing/expect.h"


void defaultConstructor() {
	Custom::Vector<int> subject;

	Testing::Expect<int>(
		subject.size(),
		"with the default constructor"
		).to("to have size() 0", 0);

	Testing::Expect<int>(
		subject.capacity(),
		"with the default constructor"
		).to("to have capacity() 0", 0);
}

void capacityConstructor() {
	Custom::Vector<int> subject(10);

	Testing::Expect<int>(
		subject.capacity(),
		"with the capacity constructor of 10"
		).to("to have the specified capacity", 10);

	Testing::Expect<int>(
		subject.size(),
		"with the capacity constructor of 10"
		).to("to have the size 10", 10);
}

void fillConstructor() {
	Custom::Vector<int> subject(10, 1);

	Testing::Expect<int>(
		subject.size(),
		"with the fill constructor of 10, 1"
		).to("to have the size 10", 10);

	Testing::Expect<int>(
		subject.capacity(),
		"with the fill constructor of 10, 1"
		).to("to have the capacity 10", 10);

	Testing::Expect<int>(
		subject.at(0),
		"with the fill constructor of 10, 1"
		).to("to be filled with 1 (start)", 1);

	Testing::Expect<int>(
		subject.at(9),
		"with the fill constructor of 10, 1"
		).to("to be filled with 1 (end)", 1);
}

void copyConstructor() {
	Custom::Vector<int> source(10, 1);
	Custom::Vector<int> subject(source);

	Testing::Expect<int>(
		subject.size(),
		"with copy constructor of a vector of size 10 filled with 1"
		).to("to have the size 10", 10);

	Testing::Expect<int>(
		subject.capacity(),
		"with copy constructor of a vector of size 10 filled with 1"
		).to("to have the capacity 10", 10);

	Testing::Expect<int>(
		subject.at(0),
		"with copy constructor of a vector of size 10 filled with 1"
		).to("to be filled with 1 (start)", 1);

	Testing::Expect<int>(
		subject.at(9),
		"with copy constructor of a vector of size 10 filled with 1"
		).to("to be filled with 1 (end)", 1);
}

void clear() {
	Custom::Vector<int> subject(10, 1);

	subject.clear();

	Testing::Expect<int>(
		subject.size(),
		"when the vector is cleared"
		).to("to have size() 0", 0);

	Testing::Expect<int>(
		subject.capacity(),
		"when the vector is cleared"
		).to("to have unchanged capacity", 10);
}

void push_back() {
	Custom::Vector<int> subject(5, 1);

	subject.push_back(2);

	Testing::Expect<int>(
		subject.at(subject.size() - 1),
		"when an item is pushed back"
		).to("append the value to the end of the vector", 2);

	Testing::Expect<int>(
		subject.capacity(),
		"when an item is pushed back at full capacity"
		).to("doubles the capacity", 10);
}

void empty() {
	Custom::Vector<int> subject(5, 1);
	subject.clear();

	Testing::Expect<int>(
		subject.size(),
		"a cleared vector"
		).to("have size 0", 0);

	Testing::Expect<int>(
		subject.capacity(),
		"a cleared vector"
		).to("an unchaged capacity", 5);
}

int main() {
	defaultConstructor();
	capacityConstructor();
	fillConstructor();
	clear();
	push_back();
	empty();
	
	return 0;
}