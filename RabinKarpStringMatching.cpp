#include<iostream>
#include<cstring>
using namespace std;
#define d 256

void search(char pat[], char sent[], int q)
{
    int M = strlen(pat);
    int N = strlen(sent);
    int p=0, t=0, h=1, j;

    for (int i = 0; i < M-1; i++)
        h = (h*d)%q;
    for (int i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + sent[i])%q;
    }
    for (int i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (sent[i+j] != pat[j])
                    break;
            }
            if (j == M)
                cout<<"Pattern found at index: "<<i<<endl;
        }
        if ( i < N-M )
        {
            t = (d*(t - sent[i]*h) + sent[i+M])%q;
            if (t < 0)
            t = (t + q);
        }
    }
}
int main()
{
    char sent[] = "PROGRAMMING IN C++";
    char pat[] = "PROGRAM";
    int q = 101;
    cout<<"The sentence: "<< sent << "\nThe pattern: "<< pat << endl;
    search(pat, sent, q);
    return 0;
}
