class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back(make_pair(heights[i], names[i]));
        }

        sort(people.rbegin(), people.rend());

        vector<string> sortedNames;
        for (auto person : people) {
            sortedNames.push_back(person.second);
        }

        return sortedNames;
    }
};