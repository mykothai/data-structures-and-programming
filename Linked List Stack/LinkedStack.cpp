#include <cstdlib>
#include <iostream>
#include <string>
using std::string;
using namespace std;


class StringNode {				                  // a node in a list of strings
private:
  string elem;				                      // element value
  StringNode* next;				                  // next item in the list

  friend class StringLinkedList;		        // provide StringLinkedList access
};

class StringLinkedList {			              // a linked list of strings
public:
  StringLinkedList();				                // empty list constructor
  ~StringLinkedList();			                // destructor
  bool empty() const;				                // is list empty?
  const string& front() const;		          // get front element
  void addFront(const string& e);		        // add to front of list
  void removeFront();				                // remove front item list
private:
  StringNode* head;				                  // pointer to the head of list
};

StringLinkedList::StringLinkedList()			  // constructor
  : head(NULL) { }

StringLinkedList::~StringLinkedList()			  // destructor
  { while (!empty()) removeFront(); }

bool StringLinkedList::empty() const			  // is list empty?
  { return head == NULL; }

const string& StringLinkedList::front() const		    // get front element
  { return head->elem; }

void StringLinkedList::addFront(const string& e) {	// add to front of list
  StringNode* v = new StringNode;			              // create new node
  v->elem = e;					                            // store data
  v->next = head;					                          // head now follows v
  head = v;				                                  // v is now the head
}

void StringLinkedList::removeFront() {		          // remove front item
  StringNode* old = head;				                    // save current head
  head = old->next;					                        // skip over old head
  delete old;						                            // delete the old head
}


  typedef string Elem;				        // stack element type
    class LinkedStack {				        // stack as a linked list
    public:
      LinkedStack();				          // constructor
      int size() const;				        // number of items in the stack
      bool empty() const;			        // is the stack empty?
      const Elem& top() const;	      // the top element
      void push(const Elem& e);  		  // push element onto stack
      void pop();		                  // pop the stack
    private:                          // member data
      StringLinkedList S;			        // linked list of elements
      int n;					                // number of elements
    };

LinkedStack::LinkedStack()
    : S(), n(0) { }				             // constructor

  int LinkedStack::size() const {      // returns number of items
      return n;
  }

  bool LinkedStack::empty() const
    { return n == 0; }				         // is the stack empty?

  const Elem& LinkedStack::top() const {
      return S.front();
  }

  void LinkedStack::push(const Elem& e) {	        // push element onto stack
    ++n;
    S.addFront(e);
  }

	// pop the stack
  void LinkedStack::pop() {
	  --n;
    S.removeFront();
  }

  int main() {
  // your main code goes here

      // 1. Prompt user to enter words
      cout << "Enter words, one per line and press enter when finished." << endl;

      // 2. Create instance(s) of the basic stack class
	  LinkedStack newStack;
	  LinkedStack newStackTwo;

      // 3. Read in a sequence of strings from the keyboard, one per line,
      //    and terminated by the null string
      string userInput;

      while (getline(cin, userInput)) {
            if(userInput == "") {
                  break;
            }
	    newStack.push(userInput);
      }

      // 4. Output a blank line, followed by a line with the length of
      //    the sequence, followed by a line with a concatenation of the
      //    strings in reverse order, followed by another blank line;
      //    To determine the size of the sequence you must use the stack size function

      cout << newStack.size() << endl;
      while(!newStack.empty()){
            cout << newStack.top();
            newStackTwo.push(newStack.top());
            newStack.pop();
      }
      cout << '\n' << endl;

      // 5. Output the sequence of strings in the original order, one per line;
      while(!newStackTwo.empty()){
            cout << newStackTwo.top() << endl;
            newStackTwo.pop();
      }

      // 6. Output a (exactly one) "goodbye" line;
      cout << "goodbye" << endl;

	  return EXIT_SUCCESS;
  }