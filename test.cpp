#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int main(){
    int a[10] = {1};
    for(auto i : a){
        cout << i << endl;
    }
    return 0;
}