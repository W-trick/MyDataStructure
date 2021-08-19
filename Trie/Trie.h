/*
 * @Author: Whao 
 * @Date: 2020-09-08 07:30:33 
 * @Last Modified by: Whao
 * @Last Modified time: 2020-09-09 05:32:40
 */

#ifndef __TRIE__H__
#define __TRIE__H__
#include <string>
#include <memory>

const unsigned int SIZE = 26;
class Trie
{
public:
    /*
    *
    */
    Trie();
    ~Trie();
    /*
    * @brief 遍历字符串，在树中没有此节点，就创建节点并连接，否则存在则向后移动
    * @param c插入字符串
    * @return void
    */
    void Insert(std::string&);
    /*
    * @brief 遍历字符串，根据字母映射遍历字典树节点，如果遍历结束，且为字符的尾节点，则查找成功
    * @param 查找的字符串
    * @return bool
    */
    bool Search(const std::string&);

    /*
    *@brief 与查找类似
    */
    bool StrartWith(const std::string& prefix);
private:
    bool isEnd;          //节点结尾
    //std::shared_ptr<Trie> next[SIZE];   //下一个节点字符
    Trie* next[SIZE];
};
#endif