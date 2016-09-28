#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

template <typename N>
struct Node{
  N data;
  struct Node* next;
};

template <typename T>
class LinkedList{
  public:
    struct Node<T>* head = NULL;

    void printList(){
      struct Node<T>* n = (struct Node<T>*) malloc(sizeof(struct Node<T>));
      n = head;

      cout<<"-----------------------\n";
      cout<<"|     Linked List     | ";
      cout<<"\n-----------------------\n";
      cout<<"  ";
      while(n != NULL){
         cout<<n->data<<"=>";
         n = n->next;
      }
      cout<<"\n\n";
    }

    void insertB(T data){
      struct Node<T>* newNode = (struct Node<T>*) malloc(sizeof(struct Node<T>));

      newNode->data = data;
      newNode->next = head;
      head = newNode;
    }

    void insertE(T data){
      struct Node<T>* newNode = (struct Node<T>*) malloc(sizeof(struct Node<T>));
      struct Node<T>* last = (struct Node<T>*) malloc(sizeof(struct Node<T>));

      last = head;
      while(last->next != NULL){
        last = last->next;
      }

      newNode->data = data;
      newNode->next = NULL;
      last->next = newNode;
    }
};

int main(){
  LinkedList<int> intll;
  LinkedList<char> charll;
  LinkedList<float> floatll;

  intll.insertB(1);
  intll.insertB(6);
  intll.insertB(2);
  intll.insertE(3);
  intll.insertE(10);

  charll.insertB('a');
  charll.insertB('b');
  charll.insertB('c');
  charll.insertE('y');
  charll.insertE('z');

  floatll.insertB(2.1);
  floatll.insertB(3.1);

  intll.printList();
  charll.printList();
  floatll.printList();

  return 0;
}
