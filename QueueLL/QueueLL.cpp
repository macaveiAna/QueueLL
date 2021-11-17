/**
* @file      QueueLL.cpp
* @author    Ana Macavei
* @version   0.1
*
* Demonstrates: Correct  way of implementing Queue Linked Lists
*/

#include <iostream>
#include <cassert> //to use debugging tool assert

struct Node {
	int data;
	Node* next;
};

class Queue {
public:
	/**
	* Default Constructor - Initializes Member Variables
	*/
	Queue() {
		head_front = nullptr;
		tail_back = nullptr;
	}

	/**
	* Destructor - frees up all dynamically allocated memory
	*/
	~Queue() {
		Node* current = head_front;

		while (current != nullptr) {
			Node* nodeToDelete = current;
			current = current->next;
			delete nodeToDelete;
		}
		head_front = nullptr;
		tail_back = nullptr;
	}

	/**
   *    Puts given value into the queue
   *    @param data The item to place in the queue
   */
	void enqueue(int data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;

		if (tail_back == nullptr) {
			assert(head_front == nullptr);
			tail_back = newNode;
			head_front = newNode;
		}
		else {
			tail_back->next = newNode;
			tail_back = newNode;
		}
	}

	/**
	 *    Removes the value from the front of queue
	*    @param data The value removed from queue (if true is returned)
	 */
	bool dequeue(int& data) {
		if (tail_back == nullptr) {
			assert(head_front == nullptr);
			return false;
		}
		//remove node from front of list
		Node* nodeToRemove = head_front;
		head_front = head_front->next;
		//was that the last node in the list?
		if (head_front == nullptr)
			tail_back = nullptr;
		//extract data and delete node
		data = nodeToRemove->data;
		delete nodeToRemove;

		return true;
	}


private:
	Node* head_front;
	Node* tail_back;
};

//test code
int main() {
	Queue nums;

	nums.enqueue(2);
	nums.enqueue(6);
	nums.enqueue(4);
	nums.enqueue(8);

	int num;
	while (nums.dequeue(num)) {
		std::cout << num << ' ';
	}
	
	//verify after queue was emptied we can add/remove more
	nums.enqueue(14);
	nums.enqueue(18);
	while (nums.dequeue(num)) {
		std::cout << num << ' ';
	}
	return 0;
}