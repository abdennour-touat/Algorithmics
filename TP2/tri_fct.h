#include <stdio.h>
#include <time.h>
#define size1 500000
// lysa
int cmp;
void Tri_insertion(int T[size1])
{
    int i, j;
    int x;
    cmp = 0;
    for (i = 1; i < (size1); i++)
    {
        x = T[i];
        j = i - 1;

        while (j >= 0 && T[j] > x)
        {
            T[j + 1] = T[j];
            j--;
            cmp++;
        }

        T[j + 1] = x;
    }
}
int partition(int T[], int deb, int fin)
{
    int i, j, piv, temp;
    piv = T[fin]; // choix du pivot : dernier element
    j = fin;
    i = deb;

    while (i < j)
    {
        while (T[i] < piv && i < j)
        {
            i++;
            cmp++;
        }
        while (T[j] >= piv)
        {
            j--;
            cmp++;
        }

        if (i < j)
        {
            temp = T[i];
            T[i] = T[j];
            T[j] = temp;
        }
    }
    T[fin] = T[i];
    T[i] = piv;

    return i;
}
void Tri_rapideN(int T[], int deb, int fin)
{
    int i;

    if (deb < fin)
    {
        i = partition(T, deb, fin);

        Tri_rapideN(T, deb, i - 1);

        Tri_rapideN(T, i + 1, fin);
        // printf("%d \t",i);
    }
}
// abdennour
void permute(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void tri_selection(int arr[], int n)
{
    int i, j, min_idx;

    // boucler le tableau
    for (i = 0; i < n - 1; i++)
    {
        // trouver le minimum
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // permuter le minimum avec le premier element
        if (min_idx != i)
            permute(&arr[min_idx], &arr[i]);
    }
}

// fonction de partition
int partition1(int arr[], int inf, int sup)
{
    int pivot, debut, fin;
    pivot = arr[inf]; // pivot au debut
    debut = inf;
    fin = sup;

    while (debut < fin)
    {
        while (arr[debut] <= pivot && debut < fin)
        {
            debut++; // debut deplace vers la droite
        }

        while (arr[fin] > pivot)
        {
            fin--; // fin deplace vers la gauche
        }

        if (debut < fin)
        {
            permute(&arr[debut], &arr[fin]); // permuter la valeur supperieur et inferieur
        }
    }

    arr[inf] = arr[fin];
    arr[fin] = pivot;
    return fin;
}

void tri_rapide0(int arr[], int gauche, int droit)
{
    int q;

    if (gauche < droit)
    {
        q = partition1(arr, gauche, droit);
        tri_rapide0(arr, gauche, q - 1); // tri sous tableau gauche
        tri_rapide0(arr, q + 1, droit);  // tri sous tableau droit
    }
}
// maya
void Tri_bulle(int T[], int n)
{
    int i, temp;
    while (n >= 2)
    {
        i = 0;
        while (i < n - 1)
        {
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
}
void Tamiser(int T[], int i, int n)
{
    int temp, d;
    d = 2 * i + 1;
    while (d <= n)
    {
        if (d < n && T[d] < T[d + 1])
        {
            d++;
        }
        if (T[i] < T[d])
        {
            temp = T[i];
            T[i] = T[d];
            T[d] = temp;
            ;
            i = d;
            d = 2 * i + 1;
        }
        else
        {
            d = n + 1;
        }
    }
}
void Tri_tas(int T[], int n)
{
    int temp;
    for (int i = n / 2; i >= 0; i--)
    {
        Tamiser(T, i, n);
    }
    for (int i = n; i >= 1; i--)
    {
        temp = T[0];
        T[0] = T[i];
        T[i] = temp;
        ;
        Tamiser(T, 0, i - 1);
    }
}
// hadjer
void fusioner(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;

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
}

void triFusion(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        triFusion(arr, l, m);
        triFusion(arr, m + 1, r);

        fusioner(arr, l, m, r);
    }
}

int partition2(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int partition_r(int arr[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);
    int temp = arr[random];
    arr[random] = arr[low];
    arr[low] = temp;

    return partition2(arr, low, high);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_r(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}
