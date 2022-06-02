#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string cur_pal = "";
        
        if (s.length() == 1) {
            return s;
        }
        else if (s.length() == 2) {
            if (s[0] == s[1]) {
                cur_pal += s[0];
                cur_pal += s[1];
            }
            else {
                cur_pal += s[1];
            }
            return cur_pal;
        }
        
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            list<int> pos;
            for (int j = i+1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    pos.push_back(j);
                }
            }
            list<int>::iterator it;
            for (it = pos.begin(); it != pos.end(); it++) {
                int dont = 0;
                int amount = 0;
                list<int> pos2;
                
                //
                
                int count_woof = *it;
                for (int i2 = i+1; i2 < *it; i2++) {
                    count_woof--;
                    int dothus = -1;
                    
                    for (int j2 = i2+1; j2 < *it; j2++) { 
                        if (s[i2] == s[j2]) {
                            dothus = j2;
                            pos2.push_back(dothus);
                        }
                        
                    }
                    
                    
                    if (dothus == -1) {
                        
                        bool dothus2 = false;
                        list<int>::iterator it2;
                        for (it2 = pos2.begin(); it2 != pos2.end(); it2++) {
                            if (i2 == *it2) {
                                dothus2 = true;
                                break;
                            }
                            
                        }
                        
                        if (dothus2 == false) {
                            dont++;
                        }
                       
                    }
                    if (s[i2]!=s[count_woof]) {
                        dont++;
                    }
                    amount = *it-i;
                    
                }
                if (dont <= 1) {
                    if (max < amount) {

                        max = amount;
                        cur_pal = "";
                        for (int iter = i; iter < *it+1; iter++) {
                            cur_pal += s[iter];
                        }
                        
                    }
                }
                
                if (s[i] == s[i+1] and max == 0) {
                    cur_pal += s[i];
                    cur_pal += s[i+1];
                    if (s[i] == s[i+2]) {
                        cur_pal += s[i+2];
                    }
                    max = 1;
                }
                
            }
        } 
        if (max == 0) {
            cur_pal += s[s.length()-1];
        }
        return cur_pal;
    }
};

int main() {
	Solution bruh;
  string breh;
  cin >> breh;
  cout << bruh.longestPalindrome(breh) << " is the longest palindrome!" << endl;
	return 0;
}
