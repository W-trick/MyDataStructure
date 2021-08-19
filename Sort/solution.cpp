#include "solution.h"
#include <iostream>


Solution::Solution()
{

}
//建堆

void Solution::adjust(std::vector<int> &vc, int len, int index)
{
    int left = index*2 + 1;      //左子节点
    int right = index*2 + 2;     //右子节点

    int maxidx = index;          // 保存当前节点下标


    //从左至右比较，取出最大值的下标
    if(left < len && vc[left] > vc[maxidx])
    {
        maxidx = left;           //
    }
    if(right < len && vc[right] > vc[maxidx])
    {
        maxidx = right;
    }

    if(maxidx != index)    //如果当前根节点不是最大值进行交换，交换后的子树节点重新建堆
    {
        std::swap(vc[maxidx], vc[index]);
        adjust(vc, len, maxidx);
    }

}

void Solution::heapsort(std::vector<int> &vc, int len)
{
    for(int i = len/2 - 1 ; i >= 0 ; --i)    //
    {
        adjust(vc, len, i);
    }

    //调整大根堆
    for(int i = len - 1 ; i >= 0; --i)
    {
        std::swap(vc[i], vc[0]);    //当前最大节点放到最后一个位置
        adjust(vc, i, 0);           //重新建堆
    }
}

/****   归并
 *  std::vector<int> vc 声明后不能使用
 * vc[index] 下标进行赋值，会导致越界
 * 下标是修改不是插入，如果用下标保证初始化时有足够的元素
 * 一般使用push_back
 *
*****/
void Solution::merge(std::vector<int> &vc, int left, int mid, int right)
{
    std::vector<int> temp(sizeof(vc), 0);    //error : vector outof range

    int i = 0;
    int first = left;
    int second = mid + 1;
    while(first <= mid && second <= right)    //合并数组
    {

          temp[i++] = vc[first] < vc[second] ? vc[first++] : vc[second++];
//        if(vc[first] < vc[second])
//        {
//            temp[i++] = vc[first++];
//        }
//        else
//        {
//            temp[i++] = vc[second++];
//        }
    }

    while(first <= mid)   //  如果数组有剩余部分继续合并
    {
        temp[i++] = vc[first++];
    }

    while(second <= right)
    {
        temp[i++] = vc[second++];
    }

    for(int j = 0; j < (right - left) + 1; ++j)    //最后整合到原始数组
    {
        vc[left + j] = temp[j];              //原始数组最初位置为传入的left为起始点
    }

}

void Solution::mergeSort(std::vector<int> &vc, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right)/2;
        mergeSort(vc, left, mid);
        mergeSort(vc, mid + 1, right);

        merge(vc, left, mid, right);  //归并
    }
}



int Solution::partition(std::vector<int> &vc, int start, int end)
{
    int pivotValue = vc[start];  //进行分区的值

    while(start < end)
    {

        while(pivotValue < vc[end] && start < end)
        {
            --end;
        }
        std::swap(pivotValue, vc[end]);  //找到比标准值小的进行交换

        while(pivotValue > vc[start] && start < end)
        {
            ++start;
        }
        std::swap(pivotValue, vc[start]);
    }

    return end;

}

void Solution::quickSort(std::vector<int> &vc, int start, int end)
{
    if(start < end)
    {
       int piv = partition(vc, start, end);
       std::cout<<"piv"<<piv<<std::endl;
       quickSort(vc, start, piv - 1);
       quickSort(vc, piv + 1, end);
    }
}


void Solution::TopK(std::vector<int> &vc, int start, int end, int k)
{
    if(start < end)
    {
        int piv =partition(vc, start, end);
        if(piv == k)
        {
            return;
        }
        else if(piv < k)
        {
            TopK(vc, piv + 1, end, k);
        }
        else
        {
            TopK(vc,start, piv - 1, k);
        }


    }
}


//BinarySerach

int Solution::BinarySerach(const std::vector<int> &vc, int target)
{
    int start = 0;          //取起始位置
    int end   = vc.size() - 1;  //取结束位置

    while(start <= end)
    {
        int mid   = (start + end)/2;     //取中间位置

        if(vc[mid] == target)           //找到返回
        {
            return mid;
        }
        if(vc[mid] > target)         //若中间值大于目标值，则在左区间继续查找
        {
            end = mid - 1;
        }
        else                        //若中间值小于目标值，则在又区间继续查找
        {
            start = mid + 1;
        }
    }
    return -1;
}



