#include <stdio.h>

// Super Trunfo - Cadastro Simples de 2 Cidades (sem comparação)

int main() {
    // Declaração das variáveis da 1ª cidade
    char nomeCidade1[50];         // Nome da cidade 1
    int populacao1;               // População da cidade 1
    float area1;                  // Área territorial da cidade 1
    float pib1;                   // Produto Interno Bruto da cidade 1
    int pontosTuristicos1;        // Quantidade de pontos turísticos

    // Declaração das variáveis da 2ª cidade
    char nomeCidade2[50];         // Nome da cidade 2
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // --- Cadastro da 1ª cidade ---
    printf("Cadastro da 1ª cidade:\n");

    printf("Nome: ");             // Solicita o nome da cidade
    scanf("%s", nomeCidade1);     // Lê o nome (sem espaços)

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);

    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Cadastro da 2ª cidade ---
    printf("\nCadastro da 2ª cidade:\n");

    printf("Nome: ");
    scanf("%s", nomeCidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);

    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Exibição dos dados das duas cartas cadastradas ---
    printf("\n--- CARTA 1 ---\n");
    printf("Nome: %s\n", nomeCidade1);
    printf("População: %d habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);

    printf("\n--- CARTA 2 ---\n");
    printf("Nome: %s\n", nomeCidade2);
    printf("População: %d habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0; // Fim do programa
}