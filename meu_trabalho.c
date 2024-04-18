#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>

// Definindo a tabela de códons
char* tabela_codons(char *codon) {
    if (strcmp(codon, "TTT") == 0 || strcmp(codon, "TTC") == 0)
        return "Fenilalanina";
    else if (strcmp(codon, "TTA") == 0 || strcmp(codon, "TTG") == 0)
        return "Leucina";
    else if (strcmp(codon, "CTT") == 0 || strcmp(codon, "CTC") == 0 || strcmp(codon, "CTA") == 0 || strcmp(codon, "CTG") == 0)
        return "Leucina";
    else if (strcmp(codon, "ATT") == 0 || strcmp(codon, "ATC") == 0 || strcmp(codon, "ATA") == 0)
        return "Isoleucina";
    else if (strcmp(codon, "ATG") == 0)
        return "Metionina";
    else if (strcmp(codon, "GTT") == 0 || strcmp(codon, "GTC") == 0 || strcmp(codon, "GTA") == 0 || strcmp (codon, "GTG") == 0)
        return "Valina";
    else if (strcmp(codon, "TCT") == 0 || strcmp(codon, "TCC") == 0 || strcmp(codon, "TCA") == 0 || strcmp(codon, "TCG") == 0 || strcmp (codon, "AGT") == 0 || strcmp (codon, "AGC") == 0)
        return "Serina";
    else if (strcmp(codon, "CCT") == 0 || strcmp(codon, "CCC") == 0 || strcmp(codon, "CCA") == 0 || strcmp(codon, "CCG") == 0)
        return "Prolina";
    else if (strcmp(codon, "ACT") == 0 || strcmp(codon, "ACC") == 0 || strcmp(codon, "ACA") == 0 || strcmp(codon, "ACG") == 0)
        return "Trionina";
    else if (strcmp(codon, "GCT") == 0 || strcmp(codon, "GCC") == 0 || strcmp(codon, "GCA") == 0 || strcmp(codon, "GCG") == 0)
        return "Alanina";
    else if (strcmp(codon, "TAT") == 0 || strcmp(codon, "TAC") == 0) return "Tirosina";
    else if (strcmp(codon, "ACT") == 0 || strcmp(codon, "TAG") == 0 || strcmp(codon, "TGA") == 0)
        return "Códon de Parada";
    else if (strcmp(codon, "CAT") == 0 || strcmp(codon, "CAC") == 0)
        return "Histidina";
    else if (strcmp(codon, "CAA") == 0 || strcmp(codon, "CAG") == 0)
        return "Glutamina";
    else if (strcmp(codon, "AAT") == 0 || strcmp(codon, "AAC") == 0)
        return "Asparagina";
    else if (strcmp(codon, "AAA") == 0 || strcmp(codon, "AAG") == 0)
        return "Lisina";
    else if (strcmp(codon, "GAT") == 0 || strcmp(codon, "GAC") == 0)
        return "Àcido Aspártico";
    else if (strcmp(codon, "GAA") == 0 || strcmp(codon, "GAG") == 0)
        return "Àcido Glutâmico";
    else if (strcmp(codon, "TGT") == 0 || strcmp(codon, "TGC") == 0)
        return "Cisteína";
    else if (strcmp(codon, "TGG") == 0)
        return "Triptofano";
    else if (strcmp(codon, "CGT") == 0 || strcmp(codon, "CGC") == 0 || strcmp(codon, "CGA") == 0 || strcmp(codon, "CGG") == 0 || strcmp(codon, "AGA") == 0 || strcmp(codon, "AGG") == 0)
        return "Arginina";
    else if (strcmp(codon, "GGT") == 0 || strcmp(codon, "GGC") == 0 || strcmp(codon, "GGA") == 0 || strcmp(codon, "GGG") == 0)
        return "Glicina";

    // adicione mais códons conforme necessário
    else
        return NULL;
}

// Função para encontrar a posição da sequência na fila e a qual lista pertence
void encontrar_codon(char *sequencia) {
    int posicao = -1;
    int tamanho_sequencia = strlen(sequencia);
    for (int i = 0; i < tamanho_sequencia - 2; i++) {
        char codon[4];
        strncpy(codon, sequencia + i, 3);
        codon[3] = '\0';
        for(int j = 0; j < 3; j++) {
            codon[j] = toupper(codon[j]); // Convertendo para maiúsculas
        }
        char *lista = tabela_codons(codon);
        if (lista != NULL) {
            posicao = i;
            printf("A sequência '%s' está na posição %d na fila e pertence à lista %s.\n", codon, posicao, lista);
        }
    }
    if (posicao == -1) {
        printf("Nenhuma sequência pertence a uma lista.\n");
    }
}

// Função principal para receber a entrada do usuário e chamar a função encontrar_codon
int main() {
    setlocale(LC_ALL, "Portuguese");
    char sequencia[100];
    printf("Digite a sequência de DNA: ");
   scanf("%s", sequencia);
    encontrar_codon(sequencia);
    return 0;
}