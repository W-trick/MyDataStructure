#ifndef SOLUTION
#define SOLUTION
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Solution
{

public:
    Solution();
    ~Solution(){}
    void adjust(std::vector<int>&vc, int len, int index);   //建堆
    void heapsort(std::vector<int>&vc, int len);            //堆排序

    void merge(std::vector<int>& vc, int left, int mid, int right);   //归并
    void mergeSort(std::vector<int>&vc, int left, int right);  //归并排序

    int partition(std::vector<int>&vc, int start, int end);
    void quickSort(std::vector<int>&vc, int start, int end);  //快排

    void TopK(std::vector<int>&vc, int start, int end, int k);    //top k 問題

    //BinarySerach

    int BinarySerach(const std::vector<int>& vc, int target);



private:
};


#endif // SOLUTION

