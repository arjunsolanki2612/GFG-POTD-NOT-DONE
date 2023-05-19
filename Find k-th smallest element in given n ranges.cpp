//{ Driver Code Starts
/* Driver program to test above function */

/*https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-given-n-ranges/1*/
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        
        /*
        Three steps of doing this question
        1: sort the range based on the first element
        2: merge overlapping interval
        3: search the queries in the range
        
        // INTUITION
        
        for finding the query in a range if the range difference is greater than the query then the query will
        definetly lie in the range 
        eg: query = 3, range = {1, 5}
        
        diff = 5-1+1 (including 5 and 1 therefore adding extra 1) = 5, so 5>3 so 3 will lie in the range
        If the diff is less then the possiblity is that the query will lie in the next range otherwise -1
        
        */
        
        //part 1 - sort
        sort(begin(range),end(range));
        
        //part 2 - merge intevals
        
        int idx=0;
        for(int i=1;i<range.size();i++){
            if(range[idx][1]>=range[i][0]){
                range[idx][1] = max(range[i][1],range[idx][1]);
            }
            else{
                idx++;
                range[idx]=range[i];
            }
        }
        
        //part 3 - searching
        vector<int>ans(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            int x = queries[i];
            for(int j=0;j<=idx;j++){
                if(range[j][1]-range[j][0]+1>=x){
                    ans[i]=range[j][0]+x-1;
                    break;
                }
                else{
                x=x-range[j][1]-range[j][0]+1;
                }
            }
            
        }
        return ans;
        
    } 
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
