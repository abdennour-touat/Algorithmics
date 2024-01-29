#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int partition(int arr[], int low, int high)
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

  return partition(arr, low, high);
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
void Tri_rapide(int T[], int deb, int fin)
{
  int i;
  if (deb < fin)
  {
    i = partition(T, deb, fin);
    Tri_rapide(T, deb, i - 1);
    Tri_rapide(T, i + 1, fin);
  }
}
void Tri_insertion(int T[])
{
  int i, j;
  int x;
  for (i = 2; i < (-1); i++)
  {
    x = T[i];
    j = i - 1;
    while (j >= 0 && T[j] > x)
    {
      T[j + 1] = T[j];
      j--;
    }
    T[j + 1] = x;
  }
}
