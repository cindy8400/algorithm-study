#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


char tree[26][2] = { '.', };
int N;

void preorder(char root) {
	if (root == '.') return;
	
	printf("%c", root);
	preorder(tree[root - 'A'][0]);
	preorder(tree[root - 'A'][1]);
}

void inorder(char root) {
	if (root == '.') return;

	inorder(tree[root - 'A'][0]);
	printf("%c", root);
	inorder(tree[root - 'A'][1]);
}

void postorder(char root) {
	if (root == '.') return;

	postorder(tree[root - 'A'][0]);
	postorder(tree[root - 'A'][1]);
	printf("%c", root);
}


int main() {
	char root, left, right;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %c %c %c", &root, &left, &right);
		tree[root - 'A'][0] = left;
		tree[root - 'A'][1] = right;
	}

	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');

	return 0;
}