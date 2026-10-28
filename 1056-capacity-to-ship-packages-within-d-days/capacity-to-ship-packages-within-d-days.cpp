class Solution {
public:
    int finddays(vector<int> &weights, int cap){
        int days = 0, load = 0;

        for(int i = 0; i < weights.size(); i++){
            if(weights[i] + load > cap){
                days += 1;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return days + 1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);

        while(low <= high){
            int mid = (low + high)/2;

            int numofdays = finddays(weights,mid);
            if(numofdays <= days){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};