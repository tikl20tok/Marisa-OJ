#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n,k;
    cin>>n>>k;
    /*
    bài này có thể mô phỏng tuần tự
    -> như testcase 10 3
    ta có
    10-3=7  +1=8 -> 3 days
    lặp lại liên tục ta còn 2 ngày và được thêm 3 lần
    ->12 +2 =14 days, hợp lí rồi

    vậy bây giờ ta đi toán học
    ta chắc chắn sẽ dùng hết n ngày
    vậy ta cần tính số lần ta sẽ trade

    declare t is time of trade
    we have this inequation:
    n-k*t+1t>=k 
    it means each time you want to trade, you need more than k, start of trade, not the end of trade

    you see, 1t refer to each time you exchange k stem
    -> n-t*(k-1)>=k (1)
    n-k>=t(k-1)
    (n-k)/(k-1)>=t
    ((n-1)-(k-1))/(k-1)>=t
    (n-1)/(k-1)-1>=t

    and accroding to mathmetic, t is an interger
    in this case, if you got the result, you need floor the t down
    so you just need to floor the (n-1)/(k-1) down to make an interger, easy right?

    and you got times of trade = (n-1)/(k-1) (floor down) -1 and +1
    you see why +1? it is because (1), when you make that, you still have k stem left 
    it means you can make another 1 trade so +1 

    */

    cout<<n+(n-1)/(k-1);


    //full ac 100%

    return 0;
}
