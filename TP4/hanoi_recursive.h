
void tour_hanoi_recursive(int no, Pile *A, Pile *C, Pile *B, char a, char c, char b)
{
    if (no == 1)
    {
        int x = pop(A);
        push(C, x);
        printf("%c to %c , i =%d\n", a, c, no);
        return;
    }
    else
    {
        if (no > 1)
        {
            tour_hanoi_recursive(no - 1, A, B, C, a, b, c);
            push(C, pop(A));
            printf("%c to %c i = %d\n", a, c, no);
            tour_hanoi_recursive(no - 1, B, C, A, b, c, a);
        }
    }
}