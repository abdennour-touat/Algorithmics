
void deplacer_detaille(Pile *x, Pile *y, char X, char Y)
{

    if (empty(y))
    {
        int temp = pop(x);

        push(y, temp);
        printf(" %c to %c, i: %d\n", X, Y, temp);
    }
    else
    {
        if (empty(x))
        {
            int temp = pop(y);
            push(x, temp);
            printf(" %c to %c, i: %d\n", Y, X, temp);
        }
        else
        {
            int temp1 = pop(x);
            int temp2 = pop(y);
            if (temp1 > temp2)
            {
                push(x, temp1);
                push(x, temp2);
                printf(" %c to %c, i: %d\n", Y, X, temp2);
            }
            else
            {
                push(y, temp2);
                push(y, temp1);
                printf(" %c to %c, i: %d\n", X, Y, temp1);
            }
        }
    }
}
void tour_hanoi_iterative_detaille(int no, Pile *a, Pile *c, Pile *b, char A, char C, char B)
{
    if (no % 2 == 1)
    {
        deplacer_detaille(a, c, A, C);
    }

    while (!empty(a) || !empty(b))
    {
        if (no % 2 == 1)
        {
            deplacer_detaille(a, b, A, B);
            deplacer_detaille(b, c, B, C);
            deplacer_detaille(a, c, A, C);
        }
        else
        {
            deplacer_detaille(a, b, A, B);
            deplacer_detaille(a, c, A, C);
            deplacer_detaille(b, c, B, C);
        }
    }
}