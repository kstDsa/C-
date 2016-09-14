#ifndef HASHINGTABLE_H
#define HASHINGTABLE_H

#include <vector>
#include <list>
#include <iterator>
#include <cstring>
#include <iostream>

using namespace std;

template<class T>
class HashingTable
{
  public:
    HashingTable(int size = 0);
    HashingTable(const HashingTable<T> &rhs);
    ~HashingTable();
    void insert(T str);
    bool find(T str);
    void split(int i, int p);
    bool remove(T str);
    HashingTable<T> &operator=(const HashingTable<T> &rhs);
    template<class U>
    friend ostream &operator<<(ostream &lhs, const HashingTable<U> &rhs);
  private:
    int hash(T str);
    vector<list<T> > vec;
};

template<class T>
HashingTable<T>::HashingTable(int size):vec(size)
{ }

template<class T>
HashingTable<T>::HashingTable(const HashingTable<T> &rhs)
{
 for(int i = 0; i < rhs.vec.size(); i++)
   vec.push_back(rhs.vec[i]);
}

template<class T>
HashingTable<T>::~HashingTable()
{ 
  vec.clear();
}

template<class T>
void HashingTable<T>::insert(T str)
{
  int h = hash(str);
  if(h >= 0)
  {
    if(h >= vec.size())
      vec.resize(h + 1);
    vec[h].push_back(str);
  }
}

template<class T>
bool HashingTable<T>::find(T str)
{
  int h = hash(str);

  if(h < 0 || h >= vec.size())
    return false;
    
  for(int i = h; i < vec.size(); i++)
  { 
    typename list<T>::const_iterator it;
    for(it = vec[i].begin(); it != vec[i].end(); it++)
      if(strcmp(str, (*it)) == 0)
        return true;
  }
  return false;
}

template<class T>
void HashingTable<T>::split(int i, int p)
{ 
  int next = i + 1;

  if(i < vec.size() && p > 0)
  {
    while(vec[i].size() > p) 
    { 
      if(next >= vec.size())
        vec.resize(next + 1);
      while(vec[next].size() < p)
      {
        typename list<T>::const_iterator it = vec[i].begin();
        advance(it, p);
        vec[next].push_back(*it);
        vec[i].remove(*it);
      }
      next++;    
    }
  }
}

template<class T>
bool HashingTable<T>::remove(T str)
{
  int h = hash(str);

  if(h < 0 || h >= vec.size())
    return false;

  for(int i = h; i < vec.size(); i++)
  {
    typename list<T>::const_iterator it;
    for(it = vec[i].begin(); it != vec[i].end(); it++)
      if(strcmp(str, (*it)) == 0)
      {
        vec[i].remove(str);
        return true;
      }
  }
  return false;
}

template<class T>
HashingTable<T> &HashingTable<T>::operator=(const HashingTable<T> &rhs)
{
  if(this != &rhs)
  {
    for(int i = 0; i < rhs.vec.size(); i++)
      vec.push_back(rhs.vec[i]);
  }
  return *this;
}

template<class U>
ostream &operator<<(ostream &lhs, const HashingTable<U> &rhs)
{
  for(int i = 0; i < rhs.vec.size(); i++)
  {
    if(rhs.vec[i].empty())
      continue;
    lhs << "List" << i << " contains:" << endl;
    typename list<U>::const_iterator it;
    for(it = rhs.vec[i].begin(); it != rhs.vec[i].end(); it++)
      lhs << ' ' << (*it) << endl;
  }
  return lhs;
}

template<class T>
int HashingTable<T>::hash(T str)
{
  return (str[0]- 'A');
}

#endif
