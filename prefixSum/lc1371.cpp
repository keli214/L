#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
    "eleetminicoworoep" 
    find the longest substring where 'a', 'e', 'i', 'o', 'u' counts are even number 
    "leetminicowor"
    storing the pattern of odd/even of each of the number
    p = '11011' -> 'a': odd, 'e': odd, 'i': even, 'o': odd, 'u': odd
    store the first occurance of the pattern
    update the pattern 
    take the difference of current pattern and loc of last occurance of pattern 
        res = max(res, i-loc[p]) 
    
*/
int findTheLongestSubstring(string s) {
    int p = 0, res = 0, n = s.size();
    unordered_map<int, int> m {{0,-1}}; //edge case where p : '00000' the idx should be -1 
    unordered_map<char, int> vowel {{'a',0}, {'e',1},{'i',2}, {'o',3}, {'u',4}};
    for(int i = 0; i < n; i++){
        if(vowel.find(s[i]) != vowel.end()){
            p ^= 1 << vowel[s[i]];
        }
        if(m.find(p) != m.end()){
            res = max(res, i-m[p]);
        }
        else{
            m[p] = i;
        }
    }
    return res;
}

int main(){
    string s = "tyrwpvlifrgjghlcicyocusukhmjbkfkzsjhkdrtsztchhazhmcircxcauajyzlppedqyzkcqvffyeekjdwqtjegerxbyktzvrxwgfjnrfbwvhiycvoznriroroamkfipazunsabwlseseeiimsmftchpafqkquovuxhhkpvphwnkrtxuiuhbcyqulfqyzgjjwjrlfwwxotcdtqsmfeingsxyzbpvmwulmqfrxbqcziudixceytvvwcohmznmfkoetpgdntrndvjihmxragqosaauthigfjergijsyivozzfrlpndygsmgjzdzadsxarjvyxuecqlszjnqvlyqkadowoljrmkzxvspdummgraiutxxxqgotqnxwjwfotvqglqavmsnmktsxwxcpxhuujuanxueuymzifycytalizwnvrjeoipfoqbiqdxsnclcvoafqwfwcmuwitjgqghkiccwqvloqrxbfjuxwriltxhmrmfpzitkwhitwhvatmknyhzigcuxfsosxetioqfeyewoljymhdwgwvjcdhmkpdfbbztaygvbpwqxtokvidtwfdhmhpomyfhhjorsmgowikpsdgcbazapkmsjgmfyuezaamevrbsmiecoujabrbqebiydncgapuexivgvomkuiiuuhhbszsflntwruqblrnrgwrnvcwixtxycifdebgnbbucqpqldkberbovemywoaxqicizkcjbmbxikxeizmzdvjdnhqrgkkqzmspdeuoqrxswqrajxfglmqkdnlescbjzurknjklikxxqqaqdekxkzkscoipolxmcszbebqpsizhwsxklzulmjotkrqfaeivhsedfynxtbzdrviwdgicusqucczgufqnaslpwzjhgtphnovlrgz";
    cout<<findTheLongestSubstring(s);
}