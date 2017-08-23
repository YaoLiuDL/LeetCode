#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using std::vector;
using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

string minWindow(string s, string t) {
    unordered_map<char, int> map;
    unordered_map<char, int> window;
    string result;

    for(char ch : t){
        map[ch]++;
    }

    int letterLength = 0;
    int minLength = INT_MAX;
    for(int high = 0, low = 0; high < s.size(); high++){
        char ch = s[high];
        window[ch]++;
        if((map.find(ch) != map.end()) && (window[ch] <= map[ch])){
            letterLength++;
        }
        if(letterLength >= t.size()){
            while((map.find(s[low]) == map.end()) || (window[s[low]] > map[s[low]])){
                window[s[low]]--;
                low++;
            }
            if(high - low + 1 < minLength){
                minLength = high - low + 1;
                result = s.substr(low, minLength);
            }
        }
    }

    return letterLength < t.size() ? "" : result;
}

int main(){
    string s = "aa";
    string t = "b";
    cout << minWindow(s, t) << endl;
    return 0;
}