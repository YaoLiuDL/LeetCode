#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int trap(vector<int>& height){
    int i = 0, j = height.size() - 1;
    int capacity = 0;
    int h = 0, l_h;
    while(i < j){
        l_h = h;
        h = height[i] < height[j] ? height[i] : height[j];
        capacity += (h - l_h) * (j - i + 1);
        
        while(i < height.size() && height[i] <= h) i++;
        while(j > -1 && height[j] <= h) j--;
    }
    
    if(capacity == 0) return 0;
    int s = 0;
    for(int i = 0; i < height.size(); i++){
        s += height[i] > h ? h : height[i];
    }

    return capacity - s;

}

int main(){
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(test) << endl;
    return 0;
}