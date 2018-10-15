#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::pair;




#include <iostream>
#include <cassert>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::pair;
using std::string;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> umap;

        auto word_len = words[0].length();
        auto words_size = words.size();

        if(0 == word_len || 0 == words_size || s.length() < words_size * word_len) {
            return result;
        }

        for(auto i = words.begin(); i != words.end(); i++) {
            auto iter = umap.find(*i);
            if(umap.end() == iter) {
                umap.insert(pair<string, int>{*i, 1});
            } else {
                ++iter->second;
            }            
        }

        size_t w_left = 0;
        size_t w_right = words_size * word_len;

        for(;w_right <= s.length(); w_left++, w_right++) {        
            unordered_map<string, int> tmp(umap);
            int hit = 1;
            for(size_t i = w_left; i < w_right; i += word_len) {
                string key = s.substr(i, word_len);                
                auto iter = tmp.find(key);

                if(tmp.end() == iter) {
                    hit = 0;
                    break;
                } else {
                    if(0 >= iter->second) {
                        hit = 0;
                        break;
                    } else {
                        iter->second--;
                    }
                }
            }

            if(1 == hit) {
                result.push_back(w_left);
            }
        }

        
        return result;       
        
    }
};




int main()
{
    string test = "barfoothefoobarman";
    
#if 1
    string words_array[2] = {"foo","bar"};
    vector<string> words;

    for(int i = 0; i < 2; i++) {
        words.push_back(words_array[i]);
    }
#else 
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
#endif
    std::vector<int> res;

    class Solution* ptr = new Solution();
    res =  ptr->findSubstring(test,words);

    for(auto i = res.begin(); i != res.end(); i++) {
        std::cout<<*i<<" ";
    }

    std::cout<<std::endl;

    return 0;

}




