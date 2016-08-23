class Solution {
    /*二分查找 找到第一个K 和 最后一个K 二者位置相减*/
public:
    int GetNumberOfK(vector<int> data ,int k) {
        /*
        vector<int>::iterator it1 = upper_bound(data.begin(), data.end(), k);
        vector<int>::iterator it2 = lower_bound(data.begin(), data.end(), k);
        int n = it1 - it2;
        return n;
        */
        if(data.empty())
            return 0;
        int number = 0;
        int first = GetFirstIndex(data,k,0,data.size()-1);
        int last = GetLastIndex(data,k,0,data.size()-1);
        if(first > -1 && last > -1)
            number = last - first + 1;
        return number;
         
    }
private:
    int GetFirstIndex(vector<int> &data, int k, int start, int end){
        if(start > end)
            return -1;
        int mid = start + (end - start) / 2;
        if(data[mid] == k){
            if((mid > start && data[mid - 1] != k) || mid == start)
                return mid;
            else
                end = mid - 1;
        }
        else{
            if(mid > k)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return GetFirstIndex(data, k, start, end);
    }
    int GetLastIndex(vector<int> &data, int k, int start, int end){
        if(start > end)
            return -1;
        int mid = start + (end - start) / 2;
        if(data[mid] == k){
            if((mid < end && data[mid + 1] != k) || mid == end)
                return mid;
            else
                start = mid + 1;
        }
        else{
            if(mid > k)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return GetLastIndex(data, k, start, end);
    }
};
