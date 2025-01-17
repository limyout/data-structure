#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "genericQueueDL.h"

using namespace std;

template<typename T>
queueClass<T>::queueClass() {
	Rear = NULL;
	Count = 0;;
}

template<typename T>
queueClass<T>::queueClass(const queueClass<T>& Q)
{
	Rear = Q.Rear;
}

template<typename T>
queueClass<T>::~queueClass()
{
	int Temp;
	while (!IsEmpty()) {
		Remove();
	}

}

template<typename T>
void queueClass<T>::Add(T Item)
{
	node<T> *NewRear = new node<T>;
	NewRear->Data = Item;

	if (Count > 0) {
		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		NewRear->Prev = Temp;
		Temp->Next = NewRear;
	}
	else {
		Head = NewRear;
	}
	Rear = NewRear;
	Count += 1;
}

template<typename T>
void queueClass<T>::Remove()
{
	if (IsEmpty()) {
		cout << "Deletion on Empty queue" << endl;
	}
	else {
		Temp = Head;
		Head = Temp -> Next;
		delete Temp;
	}
	Count -= 1;
}


template<typename T>
bool queueClass<T>::IsEmpty()
{
	if (Count != 0) {
		return 0;
	}
}


template<typename T>
bool queueClass<T>::IsFull()
{
	if (Count == MAX) {
		return 1;
	}
}

template<typename T>
void  queueClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   " << endl;
		Temp = Temp->Next;
	}
	cout << endl;
}

int main()
{
	queueClass<int> integer;
	int item = 0;

	integer.Add(1);
	integer.Add(2);
	integer.Add(3);
	integer.PrintList();
	integer.Remove();
	integer.PrintList();
	integer.Add(4);
	integer.PrintList();
}