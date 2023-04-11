#include <iostream>
#include <vector>
#include <queue>

template <class T>
class BinaryTree
{
private:

public:
    T key = (T)0;
    BinaryTree *leftNode;
    BinaryTree *rightNode;
    BinaryTree(T key_val) : key(key_val)
    {
        rightNode = NULL;
        leftNode = NULL;
    };
    ~BinaryTree();
    //std::vector<T> BinaryTreeInorderTraversal(BinaryTree *root, std::vector<T> nodesValues);
    BinaryTree *getLeft();
    BinaryTree *getRight();
    void setLeft();
};

template <class T>
void BinaryTreeInorderTraversal(BinaryTree<T>* root  ,  std::vector<T>&nodesValues)
{
    if (root != NULL)
    {
        BinaryTreeInorderTraversal(root->leftNode,nodesValues);
        nodesValues.push_back(root->key);
        //std::cout << (root->key);
        BinaryTreeInorderTraversal(root->rightNode,nodesValues);
    }
}

template <class T>
void BinaryTreePreorderTraversal(BinaryTree<T>* root  ,  std::vector<T>&nodesValues)
{
    if(root != NULL)
    {
        nodesValues.push_back(root->key);
        BinaryTreePreorderTraversal(root->leftNode,nodesValues);
        BinaryTreePreorderTraversal(root->rightNode,nodesValues);
        
    }
}

template <class T>
void BinaryTreePostorderTraversal(BinaryTree<T>* root  ,  std::vector<T>&nodesValues)
{
    if(root != NULL)
    {
        
        BinaryTreePostorderTraversal(root->leftNode,nodesValues);
        BinaryTreePostorderTraversal(root->rightNode,nodesValues);
        nodesValues.push_back(root->key);
    }
}

template <class T>
void BinaryTreePrint(std::vector<T> &nodes)
{
    for (auto &x : nodes)
        std::cout << x << " ";
    std::cout << std::endl;
}

template <class T>
BinaryTree<T> *BinaryTree<T>::getLeft()
{
    return this->leftNode;
}
template <class T>
BinaryTree<T> *BinaryTree<T>::getRight()
{
    return this->rightNode;
}

template <class T>
int BinaryTreeHeight(BinaryTree<T> * root)
{
    if(root == NULL)
        return 0;
    
    else
        return std::max(height(root->leftNode),height(root->rightNode))+1;
}

template <class T>
void getNodesAtGivenDist(BinaryTree<T>* root , int K, std::vector<T> &nodes)
{
    if(root==NULL)
        return;
    if(K==0)
        nodes.push_back(root->key);
    else
    {
        getNodesAtGivenDist<T>(root->leftNode,K-1,nodes);
        getNodesAtGivenDist<T>(root->rightNode,K-1,nodes);
    }
}

template <class T>

void levelOrderTraversal(BinaryTree<T>* root, std::vector<T> &nodes)
{
    if(root == NULL)
        return;
    std::queue< BinaryTree<T>* > q;
    q.push(root);
    while( q.empty() == false)
    {
        BinaryTree<T> * curr = q.front();
        q.pop();
        nodes.push_back(curr->key);
        if(curr->leftNode != NULL)
            q.push(curr->leftNode);
        if(curr->rightNode != NULL)
            q.push(curr->rightNode);
        
    }
    
}

template <class T>
void levelOrderTraversalLineByLine_1 (BinaryTree<T>* root)
{
    if(root == NULL)
        return;
    
    std::queue <BinaryTree<T> * > q;
    q.push(root);
    q.push(NULL);
    while (q.size() >1)
    {
        BinaryTree<T> * curr = q.front();
        q.pop();
        if(curr==NULL)
        {
            std::cout << "\n";
            q.push(NULL);
            continue;
        }

        std::cout << curr->key << " ";
        if(curr->leftNode !=NULL) q.push(curr->leftNode);
        if(curr->rightNode !=NULL) q.push(curr->rightNode);
    }
}
template <class T>
void levelOrderTraversalLineByLine_2(BinaryTree<T> * root)
{
    if(root == NULL) return;
    std::queue<BinaryTree<T>* > q;
    q.push(root);
    while(q.empty()==false)
    {
        int count = q.size();
        for(int i=0 ; i<count; i++)
        {
            BinaryTree<T>* curr = q.front();
            q.pop();
            std::cout << curr->key << " ";

            if(curr->leftNode != NULL) q.push(curr->leftNode);
            if(curr->rightNode != NULL) q.push(curr->rightNode);
        }
    }
}


template< class T>
int getSizeInNodes(BinaryTree<T>* root)
{
    if(root == NULL)
        return 0;
    
    else
        return getSizeInNodes(root->leftNode)+getSizeInNodes(root->rightNode)+1;
}

template< class T>
T getMaxValue(BinaryTree<T>* root)
{
    if(root == NULL)
        return INT64_MIN;
    else
        return std::max(root->key,std::max(getMaxValue(root->leftNode),getMaxValue(root->rightNode)));
}



int main(int argc, char **argv)
{
    BinaryTree<int> *root = new BinaryTree<int>(10);
    root->leftNode = new BinaryTree<int>(15);
    root->rightNode = new BinaryTree<int>(20);
    root->leftNode->leftNode=new BinaryTree<int>(30);
    root->leftNode->rightNode=new BinaryTree<int>(400);
    root->rightNode->rightNode = new BinaryTree<int>(50);
    root->rightNode->leftNode = new BinaryTree<int>(40);
    root->rightNode->leftNode->leftNode= new BinaryTree<int>(60);
    root->rightNode->leftNode->rightNode = new BinaryTree<int>(70);
    std::vector<int> keysTable;
    std::vector<int> keysTable1;
    std::vector<int> keysTable2;
    // BinaryTreeInorderTraversal(root,keysTable);
    // BinaryTreePreorderTraversal(root,keysTable1);
    // BinaryTreePostorderTraversal(root,keysTable2);
    // BinaryTreePrint(keysTable);
    // BinaryTreePrint(keysTable1);
    // BinaryTreePrint(keysTable2);

    std::vector<int> keysTable3;
    //getNodesAtGivenDist<int>(root,2,keysTable3);
    levelOrderTraversal(root,keysTable3);
    std::cout << "ddddd";
    BinaryTreePrint(keysTable3);
    

    return 0;
}
