#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <memory>

using namespace std;

// --------------------------------------------------------------------------
// ============================== Linked List ==============================
template<typename T>
struct SinglyLLNode{
  T data_;
  SinglyLLNode* next_;
  SinglyLLNode(T val): data_(val), next_(nullptr) {}
  ~SinglyLLNode() {/*cout<<data_<<" : SinglyLLNode is getting destroyed\n";*/}
};

template<typename T>
class LinkedList {
  private:
    SinglyLLNode<T>* head_{nullptr};
    //helper functions
    SinglyLLNode<int>* CreateNode(int val) {
      return new SinglyLLNode<int>(val);
    }

    SinglyLLNode<char>* CreateNode(char c) {
      return new SinglyLLNode<char>(c);
    }

    SinglyLLNode<string>* CreateNode(string str) {
      return new SinglyLLNode<string>(str);
    }
  public:
    LinkedList<T>(vector<T>& nums){
      SinglyLLNode<T> *crrNode = nullptr;
      for (auto num:nums) {
        SinglyLLNode<T> *newNode = CreateNode(num);
        if (head_ != nullptr) {
          crrNode->next_ = newNode;
          crrNode = crrNode->next_;
        } else {
          head_ = newNode;
          crrNode = head_;
        }
      }
    }
    ~LinkedList(){
      //cout<<"Destroy called from LinkedList\n";
      SinglyLLNode<T>* currNode = head_;
      head_ = nullptr;
      while(currNode != nullptr) {
        auto nextNode = currNode->next_;
        delete currNode;
        currNode = nextNode;
      }
    }
};
// --------------------------------------------------------------------------

// ============================== Doubly-Linked List ==============================
template<typename T>
struct DoublyLLNode{
  T data_;
  DoublyLLNode* next_;
  DoublyLLNode* prev_;
  DoublyLLNode(T val): data_(val), next_(nullptr), prev_(nullptr) {}
  ~DoublyLLNode() {/*cout<<data_<<" : DoublyLLNode is getting destroyed\n";*/}
};

template<typename T>
class DLinkedList {
  private:
    DoublyLLNode<T>* head_{nullptr};
    //helper functions
    DoublyLLNode<int>* CreateNode(int val) {
      return new DoublyLLNode<int>(val);
    }

    DoublyLLNode<char>* CreateNode(char c) {
      return new DoublyLLNode<char>(c);
    }

    DoublyLLNode<string>* CreateNode(string str) {
      return new DoublyLLNode<string>(str);
    }
  public:
    DLinkedList<T>(vector<T>& nums){
      DoublyLLNode<T> *crrNode = nullptr;
      for (auto num:nums) {
        DoublyLLNode<T> *newNode = CreateNode(num);
        if (head_ != nullptr) {
          crrNode->next_ = newNode;
          newNode->prev_ = crrNode;
          crrNode = crrNode->next_;
        } else {
          head_ = newNode;
          crrNode = head_;
        }
      }
    }
    ~DLinkedList(){
      //cout<<"Destroy called from DLinkedList\n";
      DoublyLLNode<T>* currNode = head_;
      head_ = nullptr;
      while(currNode != nullptr) {
        auto nextNode = currNode->next_;
        delete currNode;
        currNode = nextNode;
      }
    }
};
// --------------------------------------------------------------------------

// ============================== Tree ==============================
template<typename T>
struct TreeNode {
  public:
    TreeNode(T val): data_(val),left_(nullptr), right_(nullptr) { }
    ~TreeNode() {/*cout<<data_<<" : TreeNode is getting destroyed\n";*/}
    T data_;
    TreeNode* left_;
    TreeNode* right_;
};

template<typename T>
class Tree {
  private:
    TreeNode<T>* root_{nullptr};

    //helper function
    TreeNode<int>* CreateNode(int val) {
      if (val == 0) {
        return nullptr;
      }
      return new TreeNode<int>(val);
    }

    TreeNode<char>* CreateNode(char c) {
      if (c == ' ') {
        return nullptr;
      }
      return new TreeNode<char>(c);
    }

    TreeNode<string>* CreateNode(string str) {
      if  (str == " ") {return nullptr;}
      return new TreeNode<string>(str);
    }

    void CreateTree(vector<T>& nums);
    void DeleteTree(TreeNode<T> *root);
  public:
    Tree<T>(vector<T>& V) {
      CreateTree(V);
    }
    // delete copy constructor and assignment operator
    Tree<T>(const Tree<T>& ) = delete;
    void operator = (const Tree<T>& ) = delete;

    ~Tree<T>() {
      //cout<<"Tree is getting destroyed!!\n";
      DeleteTree(root_);
      root_ = nullptr;
    }
    TreeNode<T>* getRoot() { return root_;}
};

template<typename T>
void Tree<T>::CreateTree(vector<T>& nums) {
  TreeNode<T>* curr = root_;
  queue<TreeNode<T>*> Queue;
  bool leftNodeVisited = false, rightNodeVisited = false;
  for (auto num:nums){
    TreeNode<T>* newNode = CreateNode(num);
    if (curr == nullptr) {
      root_ = curr = newNode;
    } else {
      if (curr->left_ == nullptr && leftNodeVisited == false) {
        curr->left_ = newNode;
        leftNodeVisited = true;
      } else if (curr->right_ == nullptr && rightNodeVisited == false) {
        curr->right_ = newNode;
        rightNodeVisited = true;
      }
      if (newNode != nullptr) {
        Queue.push(newNode);
      }
    }
    if (leftNodeVisited == true && rightNodeVisited == true) {
      curr = Queue.front(); Queue.pop();
      leftNodeVisited = false;
      rightNodeVisited = false;
    }
  }
}

template<typename T>
void Tree<T>::DeleteTree(TreeNode<T> *root) {
  if (root == nullptr)
    return;

  DeleteTree(root->left_);
  DeleteTree(root->right_);

  delete root;
}