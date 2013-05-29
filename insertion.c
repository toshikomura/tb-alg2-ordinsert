#include <stdio.h>
#include <stdlib.h>

#define lim 6
#define indA 0



/* A função Busca retorna o índice "b" tal que v[b] < x */
int Busca(int x, int *v, int a, int b)
{
	int i = b;
	b = -1;                            //atribuição inicial estava errada
	while (i >= a)
	{
		if (a > i)
			b = -1;            //devolução estava incorreta
		else if (x < v[i])
			b = i;
		i--;
	}
	return b;
	//return Busca(x, v, a, b - 1);
}

/* Esta função troca os valores, um pelo outro, de duas posições do vetor. */
int *Troca(int *v, int a, int b)
{
	int temp, i;
	temp = v[a];
	v[a]= v[b];
	v[b]= temp;
	return v;
}


int *Insere(int *v, int a, int b)
{
	int p, i;
	p = Busca(v[b], v, a, b - 1);
	i = b;
	if (p >= 0)
	{
		while (i >= (p + 1))
		{
			Troca(v, i, i - 1);
			i--;
		}
	}
	return v;
}

int *Insertion(int *v, int a, int b)
{
	if (a > b - 1)
		return v;
	Insertion(v, a, b - 1);
	Insere(v, a, b);
	return v;
}

void main()
{
	int vetor[lim];
	int termo;
	int i = 0;
	printf("Insira os termos do vetor.\n");
	while ( i < lim)
	{
		scanf("%d", &termo);
		vetor[i] = termo;
		i++;
	}
	Insertion(vetor, indA, lim - 1);
	printf("\n");
	for (i= 0; i < lim; i++)
		printf("%d ", vetor[i]);
	printf("\n\n");
}
