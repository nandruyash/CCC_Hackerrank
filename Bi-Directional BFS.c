#include<stdio.h>

int adj[1005][1005];
int v[1005], q[1005], d[1005], f = 0, r = -1;

void bfs(int s,int n)
{
    v[s] = 1;
    q[++r] = s;
    d[s] = 1;
    while(f <= r)
    {
        int x = q[f++], i;
        for(i=1;i<=n;i++)
        {
            if(adj[x][i] == 1 && v[i] == 0)
            {
                v[i] = 1;
                q[++r] = i;
                d[i] = d[x] + 1;
            }
        }
    }
}

int main()
{
    int n, i;
    scanf("%d",&n);
 
    for(i=0;i<n-1;i++)
    {
        int s,d;
        scanf("%d %d",&s,&d);
        adj[s][d] = 1;
        adj[d][s] = 1;
    }
    
    int level;
    scanf("%d",&level);
    
    bfs(1,n);
    
    int count = 0;
    for(i=1;i<=n;i++)
        if(d[i] == level)
            count++;
    
    printf("%d",count);
    return 0;
}