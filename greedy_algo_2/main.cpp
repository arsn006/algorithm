#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    int N;
    cin >> N;
    vector<pair<int, int>> job(N);
    for(int i=0; i<N; i++){
        int s,t;
        cin >> s;
        cin >> t;
        // 終了時間でソートするため順番を入れ替える
        job[i] = make_pair(t, s);
    }

    sort(job.begin(), job.end());
    /*
    for(int i=0; i<N; i++){
        printf("T:%d S:%d\n", job[i].first, job[i].second);
    }*/
    // tは最後に選んだ仕事の時間
    
    int ans = 0, t = 0;
    for(int i=0; i<N; i++){
        if(t < job[i].second){
            ans++;
            t = job[i].first;
        }
    }
    
    printf("%d\n", ans);

}
/*
区間スケジューリング問題
入力
N N=仕事の数
S T S=開始時間 T=終了時間
5
1 3
2 5
4 7
6 9
8 10
*/