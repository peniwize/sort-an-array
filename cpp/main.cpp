/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/sort-an-array/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h> //!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md
#include <iterator>
#include <vector>

using namespace std;

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (1 < nums.size()) {
            mergeSort(nums.begin(), nums.end(), nums.size());
        }
        return nums;
    }

    template <typename I>
    void mergeSort(I left, I right, size_t size) {
        auto mid = left;
        std::advance(mid, size / 2);

        if (2 < size) {
            // Recursively merge sort left and right halves.
            mergeSort(left, mid, size / 2);
            mergeSort(mid, right, right - mid);
        }

        // Merge result.
        typename I::value_type result[size];
        typename I::value_type* o = result;
        auto l = left;
        auto r = mid;
        while (l != mid && r != right) { *o++ = *l <= *r ? *l++ : *r++; }
        while (l != mid) { *o++ = *l++; }
        while (r != right) { *o++ = *r++; }

        // Copy result over original data.
        std::copy(result, result + size, left);
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

TEST_CASE("Case 1")
{
    cerr << "Case 1" << '\n';
    vector<int> value{5, 2, 3, 1};
    CHECK(vector<int>{1, 2, 3, 5} == Solution{}.sortArray(value));
    cerr << '\n';
}

TEST_CASE("Case 2")
{
    cerr << "Case 2" << '\n';
    vector<int> value{5, 1, 1, 2, 0, 0};
    CHECK(vector<int>{0, 0, 1, 1, 2, 5} == Solution{}.sortArray(value));
    cerr << '\n';
}

TEST_CASE("Case 3")
{
    cerr << "Case 3" << '\n';
    vector<int> value{5, 1, 1, 2, 0, 0, 7, -3};
    CHECK(vector<int>{-3, 0, 0, 1, 1, 2, 5, 7} == Solution{}.sortArray(value));
    cerr << '\n';
}

/*
    End of "main.cpp"
*/
