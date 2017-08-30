/*******************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-28
Description : leetcode 290. Word Pattern 
*******************************************/

#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;
using std::istringstream;

bool wordPattern(string pattern, string str) {
    //the mapping from each char of the pattern to the integer 
    unordered_map<char, short> char2int;
    //the mapping from each word of the str to the integer
    unordered_map<string, short> str2int;
    istringstream is(str);
    int i = 0;

    for(string word; is >> word; i++){
        if(char2int[pattern[i]] != str2int[word]) return false;
        char2int[pattern[i]] = str2int[word] = i + 1;
    }
    return i == pattern.size();
}

int main(){
    string s = "aba", t = "dog sot dog dog";
    bool res = wordPattern(s, t);
    return 0;
}