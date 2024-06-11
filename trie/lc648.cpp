#include <string>
#include <vector>
#include <iostream>
#include <memory>

using std::vector, std::string, std::cout, std::endl;

struct Trie{
    bool isLast = false;
    std::shared_ptr<Trie> child[26] {};
};

string dfs(std::shared_ptr<Trie> root, string s, int idx){
    if(idx >= s.size() || !root)
        return s;
    auto curr = root->child[s[idx]-'a'];
    if(curr){
        return curr->isLast ? s.substr(0, idx + 1) : dfs(curr, s, idx+1);
    }
    return s;
}

string replaceWords(vector<string>& dictionary, string sentence){
    //construct a trie based on dictionary
    auto root = std::make_shared<Trie>();
    for(auto &w: dictionary){
        auto par = root;
        for(int i = 0; i < w.size(); ++i){
            auto& next = par->child[w[i]-'a'];
            if(next == nullptr){
                next =  std::make_shared<Trie>();
                // next = par->child[w[i]-'a'];
            }
            par = next;
        }
        par->isLast = true;
    }
    sentence += " ";
    string res = "";
    size_t l = 0, r = 0;
    while( l < sentence.size() && (r = sentence.find(' ', l)) != string::npos){
        string curr = sentence.substr(l, r-l);
        res += dfs(root, curr, 0) + " ";
        l = r + 1;
    }
    return res.substr(0, res.size()-1);
} 


int main(){
    string s {"gvwqhwahirn eihvpyjldxsujrnz jwuqmeoodqmfxlduhabs gsrddxj msrek w o eyahvgnr s os ifsdtpop wlikc rfdjeefpcltaymhu uenvhqjuijebm xykfhmlfj ghakqbrt kdrhcwlkl"};
    vector<string> dict {"wlejnow","hietgeql","wjmgto","obvndbm","xdralntr","btyxdlr","fmop","mkzpsh","smefzr","fzy","eym","aydehje","olhfkd","ipwnhgxn","dpb","ihjbl","rodpxvg"};
    cout<<replaceWords(dict, s);
}