#include <bits/stdc++.h>
using namespace std;

int N,com,ans;
int stackM[1001],head=0;

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>com;
        if(com==1)
        {
            if(head==0)
            {
                continue;
            }
            else
            {
                head--;
                if(ans==stackM[head])
                {
                    ans=0;
                    for(int j=0;j<head;j++)
                    {
                        if(stackM[j]>ans)
                        {
                            ans=stackM[j];
                        }
                    }
                }
            }
        }
        if(com==2)
        {
            cout<<ans<<'\n';
        }
        if(com==0)
        {
            cin>>com;
            if(com>ans)
            {
                ans=com;
            }
            stackM[head]=com;
            head++;
        }
    }
    return 0;
}