#include<bits/stdc++.h>
#define inf 1000000000
using namespace std;
int vis[100000],n;
int dis[100000];
vector<int>vec[100000],cost[100000];
void bfs(int s)
{
    for(int i=0; i<n; i++)
    {
        vis[i]=0;
        dis[i]=inf;
    }
    vis[s]=1;
    dis[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];
            if(vis[v]==0)
            {
                vis[v]=1;
                dis[v]=dis[u]+cost[u][i];
                q.push(v);
            }
        }
    }
}
int main()
{

    int t;
    scanf("%d",&t);
    for(int tt=1; tt<=t; tt++)
    {
        scanf("%d",&n);
        for(int i=0; i<n-1; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            vec[u].push_back(v);
            vec[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        bfs(0);
        int mxdis=0,nexts;
        for(int i=0; i<n; i++)
        {
            if(dis[i]>mxdis)
            {
                nexts=i;
                mxdis=dis[i];
            }
        }
        bfs(nexts);
        mxdis=0;
        for(int i=0; i<n; i++)
        {
            if(dis[i]>mxdis)
            {
                mxdis=dis[i];
            }
        }
        printf("Case %d: %d\n",tt,mxdis);
        for(int i=0; i<n; i++)
        {
            vec[i].clear();
            cost[i].clear();
        }
    }
}