#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Se dă o mulțime de numere naturale cu valori de la 0 la 1000. Se citesc
de la intrare diferite valori în intervalul [0,1000], să se utilizeze un
vector de octeți de dimensiune cât mai mică pentru memorarea
elementelor mulțimii.
*/
char getFlag(char v, char poz) {
	return (v >> poz) & 1;
}
char setFlag(char v, char poz, char val) {
	if (val == 1) {
		return v | (1 << poz);
	}
	else {
		return v & ~(1 << poz);
	}
}
char getFlag2(char v, char poz) {
	return (v >> poz) & 1;
}
char toggleFlag(char v, char poz) {
	return v ^ (1 << poz);
}

int main() {
	char v[1001];
	int n;
	printf("Introduceti numarul de elemente: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v[x / 8] = setFlag(v[x / 8], x % 8, 1);
	}
	for (int i = 0; i < 1000; i++) {
		if (getFlag(v[i / 8], i % 8) == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}