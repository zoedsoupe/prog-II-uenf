#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct point{
    float x; 
    float y;
} Point;

typedef struct circles{
    Point centro; 
    float r; 
} Circle;

typedef struct conj_circle{
    Circle *vet; 
    int n;
} cCirc;

typedef struct conj_point{
    Point *vet; 
    int m;
} cPoint;

void geraVetorCirc(cCirc *c)
{
    int i;
    
    c->vet = (Circle *) malloc(c->n * sizeof(Circle)); 
    
    for(i = 0; i < c->n; i++){
        c->vet[i].centro.x = 100 - rand() % 201; 
        c->vet[i].centro.y = 100 - rand() % 201; 
        c->vet[i].r = 1 + rand() % 10;
    }
}


void geraVetorPoint(cPoint *p)
{
    int i;
       
    p->vet = (Point *) malloc(p->m * sizeof(Point));
    
    for(i = 0; i < p->m; i++) {
        p->vet[i].x = 100 - rand() % 201; 
        p->vet[i].y = 100 - rand() % 201;
    }
}

void printVetCirc(cCirc c) {
    int i;

    for(i = 0; i < c.n; i++)
        printf("%d. Centro = (%.2f,%.2f) e r = %.0f\n", i+1, c.vet[i].centro.x, c.vet[i].centro.y, c.vet[i].r);
    
}

void printVetPoint(cPoint p) {
    int i;

    for(i = 0; i < p.m; i++)
        printf("%d. (%.2f,%.2f)\n", i+1, p.vet[i].x, p.vet[i].y);

}

float calculaDistancia (Point p1, Point p2) {
    float dx, dy, d;
    
    dx = p1.x-p2.x;
    dy = p1.y-p2.y;
    d = sqrt (dx*dx+dy*dy);
    return d;
}
void intersecPtoCirc(cCirc c, cPoint p) {
    int i = 0, j;
    float d;
    
    while ( i < c.n) {
        for(j=0; j < p.m; j++) {
            
            d = calculaDistancia (c.vet[i].centro, p.vet[j]);
            
            if (d <= c.vet[i].r) {
                printf("\nCirculo %d intercepta com o ponto: \n", i+1);
                printf("%d. (%.2f,%.2f)\n", j+1, p.vet[j].x, p.vet[j].y);
            }
        }    
      i++;    
    }
    
}


int main() {
    srand(time(NULL)); 

    cCirc circles; 
    cPoint points; 
    
    printf("Quantos circulos serão gerados?\nn = ");
    scanf("%d", &circles.n);
    printf("Quantos pontos serão gerados?\nm = ");
    scanf("%d", &points.m);
    geraVetorCirc(&circles); 
    geraVetorPoint(&points); 
    printf("Circulos: \n");
    printVetCirc(circles);
    printf("\n\nPoints: \n");
    printVetPoint(points);
    intersecPtoCirc(circles, points);

    return 0;
}


