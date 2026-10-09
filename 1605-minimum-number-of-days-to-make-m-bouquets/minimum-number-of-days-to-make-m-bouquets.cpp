class Solution {
public:
   int possibleNum(vector<int> bloomDay,int days,int m, int k){
           int cnt = 0;
           int bouquets = 0;

           for(int i = 0; i < bloomDay.size(); i++){
               if(bloomDay[i] <= days){
                   cnt++;
                   if(cnt == k){
                      bouquets++;
                      cnt = 0;
                   }
               }else{
                  cnt = 0;
               }
           }
           return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
             int n = (int)bloomDay.size();

            if((long long) m * k > n){
                return -1;
             }          

            int low = *min_element(bloomDay.begin(), bloomDay.end());
            int high = *max_element(bloomDay.begin(), bloomDay.end());
            int ans = -1;

            while(low <= high){
                 int mid = low + (high - low)/2;

                 if((possibleNum(bloomDay,mid,m,k))){
                       ans = mid;
                       high = mid - 1;
                 }else{
                        low = mid + 1;
                 }

              }
           return ans;
    }
};