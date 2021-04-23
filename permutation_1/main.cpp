#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX_N;
// 順列
void permutation1(int pos, int n, vector<bool> &used, vector<int> &perm) {
    if (pos == n) {
        /*
        permに対する操作
        */
        //cout << "pos:" << pos << endl;
        /*
        for (int i=0; i<MAX_N; i++) {
            cout << perm[i] << " ";
        }
        cout << endl;
        */
        return ;
    }
    
    // permのpos番目を0~n-1のどれにするかのループ
    for (int i=0; i<n; i++) {
        if (!used[i]) {
            perm[pos] = i;
            // iを使ったのでフラグをtureにする
            used[i] = true;
            permutation1(pos + 1, n, used, perm);
            // 戻ってきたらフラグを戻す
            used[i] = false;
        }
    }
    return ;
}


int main(void){
    cin >> MAX_N;
    
    vector<bool> used(MAX_N);
    vector<int> perm(MAX_N);
    
    // {0, 1, 2, 3, ..., n -1}の並べ替えn!通り
    // next_permutationを使わない
    permutation1(0, MAX_N, used, perm);
    
    // next_permutationを使う---------------------------------
    vector<int> perm2 {1, 2, 3};  // 昇順ソートする
    
    do {
        for (int i=0; i<MAX_N; i++) {
            cout << perm2[i] << " ";
        }
        cout << endl;
    } while (next_permutation(perm2.begin(), perm2.end()));
    //　順列が表示される
    //--------------------------------------------------------
}
/*
pos:3
0 1 2 
pos:3
0 2 1 
pos:3
1 0 2 
pos:3
1 2 0 
pos:3
2 0 1 
pos:3
2 1 0 
*/
