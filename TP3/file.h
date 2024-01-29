
// #ifndef file_h
// #define file_h

// #ifndef sommet_H
// #ifndef idk1_H
// #ifndef idkto1o_H
#define MAX 500
typedef struct file
{
    BTree items[MAX];
    int queue;
    int tete;

} file;
void initFile(file *f)
{
    f->tete = 0;
    f->queue = -1;
}
int isemptyfile(file *f)
{
    if (f->tete > f->queue)
        return 1;
    else
        return 0;
}
int filePleine(file *f)
{
    if (f->tete == MAX && f->tete > f->queue)
        return 1;
    else
        return 0;
}
void enfiler(file *f, BTree bt)
{
    if (filePleine(f))
        printf("la file est pleine");
    else
    {
        f->queue = f->queue + 1;
        f->items[f->queue] = bt;
    }
}
BTree deFiler(file *f)
{
    if (filePleine(f))
        return NULL;
    else
    {
        BTree X = f->items[f->tete];
        f->tete = f->tete + 1;
        return X;
    }
}