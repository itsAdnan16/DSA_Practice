#include <iostream>
#include <string>
using namespace std;

class Demo {
private:
    string num1;

public:
    Demo(string num1) {
        this->num1 = num1;
    }

    void operator+( Demo& obj)  {
        string number1 = this->num1;
        string number2 = obj.num1;
        string res = "";
        int real = number1[0] - '0' + number2[0] - '0';
        int img;

        if (number1[1] == '+' && number2[1] == '+') {
            img = number1[2] - '0' + number2[2] - '0';
            cout << res + to_string(real) + " + " + to_string(img)+"i";
            //return;
        }
        else if (number1[1] == '-' && number2[1] == '-') {
            img = number1[2] - '0' + number2[2] - '0';
            cout << res + to_string(real) + " - " + to_string(img) + "i";
            //return;
        }
        else if ((number1[1] == '+' && number2[1] != '+') || (number1[1] == '-' && number2[2]!='-')) {
            img = (number1[2] - '0') - (number2[2] - '0');
            if ((number1[2] - '0') > (number2[2] - '0')) {
                cout << res + to_string(real) + " " + number1[1] + " " + to_string(img) + "i";
            }
            else {
                cout << res + to_string(real) + " " + number2[1] + " " + to_string(img) + "i";
            }
        }
    }

    ~Demo() {
        //cout << "Destructor Called" << endl;
    }
};

int main() {
    Demo * obj1 = new Demo("3-6i");
    Demo obj2("8+8i");
    *obj1 + obj2;
    delete obj1;
    return 0;
}