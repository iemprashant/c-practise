// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void permute(vector<string> &allpermutaion,string s ,int i){
	if(i==s.length()){
		allpermutaion.push_back(s);
		return;
	}
	for(int j=i;j<s.length();j++){
		swap(s[i],s[j]);
		permute(allpermutaion,s,i+1);
		swap(s[j],s[i]);
	}
	return;
}

 
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string>allpermutaion;
		    permute(allpermutaion,S,0);
		    sort(allpermutaion.begin(),allpermutaion.end());
		    return allpermutaion;
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}