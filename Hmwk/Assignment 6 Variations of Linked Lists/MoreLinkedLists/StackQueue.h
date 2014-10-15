/*Joel R. Youngberg 9 Oct 2014
Stack/Queue variation of Linked List
*/

#include "LnkdLst.h"
template <class T>
class StackQueue : public LnkdLst<T>{
	
public:
	
	StackQueue(int d) : LnkdLst(d) {}
	//~StackQueue() : ~LnkdLst() {}
	void push(int);
	void pop();
	void add(int);

};

template <class T>
void StackQueue<T>::push(int d){
	this->prepend(d);
}

template <class T>
void StackQueue<T>::pop(){
	this->extract(position(0));
}

template <class T>
void StackQueue<T>::add(int d){
	this->append(d);
}
