#include <stdio.h>

#define TAM 5

int main() {
	int codigos[TAM];
	float precios[TAM];
	int i;
	int posMax = 0, posMin = 0;
	int codigo;
	float precio;
	
	printf("=== CARGA DE PRODUCTOS ===\n");
	
	for (i = 0; i < TAM; i++) {
		printf("\nProducto %d\n", i + 1);
		do {
			printf("Ingrese el codigo de barras (1 a 9 cifras): ");
			scanf("%d", &codigo);
			if (codigo <= 0 || codigo > 999999999) {
				printf("Error: el codigo debe ser positivo y tener hasta 9 cifras.\n");
			}
		} while (codigo <= 0 || codigo > 999999999);
		codigos[i] = codigo;
		
		do {
			printf("Ingrese el precio: ");
			scanf("%f", &precio);
			if (precio < 0) {
				printf("Error: el precio no puede ser negativo.\n");
			}
		} while (precio < 0);
		precios[i] = precio;
	}
	
	printf("Codigo de barras\tPrecio\n");
	
	for (i = 0; i < TAM; i++) {
		printf("%09d\t\t%.2f\n", codigos[i], precios[i]);
	}
	
	for (i = 1; i < TAM; i++) {
		if (precios[i] > precios[posMax]) {
			posMax = i;
		}
		
		if (precios[i] < precios[posMin]) {
			posMin = i;
		}
	}
	
	printf("PRODUCTO MAS CARO:\n");
	printf("Codigo de barras: %09d\n", codigos[posMax]);
	printf("Precio: %.2f\n", precios[posMax]);
	printf("PRODUCTO MAS BARATO:\n");
	printf("Codigo de barras: %09d\n", codigos[posMin]);
	printf("Precio: %.2f\n", precios[posMin]);
	
	return 0;
}
