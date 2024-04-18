#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    unordered_set<int> seen; // Sử dụng unordered_set để lưu trữ các giá trị đã xuất hiện

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (seen.count(a[i]) == 0) {
            // Nếu phần tử chưa xuất hiện trong set
            seen.insert(a[i]); // Thêm phần tử vào set để đánh dấu đã xuất hiện
            cout << "0" << endl; // In ra 0 để chỉ đây là lần đầu xuất hiện của phần tử
        } else {
            cout << "1" << endl; // In ra 1 nếu phần tử đã xuất hiện trước đó
        }
    }

    return 0;
}
