#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Fungsi rekursif untuk menghasilkan semua LMIS yang mungkin
void findLMIS(vector<int> &nums, vector<int> &subsequence, vector<vector<int>> &result, int currentIndex) {
    // Base Case
    if (currentIndex == nums.size()) {
        if (subsequence.size() > 0) {
            result.push_back(subsequence);
        }
        return;
    }

    // Jika elemen saat ini dapat ditambahkan ke LMIS
    if (subsequence.empty() || nums[currentIndex] > subsequence.back()) {
        subsequence.push_back(nums[currentIndex]);
        findLMIS(nums, subsequence, result, currentIndex + 1);
        subsequence.pop_back();
    }

    // Lewati elemen saat ini jika ingin membuat LMIS lainnya tanpa elemen ini
    findLMIS(nums, subsequence, result, currentIndex + 1);
}

// Fungsi untuk menemukan semua LMIS yang mungkin dari array nums
vector<vector<int>> findallLMIS(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> subsequence;

    findLMIS(nums, subsequence, result, 0);

    return result;
}

// Fungsi untuk menemukan LMIS terpanjang dari semua LMIS yang ditemukan
vector<int> longestIncreasingSubsequence(vector<vector<int>> &allLMIS) {
    vector<int> longest;
    int maxLength = 0;

    for (const auto &LMIS : allLMIS) {
        if (LMIS.size() > maxLength) {
            maxLength = LMIS.size();
            longest = LMIS;
        }
    }

    return longest;
}

int main() {
    // Input
    vector<int> arr = {4, 1, 13, 7, 0, 2, 8, 11, 3};

    // Mencari semua LMIS
    vector<vector<int>> allLMIS = findallLMIS(arr);

    // Mencari LMIS terpanjang dari semua LMIS yang ditemukan
    vector<int> longestLMIS = longestIncreasingSubsequence(allLMIS);

    // Menampilkan LMIS terpanjang
    cout << "\nPanjang Largest Monotically Increasing Subsequence : " << longestLMIS.size();
    cout << "\nSemua Largest Monotically Increasing Subsequence dengan Panjang " << longestLMIS.size() << ":" << endl;
    for (const auto &LMIS : allLMIS) {
        if (LMIS.size() == longestLMIS.size()) {
            for (const auto &num : LMIS) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
