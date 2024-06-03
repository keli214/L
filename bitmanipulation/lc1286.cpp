#include <string>
#include <iostream>
#include <set>
using namespace std;

class CombinationIterator {
    string chars;
    int n;
    set<string> combs;
    set<string>::iterator curr;

    void generate(string& s, int n) {
        int L = s.size();
        for(int mask = 0; mask < 1 << L; mask++) {         // iterate mask from [0, 2^L)
            int num = mask, i = 0;
            string comb = "";
            while(num){                 
                if(num & 1)                         
                    comb += s[i];   
                i++;
                num >>= 1;
            }      
            if(comb.size() == n) combs.insert(move(comb));                // insert the constructed string into set
        }
        curr = begin(combs);
    }

public:
    CombinationIterator(string characters, int combinationLength): chars(characters), n(combinationLength){
        generate(characters, combinationLength);
    }
    
    string next() {
        return *curr++;
    }
    
    bool hasNext() {
        return curr != combs.end();
    }
};