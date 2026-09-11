#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void desenhaForca(int);

int main() {
    srand(time(NULL));

    // matrizes de palavras
    char listaFrutas[15][20]  = {"abacaxi", "morango", "melancia", "laranja", "banana", "manga", "limao", "goiaba", "cereja","carambola", "melao", "amora", "kiwi", "caju", "maracuja"};
    char listaPaises[15][20]  = {"brasil", "argentina", "japao", "mexico", "franca", "italia", "alemanha", "canada", "egito", "russia", "estados unidos", "china", "india", "portugal", "nigeria"};
    char listaObjetos[15][20] = {"cadeira", "caneta", "celular", "espelho", "garrafa", "martelo", "mochila", "notebook", "teclado", "tesoura", "mouse", "guitarra", "microfone", "televisao", "controle"};
    char listaAnimes[15][20]  = {"naruto", "bleach", "pokemon", "evangelion", "berserk", "haikyuu", "one piece", "jujutsu kaisen", "rezero", "digimon", "boku no hero", "frieren", "fire force", "gachiakuta", "solo leveling"};
    char listaJogos[15][20]   = {"minecraft", "roblox", "fortnite", "skyrim", "overwatch", "counter strike", "league of legends", "terraria", "zelda", "bloodborne", "valorant", "rocket league", "grand theft auto", "the last of us", "god of war"};

    int tema, erros = 0;

    printf("--- BEM-VINDO ---\n");
    printf("Escolha o Tema:\n");
    printf("1 - Frutas\n2 - Paises\n3 - Objetos\n4 - Animes\n5 - Jogos\n");
    printf("Opcao: ");
    scanf("%d", &tema);

    char palavraSecreta[20];
    int indiceSorteado = rand() % 10;

    // Define qual lista usar baseado no tema
    if(tema == 1) strcpy(palavraSecreta, listaFrutas[indiceSorteado]);
    else if(tema == 2) strcpy(palavraSecreta, listaPaises[indiceSorteado]);
    else if(tema == 3) strcpy(palavraSecreta, listaObjetos[indiceSorteado]);
    else if(tema == 4) strcpy(palavraSecreta, listaAnimes[indiceSorteado]);
    else strcpy(palavraSecreta, listaJogos[indiceSorteado]);

    int tam = strlen(palavraSecreta);
    char descoberta[tam + 1];

    for(int i = 0; i < tam; i++) descoberta[i] = '_';
    descoberta[tam] = '\0';

    while(erros < 6 && strchr(descoberta, '_') != NULL) {
        printf("TEMA ESCOLHIDO: %d\n", tema);
        desenhaForca(erros);
        printf("\nPalavra: %s\n", descoberta);

        char chute;
        printf("\nChute uma letra: ");
        scanf(" %c", &chute);
        chute = tolower(chute);

        // Verifica se a letra existe na palavra
        if(strchr(palavraSecreta, chute) == NULL) {
            erros++;
        } else {
            for(int i = 0; i < tam; i++) {
                if(palavraSecreta[i] == chute) {
                    descoberta[i] = chute;
                }
            }
        }
    }
    desenhaForca(erros);

    if(strchr(descoberta, '_') == NULL) {
        printf("\n PARABENS! Voce acertou: %s\n", palavraSecreta);
    } else {
        printf("\n PERDEU! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}

void desenhaForca(int erros) {
    printf("\n  +---+ \n  |   | \n");
    printf("  %c   | \n", (erros >= 1 ? 'O' : ' '));
    if (erros == 2) printf("  |   | \n");
    else if (erros == 3) printf(" /|   | \n");
    else if (erros >= 4) printf(" /|\\  | \n");
    else printf("      | \n");
    if (erros == 5) printf(" /    | \n");
    else if (erros >= 6) printf(" / \\  | \n");
    else printf("      | \n");
    printf("      | \n=========\n");
}