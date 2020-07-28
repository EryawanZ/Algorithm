// ERz
// 28-7-2020
// https://www.hackerrank.com/challenges/unbounded-knapsack/problem

#include <iostream>
#include <vector>
#include <assert.h>
#include <limits>
using namespace std;

int knaphsack(int coin, int target, int arr[], int n){
    if(coin > target)
        return -1;
    if(n < 0)
        return coin;
    return max(knaphsack(coin+arr[n], target, arr, n), knaphsack(coin, target, arr, n-1));    
}

int main(){ int t = 1;
    cin >> t;
    while(t--){ int n = 3, a = 11, *arr;
        cin >> n >> a;
        arr = new int[n];
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << knaphsack(0, a, arr, n-1) << endl;
        delete arr;
    }
    return 0;
}