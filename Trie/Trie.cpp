#include "Trie.h"
#include <iostream>
#include <string.h>

Trie::Trie():isEnd(false)
{
    std::cout<<"Trie Ctor"<<std::endl;
    memset(next, 0, sizeof(next));
}

Trie::~Trie()
{
    for(int i=0;i<SIZE;++i)
    {
        if(this->next[i] == NULL)
        continue;

        delete this->next[i];
        std::cout<<"Trie dtor"<<std::endl;
    }
  
}

void Trie::Insert(std::string& word)
{
    Trie* Node = this;
    for(char c: word)
    {
        if(Node->next[c-'a'] == NULL)
            Node->next[c-'a'] = new Trie();
        
        Node = Node -> next[c-'a'];
    }
    Node->isEnd = true;
}

bool Trie::Search(const std::string& word)
{
    Trie* Node = this;
    for(char c: word)
    {
        if(Node -> next[c - 'a'] != NULL)
            Node = Node->next[c - 'a'];
        
        else
        {
            return false;
        }
    }
    return Node->isEnd;
}

bool Trie::StrartWith(const std::string& prefix)
{
    Trie* Node = this;

    for(char c: prefix)
    {
        if(Node->next[c - 'a'] != NULL)
        {
            Node = Node->next[c - 'a'];
        }
        else
        {
            return false;
        }
    }
    return true;
}
