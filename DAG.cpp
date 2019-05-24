#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<list>
using namespace std;
const int nr_max=999;
void citire(vector<pair<int,pair<int,int>>> &E,map<int,set<int>> &vecini,int &n,int &m,int &st)
{

    int a,b,c;
    cin>>n>>m;
    E.resize(m+1);
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        vecini[a].insert(b);
        E[i].first=c;
        E[i].second.first=a;
        E[i].second.second=b;
    }
    cin>>st;
}
void initializare(int n,int st,vector<int> &t, vector<int> &d)
{
    t.resize(n+1);
    d.resize(n+1);
    for(int i=1; i<=n; i++)
    {
        t[i]=0;
        d[i]=nr_max;

    }
    d[st]=0;
}

void topologic_sort_util(int nod,map<int,set<int>> vecini,vector<int> &stiva,bool viz[])
{
    viz[nod]=true;
    set<int>::iterator i;
    //pt fiecare vecini al lui nod
    for( i=vecini[nod].begin(); i!=vecini[nod].end(); i++)
    {
        //daca nu a fost vizitat il vizitam
        if(viz[*i]==false)
        {
            topologic_sort_util(*i,vecini,stiva,viz);
        }
    }
    //cand se ajunge in cap se pune in stiva
    stiva.push_back(nod);
}
vector<int> topologic_sort(map<int,set<int>> vecini,int n)
{
    vector<int> stiva;
    bool viz[30];

    for(int i=1; i<=n; i++)
        viz[i]=false;

    //plecam cu DFS din fiecare nod al grafului

    for(int i=1; i<=n; i++)
    {
        if(viz[i]==false)
            topologic_sort_util(i,vecini,stiva,viz);
    }
    vector<int> stiva2=stiva;
//    cout<<"asta e sortarea"<<endl;
//    while(!(stiva.empty()))
//    {
//        cout<<stiva.back()<<" ";
//        stiva.pop_back();
//    }
    cout<<endl;
    return stiva2;
}
void DAG(vector<pair<int,pair<int,int>>> E,map<int,set<int>> &vecini,int n,int m,int st,vector<int> &t,vector<int> &d)
{
    initializare(n,st,t,d);
    vector<int> SortTop=topologic_sort(vecini,n);
    list<int> SortTop2;
     SortTop2.resize(n);
    cout<<"sortare" <<endl;
    for(auto i=SortTop.begin(); i!=SortTop.end(); i++)
    {
        SortTop2.push_front(*i);
    }cout<<endl;
    for(auto i=SortTop2.begin(); i!=SortTop2.end(); i++)
    {
        for(int j=0; j<m; j++)
        {
            if(E[j].second.first==*i)
            {
                if(d[*i]+E[j].first<d[E[j].second.second])
                {
                    d[E[j].second.second]=d[*i]+E[j].first;
                    t[E[j].second.second]=*i;
                }
            }

        }
    }
    for(int k=1; k<=n; k++)
    {
        cout<<d[k]<<"  ";
        //cout<<endl;
    }
    cout<<endl;
    for(int k=1; k<=n; k++)
    {
        cout<<t[k]<<"   ";
        //cout<<endl;
    }
}
int main()
{
    vector<pair<int,pair<int,int>>> E;
    int n, st, m;
    map<int,set<int>> vecini;
    vector<int> t,d;
    citire(E,vecini,n,m,st);
    DAG(E,vecini,n,m,st,t,d);
}
