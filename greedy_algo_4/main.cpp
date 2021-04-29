#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N, R;
    cin >> N >> R;
    vector<int> X(N);
    
    for(int i = 0; i < N; i++){
        cin >> X[i];
    }
    
    int i = 0, ans = 0;
    while(i < N){
        // sはカバーされていない一番左の点
        int s = X[i++];
        // sから距離Rを超える点まで進む
        while(i < N && X[i] <= s + R) i++;
        //cout << s+R << endl;
        // pは新しく印をつける点の位置
        int p = X[i - 1];
        
        while(i < N && X[i] <= p + R) i++;
        //cout << p+R << endl;
        //cout << endl;
        ans++;
    }
    
    cout << ans << endl;
    
}
/*
Saruman's Army
入力
6
10
1 7 15 20 30 50

debug:s+R p+R
11
17

30
40

60
60
*/
