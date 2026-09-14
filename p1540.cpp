#include <bits/stdc++.h>
using namespace std;
int ram[10001];
int N,M,ans=0;
int head=1,tail=1;
int main()
{
    cin>>M>>N;
    int word;
    bool search=false;
    for(int i=1;i<=N;i++)
    {
        cin>>word;
        for(int j=tail;j<head;j++)
        {
            if(ram[j]==word)
            {
                search=true;
                break;
            }
        }
        if(!search)
        {
            ans++;
            ram[head]=word;
            head++;
            if(head-tail>M)
            {
                tail++;
            }
        }
        search=false;
    }
    cout<<ans;
	return 0;
}
