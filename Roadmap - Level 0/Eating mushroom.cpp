#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x,y;
    cin>>x>>y;
    /*
    bài này duyệt trâu cx đc vì y nhỏ
    nhưng vs sức mạnh và tư duy thì phải chơi chu kì

    sau y ngày
    -> bắt đầu từ x, kết thúc vào ngày thứ x+y

    */
    long long start,en;
    start=x;en=x+y;

    long long tong=0;
    long long tronven=(y/7)*5;//số ngày trọn vẹn ăn nấm
    tong+=tronven;
    //tính phần thừa ra:
    /*
      2 3 4 5 6 7 8 mod 7
    = 2 3 4 5 6 0 1
    -> ta nhắm đến những ngày mà có dư là 2 3 4 5 6
    
    ví dụ: 6 5 -> start=6, en=11
    mỗi khi ta có 1 modulo thì lấy trừ đi thôi
    6%7==6 -> số ngày là 1 (đếm từ phải sang trái)
    11%7==3 -> số ngày là 2 (đếm từ trái sang phải)
    */
    long long a[10],b[10];
    a[7]=0;b[7]=0;
    a[8]=0;b[8]=0;

    a[6]=1;a[5]=2;a[4]=3;a[3]=4;a[2]=5;
    b[2]=1;b[3]=2;b[4]=3;b[5]=4;b[6]=5;

    tong+=a[start%7];
    tong+=b[en%7];

    cout<<tong;






    return 0;
}
