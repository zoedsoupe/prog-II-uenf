/* UENF-CCT-LCMAT-Ci�ncia da Computa��o
Data de in�cio: 14/10/19
Monitoria de Programa��o II - Exerc�cio
========================================*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct ponto{
    float x;
    float y;
} Ponto;

typedef struct circulo{
    Ponto centro; // exemplo de acesso as coordenadas do centro: c.centro.x e c.centro.y
    float r; // raio
} Circulo;

typedef struct conj_circulo{
    Circulo *vet; // ponteiro a ser alocado como vetor de n posi��es
    int n;
} cCirc;

typedef struct conj_ponto{
    Ponto *vet; // ponteiro a ser alocado como vetor de m posi��es
    int m;
} cPonto;

void geraVetorCirc(cCirc *c)
{
    int i;
    
    // Aloca o vetor de c�rculos dinamicamente
    c->vet = (Circulo *) malloc(c->n * sizeof(Circulo)); // aloca��o din�mica
    
    // Preenche o vetor de c�rculos com valores aleat�rios
    for(i = 0; i < c->n; i++){
        c->vet[i].centro.x = 100 - rand() % 201; // rand() % 201 gera um n�mero aleat�rio entre 0 e 200,
        c->vet[i].centro.y = 100 - rand() % 201; // portanto o intervalo das coordenadas � de [-100,100]
        c->vet[i].r = 1 + rand() % 10;
    }
}


void geraVetorPonto(cPonto *p)
{
    int i;
    
    // Aloca o vetor de pontos dinamicamente
    p->vet = (Ponto *) malloc(p->m * sizeof(Ponto));
    
    // Preenche o vetor de pontos com valores aleat�rios
    for(i = 0; i < p->m; i++){
        p->vet[i].x = 100 - rand() % 201; 
        p->vet[i].y = 100 - rand() % 201;
    }
}

void exibeVetorCirc(cCirc c)
{
    int i;

    for(i = 0; i < c.n; i++)
        printf("%d. Centro = (%.2f,%.2f) e r = %.0f\n", i+1, c.vet[i].centro.x, c.vet[i].centro.y, c.vet[i].r);
    
}

void exibeVetorPonto(cPonto p)
{
    int i;

    for(i = 0; i < p.m; i++)
        printf("%d. (%.2f,%.2f)\n", i+1, p.vet[i].x, p.vet[i].y);

}

float calculaDistancia (Ponto p1, Ponto p2)
{
    float dx, dy, d;
    
    dx = p1.x-p2.x;
    dy = p1.y-p2.y;
    d = sqrt (dx*dx+dy*dy);
    return d;
}
void intersecaoPtoCirc(cCirc c, cPonto p)
{
    int i = 0, j;
    float d;
    
    while ( i < c.n)
    {
        
        for(j=0; j < p.m; j++)
        {
            
            d = calculaDistancia (c.vet[i].centro, p.vet[j]);
            
            if (d <= c.vet[i].r)
            {
                printf("Circulo %d intercepta com: \n", i+1);
                printf("%d.\t (%.2f,%.2f)\n", j+1, p.vet[j].x, p.vet[j].y);
            }
        }    
      i++;    
    }
    
}


int main()
{
    srand(time(NULL)); // inicializador de n�meros aleat�rios
    
    cCirc circulos; // conjunto de c�rculos
    cPonto pontos; // conjunto de pontos
    
    printf("Digite o numero de circulos que serao gerados\nn = ");
    scanf("%d", &circulos.n);
    
    printf("Digite o numero de pontos que serao gerados\nm = ");
    scanf("%d", &pontos.m);
    
    geraVetorCirc(&circulos); // passagem por refer�ncia
    geraVetorPonto(&pontos); // aqui tamb�m
    
    printf("C�rculos: \n");
    exibeVetorCirc(circulos);
    
    printf("\n\nPontos: \n");
    exibeVetorPonto(pontos);

    intersecaoPtoCirc(circulos, pontos);

    
    return 0;
}


