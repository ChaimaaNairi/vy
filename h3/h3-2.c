#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createTree(char exp[]) {
    int len = strlen(exp);
    Node* stack[len];
    int top = -1;
     for (int i = 0; i < len; i++) {
            Node* node = (Node*) malloc(sizeof(Node));
            node->data = exp[i];
            node->left = NULL;
            node->right = NULL;

    if (isalnum(exp[i])) {
                stack[++top] = node;
            } else {
                Node* right = stack[top--];
                Node* left = stack[top--];

                node->left = left;
                node->right = right;
                stack[++top] = node;
            }
        }

    return stack[top];
}

void printTree(Node* node, int space) {
    if (node == NULL) {
        return;
    }

    space += 4;
printTree(node->right, space);
    printf("\n");

    for (int i = 4; i < space; i++) {
        printf(" ");
    }

    printf("%c\n", node->data);

    printTree(node->left, space);
}

    
int main() {
    // Ağacın örneği
    struct Node* root = buildTree();

    // Ağacın inorder traversiyle ifadesi yazdırılır.
    printf("Inorder traversal ile ağaç yazdırılıyor:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}