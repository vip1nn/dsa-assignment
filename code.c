#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char id[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char id[])
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, char id[])
{
    if(root == NULL)
        return createNode(id);

    if(strcmp(id, root->id) < 0)
        root->left = insert(root->left, id);
    else
        root->right = insert(root->right, id);

    return root;
}

void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->id);
        inorder(root->right);
    }
}

int bstSearch(struct Node *root, char key[], int *comparisons)
{
    while(root != NULL)
    {
        (*comparisons)++;

        if(strcmp(key, root->id) == 0)
            return 1;

        if(strcmp(key, root->id) < 0)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

int linearSearch(char ids[][20], int n, char key[], int *comparisons)
{
    int i;

    for(i = 0; i < n; i++)
    {
        (*comparisons)++;

        if(strcmp(ids[i], key) == 0)
            return 1;
    }

    return 0;
}

int main()
{
    char ids[][20] = {
        "A102", "A25", "A7", "B100",
        "B12", "A120", "B3", "A45"
    };

    int n = 8;
    int i, bstComp, linearComp;
    char key[20];

    struct Node *root = NULL;

    for(i = 0; i < n; i++)
        root = insert(root, ids[i]);

    printf("Identification Numbers:\n");
    for(i = 0; i < n; i++)
        printf("%s ", ids[i]);

    printf("\n\nInorder Traversal:\n");
    inorder(root);

    printf("\n\nSearch Comparison:\n");

    strcpy(key, "B12");
    bstComp = 0;
    linearComp = 0;

    bstSearch(root, key, &bstComp);
    linearSearch(ids, n, key, &linearComp);

    printf("\nKey: %s", key);
    printf("\nBST comparisons: %d", bstComp);
    printf("\nLinear Search comparisons: %d\n", linearComp);

    strcpy(key, "A45");
    bstComp = 0;
    linearComp = 0;

    bstSearch(root, key, &bstComp);
    linearSearch(ids, n, key, &linearComp);

    printf("\nKey: %s", key);
    printf("\nBST comparisons: %d", bstComp);
    printf("\nLinear Search comparisons: %d\n", linearComp);

    strcpy(key, "C10");
    bstComp = 0;
    linearComp = 0;

    bstSearch(root, key, &bstComp);
    linearSearch(ids, n, key, &linearComp);

    printf("\nKey: %s (not present)", key);
    printf("\nBST comparisons: %d", bstComp);
    printf("\nLinear Search comparisons: %d\n", linearComp);

    return 0;
}
