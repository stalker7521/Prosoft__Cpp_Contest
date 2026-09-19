#include <vector>
using namespace std;
#include <iostream>
class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int left = 0;
        // int, чтобы избежать underflow при right = -1
        int right = nums.size() - 1; 

        //  <= т.к левый и правый указатель могут сойтись на искомом элементе
        while (left <= right) {
            // Безопасное вычисление середины без переполнения
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution solution;
    int result = solution.search(nums, target);
    
    
    cout << result << endl;
    return 0;
}