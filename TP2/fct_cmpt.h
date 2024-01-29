#include <time.h>
long long cmp = 0;
void permute(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// Ouiza
int Tri_insertionmodifie(int T[], int size)
{
    int i, j;
    int x;
    int cmp = 0;
    for (i = 1; i < (size); i++)
    {
        x = T[i];
        j = i - 1;
        cmp++;
        while (j >= 0 && T[j] > x)
        {
            T[j + 1] = T[j];
            j--;
            cmp++;
        }

        T[j + 1] = x;
    }
    return cmp;
}
// rapide pivot=N
// int cmp;
int partitionNmodifie(int A[], int start, int end)
{
    int i = end - 1;
    int piv = A[end]; // pivot=dernier element
    for (int j = end; j >= start; j--)
    {
        cmp++;
        if (A[j] > piv)
        {
            permute(&A[i], &A[j]);
            i -= 1;
        }
    }
    permute(&A[end], &A[i + 1]);
    return i; // position dÃ©coupage
}
// il faut initialiser cmp=0 avant l'appel de cette fonctions
void quickNmodifie(int A[], int p, int r)
{
    while (p < r)
    {
        int q = partitionNmodifie(A, p, r);

        if (q - p <= r - (q + 1))
        {
            quickNmodifie(A, p, q);
            p = q + 1;
        }
        else
        {
            quickNmodifie(A, q + 1, r);
            r = q;
        }
    }
}
// abdennour
long long tri_selectionmodifie(int arr[], int n)
{
    int i, j, min_idx;
    long long cmp;

    // boucler le tableau
    for (i = 0; i < n - 1; i++)
    {
        // trouver le minimum
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
            cmp++;
        }

        // permuter le minimum avec le premier element
        if (min_idx != i)
            permute(&arr[min_idx], &arr[i]);
    }
    return cmp;
}
int partition0modifie(int A[], int start, int end)
{
    int i = start + 1;
    int piv = A[start]; // make the first element as pivot element.
    for (int j = start + 1; j <= end; j++)
    {
        cmp++;
        /*rearrange the array by putting elements which are less than pivot
           on one side and which are greater that on other. */

        if (A[j] < piv)
        {
            permute(&A[i], &A[j]);
            i += 1;
        }
    }
    permute(&A[start], &A[i - 1]); // put the pivot element in its proper place.
    return i - 1;                  // return the position of the pivot
}
// il faut initialiser cmp=0 avant l'appel de cette fonctions
void quick0modifie(int A[], int p, int r)
{
    while (p < r)
    {
        int q = partition0modifie(A, p, r);

        if (q - p <= r - (q + 1))
        {
            quick0modifie(A, p, q);
            p = q + 1;
        }
        else
        {
            quick0modifie(A, q + 1, r);
            r = q;
        }
    }
}
// maya
int Tri_bulle_modifie(int T[], int n)
{
    int i, temp, cpt = 0;
    while (n >= 2)
    {
        i = 0;
        while (i < n - 1)
        {
            cpt++;
            if (T[i + 1] < T[i])
            {

                temp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = temp;
            }
            i++;
        }
        n--;
    }
    return cpt;
}
int Tamiser_modifie(int T[], int i, int n)
{
    int temp, d, cpt = 0;
    d = 2 * i + 1;
    while (d <= n)
    {
        cpt = cpt + 2;
        if (d < n && T[d] < T[d + 1])
        {
            d++;
        }
        if (T[i] < T[d])
        {
            temp = T[i];
            T[i] = T[d];
            T[d] = temp;
            i = d;
            d = 2 * i + 1;
        }
        else
        {
            d = n + 1;
        }
    }
    return cpt;
}
int Tri_tas_modifie(int T[], int n)
{
    int temp, cpt = 0;
    for (int i = n / 2; i >= 0; i--)
    {
        cpt = cpt + Tamiser_modifie(T, i, n);
    }
    for (int i = n; i >= 1; i--)
    {
        temp = T[0];
        T[0] = T[i];
        T[i] = temp;
        ;
        cpt += Tamiser_modifie(T, 0, i - 1);
    }
    return cpt;
}
// Hadjer
// il faut initialiser cmp=0 avant l'appel de cette fonctions
int fusionermodifie(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;
    int cpt = 0;

    int L[n1], M[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
        cpt++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
    return cpt;
}

int triFusionmodifie(int arr[], int l, int r)
{
    static int cmp = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        triFusionmodifie(arr, l, m);
        triFusionmodifie(arr, m + 1, r);

        cmp = cmp + fusionermodifie(arr, l, m, r);
    }
    return cmp;
}

int partition2modifie(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {

        do
        {
            cmp++;
            i++;
        } while (arr[i] < pivot);

        do
        {
            cmp++;
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition_rmodifie(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;

    return partition2modifie(arr, low, high);
}
void quickSortmodifie(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_rmodifie(arr, low, high);

        quickSortmodifie(arr, low, pi);
        quickSortmodifie(arr, pi + 1, high);
    }
}