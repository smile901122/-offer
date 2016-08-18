class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int n1 = pushV.size();
        int n2 = popV.size();
        bool res = false;
        if(n1 == n2){
        	stack<int> st;
        	int i = 0;
        	int j = 0;
        	while(j < n2){
            	while(st.empty() || st.top() != popV[j]){
                	if(i == n2)		break;
                	st.push(pushV[i]);
                	++i;
            	}
            	if(st.top() != popV[j])		break;
            	else{
                	st.pop();
                	++j;
            	}
        	}
        if(st.empty() && j == n2)	res = true;;
        }
        return res;
    }
};
