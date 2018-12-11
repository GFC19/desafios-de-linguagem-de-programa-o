#include <stdio.h>
#include <stdlib.h>
int MDC(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}  
int MMC(int a, int b) {
	return (a*b) / MDC(a,b);
}
int rMMC(int*const vet, int N) { 
	if(N >= 2) {
		vet[N-2] = MMC(vet[N-1],vet[N-2]);
		N--;
		return rMMC(vet,N);
	}
	return MMC(vet[N],vet[N-1]);
}
int ver_s () {
	int correto = 0;
	int s = -1;
		while(correto != 1) {
			scanf("%d",&s);
			if(s<0 || s>50) { 
				printf("Você errou!");
			} else {
				return s;
			}
		} 
}
int main() {
	printf("       Desafio - A \n\n");
	printf("Digite um numeros: ");
	int N = ver_s ();
	int lancamentos[N];
	for(int i=0;i<N;i++) scanf("%d",&lancamentos[i]); printf("%d",rMMC(lancamentos,N));
		return 0;
	}
