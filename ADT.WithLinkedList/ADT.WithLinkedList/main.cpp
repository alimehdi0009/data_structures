
#include<iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main(char *args[])
{

	DoublyLinkedList<int>* dll = new DoublyLinkedList<int>();

	dll->addStart(1);
	dll->addStart(2);
	dll->addStart(3);
	dll->addStart(4);
	dll->addStart(5);

	dll->addEnd(5);
	dll->addEnd(6);
	dll->addEnd(7);
	dll->addEnd(7);
	dll->addEnd(8);
	dll->addEnd(9);
	dll->addEnd(10);
	dll->addEnd(10);

	cout << "original" << endl;

	dll->traverse();

	cout << endl;
	cout << endl;


	dll->removeStart();

	cout << "removed start" << endl;

	dll->traverse();

	cout << endl;

	dll->removeEnd();
	
	dll->traverse();

	cout << endl;

	cout << "removed end" << endl;

	dll->removeRandom(6);

	cout << endl;

	cout << "removed random - 6" << endl;


	dll->traverse();

	cout << endl;
	return 0;
}