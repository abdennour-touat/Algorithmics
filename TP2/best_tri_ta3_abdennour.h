#include <stdio.h>

void permute(int *xp, int *yp)
{
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

int partition(int A[], int start, int end)
{
   int i = start + 1;
   int piv = A[start]; // make the first element as pivot element.
   for (int j = start + 1; j <= end; j++)
   {
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

/* function to implement quick sort */
void quick(int A[], int debut, int fin)
{
   while (debut < fin)
   {
      int q = partition(A, debut, fin);
      if (q - debut <= fin - (q + 1))
      {
         quick(A, debut, q);
         debut = q + 1;
      }
      else
      {
         quick(A, q + 1, fin);
         fin = q;
      }
   }
   // if (start < end)
   // {
   //    // stores the position of pivot element
   //    int piv_pos = partition(A, start, end);
   //    quick(A, start, piv_pos - 1); // sorts the left side of pivot.
   //    quick(A, piv_pos + 1, end);   // sorts the right side of pivot.
   // }
