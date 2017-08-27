/**********************************************************************
Copyright : CNIC
Author : LiuYao
Date : 2017-8-27
Description : leetcode 205. Isomorphic Strings 
**********************************************************************/

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

/**
 * Method 1 : 
 * Use map to mapping from char to int position
 */
bool isIsomorphic1(string s, string t) {
    if(s.size() != t.size()) return false;
    //the mapping from char to int
    unordered_map<char, int> s_map;
    unordered_map<char, int> t_map;
    vector<int> s_int(s.size(), 0), t_int(s.size(), 0);
    for(int i = 0; i < s.size(); i++){
        if(s_map.find(s[i]) == s_map.end())
            s_map[s[i]] = i;
        s_int[i] = s_map[s[i]];

        if(t_map.find(t[i]) == t_map.end())
            t_map[t[i]] = i;
        t_int[i] = t_map[t[i]];
    }

    for(int i = 0; i < s.size(); i++){
        if(s_int[i] != t_int[i]) return false;
    }

    return true;
}

/**
 * Method 2 : 
 * Use a 256 length int array to mapping from char to int position
 */
bool isIsomorphic2(string s, string t){
    if(s.size() != t.size()) return false;
    int s_map[256] = {0}, t_map[256] = {0}, n = s.size();
    for(int i = 0; i < n; i++){
        if(s_map[s[i]] != t_map[t[i]]) return false;
        s_map[s[i]] = t_map[t[i]] = i + 1;
    }
    return true;
}

int main(){
    string s = "egg", t = "add";
    bool a = isIsomorphic2(s, t);
    return 0;
}