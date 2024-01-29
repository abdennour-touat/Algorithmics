#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"
#include "pile.h"
#include "file.h"
#include <limits.h>
#include <time.h>

#define COUNT 4

void errorB(char *s)
{
    fprintf(stderr, "%s", s);
    exit(EXIT_FAILURE);
}
/*****************************************************************************/
/**************************** fonctions de base ******************************/
/*****************************************************************************/

BTree makeEmptyBTree(void)
{
    return (BTree)NULL;
}

BTree makeNode(Element e, BTree l, BTree r)
{
    BTree new;
    if ((new = (BTree)malloc(sizeof(Node))) == NULL)
        errorB("Allocation ratée!");
    new->elem = e;
    new->left = l;
    new->right = r;
    return new;
}

BTree makeLeaf(Element e)
{
    return makeNode(e, makeEmptyBTree(), makeEmptyBTree());
}

int isEmptyBTree(BTree bt)
{
    return (bt == NULL);
}

Element root(BTree bt)
{
    if (isEmptyBTree(bt))
        errorB("Pas de noeud à la racine d'un arbre vide!!!");
    return bt->elem;
}

BTree leftChild(BTree bt)
{
    if (isEmptyBTree(bt))
        errorB("Pas de fils gauche dans un arbre vide!!!");
    return bt->left;
}

BTree rightChild(BTree bt)
{
    if (isEmptyBTree(bt))
        errorB("Pas de fils droit dans un arbre vide!!!");
    return bt->right;
}

int isLeaf(BTree bt)
{
    return !isEmptyBTree(bt) && isEmptyBTree(leftChild(bt)) && isEmptyBTree(rightChild(bt));
}

void freeNode(Node *c)
{
    free(c);
}

/*****************************************************************************/
/*************************** fonctions bas niveau ****************************/
/*****************************************************************************/

void insertRight(Node *n, Element e)
{
    if (!isEmptyBTree(n) && isEmptyBTree(rightChild(n)))
        n->right = makeLeaf(e);
    else
        errorB("insertRight impossible!");
}

void insertLeft(Node *n, Element e)
{
    if (!isEmptyBTree(n) && isEmptyBTree(leftChild(n)))
        n->left = makeLeaf(e);
    else
        errorB("insertLeft impossible!");
}

Element deleteRight(Node *n)
{
    if (isEmptyBTree(n) || !isLeaf(rightChild(n)))
        errorB("deleteRight imossible!");

    Element res = root(n->right);
    n->right = makeEmptyBTree();
    return res;
}

Element deleteLeft(Node *n)
{
    if (isEmptyBTree(n) || !isLeaf(leftChild(n)))
        errorB("deleteLeft imossible!");

    Element res = root(n->left);
    n->left = makeEmptyBTree();
    return res;
}

void insertRightmostNode(BTree *bt, Element e)
{
    if (isEmptyBTree(*bt))
        *bt = makeLeaf(e);
    else
    {
        BTree tmp = *bt;
        while (!isEmptyBTree(rightChild(tmp)))
            tmp = rightChild(tmp);
        insertRight(tmp, e);
    }
}

Element deleteLeftmostNode(BTree *bt)
{
    Element res;
    if (isEmptyBTree(*bt))
        errorB("deleteLeftmostNode imossible!");
    if (isEmptyBTree(leftChild(*bt)))
    {
        res = root(*bt);
        *bt = rightChild(*bt);
    }
    else
    {
        BTree tmp = *bt;
        while (!isEmptyBTree(leftChild(leftChild(tmp))))
            tmp = leftChild(tmp);
        res = root(leftChild(tmp));
        tmp->left = (tmp->left)->right;
    }
    return res;
}

// qst 3
// recursive
int findElem(BTree bt, Element e)
{
    if (isEmptyBTree(bt))
        return 0;
    return (bt->elem == e) || findElem(leftChild(bt), e) || findElem(rightChild(bt), e);
}
// version iterative
int findElemIter(BTree bt, Element e)
{
    if (isEmptyBTree(bt))
        return 0;
    pile *p = (pile *)malloc(sizeof(pile));
    initPile(p);
    empiler(p, bt);
    while (!pileVide(p))
    {
        BTree t = depiler(p);
        if (t->elem == e)
            return 1;
        if (!isEmptyBTree(leftChild(t)))
            empiler(p, leftChild(t));
        if (!isEmptyBTree(rightChild(t)))
            empiler(p, rightChild(t));
    }
    return 0;
}
Element findMin(BTree bt)
{
    if (bt == NULL)
        return INT_MAX;
    int res = bt->elem;
    int lres = findMin(bt->left);
    int rres = findMin(bt->right);
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;
    return res;
}
Element findMinIter(BTree bt)
{
    if (isEmptyBTree(bt))
        return INT_MAX;
    pile *p = (pile *)malloc(sizeof(pile));
    initPile(p);
    empiler(p, bt);
    int min = bt->elem;
    while (!pileVide(p))
    {
        BTree t = depiler(p);

        if (!isEmptyBTree(leftChild(t)))
        {
            if (leftChild(t)->elem < min)
            {
                min = leftChild(t)->elem;
            }
            empiler(p, leftChild(t));
        }
        if (!isEmptyBTree(rightChild(t)))
        {
            if (rightChild(t)->elem < min)
            {
                min = rightChild(t)->elem;
            }
            empiler(p, rightChild(t));
        }
    }
    return (Element)min;
}

void printWidthOrder(BTree bt)
{
    if (bt == NULL)
        printf("vide");
    file *f = (file *)malloc(sizeof(file));
    // printf("debut: %d fin : %d", f->debut, f->fin);
    initFile(f);
    enfiler(f, bt);
    while (!isemptyfile(f))
    {
        BTree b = deFiler(f);
        int val = b->elem;
        printf("%d->", val);
        if (b->left != NULL)
        {
            enfiler(f, b->left);
        }
        if (b->right != NULL)
        {
            enfiler(f, b->right);
        }
    }
}
int getLevelCount(BTree node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftMaxLevel = 1 + getLevelCount(node->left);
    int rightMaxLevel = 1 + getLevelCount(node->right);
    if (leftMaxLevel > rightMaxLevel)
    {
        return leftMaxLevel;
    }
    else
    {
        return rightMaxLevel;
    }
}
void printLevel(BTree node, int level)
{
    if (node != NULL && level == 0)
    {
        printf("%d ", node->elem);
    }
    else if (node != NULL)
    {
        printLevel(node->left, level - 1);

        printLevel(node->right, level - 1);
    }
}
void printWidthOrderRec(BTree node)
{
    int i;
    int levelCount = getLevelCount(node);
    for (i = 0; i < levelCount; i++)
    {
        printLevel(node, i);
        printf("\n");
    }
}
BTree insertLevelOrder(int arr[], int i, int n)
{
    BTree root = NULL;
    // Base case for recursion
    if (i < n)
    {
        root = makeNode(arr[i], NULL, NULL);

        // insert left child
        root->left = insertLevelOrder(arr,
                                      2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(arr,
                                       2 * i + 2, n);
    }
    return root;
}
int main()
{
    FILE *f3, *f4, *f5 = NULL;
    f3 = fopen("qst3.csv", "w+");
    f4 = fopen("qst4.csv", "w+");
    f5 = fopen("qst5.csv", "w+");
    fprintf(f3, "taille,tempsrec,tempsiter\n");
    fprintf(f4, "taille,tempsrec,tempsiter\n");
    fprintf(f5, "taille,tempsrec,tempsiter\n");
    time_t t1, t2, t3, t4;
    double delta1, delta2;
    int **list_arr = NULL;
    int nb_lists = 150;
    list_arr = (int **)malloc(sizeof(int *) * nb_lists);
    for (int i = 0; i < nb_lists; i++)
    {
        list_arr[i] = (int *)malloc(sizeof(int) * (i + 1) * 10);
        for (int j = 0; j < (i + 1) * 10; j++)
        {
            list_arr[i][j] = random() % 1000;
        }
    }
    BTree *list_tree = NULL;
    list_tree = (BTree *)malloc(sizeof(BTree) * nb_lists);
    for (int i = 0; i < nb_lists; i++)
    {
        list_tree[i] = insertLevelOrder(list_arr[i], 0, (i + 1) * 10);
    }
    // qst 3
    for (int k = 0; k < nb_lists; k++)
    {
        int x = random() % 10;
        delta2 = 0;
        for (int l = 0; l < 1000; l++)
        {
            t3 = clock();
            findElemIter(list_tree[k], x);
            t4 = clock();
            delta2 += (double)(t4 - t3);
        }
        delta1 = 0;
        for (int l = 0; l < 1000; l++)
        {
            t1 = clock();
            findElem(list_tree[k], x);
            t2 = clock();
            delta1 += (double)(t2 - t1);
        }
        fprintf(f3, "%d,%f,%f\n", (k + 1) * 1000, (delta1 / 1000), (delta2 / 1000));
    }
    // qst4

    for (int k = 0; k < nb_lists; k++)
    {
        delta2 = 0;
        for (int l = 0; l < 1000; l++)
        {
            t3 = clock();
            findMinIter(list_tree[k]);
            t4 = clock();
            delta2 += (double)(t4 - t3);
        }
        delta1 = 0;
        for (int l = 0; l < 1000; l++)
        {
            t1 = clock();
            findMin(list_tree[k]);
            t2 = clock();
            delta1 += (double)(t2 - t1);
        }
        fprintf(f4, "%d,%f,%f\n", (k + 1) * 1000, (delta1 / 1000), (delta2 / 1000));
    }

    for (int k = 0; k < nb_lists; k++)
    {
        delta1 = 0;
        for (int l = 0; l < 50; l++)
        {
            t1 = clock();
            printWidthOrderRec(list_tree[k]);
            t2 = clock();
            delta1 += (double)(t2 - t1);
        }
        delta2 = 0;
        for (int l = 0; l < 70; l++)
        {
            t3 = clock();
            printWidthOrder(list_tree[k]);
            t4 = clock();
            delta2 += (double)(t4 - t3);
        }
        fprintf(f5, "%d,%f,%f\n", (k + 1) * 10, (delta1 / 70), (delta2 / 70));
    }
}