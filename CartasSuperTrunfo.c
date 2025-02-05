#include <stdio.h>


// variaveis
#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TAM_CODIGO 4

//armazenar os dados da cidade
typedef struct {
    char codigo[TAM_CODIGO];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    char nome[30];
} Cidade;

//cadastrar uma cidade
void cadastrar_cidade(Cidade *cidade, char estado, int numero_cidade) {
    // Gera o código da cidade
    snprintf(cidade->codigo, TAM_CODIGO, "%c%02d", estado, numero_cidade);

    printf("\nCadastro da cidade %s:\n", cidade->codigo);

    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", cidade->nome);

    printf("Informe a população: ");
    scanf("%d", &cidade->populacao);

    printf("Informe a área (km²): ");
    scanf("%f", &cidade->area);

    printf("Informe o PIB: ");
    scanf("%f", &cidade->pib);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    printf("Cadastro concluído para %s!\n\n", cidade->nome);
}

// exibir os dados cadastrados de todas as cidades
void exibir_cidades(Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO]) {
    printf("\n==== Dados Cadastrados ====\n");
    for (int estado = 0; estado < NUM_ESTADOS; estado++) {
        for (int numero_cidade = 0; numero_cidade < CIDADES_POR_ESTADO; numero_cidade++) {
            Cidade cidade = cidades[estado][numero_cidade];
            printf("\nCidade: %s (%s)\n", cidade.nome, cidade.codigo);
            printf("População: %d habitantes\n", cidade.populacao);
            printf("Área: %.2f km²\n", cidade.area);
            printf("PIB: %.2f bilhões\n", cidade.pib);
            printf("Pontos turísticos: %d\n", cidade.pontos_turisticos);
        }
    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO];

    printf("=== Cadastro de Cidades ===\n");
    for (int estado = 0; estado < NUM_ESTADOS; estado++) {
        for (int numero_cidade = 0; numero_cidade < CIDADES_POR_ESTADO; numero_cidade++) {
            char estado_char = 'A' + estado;
            cadastrar_cidade(&cidades[estado][numero_cidade], estado_char, numero_cidade + 1);
        }
    }

    exibir_cidades(cidades);

    return 0;
}
