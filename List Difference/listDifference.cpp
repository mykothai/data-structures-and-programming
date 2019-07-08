/*
**  Assignment, CMPT-225
**
**  This program reads a sequence of integers from a text file,
**  separates the integers into two lists, L1 and L2 for which
**  a '0' delimits the lists and outputs the largest number that
**  occurs in L1 but does not occur in L2, or "NONE" if there
**  is no such number.
*/
#include <iostream>
#include <fstream>
#include <string>
#include "priority_queue.h" //code not by me

using namespace std;

int main(){
	//create priority_queue q1 and q2
      priority_queue<int> q1;
      priority_queue<int> q2;

      int x;
      int count = 0;
      int L1count = 0;
      int L2count = 0;
      bool List2 = false;

      string filename;
      ifstream usersFile;

      cout << "Enter a filename then press enter (in the format of filename.txt): ";
      cin >> filename;

      usersFile.open(filename); //to hard code a file, replace filename with "sample1.txt"

      if (!usersFile) {
             cout << "Unable to open file." << endl;
             cout << "Please make sure the file name is in the format filename.txt and re-run the program." << endl;
             exit(1);
      }

      // loop to place integers in q1 and q2
      // std::priority_queue sorts as elements are placed
      while( usersFile >> x ) {
            if( x == 0 ) {                      // if there is a 0, list 2 exists
                  List2 = true ;
            }

            else if (!List2) {                  // if there is not second list, increment the count
                  L1count++;                    // for elements in list 1 and push to queue 1
                  q1.push(x);
            }

            else {
                  L2count++;                    // push list 2 elements to queue 2
                  q2.push(x);
            }
            count++;                            // increment to the next element in the file

            if (usersFile.eof()) {
                  break;
            }
     }

     usersFile.close();

      // cout << "<studentID> <computingID> <firstName> <lastName>" << endl;    // required for assignment

      //maxL1 and maxL2 will be largest numbers in each queue
      int maxL1 = 0;
      int maxL2 = 0;

      //while q1 is not empty, compare maxL1 and maxL2, else output NONE
      while (!q1.empty()) {
            maxL1 = q1.top();                   // assign the top of q1 to maxL1 for comparison

            if (q2.empty()) {                   // if q2 is empty then return maxL1
                  cout << maxL1 << endl;
                  return 0;
            }

            maxL2 = q2.top();                   // assign the top of q2 to maxL2
            int temp = 0;

            while (maxL1 < maxL2) {             // loop through q2 to check for an integer
                  q2.pop();                     // that equals the current max in q1 and
                  maxL2 = q2.top();             // if not found, pop q2 to get next new maxL2
                  if (q2.empty()) {             // if q2 is empty then return maxL1
                        cout << maxL1 << endl;
                        return 0;
                  }
            }
            if (maxL1 == maxL2) {               // if a matching integer from both lists are found then pop both from each queue
                  temp = maxL1;                 // temp is set to handle duplicates in q1
                  q1.pop();
                  q2.pop();

                  if (q1.empty()) {             // if q1 is now empty then print NONE
                        cout << "NONE" << endl;
                  	return 0;
                  }

                  if (q2.empty()) {
                        cout << maxL1 << endl;  // if q2 is empty then print maxL1
                        return 0;
                  }

                  maxL1 = q1.top();             // if neither queues are empty, set new max
                  maxL2 = q2.top();             // integers for each queue

                  // this while loop handles duplicates in q1
                  while (q1.top() == temp) {    // if the next integer in q1 is temp (duplicate integer), keep popping
                        q1.pop();
                        if (q1.empty()) {       // if q1 is now empty then print NONE
                              cout << "NONE" << endl;
                        	return 0;
                        }
                        maxL1 = q1.top();       // set new maxL1 to next integer in the queue
                   }
            }

            else {
                   cout << maxL1 << endl;       // maxL1 is the max in q1 that doesn't show up in q2
                   return 0;
            }
      }

      cout << "NONE" << endl;
	return 0;
}
