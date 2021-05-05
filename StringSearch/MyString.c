
#include "MyString.h"

int bruteSearch(char *txt, char *pat) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i;
    for (i=0; i<=N; i++){
        int j;
        for (j=0; j<M; j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if (j==M){
            return i;
        }
    }
    return N;
}

int bruteSearchAlt(char *txt, char *pat) {
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    for(i=0, j=0; i<N && j<M; i++){
        if (txt[i]==pat[j]){
            j++;
        } else {
            i-=j;
            j=0;
        }
    }
    if (j==M){
        return i-M;
    } else {
        return N;
    }
    return 0;
}




int** computeDfa(char *pat) {
    int M = strlen(pat), i;
    int R = 256;
    int** dfa = (int**) malloc(255*sizeof(int*));
    for(i=0; i<R; i++)
        dfa[i] = (int*) malloc(M*sizeof(int));
    int X, j, c;
    dfa[*pat][0] = 1;
    for (X = 0, j = 1; j < M; j++){
        // calculate dfa[][j]
        for(c = 0; c < R; c++){
            dfa[c][j] = dfa[c][X];
        }
        dfa[pat[j]][j] = j+1;
        X = dfa[pat[j]][X];
    }
    return dfa;
}




int kmpSearch(char *txt, char *pat, int **dfa) {
    int j, M = strlen(pat);
    int i, N = strlen(txt);

    for (i = 0, j = 0; i < N && j < M; i++){
        j = dfa[txt[i]][j];
    }
    if (j == M){
        return i - M;
    }
    else{
        return N;
    }
    return 0;
}




