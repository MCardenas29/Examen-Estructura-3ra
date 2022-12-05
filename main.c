#include <stdlib.h>
#include <stdio.h>

struct node {
	struct node* left;
	struct node* right;
	int level;
	int data;
};

struct node* new_node(int data);
void insert_node(struct node* root, struct node* node);
int search(struct node* tree, int data);

int main() {
	struct node* tree = new_node(6);
	insert_node(tree, new_node(5));
	insert_node(tree, new_node(11));
	insert_node(tree, new_node(4));
	insert_node(tree, new_node(3));
	insert_node(tree, new_node(8));
	insert_node(tree, new_node(12));
	insert_node(tree, new_node(9));
	insert_node(tree, new_node(21));
	
	return 0;
}


struct node* new_node(int data) {
	struct node* node = NULL;
	node = malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->level = 1;
	node->data = data;
	return node;
}

void insert_node(struct node* root, node* node) {
	if (node->data > root->data)
		root->right = node;
	else
		root->left = node;
	node->level = root->level + 1;
}

int search(struct node* tree, int data) {
	int l = 0;
	if (tree == NULL)
		return 0;
	if (tree->data == data)
		return tree->level;
	l = search(tree->left);
	if (l > 0)
		return l;
	l = search(tree->right);
	if (l > 0)
		return l;
	return 0;
}
