#include <stdio.h>
int fat(int f){
    if (f<=1)
        return 1;
    return f*fat(f-1);
}

int combinacao(int n, int x){
    return fat(n)/(fat(n-x)*fat(x));
}

float potencia (float base, int expoente){
    if (expoente==0){
        return 1.0;
    }
    return base*potencia(base, expoente-1);
} 

float binominal(int n, float p, int x){
    return combinacao(n,x)*potencia(p/100,x)*potencia((100-p)/100,n-x);
}

float acumulativo(int n, float p, int x){
    if (x<0)
        return 0;
    return combinacao(n,x)*potencia(p/100,x)*potencia((100-p)/100,n-x)+acumulativo(n,p,x-1);
}
int main(){
    int n, x;
    float p, resultado, racumulativo;
    printf("digite o n (quantidade de testes): ");
    scanf("%d", &n);
    printf("digite o p (taxa de sucesso) em valor relativo: ");
    scanf("%f", &p);
    printf("digite o x  (quantidade de sucesso): ");
    scanf("%d", &x);
    resultado=binominal(n,p,x)*100;
    racumulativo=acumulativo(n,p,x)*100;
    printf("o binomio e: %f \n", resultado);
    printf("o binomio acumulativo e: %f \n", racumulativo);
    return 0;
}