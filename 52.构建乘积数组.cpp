class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	const int n = A.size();
        vector<int> B(n, 1);
        for(int i = 1; i < n; ++i){
            B[i] = B[i - 1] * A[i - 1];
        }
        int temp = 1;
        for(int i = n - 2; i >= 0; --i){
            temp *= A[i + 1];
            B[i] *= temp;
        }
        return B;
    }
};
