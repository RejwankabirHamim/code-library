#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
using    namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define dbg(x) cout<<#x<<": "<<x<<endl;
#define M  998244353 // 1000000007  //
#define ll long long
#define pa pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define vi vector<int>
#define vll vector<ll>
#define fr(i,n,j) for(i=j;i<=n;i++)
#define rfr(i,n,j) for(i=n;i>=j;i--)
#define ct continue;
#define yo cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define endl '\n'
ll a[500005],b[500005],c[500005],d[500005];

struct wavelet_tree{
	#define vi vector<int>
	#define pb push_back
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
	vi c; // c holds the prefix sum of elements

	//nos are in range [x,y]
	//array indices are [from, to)
	wavelet_tree(int *from, int *to, int x, int y){
		lo = x, hi = y;
		if( from >= to) return;
		if( hi == lo ){
			b.reserve(to-from+1);
            		b.pb(0);
			c.reserve(to-from+1);
            		c.pb(0);
            		for(auto it = from; it != to; it++){
            			b.pb(b.back() + 1);
            			c.pb(c.back()+*it);
            		}
			return;
		}
		int mid = (lo+hi)/2;
		auto f = [mid](int x){
			return x <= mid;
		};
		b.reserve(to-from+1);
		b.pb(0);
		c.reserve(to-from+1);
		c.pb(0);
		for(auto it = from; it != to; it++){
			b.pb(b.back() + f(*it));
			c.pb(c.back() + *it);
		}
		//see how lambda function is used here
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}

	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}

	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
	}

	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}

	//sum of nos in [l ,r] less than or equal to k
	int sumk(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return c[r] - c[l-1];
		int lb = b[l-1], rb = b[r];
		return this->l->sumk(lb+1, rb, k) + this->r->sumk(l-lb, r-rb, k);
	}

	~wavelet_tree(){
		delete l;
		delete r;
	}
};

int main()
{

}
