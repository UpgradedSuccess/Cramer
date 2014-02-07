#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int det(int[3][3]);

int main()
{
	int matriz[3][3], auxmatriz[3][3], determinantes[4], tindep[3], sol[3], k, i, j;

	printf("\nIntroduzca los elementos por filas: \n\n");
	for (k = 0; k < 3; k++)
		scanf_s("%d %d %d", &matriz[k][0], &matriz[k][1], &matriz[k][2]);
	system("cls");
	printf("Su matriz es:\n\n");
	for (k = 0; k < 3; k++)
		for (i = 0; i < 3; i++)
		{
			if (i == 0)
				printf("(");
			printf("  %d  ", matriz[k][i]);
			if (i == 2)
				printf(")\n");
		}
	printf("Pulse una tecla");
	_getch();
	system("cls");
	if ((determinantes[0] = det(matriz)) == 0)
	{
		printf("El determinante de la matriz introducida es 0.\n");
		exit(0);
	}
	printf("\n\nIntroduzca el vector de terminos independientes:\n\n");
	scanf_s("%d %d %d", &tindep[0], &tindep[1], &tindep[2]);
	for (k = 0; k < 3; k++)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				auxmatriz[i][j] = matriz[i][j];
		auxmatriz[0][k] = tindep[0];
		auxmatriz[1][k] = tindep[1];
		auxmatriz[2][k] = tindep[2];
		determinantes[k+1] = det(auxmatriz);
		sol[k] = determinantes[k+1] / determinantes[0];
	}
	system("cls");
	printf("La solucion es: \n");
	printf("a = %d\n", sol[0]);
	printf("b = %d\n", sol[1]);
	printf("c = %d\n", sol[2]);
	_getch();

	return 0;
}

int det(int matriz[3][3])
{
	return (matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[1][0] * matriz[2][1] * matriz[0][2] + matriz[0][1] * matriz[1][2] * matriz[2][0] - matriz[0][2] * matriz[1][1] * matriz[2][0] - matriz[0][0] * matriz[2][1] * matriz[1][2] - matriz[2][2] * matriz[0][1] * matriz[1][0]);
}