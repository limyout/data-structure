#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "GenericDoublyListP.h"

using namespace std;

template<typename T>
listClass<T>::listClass() {
	Count = 0;
	Head = NULL;
	Temp = NULL;
}

template<typename T>
listClass<T>::listClass(const listClass<T>& L)
{
	Count = L.Count;
	if (L.Head == NULL)
		Head = NULL;
	else
	{
		Head->Data = L.Head->Data;
		node<T> *Temp1 = Head;
	}
}

template<typename T>
listClass<T>::~listClass()
{
	while (!IsEmpty()) {
		Delete(1);
	}

}

template<typename T>
void listClass<T>::Insert(int Position, T Item) {
	node<T> *n = new node<T>;
	n->Next = NULL;
	n->Data = Item;

	if (Head != NULL) {

		Temp = Head;

		if ((Count + 1) == Position) {
			for (int i = 1; i < (Position - 1); i++) {
				Temp = Temp->Next;
			}
			Temp->Next = n;
			n->Prev = Temp;
		}
		else {
			for (int i = 1; i < Position; i++) {
				Temp = Temp->Next;
			}
			n->Prev = Temp->Prev;
			Temp->Prev = n;
			n->Next = n->Prev->Next;
			n->Prev->Next = n;
		}
	}
	else {
		Head = n;
	}

	Count += 1;
}

template<typename T>
void listClass<T>::Delete(int Position) {

	node<T> *Temp = this->Head;

	if (IsEmpty())
		cout << "Deletion on Empty List" << endl;
	else if ((Position > Count) || (Position < 1))
		cout << "Position out of Range" << endl;
	else
	{
		Temp = Head;
		if (Position == 1) {
			Head = Head->Next;
		}
		else {
			for (int i = 1; i < Position; i++) {
				Temp = Temp->Next;
			}
			Temp->Next->Prev = Temp->Prev;
			Temp->Prev->Next = Temp->Next;
		}
		Count -= 1;
		delete (Temp);
	}
}

template<typename T>
void listClass<T>::Retrieve(int Position, T & item) {
	if (IsEmpty())
		cout << "Deletion on Empty List" << endl;
	else if ((Position > Count) || (Position < 1))
		cout << "Position out of Range" << endl;
	else
	{
		Temp = Head;
		for (int i = 1; i < Position; i++) {
			Temp = Temp->Next;
		}
		item = Temp->Data;
		cout << "copied value : " << item << endl;
	}
}

template<typename T>
bool listClass<T>::IsEmpty() {
	return (Count == 0);
}

template<typename T>
int listClass<T>::Length() {
	cout << "Length is " << Count << endl;
	return 0;
}

template<typename T>
void listClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   ";
		Temp = Temp->Next;
	}
	cout << endl;
}

int main()
{
	listClass<int> integer;
	int item;

	integer.Insert(1, 1);
	integer.Insert(2, 2);
	integer.Insert(3, 3);
	integer.PrintList();
	integer.Insert(3, 4);
	integer.PrintList();
	integer.Insert(5, 5);
	integer.PrintList();
	integer.Delete(4);
	integer.PrintList();
	integer.Delete(1);
	integer.PrintList();
	integer.Length();
	integer.Retrieve(2, item);
}