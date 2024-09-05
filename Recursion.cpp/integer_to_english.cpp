#include <iostream>
#include <vector>
using namespace std;

string ItoS(int number) {
    vector<string> eng = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                          "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                          "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty",
                          "Sixty", "Seventy", "Eighty", "Ninety", "Hundred", "Thousand", "Million",
                          "Billion"};
    vector<int> integers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                            20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000};
    string ans = "";
    string space = " ";
    while (number > 0) {
        int index = integers.size() - 1;
        while (number < integers[index]) {
            index--;
        }
        int nearest_integer = integers[index];
        int prefix = 1;
        if (nearest_integer >= 100) {
            prefix = number / nearest_integer;
            //prefix will be a iteger value and to convert it into words we need to call the function again
            ans += ItoS(prefix) + space + eng[index] + space;
        } else {
            ans += eng[index] + space;
        }
        number = number % nearest_integer;
    }
    return ans;
}

int main() {
    int n = 1557523;
    string ans = ItoS(n);
    cout << ans;
}

//155752 as Thousand Seven Hundred Fifty Two 