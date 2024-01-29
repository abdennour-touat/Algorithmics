/**
 * fonction deplacer
 * @param Pile x
 * @param Pile y
 *nous comparons le haut des deux piles et décidons ensuite de ce qu'il faut déplacer.
 * nous déplaçons vers la pile qui n'est pas vide
 * si les deux piles ne sont pas vides, nous déplaçons la valeur minimale du sommet de la pile.
 */
void deplacer(Pile *x, Pile *y)
{
    if (empty(y))
    {
        push(y, pop(x));
    }
    else
    {
        if (empty(x))
        {
            push(x, pop(y));
        }
        else
        {
            if (x->T[x->debut] > y->T[y->debut])
            {
                push(x, pop(y));
            }
            else
            {
                push(y, pop(x));
            }
        }
    }
}
/**
 * fonction tour_hanoi_iterative
 * @param int no : nombre de disque
 * @param Pile a
 * @param Pile b
 * @param Pile c
 * nous vérifions d'abord la parité du nombre de piles
 * si la pile est une paire : on se deplace entre  : A à B , A à C et ensuite B à C
 * si elle est impaire : alors on se déplace entre : A à C , A à B et ensuite B à C
 */
void tour_hanoi_iterative(int no, Pile *a, Pile *c, Pile *b)
{
    if (no % 2 == 1)
    {
        deplacer(a, c);
        while (!empty(a) || !empty(b))
        {
            deplacer(a, b);
            deplacer(b, c);
            deplacer(a, c);
        }
    }
    else
    {

        while (!empty(a) || !empty(b))
        {
            deplacer(a, b);
            deplacer(a, c);
            deplacer(b, c);
        }
    }
}