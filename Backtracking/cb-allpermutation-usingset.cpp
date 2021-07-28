// { Driver Code Starts
#include<bits/stdc++.h>
#include <set>
using namespace std;

void permute(set<string> &allpermutaion,string s ,int i){
	if(i==s.length()){
		allpermutaion.insert(s);
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
		set <string>find_permutation(string S)
		{
		    set<string>allpermutaion;
		    permute(allpermutaion,S,0);
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
	    set<string> ans = ob.find_permutation(S);
	    for(auto i: ans) 
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}