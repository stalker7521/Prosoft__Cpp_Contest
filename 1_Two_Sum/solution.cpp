#include <iostream>
#include <vector>
#include <unordered_map>
/*
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
*/

class Solution {
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Храним просматриваемые числа как ключи, а их индексы как значения для поиска за O(1)
        std::unordered_map<int, int> num_to_index;

        for (size_t i = 0; i < nums.size(); ++i){
            int current_number = nums[i];
            int needed_number = target - current_number;
            
            // Используем find() вместо count(), чтобы избежать двойной поиск по хэш-таблице
            auto it = num_to_index.find(needed_number);

            if (it == num_to_index.end()){
                num_to_index[current_number] = i;
            }
            else{
                return {it->second, static_cast<int>(i)};
            }
        }
        return {};
    }
};

int main() {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);

     if (!result.empty()) {
        std::cout << "Result: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }
    return 0;
    
}