#include<iostream>
#include<utility>
#include<vector>
#include<set>
#include<list>
#include<algorithm>
using namespace std;
void citire(vector<pair<int,pair<int,int>>> &E,int &n,int &m,int &st)
{
    cin>>n>>m;
    E.resize(m+1);
    int i,a,b,p;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>p;
        E[i].first=p;
        E[i].second.first=a;
        E[i].second.second=b;
    }
    cin>>st;
}

void Initializare(vector<int> &t,vector<int> &d,int n,int st)
{
    t.resize(n+1);
    d.resize(n+1);
    for(int i=1; i<=n; i++)
    {
        t[i]=0;
        d[i]=50000;
    }
    d[st]=0;
}
int min(list<int> Q,vector<int> d)
{
    list<int>::iterator i_list;
    int min=54637,u;
    for(i_list=Q.begin();i_list!=Q.end();i_list++)
    {
        if(d[*i_list]<min)
        {
            min=d[*i_list];
            u=*i_list;
        }
    }
    return u;
}
void Dijkstra(vector<pair<int,pair<int,int>>> E,int n, int m,int st, vector<int> t, vector<int > d )
{
    list<int> Q;
    for(int i=1; i<=n; i++)
    {
        Q.push_back(i);
    }
    Initializare(t,d,n,st);
    while(!(Q.empty()))
    {
       int u=min(Q,d);
        Q.remove(u);
       for(int i=0;i<m;i++)
       {
           if(E[i].second.first==u)
           {
               if(d[u]+E[i].first<d[E[i].second.second])
                {
                    d[E[i].second.second]=d[u]+E[i].first;
                    t[E[i].second.second]=u;
                }
           }
       }
    }
    for(int i=1;i<=n;i++)
        cout<<d[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<t[i]<<" ";

}
int main()
{
    vector<pair<int,pair<int,int>>> E;
    vector<int> t;
    vector<int> d;
    int n ,m ,st;
    citire(E,n,m,st);
    Dijkstra(E,n,m,st,t,d);
    return 0;
}
