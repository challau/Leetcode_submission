class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }

        int row = (int)matrix.size();
        int col = (int)matrix[0].size();

        int low = 0;
        int high = row * col - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int r = mid/col;
            int c = mid%col;

            int curr = matrix[r][c];

            if(curr == target){
                return true;
            }else if(curr < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }

        }
        return false;
    }
};