#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:
    int maxArea(const vector<int>& height) {
        int left = 0, max_area = 0;
        int right = height.size() - 1;
        while (left < right){
            // Площадь ограничена меньшей из двух высот
            int current_area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, current_area);

            // Двигаем указатель, который стоит на меньшей высоте,
            // тк сдвиг большей высоты гарантированно не увеличит общую высоту контейнера.
            height[left] < height[right] ? left++ : right--;
        }

        return max_area;
    }
};

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    int result = solution.maxArea(height);

    cout << "Result: " << result << endl; 
    return 0;
}