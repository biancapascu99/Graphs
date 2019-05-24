#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int const nr_max=9999;
//void citire(vector<pair<int,pair<int,int>>> &E,int &n,int &m,int &st)
//{
//    int i;
//    cin>>n>>m;
//    E.resize(m+1);
//    for(i=0;i<m;i++)
//    {
//        int a,b,p;
//        cin>>a>>b>>p;
//        E[i].second.first=a;
//        E[i].second.second=b;
//        E[i].first=p;
//    }
//    cin>>st;
//}
//
//void initializare(vector<int> &t,vector<int> &d, int n,int st)
//{
//    t.resize(n+1);
//    d.resize(n+1);
//    for(int i=1;i<=n;i++)
//    {
//        t[i]=0;
//        d[i]=nr_max;
//    }
//    d[st]=0;
//}

void B_ford(vector<pair<int,pair<int,int>>> E,vector<int> &t,vector<int> &d, int n, int m, int st)
{
    int j,i;
    t.resize(n+1);
    d.resize(n+1);
    for(int i=1; i<=n; i++)
    {
        t[i]=0;
        d[i]=nr_max;
    }
    d[st]=0;
    for( i=1; i<=n-1; i++)
    {
        for( j=0; j<m; j++)
            if(d[E[j].second.first]+E[j].first<d[E[j].second.second])
            {
                d[E[j].second.second]= d[E[j].second.first]+E[j].first;
                t[E[j].second.second]= E[j].second.first;
            }
    }
}

int main()
{
    int n,m,i,st;
    vector<int> t, d;
    vector<pair<int,pair<int,int>>> E;
//    int i;
    cin>>n>>m;
    E.resize(m+1);
    for(i=0; i<m; i++)
    {
        int a,b,p;
        cin>>a>>b>>p;
        E[i].second.first=a;
        E[i].second.second=b;
        E[i].first=p;
    }
    cin>>st;
    B_ford(E,t,d,n,m,st);
    for(i=1; i<=n; i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;
    for(i=1; i<=n; i++)
    {
        cout<<d[i]<<" ";
    }

}
