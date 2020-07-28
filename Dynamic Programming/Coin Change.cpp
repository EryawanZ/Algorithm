#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <assert.h>
using namespace std;

int ans[251], coin[251];
int main(){ int a, n;
    cin >> a >> n;
    for (int i=0; i<n; i++){
        cin >> coin[i];        
    }
    ans[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=a; j++){
            if(j-coin[i] < 0){
                continue;
            }
            ans[j] += ans[j-coin[i]];
        }
    }
    cout << ans[a] << endl;
    return 0;
}
