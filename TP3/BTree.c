#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"
#include "pile.h"
#include "file.h"
#include <limits.h>
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
BTree inserer_val(int *list, int start, int end)
{
	BTree T = NULL;
	if (start >= end)
		return NULL;
	int val = list[start];
	T = makeNode(val, NULL, NULL);
	if (start % 2 == 0)
	{
		T->left = inserer_val(list, start + 1, end);
	}
	else
	{
		T->right = inserer_val(list, start + 1, end);
	}
	return T;
}

void prefixe(BTree root)
{
	if (root == NULL)
		return;
	// if (rightChild(root))
	// {
	// 	printf("\t\\");
	// }
	// if (leftChild(root))
	// {
	// 	printf("//\n");
	// }
	printf("%d->", root->elem);
	prefixe(root->left);
	// printf("\t");
	prefixe(root->right);
}
// recursive
// la complexite:
/**
 * dans le pire cas on compare tout les noeud des 2 arbres et donc on fait un appel recursive n fois => O(N)
 */
int equalBTrees(BTree bt1, BTree bt2)
{
	if (isEmptyBTree(bt1) && isEmptyBTree(bt2))
		return 1;

	if (!isEmptyBTree(bt1) && !isEmptyBTree(bt2))
		return (bt1->elem == bt2->elem) && equalBTrees(bt1->left, bt2->left) && equalBTrees(bt1->right, bt2->right);

	return 0;
}
// iterrative
/**
 * on empile tout les noeuds dans la pile et donc O(N)
 */
int equalBTreesIter(BTree bt1, BTree bt2)
{
	// si les 2 arbres sont vide alors vrai
	if (isEmptyBTree(bt1) && isEmptyBTree(bt2))
		return 1;
	// si une arbre a des fils et l'autre non donc fausse
	if (isEmptyBTree(bt1) || isEmptyBTree(bt2))
		return 0;
	// initialiser la pile
	pile *p = (pile *)malloc(sizeof(pile));
	initPile(p);
	// empiler les tetes des piles
	empiler(p, bt1);
	empiler(p, bt2);

	while (!pileVide(p))
	{
		// depiler les noeuds
		BTree b1 = depiler(p);
		BTree b2 = depiler(p);
		// elem diff => fausse
		if (b1->elem != b2->elem)
		{
			return 0;
		}
		// si les 2 noeuds ont des fils gauche, donc on empiler les fils pour les comparer
		if (!(isEmptyBTree(leftChild(b1))) && !(isEmptyBTree(leftChild(b2))))
		{
			empiler(p, b1->left);
			empiler(p, b2->left);
		}
		else
		{
			// si un noeud a un fils gauche et l'autre non donc c fausse
			if (((isEmptyBTree(leftChild(b1))) && !(isEmptyBTree(leftChild(b2)))) || (!(isEmptyBTree(leftChild(b1))) && (isEmptyBTree(leftChild(b2)))))
			{
				return 0;
			}
		}
		// meme chose mais pour les fils droits
		if (!isEmptyBTree(rightChild(b1)) && !isEmptyBTree(rightChild(b2)))
		{
			empiler(p, b1->right);
			empiler(p, b2->right);
		}
		else
		{
			if ((isEmptyBTree(rightChild(b1)) && !isEmptyBTree(rightChild(b2))) || (!isEmptyBTree(rightChild(b1))) && (isEmptyBTree(rightChild(b2))))
			{
				return 0;
			}
		}
	}
	return 1;
}
// qst2
// recursive
/*
	dans le pire cas on compare
*/
int isSubTree(BTree sbt, BTree bt)
{
	// les elems sont egeaux
	if (bt->elem == sbt->elem)
	{
		// printf("bt: %d sbt : %d\n", bt->elem, sbt->elem);
		// si on a arrive a la fin de la sous arbre donc vraie
		if (leftChild(sbt) == NULL && rightChild(sbt) == NULL)
			return 1;
		else if (equalBTrees(sbt, bt))
		{
			return 1;
		}
		else

		{
			// si sous arbre a un fils gauche donc on compare le fils gauche de sous liste avec le fils gauche de l'arbre (hna wa9il nrmlm nzid nverifier si l'arbre a un fils gauche)
			if (leftChild(sbt) != NULL)
				isSubTree(leftChild(sbt), leftChild(bt));
			else
			{
				// mm chose pour fils droit
				if (rightChild(sbt) != NULL)
					isSubTree(rightChild(sbt), rightChild(bt));
			}
		}
	}
	else
	{
		// si l'arbre n'a pas encore arrive a les feuilles on teste sinon c fausse
		if (leftChild(bt) != NULL)
		{
			isSubTree(sbt, leftChild(bt));
		}
		else
		{
			if (rightChild(bt) != NULL)
			{
				isSubTree(sbt, rightChild(bt));
			}
			else
			{
				return 0;
			}
		}
	}
}
// iterative
int isSubTreeIter(BTree sbt, BTree bt)
{
	if (isEmptyBTree(sbt) && isEmptyBTree(bt))
		return 1;
	if (isEmptyBTree(bt) || isEmptyBTree(sbt))
		return 0;
	pile *p = (pile *)malloc(sizeof(pile));
	initPile(p);
	empiler(p, sbt);
	empiler(p, bt);
	while (!pileVide(p))
	{
		BTree b = depiler(p);
		BTree sb = depiler(p);
		printf("sb: %d, b = %d\n", sb->elem, b->elem);
		// si les elements sont egeaux

		// si on a arrive a la fin de sous arbre donc c vraie
		if (equalBTreesIter(sb, b))
			return 1;
		// else if (leftChild(sb) != NULL)
		// {
		// 	// sinon on verifer si le sous arbre a des fils gauche(droits) et l'empiler avec les files gauches(droits) de l'arbre
		// 	empiler(p, leftChild(sb));
		// 	empiler(p, leftChild(b));
		// }
		// else
		// {
		// 	if (rightChild(sb) != NULL)
		// 	{
		// 		empiler(p, rightChild(sb));
		// 		empiler(p, rightChild(b));
		// 	}
		// }

		else
		{
			// si les elems sont pas egeaux alors
			if (leftChild(b) != NULL)
			{
				// si l'arbre a des fils gauches(droits) alors on les empiles pour les comparer avec le sous arbre sinon c fausse
				empiler(p, sb);
				empiler(p, leftChild(b));
			}
			else
			{
				if (rightChild(b) != NULL)
				{
					printf("hello");
					empiler(p, sb);
					empiler(p, rightChild(b));
				}
				else
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

// qst 3
// recursive
int findElem(BTree bt, Element e)
{
	if (isEmptyBTree(bt))
		return 0;
	return (bt->elem == e) || findElem(leftChild(bt), e) || findElem(rightChild(bt), e);
}
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
		return INT_MIN;
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
		printf("%d->", node->elem);
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
	}
}
int main()
{
	BTree tr1, tr2 = NULL;
	// int list[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	// int list2[] = {0, 1, 2, 3, 99, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	// tr = inserer_val(list, 0, sizeof(list) / sizeof(int));
	// tr2 = inserer_val(list2, 0, sizeof(list) / sizeof(int));

	tr1 = makeLeaf(5);
	tr1->left = makeLeaf(34);
	tr1->right = makeLeaf(99);
	tr1->left->left = makeLeaf(3435);
	tr1->left->right = makeLeaf(88);
	tr1->right->left = makeLeaf(32);
	tr1->right->left = makeLeaf(9934);

	tr1->left->left->left = makeLeaf(432);
	tr1->left->right->right = makeLeaf(134);
	tr1->right->left->left = makeLeaf(9437);
	tr1->right->left->right = makeLeaf(34);

	tr2 = makeLeaf(5);
	tr2->left = makeLeaf(34);
	tr2->right = makeLeaf(99);
	tr2->left->left = makeLeaf(3435);
	tr2->left->right = makeLeaf(88);
	tr2->right->left = makeLeaf(32);
	tr2->right->left = makeLeaf(9934);

	tr2->left->left->left = makeLeaf(432);
	tr2->left->right->right = makeLeaf(134);
	tr2->right->left->left = makeLeaf(9437);
	tr2->right->left->right = makeLeaf(34);
	// prefixe(tr);
	// printf("------\n");
	// prefixe(tr2);
	// printf("------\n");
	// printf("equal iter: %d\n\n", equalBTreesIter(tr1, tr2));
	// printf("equal rec: %d\n\n", equalBTrees(tr1, tr2));
	// printf("---------qst2----------\n\n");

	int tlist[] = {0, 5, 26, 345, 445, 522, 687, 74543, 824, 925, 1550, 12451, 14352, 12543, 14543, 152345, 12226};
	int slist[] = {3, 4, 5, 6, 7, 8, 9, 34};
	BTree Ar1, Ar2 = NULL;
	// Ar1 = inserer_val(tlist, 0, sizeof(tlist) / sizeof(int));
	// Ar2 = inserer_val(slist, 0, sizeof(slist) / sizeof(int));
	Ar1 = makeLeaf(18);
	Ar1->left = makeLeaf(15);
	Ar1->right = makeLeaf(100);
	Ar1->left->left = makeLeaf(31);
	Ar1->left->left->right = makeLeaf(2);
	Ar1->left->left->left = makeLeaf(10);
	Ar1->left->left->right->right = makeLeaf(22);
	Ar1->left->left->right->right->left = makeLeaf(31);
	Ar1->left->right = makeLeaf(77);
	Ar1->left->right->left = makeLeaf(6);
	Ar1->right = makeLeaf(100);
	Ar1->right->right = makeLeaf(28);
	Ar1->right->left = makeLeaf(12);

	// Ar2 = makeLeaf(5);
	// Ar2->left = makeLeaf(34);
	// Ar2->right = makeLeaf(99);
	// Ar2->left->left = makeLeaf(3435);
	// Ar2->left->right = makeLeaf(8887);
	// Ar2->right->left = makeLeaf(32);
	// Ar2->right->left = makeLeaf(9934);

	// Ar2->left->left->left = makeLeaf(432);
	// Ar2->left->right->right = makeLeaf(134);
	// Ar2->right->left->left = makeLeaf(9437);
	// Ar2->right->left->right = makeLeaf(34);
	// prefixe(Ar1);
	printf("\n");
	// prefixe(Ar1);
	// printf("\n");
	// print2D(Ar1);
	// printf("is sub tree iter: %d\n", isSubTreeIter(Ar2, Ar1));
	// printf("is sub tree rec: %d\n", isSubTree(Ar2, Ar1));
	int x = 3432;
	int y = 31;
	printf("%d existe ? : %d\n", x, findElemIter(Ar1, x));
	printf("%d existe ? : %d\n", y, findElemIter(Ar1, y));
	printf("the minimum is : %d\n", findMin(Ar1));

	// printf("the min is %d\n", printWidthOrder(Ar1));
	printWidthOrderRec(Ar1);
	// printWidthOrderRec(Ar1);
	// printWidthOrder(Ar1);
}
