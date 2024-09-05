#include <iostream>
using namespace std;

int x = 2; // GLOBAL VARIABLE

void fun() {
    int x = 60;
    cout << x << endl; // prints local x
    cout << ::x << endl; // prints global x
}

int main() {
    int x = 20; // local to main() function
    // cout << x << endl; // prints local x
    // cout << ::x << endl; // accessing Global with ::

    {
        int x = 50; // Error: Redefinition of 'x'
        int y = 44;

        cout << x << endl; // prints local x
        cout << y << endl; // prints local y
        cout << ::x << endl; // prints global x
    }

    // fun(); // calling fun()

    return 0;
.
















