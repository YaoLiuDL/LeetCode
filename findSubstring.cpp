#include <vector>
#include <map>
#include <string>

using std::map;
using std::vector;
using std::string;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res(2, 0);
    map<string, int> wordsToCount;
    for(int i = 0; i < words.size(); i++){
        wordsToCount[words[i]] = 0;
    }

    int wordLength = words[0].length();

    for(int i = 0; i < s.length(); i += wordLength){
        string current = s.substr(i, wordLength);
        wordsToCount[current] ++;
        if(wordsToCount[current] > 1) {
            res[1] = i;
            return res;
        }
    }

    res[1] = s.length() - 1;
    return res;
}

int main(){
    string test = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> res = findSubstring(test, words);
    return 0;
}