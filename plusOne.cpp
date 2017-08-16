#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> plusOne(vector<int>& digits) {
    int last = 0, temp = 0;

    for(int i = digits.size() - 1; i > -1; i--){
        temp = digits[i] + last;
        last = temp / 10;
        digits[i] = temp % 10;
    }

    if(last) digits.insert(digits.begin(), last);

    return digits;
}