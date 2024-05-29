#include <bits/stdc++.h>
using namespace std;

int n, k1, k2;
int nm1, np1;
int k11, k21;
int dem;

void Try(int k) {
	for (int i = k11; i <= k21; ++i) {
		k += i;
		if (k >= nm1) {
			if (k == nm1 || k == np1) ++dem; //k=n-1,nếu ngày đầu là nghỉ thì ngày cuối cũng là nghỉ, nếu ngày đầu làm thì đến cuối sẽ có 2 ngày nghỉ trùng nhau, ta đẩy ngày nghỉ cuối lên đầu nên có 1 cách
			// k=n+1, nếu ngày đầu là ngày làm thì bỏ ngày nghỉ ở cuối đi, nếu ngày đầu là nghỉ ta bỏ ngyaf nghỉ ở đầu nên được 1 cách
			else if (k == n) dem += 2; // k=n, ngày đầu là nghỉ hay làm thì đều được nên được 2 cách
			else return;
		} else Try(k);
		k -= i;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k1 >> k2;
	nm1 = n - 1; np1 = n + 1;
	k11 = k1 + 1; k21 = k2 + 1;
	Try(0);
	cout << dem;
	return 0;
}

