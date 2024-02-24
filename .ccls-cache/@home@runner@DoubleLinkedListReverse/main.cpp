#include <iostream>

using namespace std;

class Node {
public:
  int value;
  Node *next;
  Node *prev;

  Node(int value) {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList(int value) {
    Node *newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }

  ~DoublyLinkedList() {
    Node *temp = head;
    while (head) {
      head = head->next;
      delete temp;
      temp = head;
    }
  }

  void printList() {
    Node *temp = head;
    if (temp == nullptr) {
      cout << "empty" << endl;
      return;
    }
    while (temp->next != nullptr) {
      cout << temp->value << " <-> ";
      temp = temp->next;
    }
    cout << temp->value << endl;
  }

  Node *getHead() { return head; }

  Node *getTail() { return tail; }

  int getLength() { return length; }

  void append(int value) {
    Node *newNode = new Node(value);
    if (length == 0) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  //   +=====================================================+
  //   |                 WRITE YOUR CODE HERE                |
  //   | Description:                                        |
  //   | - This is the reverse method.                       |
  //   | - It reverses the entire doubly linked list.        |
  //   | - Return type: void                                 |
  //   |                                                     |
  //   | Tips:                                               |
  //   | - Create two pointers: current and temp.            |
  //   | - Loop through the list swapping next and prev      |
  //   |   for each node.                                    |
  //   | - After loop, swap head and tail pointers.          |
  //   | - Check output from Test.cpp in "User logs".        |
  //   +=====================================================+
  void reverse() {
    // Check if the list is empty or has only one node.
    if (head == nullptr || head->next == nullptr) {
      return; // No need to reverse.
    }

    Node *current = head;
    Node *temp = nullptr;

    // Loop through the list swapping next and prev for each node.
    while (current != nullptr) {
      // Swap the next and prev pointers of the current node.
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;

      // Move to the next node in the original list, which is prev in the
      // current context.
      current = current->prev;
    }

    // After loop, swap head and tail pointers.
    temp = head;
    head = tail;
    tail = temp;
  }
};
