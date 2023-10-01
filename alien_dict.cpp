#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    
    string topological_sort(int V,vector<int>adj[])
    {
       vector<int>incoming(V,0);
       
       for(int i=0;i<V;i++)
       {
           for(auto k:adj[i])
           {
               incoming[k]++;
           }
       }
       queue<int>que;
       
       for(int i=0;i<V;i++)
       {
         if(incoming[i]==0)
         {
             que.push(i);
         }
       }
       vector<int>topo;
       while(!que.empty())
       {
           int node=que.front();que.pop();
           topo.push_back(node);
           
           for(auto i:adj[node])
           {
               incoming[i]--;
               if(incoming[i]==0)que.push(i);
           }
       }
           string str="";
      for(int i=0;i<V;i++)
      {
          str+=char(topo[i]+'a');
      }
      return str;
    }
    
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++)
        {
            string str1=dict[i];
            string str2=dict[i+1];
            
            int len=min(str1.size(),str2.size());
            
            for(int j=0;j<len;j++)
            {
               if(str1[j]!=str2[j])
               {
                   adj[str1[j]-'a'].push_back(str2[j]-'a');
                   break;
               }
            }
        }
   
   string str=topological_sort(K,adj);
   return str;
    }
};
string order;
bool f(string a,string b)
{
	int p1=0;
	int p2=0;
	for(int i=0;i<min(a.size(),b.size()) and p1==p2;i++)
	{
		p1=order.find(a[i]);
		p2=order.find(a[i]);
	}
	if(p1==p2 and a.size() !=b.size()) return a.size()<b.size();

	return p1<p2;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,K;
		cin>>N>>K;
		string dict[N];
		for(int i=0;i<ans.size();i++)order+=ans[i];

		string temp[N];
        std::copy(dict,dict+N,K);
        sort(temp,temp+N,f);

        bool f=true;
        for(int i=0;i<N;i++)
        {
        	if(dict[i]!=temp[i])f=false;
        }
        if(f)cout<<1;
        else cout<<0;
        cout<<endl;
	}
	return 0;
}
