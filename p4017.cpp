#include <bits/stdc++.h>
using namespace std;

struct food{
    short int eaten[5001];
    int num;
    int rela;
};

food creature[5001];
const int mod=80112002;
unsigned short int n,line[5001],ans[5001],root;
int m;
long long sum;
int dp[5001];
unsigned short int head=0,tail=0;

int main()
{
    //初始化
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        creature[x].eaten[creature[x].num]=y;
        creature[x].num++;
        creature[y].rela++;
    }

    for(int i=1;i<=n;i++)
    {
        if(creature[i].rela==0)//找出生产者
        {
            line[tail]=i;
            tail++;
            dp[i]=1;//生产者自己食物链长度为1
        }
        if(creature[i].num==0)//找顶级捕食者
        {
            ans[root]=i;
            root++;
        }
    }
    //队列求拓扑序
    while(tail>head)
    {
        for(int i=0;i<creature[line[head]].num;i++)
        {
            creature[creature[line[head]].eaten[i]].rela--;//弹出节点就减少其子节点入度
            if(creature[creature[line[head]].eaten[i]].rela==0)
            {
                line[tail]=creature[line[head]].eaten[i];//将0入度节点加入队列
                tail++;
            }
        }
        head++;//弹出开头的数据
    }
    //对符合拓扑序的食物链dp
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<creature[line[i]].num;j++)
        {
            dp[creature[line[i]].eaten[j]]=dp[creature[line[i]].eaten[j]]+dp[line[i]];//警示后人不要dp反了
            dp[creature[line[i]].eaten[j]]=dp[creature[line[i]].eaten[j]]%mod;
        }
    }
    //对顶级捕食者下属的所有链加和
    for(int i=0;i<root;i++)
    {
        sum=sum+dp[ans[i]];
        sum=sum%mod;
    }
    cout<<sum;
    return 0;
}
