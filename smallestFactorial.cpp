//formula is: floor(x/5) + floor(x/25)+......
//video link: https://youtu.be/wkvVdggCSeo
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(int mid, int n){
        int count = 0;
        int f = 5;
        while (f <= mid){
            count += mid/f;
            f = f * 5;
        }
        return count >= n;
    }
    int findNum(int n)
    {
        //complete the function here
        if (n == 1){
            return 5;
        }
        int start = 0;
        int end = n*5;
        int smallestFactorial = -1;
        while (start <= end){
            int mid = start + (end -start)/2;
            if(check(mid, n)){
                smallestFactorial = mid;
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
        return smallestFactorial;
    }
};
