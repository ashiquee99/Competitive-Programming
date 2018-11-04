#include <bits/stdc++.h>
using namespace std;
typedef                long long int ll;
#define                MX 1000006
#define                FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL)
#define                exit() return 0;

using namespace std;

int f[MX];//the failure array
void failure_function(string& pattern)
{
    f[0] = 0;
    int i = 1, j = 0, len_p = pattern.size();

    while (i<len_p)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            f[i] = j;
            i++;
        }
        else
        {
            if (j>0)//here j is non zero
            {
                j = f[j - 1];
            }
            else
            {
                f[i] = 0;
                i++;
            }
        }

    }
    return;
}

void KMP_match(string& txt, string& pattern)
{
    int i = 0, j = 0, ret = -1;
    int len_t = txt.size(), len_p = pattern.size();

    while (i < len_t)
    {
        if (txt[i] == pattern[j])
        {
            i++;
            j++;
            if (j == len_p)
            {
                ret = i - len_p;
                printf("A match found from index %d\n", ret);
                j = f[j - 1];
            }
        }
        else
        {
            if (j)
            {
                j = f[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    string S, m;
    cin>>S;
    cin>>m;
    failure_function(S);
    KMP_match(S, m);
    return 0;
}
