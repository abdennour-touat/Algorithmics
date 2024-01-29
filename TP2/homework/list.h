#include <stdio.h>
#include <stdlib.h>
#ifndef PARSER_H
#define PARSER_H
typedef struct noeud
{
    int val;
    struct noeud *suiv;
} noeud;

// noeud *creer_noeud()
// {
//     noeud *nd;
//     nd = (noeud *)malloc(sizeof(noeud));
//     return nd;
// }
#endif