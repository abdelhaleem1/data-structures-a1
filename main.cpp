#include <iostream>
#include <vector>

using namespace std;



int updated_binary_search(vector<int>& v, int target, int& comparisons) {
    int n = v.size();
    int left = 0;
    int right = n-1;
    while(left<=right) {
        int mid = (left+right)/2;
        if(v[mid] == target) {
            comparisons++;
            return mid;
        }

        if (v[left] == v[mid] && v[mid] == v[right]) {
            comparisons++;
            left++;
            right--;
            continue;
        }

        if(v[left] <= v[mid]) {
            comparisons+=2;
            if(v[left] <= target && target < v[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }else {
            comparisons+=2;
            if (v[mid] < target && target <= v[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1 ;
}


int main() {
    int comparisons = 0;
    vector<int> v = {5, 6, 7, 1, 2, 3, 4};
    int res = updated_binary_search(v, 2, comparisons);

    if(res != -1) {
        cout<<"Target found at index:"<< res<<endl;
    }else {
        cout<<"Target is not found"<<endl;
    }
    cout<<"Total comparisons: "<<comparisons<<endl;
    return 0;
}
