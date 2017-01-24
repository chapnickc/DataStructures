#include <iostream>
using namespace std;

int main() {
    // this could be a pointer to a single int,
    //  or it could be the start of an array
    //int* myarray=0; // or int* myarray;
    int* myarray;
    int len=-1;

    while (len!=0) {
        cout << "how many numbers to enter (0 to quit): ";
        cin >> len;

        cout << "pointer to len " << &len << endl;

        // allocate space for a new array
        // you have no control over what 
        // addr "new" will start
        //myarray = new int[len];

        // will give segmentation fault 
        // if you don't allocate it

        //cout << "pointer to len = " << &len << "\n";
        for (int i = 0; i < len; i++) {
            //cout << "pointer = " << myarray+i << "\n";
            // these are allocated on the stack
            cout << "pointer = " << myarray+i << "\n";
            cout << "Enter value #" << i << ": ";
            //cin >> myarray[i];
            cin >> *(myarray+i);
        }

        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += myarray[i];
        }
        cout << "sum = " << sum << endl;
        // if you don't use this, this is a memory leak
        delete myarray;
    }

    return 0;
}
