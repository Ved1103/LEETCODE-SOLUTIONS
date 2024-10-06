class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        int n = sentence1.size(), m = sentence2.size();
        if (n < m) {
            swap(sentence1, sentence2);
        }
        vector<string> s1, s2;
        stringstream ss1(sentence1);
        string token;
        while (ss1 >> token) {
            s1.push_back(token);
        }

        stringstream ss2(sentence2);
        string temp;
        while (ss2 >> temp) {
            s2.push_back(temp);
        }
        
        int sz1 = s1.size(), sz2 = s2.size();
        int i = 0, j = sz1 - 1;
        int k = 0, l = sz2 - 1;
        
        while (i <= j && k <= l && s1[i] == s2[k]) {
            i++;
            k++;
        }
        
        while (i <= j && k <= l && s1[j] == s2[l]) {
            j--;
            l--;
        }
        
        return k > l;
    }
};
