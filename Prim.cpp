#include "pch.h"
#include <iostream>
#include<set>
#include<iterator>
using namespace std;
const int nr_max = 1000;
struct muchie
{
    int a,b,cost;
};
int main()
{
    muchie legatura, vect_leg[100];
    int n, m, x, i, d[100], tata[100];
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> vect_leg[i].cost;
        cin >> vect_leg[i].a;
        cin >> vect_leg[i].b;
    }
    int s=1;
    set<int> Q;
    for (i = 1; i <= n; i++)
    {
        d[i] = nr_max;
        tata[i] = 0;
        Q.insert(i);
    }
    d[s] = 0;
    while (!(Q.empty()))
    {
        set<int>::iterator i_set;
        int dist_min = d[*Q.begin()], nod_min = *Q.begin();
        for (i_set = Q.begin(); i_set != Q.end(); i_set++)
        {
            if (d[*i_set] < dist_min)
            {
                dist_min = d[*i_set];
                nod_min = *i_set;
            }
        }
        Q.erase(nod_min);
        int u = nod_min;
        for (i = 1; i <= m; i++)
        {
            if (vect_leg[i].a ==u || vect_leg[i].b == u)
            {
                if (Q.count(vect_leg[i].b) == 1 && vect_leg[i].cost < d[vect_leg[i].b])
                {
                    d[vect_leg[i].b] = vect_leg[i].cost;
                    tata[vect_leg[i].b] = u;

                }
                else

                    if (Q.count(vect_leg[i].a) == 1 && vect_leg[i].cost < d[vect_leg[i].a])
                    {
                        d[vect_leg[i].a] = vect_leg[i].cost;
                        tata[vect_leg[i].a] = u;
                    }
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (i != s)
        {
            cout << i << " " << tata[i] << endl;
        }

    }



}
