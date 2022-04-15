#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL

using namespace std;

template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  //EFFECTS:  returns true if the list is empty
  bool empty() const {
    if(size() == 0)
      return true;
    return false;
  }//checked

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const{
    return list_size;
  }//checked

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front(){
    assert(size()>0);
    return (first->datum);
  }//checked

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    assert(size()>0);
    return (last->datum);
  }//checked

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    Node *cur = new Node;
    cur->datum = datum;
    cur->next = first;
    cur->prev = nullptr;
    list_size++;
    if(list_size == 1){
      last = cur;
      first = cur;
      return;
    }else{
      first->prev = cur;
      first = cur;
    }
  }//checked

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    Node *cur = new Node;
    cur->datum = datum;
    cur->next = nullptr;
    cur->prev = last;
    list_size++;
    if(list_size == 1){
      last = cur;
      first = cur;
      return;
    }else{
      last->next = cur;
      last = cur;
      return;
    }
  }//checked

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    if(list_size == 0)
      return;
    if(list_size == 1){
      Node *pop_node = last;
      first = nullptr;
      last = nullptr;
      list_size--;
      delete pop_node;
      return;
    }
    Node *pop_node = first;
    first = pop_node->next;
    first->prev = nullptr;
    delete pop_node;
    list_size--;
  }//checked

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back(){
    if(list_size == 0)
      return;
    if(list_size == 1){
      Node *cur = last;
      delete cur;
      first = nullptr;
      last = nullptr;
      list_size--;
      return;
    }
    Node *cur = last;
    last = cur->prev;
    last->next = nullptr;
    delete cur;
    list_size--;
  }//checked

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){
    while(size()>0){
      pop_back();
    }
  }//checked

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

  List(){
    first = nullptr;
    last = nullptr;
  }

  ~List(){
    clear();
  }//checked in Valgrind

  List(const List &other){
    copy_all(other);
  }

  List & operator=(const List &rhs){
    if(!empty()){
      return *this;
    }
    copy_all(rhs);
    return *this;
  }

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other){
    if(other.empty())
      return;
    Node *temp = other.first;
    while(1){
      T temp_datum = temp->datum;
      this->push_back(temp_datum);
      if(temp->next == nullptr)
        return;
      temp = temp->next;
    }
    delete temp;
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

  int list_size = 0;

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.

    Iterator()
    : node_ptr(nullptr) { 

    }

    Iterator & operator=(const Iterator &rhs){
      node_ptr = rhs.node_ptr;
      return *this;
    }

    T & operator*(){
      return node_ptr->datum;
    }

    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }// do not modify this

    Iterator& operator++() {
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    bool operator==(Iterator rhs) const{
      return node_ptr == rhs.node_ptr;
    }

    bool operator!=(Iterator rhs) const{
      return node_ptr != rhs.node_ptr;
    }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List;

    // construct an Iterator at a specific position
    Iterator(Node *p){
      node_ptr = p;
    }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const{
    return Iterator();
  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
  void erase(Iterator i){
    if(i.node_ptr== nullptr)
      return;
    if(i.node_ptr == last){
      pop_back();
      return;
    }
    if(i.node_ptr == first){
      pop_front();
      return;
    }

    Node *next_node = i.node_ptr->next;
    i.node_ptr->prev->next = next_node;
    next_node->prev = i.node_ptr->prev;
    list_size--;
    delete i.node_ptr;//delete the node
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
  void insert(Iterator i, const T &datum){
    if(i.node_ptr == nullptr){
      push_back(datum);
      return;
    }
    if(i.node_ptr == first){
      push_front(datum);
      return;
    }
    Node *cur = new Node;
    cur->datum = datum;
    cur->next = i.node_ptr;
    cur->prev = i.node_ptr->prev;
    i.node_ptr->prev->next = cur;
    i.node_ptr->prev = cur;
    list_size++;
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.


#endif // Do not remove this. Write all your code above this line.
