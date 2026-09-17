#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;

        // Подсчет частоты вхождения каждого числа за O(N)
        for (int num: nums){
            freq_map[num]++;
        }

        // Создаем массив корзин.
        // Индекс = частота, значение - список чисел с такой частотой.
        // Используем nums.size()+1 тк частота может быть равна длине массива
        vector<vector<int>> buckets(nums.size()+1);

        // Распределяем числа по корзинам
        for (auto [num, count]: freq_map){
            buckets[count].push_back(num);
        }

        vector<int> result;
        result.reserve(k);

        // Собираем топ из k элементов
        //Итерируемся по корзинам с конца тк максимальная частота в конце
        for (int i = buckets.size() - 1; i > 0; --i){
            if (!buckets[i].empty()){
                for (int num: buckets[i]){
                    result.push_back(num);
                    // Воззвращаем результат, как собрали k элементов
                    if (result.size() == k){
                        return result;
                    }
                }
            }
        }
        return {};
    }
};

/*
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/
int main(){
    vector<int> nums = {1,2,1,2,1,2,3,1,3,2};
    int k = 2;
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    sort(result.begin(), result.end());
    cout << "Result: [";
    if (!result.empty()){
        for (int num: result){
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    else{
        cout << "No solution found" << endl;
    }
    return 0;
}