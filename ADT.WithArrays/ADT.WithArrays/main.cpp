#include<iostream>

#include "LinkedList.h"
using namespace std;

int main(char args[]) 
{
	int numbersArray[] = {1,2,4,5,6,7,8,9};

	LinkedList<int>* ll = new LinkedList<int>(numbersArray);

	ll->traverse();
	return 0;
}