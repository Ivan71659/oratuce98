#include <iostream>

using namespace std;

class node {
  public: 
    int data;
    node* next;

    node(int data) {
      this->data = data;
      this->next = nullptr;
    }
};

class list {
  public: 
    node* head;

    list () {
      head = nullptr;
    }

    void add (int data) {
      node* new_node = new node (data);

      if (head == nullptr) {
        head = new_node;
      }

      else {
        node* current = head;

        while (current->next != nullptr) {
          current = current->next;
        }

        current->next = new_node;
      }
    }

    void print () {
      node* current = head;
      while (current != nullptr){
        cout << current->data << " ";
        current = current->next;
      }
      cout << "\n";
    }

    // Question 1: Create a method to add the total of a linked list.
    int method1 (){
      node* current = head;
      int count = 0;
      
      while(current != nullptr){
        count += current->data;
        current = current->next;
      }
      
      return count;
    }

    // Question 2: Create a method to remove all numbers from a linked list that are bigger than 10. Assume that the head is always less than 10.
    void method2 (){
      node* current = head;

      while(current != nullptr && current->next != nullptr){
        int value = current->next->data;
        
        if(value > 10) {
          node* del = current->next;
          current->next = del->next;
          delete del;
        }
        else{
          current = current->next;
        }
      }
    }
  
    // Question 3: Create a method that returns the middle value of a linked list.
    int method3 (){
      node* current = head;
      int size = 0;
      
      while(current != nullptr) {
        size += 1;
        current = current->next;
      }
        
      size/=2;
      current = head;
      
      for (int i = 0; i < size; i++) {
        current = current->next;
      }
      
      return current->data;
    }
};

int main () { 
  list l; 
  l.add(1);
  l.add(2);
  l.add(3);
  l.add(4);
  l.add(5);

  cout << "\nQuestion # 1: " << l.method1 () << "\n";

  list l2; 
  l2.add(1);
  l2.add(20);
  l2.add(3);
  l2.add(40);
  l2.add(5);

  l2.method2 ();
  cout << "\nQuestion # 2: ";
  l2.print ();

  cout << "\nQuestion # 3: " << l.method3() << "\n";
  
}
