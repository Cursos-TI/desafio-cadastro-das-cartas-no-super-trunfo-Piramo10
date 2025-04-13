#include <stdio.h>

// Definição da estrutura Cidade
typedef struct {
    int codigo;
    char nome[50];
    char estado[3];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePop;
    float pibPerCapita;
    float superPoder;
} Cidade;

// Função que calcula o "Super Poder" da cidade com base nos atributos
float calcularSuperPoder(Cidade c) {
    float inversoDensidade = 1.0 / c.densidadePop; // Quanto menor a densidade, maior o poder
    return (float)c.populacao + c.area + c.pib + (float)c.pontosTuristicos + c.pibPerCapita + inversoDensidade;
}

// Função para cadastrar uma cidade e calcular seus atributos derivados
Cidade cadastrarCidade(int numero) {
    Cidade c;

    // Coleta de dados da cidade
    printf("\n--- Cadastro da %dª cidade ---\n", numero);
    
    printf("Código da Carta: ");
    scanf("%d", &c.codigo);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", c.nome); // Lê até 49 caracteres com espaços

    printf("Estado (UF): ");
    scanf(" %2s", c.estado); // Lê até 2 caracteres (ex: SP, RJ)

    printf("População: ");
    scanf("%d", &c.populacao);

    printf("Área (em km²): ");
    scanf("%f", &c.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &c.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c.pontosTuristicos);

    // Cálculos derivados
    if (c.area == 0) {
        c.densidadePop = 0; // Evita divisão por zero
    } else {
        c.densidadePop = c.populacao / c.area;
    }

    c.pibPerCapita = (c.pib * 1000000000) / c.populacao; // PIB convertido de bilhões para reais
    c.superPoder = calcularSuperPoder(c); // Calcula o valor do "super poder"

    return c;
}

// Exibe todas as informações da cidade formatadas como uma "carta"
void exibirCarta(Cidade c) {
    printf("\n--- CARTA %d ---\n", c.codigo);
    printf("Cidade: %s (%s)\n", c.nome, c.estado);
    printf("População: %d habitantes\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePop);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

// Compara duas cidades em diferentes critérios e mostra quem vence cada um
void compararCartas(Cidade c1, Cidade c2) {
    int pontosC1 = 0, pontosC2 = 0;

    printf("\n--- COMPARAÇÃO DE CARTAS ---\n");

    // Comparação: População
    if (c1.populacao > c2.populacao) {
        pontosC1++;
        printf("População: Cidade 1 vence\n");
    } else if (c2.populacao > c1.populacao) {
        pontosC2++;
        printf("População: Cidade 2 vence\n");
    } else {
        printf("População: Empate\n");
    }

    // Comparação: Área
    if (c1.area > c2.area) {
        pontosC1++;
        printf("Área: Cidade 1 vence\n");
    } else if (c2.area > c1.area) {
        pontosC2++;
        printf("Área: Cidade 2 vence\n");
    } else {
        printf("Área: Empate\n");
    }

    // Comparação: PIB
    if (c1.pib > c2.pib) {
        pontosC1++;
        printf("PIB: Cidade 1 vence\n");
    } else if (c2.pib > c1.pib) {
        pontosC2++;
        printf("PIB: Cidade 2 vence\n");
    } else {
        printf("PIB: Empate\n");
    }

    // Comparação: Pontos Turísticos
    if (c1.pontosTuristicos > c2.pontosTuristicos) {
        pontosC1++;
        printf("Pontos Turísticos: Cidade 1 vence\n");
    } else if (c2.pontosTuristicos > c1.pontosTuristicos) {
        pontosC2++;
        printf("Pontos Turísticos: Cidade 2 vence\n");
    } else {
        printf("Pontos Turísticos: Empate\n");
    }

    // Comparação: PIB per capita
    if (c1.pibPerCapita > c2.pibPerCapita) {
        pontosC1++;
        printf("PIB per capita: Cidade 1 vence\n");
    } else if (c2.pibPerCapita > c1.pibPerCapita) {
        pontosC2++;
        printf("PIB per capita: Cidade 2 vence\n");
    } else {
        printf("PIB per capita: Empate\n");
    }

    // Comparação: Densidade populacional (menor vence)
    if (c1.densidadePop < c2.densidadePop) {
        pontosC1++;
        printf("Densidade Populacional: Cidade 1 vence\n");
    } else if (c2.densidadePop < c1.densidadePop) {
        pontosC2++;
        printf("Densidade Populacional: Cidade 2 vence\n");
    } else {
        printf("Densidade Populacional: Empate\n");
    }

    // Comparação: Super Poder
    if (c1.superPoder > c2.superPoder) {
        pontosC1++;
        printf("Super Poder: Cidade 1 vence\n");
    } else if (c2.superPoder > c1.superPoder) {
        pontosC2++;
        printf("Super Poder: Cidade 2 vence\n");
    } else {
        printf("Super Poder: Empate\n");
    }

    // Resultado final
    printf("\n--- RESULTADO FINAL ---\n");
    printf("Cidade 1: %d ponto(s)\n", pontosC1);
    printf("Cidade 2: %d ponto(s)\n", pontosC2);

    if (pontosC1 > pontosC2) {
        printf("Cidade 1 é a vencedora!\n");
    } else if (pontosC2 > pontosC1) {
        printf("Cidade 2 é a vencedora!\n");
    } else {
        printf("Empate geral entre as cidades!\n");
    }
}

// Função principal que executa o programa
int main() {
    // Cadastra duas cidades
    Cidade cidade1 = cadastrarCidade(1);
    Cidade cidade2 = cadastrarCidade(2);

    // Exibe as cartas de cada cidade
    exibirCarta(cidade1);
    exibirCarta(cidade2);

    // Compara as cartas em diferentes critérios
    compararCartas(cidade1, cidade2);

    return 0;
}
