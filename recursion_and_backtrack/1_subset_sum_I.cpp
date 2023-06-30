class Solution
{
public:

    void sub(vector<int> v, vector<int>& ans, int i, int sum){
        if(i==v.size()){
            ans.push_back(sum);
            return;
        }
        
        sub(v,ans,i+1, sum+v[i]);
        sub(v,ans,i+1,sum);
        return ;
        
    }
    

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> v;
        sub(arr, v, 0, 0);
        return v;
    }
};
