/*
 * @Author: Whao 
 * @Date: 2020-09-09 05:25:41 
 * @Last Modified by:   Whao 
 * @Last Modified time: 2020-09-09 05:25:41 
 */
#include "Trie.h"
#include <string>
#include <iostream>
int main(int argc, char** argv)
{
    Trie* trie = new Trie();
    std::string str = "hello";
    trie->Insert(str);
    std::string str1 = "world";

    trie->Insert(str1);

    
    if(trie->Search(str))
    {
        std::cout<<"true"<<std::endl;
    }
    
    std::string prefix = "he";
    if(trie->StrartWith(prefix))
    {
        std::cout<<"prefix true"<<std::endl;
    }

    delete trie;
    return 0;
}