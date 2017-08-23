#include <vector>
#include <string>

using std::string;
using std::vector;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<unordered_map<char, bool>> mappings;
    vector<vector<string>> res;
    for(int i = 0; i < strs.size(); i++){
        string str = strs[i];
        bool exist = false;
        for(int j = 0; j < mappings.size(); j++){
            unordered_map<char, bool> mapping = mappings[j];
            if(mapping.size() != str.size()) continue;
            bool flag = true;
            for(int m = 0; m < str.size(); m++){
                if(mapping.find(str[m]) == mapping.end() && ) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                res[j].push_back(str);
                exist = true;
            }
        }
        if(!exist) {
            vector<string> tmp = {str};
            res.push_back(tmp);
            unordered_map<char, bool> tmp_map;
            for(int m = 0; m < str.size(); m++){
                tmp_map[str[m]] = false;
            }
            mappings.push_back(tmp_map);
        }
    }
    return res;
}