// C++ program for implementation of KMP 
// pattern searching algorithm

#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* LPS);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int LPS[M];
    computeLPSArray(pat, M, LPS);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = LPS[j - 1];
        }

        else if (i < N && pat[j] != txt[i]) {

            if (j != 0)
                j = LPS[j - 1];
            else
                i = i + 1;
        }
    }
}

void computeLPSArray(char* pat, int M, int* LPS)
{
    int len = 0;

    LPS[0] = 0; 

    
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            LPS[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            
            if (len != 0) 
                len = LPS[len - 1];
            else // if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}

int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}