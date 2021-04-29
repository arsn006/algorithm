#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<char> S(N);
    
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }
    
    int a = 0, b = N - 1;
    while(a<=b){
        bool left = false;
        for(int i = 0; a + i <= b; i++){
            //printf("a:%d b:%d i:%d\n", a, b, i);
            if(S[a+i] < S[b-1]){
                left = true;
                break;
            }
            else if(S[a+i] > S[b-1]){
                left = false;
                break;
            }
        }
        // printf("%s",S[a++]) では処理が遅くてエラーになる
        // putchar or cout を利用する
        if(left) putchar(S[a++]);
        else putchar(S[b--]);
    }
    
    cout << endl;
    
}
/*
先頭と末尾の文字で比較し、小さい方の文字を出力する
辞書順最小問題
入力
6
ACDBCB
*/
