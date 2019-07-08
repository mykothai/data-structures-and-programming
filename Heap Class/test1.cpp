/*************************************************************
   Test Program for Basic Heap Class - Preliminiary Version.
**************************************************************/
#include <iostream>
#include "heap.h"
using namespace std;

void heapTest();

int main(){
      heapTest();
      return 0;
}

/*
void Show( Heap & H, string s ){
      cout << s << ".capacity=" << H.capacity() << endl;
      cout << s << ".size=" << H.size() << endl;
      cout << s << "=" ; H.display(); cout << endl;
      cout << "-----------------------\n";
}
*/

void heapTest(){

      // Test default constructor and basic functions
      Heap H;

      cout << endl << endl;
      cout << "///////////////////////////////" << endl;
      cout << "// Before adding to the heap //" << endl;
      cout << "///////////////////////////////" << endl;
      cout << "Current capacity: " << H.capacity() << endl;
      cout << "Is H empty? " << H.empty() << endl;
      cout << "Size: " << H.size() << endl;
      cout << "Peek at min priority element: " << H.peekMin() << endl;
      cout << "Peek at min priority: " << H.peekMinPriority() << endl;

      cout << endl;
      cout << "///////////////////////////////" << endl;
      cout << "// Adding to the heap        //" << endl;
      cout << "///////////////////////////////" << endl;

// PLAYING AROUND TEST VALUES
      // H.insert(101,1);
      // H.insert(114,1);
      // H.insert(111,1);
      // H.insert(119,1);
      // H.insert(108,1);
      // H.insert(100,1);
      // H.insert(90,1);
      // H.insert(50,1);

   // OG TEST VALUES
      H.insert(91,7);
      H.insert(92,6);
      H.insert(93,8);
      H.insert(99,10);
      H.insert(94,5);
      H.insert(95,9);
      H.insert(89,1);
      H.insert(72,4);
      H.insert(82,2);
      H.insert(87,3);

      // greater than size 10 heap
      H.insert(80,11);
      H.insert(88,5);


      cout << "Is H empty? " << H.empty() << endl;
      cout << "Size: " << H.size() << endl;
      cout << endl;

      while( !H.empty() ){
        cout << "Size: " << H.size() << endl;
        cout << "min priority: " << H.peekMinPriority() << endl;
        cout << "min priority element: " << H.peekMin() << endl;
        cout << endl;
        H.extractMin();
      }

      cout << "Size: " << H.size() << endl;

}
