#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <string>

#include "genericStackDL.h"

using namespace std;

template<typename T>
stackClass<T>::stackClass() {
	Top = NULL;
	Count = 0;;
}

template<typename T>
stackClass<T>::stackClass(const stackClass<T>& S)
{
	Top = S.Top;
}

template<typename T>
stackClass<T>::~stackClass()
{
	int Temp;
	while (!IsEmpty()) {
		Temp = Pop();
	}

}

template<typename T>
void stackClass<T>::Push(T Item)
{
	node<T> *NewTop = new node<T>;
	NewTop->Data = Item;

	if (Count > 0) {
		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		NewTop->Prev = Temp;
		Temp->Next = NewTop;
	}
	else {
		Head = NewTop;
	}
	Top = NewTop;
	Count += 1;
}
template<typename T>
int stackClass<T>::Pop()
{
	if (IsEmpty()) {
		cout << "Deletion on Empty Stack" << endl;
	}
	else {
		Temp = Head;
		for (int i = 0; i < Count - 1; i++) {
			Temp = Temp->Next;
		}
		Top = Temp->Prev;
		delete Temp;
	}
	Count -= 1;
	return 0;
}

template<typename T>
void stackClass<T>::GetTop(T& Item)
{
	Temp = Head;
	for (int i = 0; i < Count - 1; i++) {
		Temp = Temp->Next;
	}
	Item = Temp->Data;
	cout << "Top's Data : " << Count << " ----- " << Item << endl;
}

template<typename T>
bool stackClass<T>::IsEmpty()
{
	if (Count != 0) {
		return 0;
	}
}

template<typename T>
bool stackClass<T>::IsFull()
{
	if (Count == MAX) {
		return 1;
	}
}

template<typename T>
void  stackClass<T>::PrintList() {
	Temp = Head;
	for (int i = 1; i < Count + 1; i++) {
		cout << i << "'s list : " << Temp->Data << "   " << endl;
		Temp = Temp->Next;
	}
	cout << endl;
}

int main()
{
	stackClass<int> integer;
	int item = 0;

	integer.Push(1);
	integer.Push(2);
	integer.Push(3);
	integer.PrintList();
	integer.Pop();
	integer.PrintList();
	integer.Push(4);
	integer.PrintList();
	integer.GetTop(item);
}