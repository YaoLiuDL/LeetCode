/*****************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-27
Description : leetcode 187. Repeated DNA Sequences 
*****************************************************/
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using std::string;
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

/**
 * Method 1 : 
 * Use the mapping from string to int to implement
 */
vector<string> findRepeatedDnaSequences1(string s) {
    vector<string> res;
    //the mapping from string to the count of occurring
    unordered_map<string, int> map;
    for(int i = 0; i <= (int)s.length() - 10; i++){
        string subStr = s.substr(i, 10);
        if(++map[subStr] == 2){
            res.push_back(subStr);
        }
    }

    return res;
}

/**
 * Method 2 : 
 * Use the mapping from int to int to implement .
 * Use three bits to express one letter, so ten letters need 30 bits space.
 */
vector<string> findRepeatedDnaSequences2(string s) {
    vector<string> res;
    if(s.size() < 10) return res;
    //the mapping from 30 bits to int 
    unordered_map<int, int> map;
    int i = 0, t = 0;
    while(i < 9){
        t = t << 3 | s[i++] & 7;
        cout << t << endl;
    }
    while(i < s.size())
        if(map[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++  == 1)
            res.push_back(s.substr(i - 9, 10));
    
    return res;
}

int main(){
    string s = "AAAACGTTCCCCCCCCCCC";
    vector<string> res = findRepeatedDnaSequences2(s);
    return 0;
}
