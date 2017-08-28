/*************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-28
Description： leetcode 242. Valid Anagram 
*************************************************************/

#include <string>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::sort;
using std::unordered_map;

/**
 * Method 1 : 
 * Use sort function to implement
 * time : O(nlogn); space : O(1)
 */
bool isAnagram1(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) return true;
    return false;
}

/**
 * Method 2 : 
 * Use map to store the count of each char
 * time : O(n); space : O(n)
 */
 bool isAnagram2(string s, string t){
    //the mapping from char to the count
    unordered_map<char, int> s_map;

    for(auto ch :  s){
        s_map[ch]++;
    }

    for(auto ch : t){
        if(s_map.find(ch) == s_map.end()) return false;
        s_map[ch]--;
    }

    
    for(auto itr : s_map){
        if(!itr.second) return false;
    }

    return true; 
 }

int main(){
    string s = "ada";
    string t = "aad";
    bool res = isAnagram2(s, t);
    return 0;
}