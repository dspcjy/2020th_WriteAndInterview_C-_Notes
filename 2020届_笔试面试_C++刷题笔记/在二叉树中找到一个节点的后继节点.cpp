#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
/*
题目：在二叉树中找到一个节点的后继节点。
 *  该结构比普通二叉树节点结构多了一个指向父节点的parent指针。假
	设有一 棵BTreeNode *类型的节点组成的二叉树，树中每个节点的parent指针
	都正确地指向 自己的父节点，头节点的parent指向nullptr。只给一个在
	二叉树中的某个节点 node，请实现返回node的后继节点的函数。

	后继节点：在二叉树的中序遍历的序列中，node的下一个节点叫作node的后继节点。
	前继节点：在二叉树的中序遍历的序列中，node的上一个节点叫作node的前继节点。
思路：
	方法一：利用node结点的parent指针，找到头结点，然后利用中序遍历，找到node结点，然后找到它的下一个结点
	方法二：
	找前驱结点  分类讨论左孩子
　　找后继结点，分类讨论右孩子
	1->若节点X有右子树，那它的后继结点就是它的右子树中最左的结点（若它的右子树没有左子树，那就是右子树本身）
	2->若节点X没有右子树，则向上循环遍历到该节点所在左子树的根。
*/
static struct BTreeNode
{
	int value;
	BTreeNode *left;
	BTreeNode *right;
	BTreeNode *parent;

	BTreeNode(int data)
	{
		this->value = data;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
	}
};

// 递归：中序
static void inOrderRecur(BTreeNode *head)
{
	if (head == nullptr) {
		return;
	}
	inOrderRecur(head->left);
	cout << head->value << " ";
	inOrderRecur(head->right);
}

// 右节点为空则找最左节点
static BTreeNode * getLeftMost(BTreeNode * node) 
{
	if (node == nullptr) {
		return node;
	}
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

// 找后继节点
static BTreeNode * getSuccessorNode(BTreeNode * node) 
{
	if (node == nullptr) {
		return node;
	}
	if (node->right != nullptr) {
		return getLeftMost(node->right);
	}
	else {//右节点为空
		BTreeNode * parent = node->parent;
		while (parent != nullptr && parent->left != node) {
			node = parent;
			parent = node->parent;
		}
		return parent;
	}
}


int main0202021122101255(void)
{

	BTreeNode * head = new BTreeNode(6);
	head->parent = nullptr;
	head->left = new BTreeNode(3);
	head->left->parent = head;
	head->left->left = new BTreeNode(1);
	head->left->left->parent = head->left;
	head->left->left->right = new BTreeNode(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new BTreeNode(4);
	head->left->right->parent = head->left;
	head->left->right->right = new BTreeNode(5);
	head->left->right->right->parent = head->left->right;
	head->right = new BTreeNode(9);
	head->right->parent = head;
	head->right->left = new BTreeNode(8);
	head->right->left->parent = head->right;
	head->right->left->left = new BTreeNode(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new BTreeNode(10);
	head->right->right->parent = head->right;

	cout << "递归—中序：";
	inOrderRecur(head);
	cout << endl;

	BTreeNode * curNode;
	BTreeNode * laterNode;

	curNode = head->left;
	cout << curNode->value << " 的后继节点：";
	laterNode = getSuccessorNode(curNode);
	cout << laterNode->value << endl;
	
	curNode = head->left->left;
	cout << curNode->value << " 的后继节点：";
	laterNode = getSuccessorNode(curNode);
	cout << laterNode->value << endl;

	curNode = head->left->left->right;
	cout << curNode->value << " 的后继节点：";
	laterNode = getSuccessorNode(curNode);
	cout << laterNode->value << endl;

	cout<<"Write By JZQ!"<<endl;
	//自动排版：ctrl+k+F
	return 0;
}