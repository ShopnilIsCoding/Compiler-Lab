#include<bits/stdc++.h>
using namespace std;

string Q0(string a)
{
        if(a[0]=='_' || (a[0]>=65&&a[0]<=90)||(a[0]>=97 && a[0]<=122))
            return "Final";
        else
            return "Trap";
}
string Final(int l, string a)
{
    for (int i = 1; i < l; i++)
    {
        if (!((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 120) || a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7' || a[i] == '8' || a[i] == '9' || (a[i] == '_')))
            return "Trap";
    }
    return "Final";
}

int main()
{
    string a;
    cin>>a;
    int l= a.size();

     if(Q0(a)=="Trap")
     {
     cout<<Q0(a);
     return 0;
    }
    else
    {
        cout<<Final(l,a);
    }
}