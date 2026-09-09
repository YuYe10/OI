#include <iostream>  
#include <vector>  
#include <unordered_map>  
#include <algorithm>

using namespace std;  

// 定义树的结构  
struct TreeNode {  
    int value;  
    TreeNode* left;  
    TreeNode* right;  
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}  
};  

// 函数：构建二叉树  
TreeNode* buildTree(const vector<int>& parents, vector<int>& inorder) {  
    int n = parents.size();  
    unordered_map<int, TreeNode*> nodes;  

    // 创建所有节点  
    for (int i = 1; i <= n; ++i) {  
        nodes[i] = new TreeNode(i);  
    }  

    // 建立父子关系  
    for (int i = 1; i <= n; ++i) {  
        if (parents[i - 1] != 0) {  
            if (nodes[parents[i - 1]]->left == nullptr && nodes[parents[i - 1]]->right == nullptr) {  
                vector<int>::iterator it_i = find(inorder.begin(), inorder.end(), i);
                vector<int>::iterator it_r = find(inorder.begin(), inorder.end(), parents[i-1]);
                int index_i = static_cast<int>(it_i - inorder.begin());
                int index_r = static_cast<int>(it_r - inorder.begin());
                if(index_i > index_r)
                    nodes[parents[i - 1]]->right = nodes[i];
                else
                    nodes[parents[i - 1]]->left = nodes[i];
            } else if(nodes[parents[i - 1]]->left == nullptr && nodes[parents[i - 1]]->right != nullptr){  
                nodes[parents[i - 1]]->left = nodes[i];  
            } else if(nodes[parents[i - 1]]->left != nullptr && nodes[parents[i - 1]]->right == nullptr){  
                nodes[parents[i - 1]]->right = nodes[i];  
            }   
        }  
    }  

    // 返回根节点  
    return nodes[1];  
}  

//中序遍历
/*void inOrder(TreeNode* root, vector<int>& result){
    if (root == nullptr) return; 
    inOrder(root->left, result); 
    result.push_back(root->value);  
    inOrder(root->right, result);
}*/

// 先序遍历  
void preOrder(TreeNode* root, vector<int>& result) {  
    if (root == nullptr) return;  
    result.push_back(root->value);  
    preOrder(root->left, result);  
    preOrder(root->right, result);  
}  

// 后序遍历  
void postOrder(TreeNode* root, vector<int>& result) {  
    if (root == nullptr) return;  
    postOrder(root->left, result);  
    postOrder(root->right, result);  
    result.push_back(root->value);  
}  

int main() {  
    int n;  
    cin >> n;  

    vector<int> parents(n);  
    for (int i = 0; i < n; ++i) {  
        cin >> parents[i];  
    }  

    vector<int> inorder(n);  
    for (int i = 0; i < n; ++i) {  
        cin >> inorder[i];  
    }  

    // 创建二叉树  
    TreeNode* root = buildTree(parents, inorder);  

    // 获取先序和后序遍历  
    vector<int> in_result;
    vector<int> pre_result;  
    vector<int> post_result;  
    //inOrder(root, in_result);
    preOrder(root, pre_result);  
    postOrder(root, post_result);  

    // 输出结果  
    /*for (int val : in_result) {  
        cout << val << " ";  
    }  
    cout << endl;*/
    for (int val : pre_result) {  
        cout << val << " ";  
    }  
    cout << endl;  
    for (int val : post_result) {  
        cout << val << " ";  
    }  
    cout << endl;  

    return 0;  
}