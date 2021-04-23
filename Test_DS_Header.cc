#include "DS.hpp"

int main() {
  {
    vector<string> Elements = {"2","3"," ","4", "5"};
    Tree<string> T(Elements);

    vector<int> iEle = {1,2,3,0,4,5};
    Tree<int> iT(iEle);

    vector<char> cEle = {'a','b','c',' ','d','e'};
    Tree<char> cT(cEle);
  }

  {
    vector<int> iEle = {1,2,3};
    LinkedList<int> iList(iEle);

    vector<char> cEle = {'a','b','c','d','e'};
    LinkedList<char> cList(cEle);
  }

  {
    vector<int> iEle = {1,2,3};
    DLinkedList<int> iList(iEle);

    vector<char> cEle = {'a','b','c','d','e'};
    DLinkedList<char> cList(cEle);
  }
}