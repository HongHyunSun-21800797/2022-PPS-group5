class Solution {
public:
    int order[1001] = {-1, };
    
    void bubblesort(vector<int>& arr) {
        bool changed = false;
        
        for(int i = 0; i < arr.size(); i++) {
            changed = false;
            for(int j = 0; j < arr.size() - 1 -i; j++) {
                if(order[arr[j]] > order[arr[j+1]]) {
                    swap(arr[j], arr[j+1]);
                    changed = true;
                }
                else if(order[arr[j]] == order[arr[j+1]] && arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    changed = true;
                }
            }
            if(!changed) break;
        }
    }
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int cnt = 1;
        
        for(int i = 0; i < arr2.size(); i++) order[arr2[i]] = cnt++;
        cnt = 0;
        for(int i = 0; i < arr1.size(); i++) {
            if(order[arr1[i]] == 0) {
                order[arr1[i]] = 2000;
                cnt++;
            }
        }
        bubblesort(arr1);
        
        //sort(arr1.begin() + cnt, arr1.end());
        
        return arr1;
    }
};