
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void converte(float milhas, float *km, float *m)
{
    *km = milhas * 1.609;
    *m = (*km) * 0.2778;
}

int main()
{

    float milhas, metro, km;

    printf("Digite a quantidade de milhas\n");
    scanf("%f", &milhas);

    converte(milhas, &km, &metro);

    printf("milhas por hora = %f \n km = %f \n ms = %f", milhas, km, metro);

    return 0;
}
