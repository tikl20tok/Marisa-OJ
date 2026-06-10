#include<bits/stdc++.h>
using namespace std;
/*
this is a hard one (n logn with segment tree)
well, we can easily do nxq

but because we are smarter so we will choose segment tree + backtracking
we notice that:
each time we add 1 element, the size +=1
and also, all the element to the right will +1 its position

-> in segment tree, we will have a check array (true/false, choosed or not)
if it is not choose, put the element in
else
put it at the +1 position

you may think what if it can OUT OF BOUND
the answer is NO, according to mathmetic, just when you add, the size will bigger
but it is change or not, still not affect (? maybe this demonstrate true)

we run from the bottom to the top of insert actions, walk one tree, a kind of BACKTRACK

use segment tree here
each time you get down
you subtract the pos
the condition:
if (pos<=remain_of_left)
{
    scope it to left
}
    else
    {
        scope it to right
    }

and when you reach start==en,
outp[start or en up to you]=val
tree[node]=0

then update the sum: tree[node]= tree[2*node+1] + tree[2*node];
*/
struct inform
{
    long long pos,val;
};

vector<long long> tree,outp;//this will count how many empty slots


void build (long long node, long long start, long long en)
{
    if (start==en)
    {
        tree[node]=1;
        return;
    }
    long long mid = start+(en-start)/2;
    build(2*node,start,mid) ;
    build(2*node+1,mid+1,en);
    tree[node]= tree[2*node+1] + tree[2*node];//sum of each node
}
void insert (long long node, long long start, long long en, long long pos, long long value)
{
    if (start==en)
    {
        outp[start]=value;
        tree[node]=0;//choosed
        return;
    }

    long long mid = start+(en-start)/2;
    long long remain_of_left = tree[2*node];
    if (pos<=remain_of_left)//if the position of it in left
    {
        insert(2*node, start, mid, pos, value);
    }
    else //if in right
    {
        insert(2*node+1, mid+1, en, pos-remain_of_left, value);
        /*
        you notice that we use pos-remain_of_left

        well, for example you got index 1 2 3 4 5 6
        you search for 4
        you current at 3 5
        so all the way you got from the first is:
        4>3 -> to the right, you got 4 6
        subtract 3 (remain_of_left)
        -> pos=1
        mid = 4 + (6-4)/2=5
        remain of left = 4 to 5, example is 2
        1<2
        -> to the left, and you got the result, easy huh?
        */
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    /*
    this code is not follow the work (n*q)
    it just aim for the best algorithm to solve this (q*logn)
    */
    long long n,q;
    cin>>n>>q;
    vector<long long> a(n+5);
    vector<inform> actions(q+5);
    long long i,j;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=q;i++)
    {
        cin>>actions[i].pos>>actions[i].val;
    }
    tree.resize(4*(n+q+5),0);
    outp.resize(n+q+5,-(1LL<<60));

    build(1, 1, n+q);

    //this is q
    for (i=q;i>=1;i--)
    {
        //this one just is corner case, you can abandon it if the input is right
        {
            if (tree[1]==0)//this means there are not have any left, pos must be in 1 -> tree[1] (full segment)
            {
                continue;
            }
            //make a check more
            if (actions[i].pos>tree[1])
            {
                actions[i].pos=tree[1];
                /*
                why?
                because this is to check if it is in valid range
                */
            }
        }   

        insert(1, 1, n+q, actions[i].pos, actions[i].val);
    }

    //this reverse loop, if use forward loop, it will completely wrong
    /*
    i don't know how to demonstrate this properly

    but when you reverse, you like greedy
    you give a bigger index and walk on tree, it feel like index near you
    otherwise, you make smaller index in, and the quantity of empty reduce
    -> bigger will more bigger and far than the empty, maybe this one break the logic of segment tree
    */
    for(i=n;i>=1;i--)
    {
        insert(1, 1, n+q, i, a[i]);
    }
    for (i=1;i<=n+q;i++)
    {
        cout<<outp[i]<<" ";
    }


    //now, all inserted, just fill the blank
    /*
    this one still true due to you just need to fill empty slot
    long long index=1;
    for (i=1;i<=n+q;i++)
    {
        if (outp[i]==-(1LL<<60)&&index<=n)
        {
            cout<<a[index]<<" ";
            index+=1;
            continue;
        }
        cout<<outp[i]<<" ";
    }
    */


    //maybe have some corner case that idk



    return 0;
}
