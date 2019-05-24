#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

void citire(map<int,set<int>> &vecini,int &n,int &m)
{
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        vecini[a].insert(b);
        //vecini[b].insert(a);
    }
}
void topologic_sort_util(int nod,map<int,set<int>> vecini,vector<int> &stiva,bool viz[])
{
    viz[nod]=true;
    set<int>::iterator i;
    //pt fiecare vecini al lui nod
    for( i=vecini[nod].begin();i!=vecini[nod].end();i++)
    {//daca nu a fost vizitat il vizitam
        if(viz[*i]==false)
        {
            topologic_sort_util(*i,vecini,stiva,viz);
        }
    }
    //cand se ajunge in cap se pune in stiva
    stiva.push_back(nod);
}
void topologic_sort(map<int,set<int>> vecini,int n)
{
    vector<int> stiva;
    bool viz[30];

    for(int i=1;i<=n;i++)
        viz[i]=false;

    //plecam cu DFS din fiecare nod al grafului

    for(int i=1;i<=n;i++)
    {
        if(viz[i]==false)
            topologic_sort_util(i,vecini,stiva,viz);
    }
    while(!(stiva.empty()))
    {
        cout<<stiva.back()<<" ";
        stiva.pop_back();
    }
}
int main()
{
     vector<int> stiva;
     bool viz;
     map<int,set<int>> vecini;
     int n,m;
     citire(vecini,n,m);
     topologic_sort(vecini,n);
}
