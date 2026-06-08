#include<bits/stdc++.h>
using namespace std;
/*
bài này duyệt trâu được vì y<=10^6

nhưng mạnh là phải chơi chu kì

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x,y;
    cin>>x>>y;
    long long tong=0;
    long long tronven=(y/7)*5;//đây là phần trọn vẹn 5 ngày
    tong+=tronven;
    long long i;

    /*
    ta có
     2 3 4 5 6 7 8 mod 7
    =2 3 4 5 6 0 1
    và nếu dãy đó mỗi cái -2 thì mod 7 thành
    =0 1 2 3 4 5 6
    -> cái này giúp ta dễ dàng hơn trong việc duyệt trâu
    */
    /*
    với phần không trọn vẹn
    ta nên áp dụng duyệt trâu cho nó dễ và an toàn
    */
    long long du=y%7;//cái này là số ngày còn lại
    for (i=0;i<du;i++)//nếu ko trọn vẹn, thì duyệt như thế này đủ để hốt hết tất cả các khúc
    {
        long long thu=(i+x-2)%7;//ờm cụ thể là thứ -2, do lấy modulo ròi
        //ta phải x-2 bởi vì ở trên ta đang noi theo form -2 rồi
        if (thu<=4)
        {
            tong+=1;
        }
        /*
        giải thích cụ thể hơn thì nó là quy luật tịnh tiến
        ờm
        ví dụ ta bắt đầu vào ngày thứ 6
        ta cộng i lên là số ngày mà ta đi lên
        bản chất mod 7 nó vẫn quẩn quanh mấy số 0->6 để ta ra thứ thôi
        -> ko quan tâm ngày, chỉ quan tâm thứ
        giả sử trong phần lịch có phần trọn vẹn thì chắc chắn phần thừa là 1 đoạn liên tiếp, đơn giản là thế nên áp dụng tịnh tiến đc
        ko bao giờ có chuyện nó ko phải đoạn


        KHÔNG THÍCH X-2 CŨNG ĐƯỢC,
        NẾU THẾ CHỈ CẦN CÁI thu thuộc {2,3,4,5,6}
        */
    }
    cout<<tong;






    return 0;
}
