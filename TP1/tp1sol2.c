#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool A1(long long n)
{
	// boolean
	bool premier = true;
	long long i = 2;
	while (i <= n - 1 && premier)
	{
		if (n % i == 0)
		{
			premier = false;
		}
		else
		{
			i++;
		}
	}
	return premier;
}

bool A2(long long n)
{
	// boolean
	bool premier = true;
	long long i = 2;
	while (i <= n / 2 && premier)
	{
		if (n % i == 0)
		{
			premier = false;
		}
		else
		{
			i++;
		}
	}
	return premier;
}
bool A5(long long n)
{
	// boolean
	bool premier = true;
	long long i = 2;
	while (i <= sqrt((double)n) && premier)
	{
		if (n % i == 0)
		{
			premier = false;
		}
		else
		{
			i++;
		}
	}
	return premier;
}
bool A4(long long n)
{
	// boolean
	bool premier = true;
	if (n != 2 && n % 2 == 0)
	{
		premier = false;
	}
	else
	{
		if (n != 2)
		{

			long long i = 3;
			while (i <= n / 2 && premier)
			{
				if (n % i == 0)
				{
					premier = false;
				}
				else
				{
					i = i + 2;
				}
			}
		}
	}
	return premier;
}
bool A3(long long n)
{
	// boolean
	bool premier = true;
	if (n != 2 && n % 2 == 0)
	{
		premier = false;
	}
	else
	{
		if (n != 2)
		{
			long long i = 3;
			while (i <= n - 2 && premier)
			{
				if (n % i == 0)
				{
					premier = false;
				}
				else
				{
					i = i + 2;
				}
			}
		}
	}
	return premier;
}
bool A6(long long n)
{
	// boolean
	bool premier = true;
	if (n != 2 && n % 2 == 0)
	{
		premier = false;
	}
	else
	{
		if (n != 2)
		{
			long long i = 3;
			while (i <= sqrt((double)n) && premier)
			{
				if (n % i == 0)
				{
					premier = false;
				}
				else
				{
					i = i + 2;
				}
			}
		}
	}
	return premier;
}

long main()
{
	// declarer les vars t1 t2 pour calculer le temp d'execution
	clock_t t1, t2;
	double delta;

	// //10 nombres avec des tailles differentes
	// 	long long numero_premier[] = {
	// 	100123456789,
	// 	9000000001,
	// 	2459868287,
	// 	1057438801,
	// 	1000000009,
	// 	22616281,
	// 	1618033,
	// };

	long long numero_premier[] = {
		26183087459,
		9000000001,
		2459868287,
		1057438801,
		1000000009,
		22616281,
		1618033,
	};
	// 20 nombres avec des memmes tailles

	// 	 long long numero_premier[] = {1000000009 ,
	// 1000000021,
	// 1000000087,
	// 1000000181,
	// 1000000861,
	// 2232232273,
	// 2233777723,
	// 2236133941,
	// 2245849783,
	// 2282113373,
	// 2319131071,
	// 2588244151,
	// 2589767209,
	// 2595860413,
	// 2599291451,
	// 2627282963,
	// 8192454631,
	// 8278487999,
	// 8332512563,
	// };

	// long long numero_premier[] = {
	// 8332512563,
	// 8278487999,
	// 8192454631,
	// 2627282963,
	// 2599291451,
	// 2595860413,
	// 2589767209,
	// 2588244151,
	// 2319131071,
	// 2282113373,
	// 2245849783,
	// 2236133941,
	// 2233777723,
	// 2232232273,
	// 1000000861,
	// 1000000181,
	// 1000000087,
	// 1000000021,
	// 1000000009 ,
	// };
	// long long numero_premier[] = {9930773497,6043912529 , 819525272479, 5557509341};
	// for (int i = 0; i< sizeof(numero_premier)/sizeof(long long) ; i++){
	// printf("temps d'execution pour le numero %lld\n", numero_premier[i]);
	// printf("Algorithme 1\n");
	// t1 =clock();
	// A1(numero_premier[i]);
	// t2 = clock();
	//  delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("%F\n",delta);

	// printf("Algorithme 2\n");
	// t1 =clock();
	// A2(numero_premier[i]);
	// t2 = clock();
	// delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("%F\n",delta);

	// printf("Algorithme 3\n");
	// t1 =clock();
	// A3(numero_premier[i]);
	// t2 = clock();
	// delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("%F\n",delta);

	// printf("Algorithme 4\n");
	// t1 =clock();
	// A4(numero_premier[i]);
	// t2 = clock();
	// delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("%F\n",delta);

	// printf("Algorithme 5\n");
	// t1 =clock();
	// A5(numero_premier[i]);
	// t2 = clock();
	// delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("%F\n",delta);

	// printf("Algorithme 6\n");
	// t1 =clock();
	// A6(numero_premier[i]);
	// t2 = clock();
	// delta = (double)(t2-t1)/CLOCKS_PER_SEC;
	// printf("%F\n",delta);
	// }

	// reexecurtion chaque algorithme 50 fois
	for (int i = 0; i < sizeof(numero_premier) / sizeof(long int); i++)
	{
		printf("temps d'execution pour le numero %lld\n", numero_premier[i]);
		printf("Algorithme 1\n");
		delta = 0;
		for (int j = 0; j < 30; j++)
		{
			t1 = clock();
			A1(numero_premier[i]);
			t2 = clock();
			delta = delta + (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		delta = delta / 30;
		printf("%F\n", delta);

		printf("Algorithme 2\n");
		delta = 0;
		for (int j = 0; j < 30; j++)
		{
			t1 = clock();
			A2(numero_premier[i]);
			t2 = clock();
			delta = delta + (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		delta = delta / 30;
		printf("%F\n", delta);

		printf("Algorithme 3\n");
		delta = 0;
		for (int j = 0; j < 30; j++)
		{
			t1 = clock();
			A3(numero_premier[i]);
			t2 = clock();
			delta = delta + (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		delta = delta / 30;
		printf("%F\n", delta);

		printf("Algorithme 4\n");
		for (int j = 0; j < 30; j++)
		{
			t1 = clock();
			A4(numero_premier[i]);
			t2 = clock();
			delta = delta + (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		printf("%f\n", delta);
		delta = delta / 30;
		printf("%F\n", delta);

		printf("Algorithme 5\n");
		delta = 0;
		for (int j = 0; j < 30; j++)
		{
			t1 = clock();
			A5(numero_premier[i]);
			t2 = clock();
			delta = delta + (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		delta = delta / 30;
		printf("%F\n", delta);

		printf("Algorithme 6\n");
		delta = 0;
		for (int j = 0; j < 30; j++)
		{
			t1 = clock();
			A6(numero_premier[i]);
			t2 = clock();
			delta = delta + (double)(t2 - t1) / CLOCKS_PER_SEC;
		}
		delta = delta / 30;
		printf("%F\n", delta);
	}

	return 0;
}
