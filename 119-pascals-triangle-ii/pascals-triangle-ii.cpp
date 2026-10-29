class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        long long curr = 1;
        vec.push_back(curr);

        for(int i = 1; i <= rowIndex; i++) {
            curr = curr * (rowIndex - i + 1)/i;
            vec.push_back(curr);
        }
        return vec;
    }
};