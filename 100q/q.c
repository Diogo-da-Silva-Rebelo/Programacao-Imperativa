#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//1.Maior elemento de uma sequência
void maior_sequencia(){
    int num, maior = INT_MIN;
    printf("Insira a sua sequência: ");

    do{
        scanf("%d", &num);
        if (num == 0) break;
        if (num > maior) maior=num;
    }
    while (num);
    printf("O maior elemento é: %d\n", maior);
}

//Versão com apontador numero
void maior_sequencia2() {
    int *num, maior = INT_MIN;
    printf("Insira a sua sequência: ");

    do {
        scanf("%d", num);
        if (*num == 0) break;
        if (*num > maior) maior = *num;
    } while (*num);
    printf("O maior elemento é: %d\n", maior);
}

//2.Média da seuqência
void media (){
    int num, total=0;
    float media, soma=0;

    printf("Insira a sua sequência: ");
    do {
        scanf("%d", &num);
        if (num == 0) break;
        soma += num;
        total++;
    } while (num != 0);
    media = soma/total;
    printf("A média é: %.2f\n ", media);
}

//3.Segundo maior elemento da seuqência
void segundo_maior() {
    int maior = INT_MIN, seg_maior = INT_MIN, num;
    printf("Insira a sua sequência: ");

    do {
        scanf("%d", &num);
        if (num == 0) break;
        if (num > maior){
            seg_maior = maior;
            maior = num;
        }
    } while (num != 0);
    printf("O segundo maior elemento é: %d\n", seg_maior);
}

//4.Número de bits iguais a 1 num número
int bitsUm (unsigned int n){
    int res = 0;
    while (n) {
        if (n%2 == 1) res++;
        n = n/2;
    }
    return res;
}

//5.Número de zeros no final da representação binária
int trailingZ (unsigned int n) {
    int i=0;

    if (n == 0) return 32;
    while(n && n%2 == 0) {
        i++;
        n/=2;
    }
    return i;
}

//6.Dígitos necessaŕios para escrever um número em decimal
int qDig (unsigned int n) {
    int res = 0;
    while (n){
        n/=10;
        res++;
    }
    return res;
}

//7. Concatenação de duas strings
char *mystrcat (char s1[], char s2[]){
    int i, j;

    for(i=0;s1[i];i++); //coloca i na última posição de s1;
    for(j=0;s2[j];j++)
    {
        s1[i+j]= s2[j];
        s1[i+j+1]='\0'; //por cada iteração é posto no final o '\0'
    }
    //s1[i+j]='\0'; Isto também funcionaria (retirando a linha comentada acima)
    return s1;
}

//8.Cópia de duas strings
char *mystrcpy(char s1[], char s2[]) {
    int i;
    for (i=0;s2[i];i++) s1[i]=s2[i];
    s1[i] = '\0';
    return s1;
    //obs. se s2 for maior que s1, s2 não fica totalmente copiado para s1
}

//9.Comparação de duas strings
int mystrcmp (char s1[], char s2[]) {
    int i;

    for (i=0;;i++) {
        if (s1[i] != s2[i]) return s1[i] < s2[i] ? -1 : 1;
        if (s1[i] == '\0') return 0;
    }
}
//Obs. esta função não relaciona tamanhos. Ela olha para o código ASCII de char

//10. Posição onde s2 ocorre em s1, retornando onde ocorre em s1
char* mystrstr (char s1[], char s2[]) {
    //length[s2]<length[s1], pois s2 está contido em s1
    int i, j;
    if (!*s2) return s1;
    if (!*s1) return (!*s2) ? s1 : NULL;
    for (i = 0; s1[i]; i++) {
        for (j = 0; s1[i + j] && s2[j] && s1[i + j] == s2[j]; j++) {
            if (!s2[j + 1]) return s1 + i;
            //anda tantas vezes quanto as chars iguais, daí s1+i.
        }
    }
    return NULL;
}
/*
Análise detalhada da função acima:
A função retorna a posição onde s2 ocorre em s1. Assim, vamos analisar
o seguinte exemplo:

 s1: "O Diogo"
 s2: "Diogo" [note-se que o tamanho de s2 é sempre menor que o de s1]

 Casos:
-> Se não existir s2, ou seja, se s2 for NULL, então retorna-se a pri
meira posição de s1, imprimindo s1;
-> Se não existir s1 (ou seja, s1: ""), convém verificar se s2 é "". Se
sim, então, retorna-se s1. Caso s2 != "", então retorna-se NULL, pois s2
não ocorre em s1;
-> Se ambas as strings existirem, temos o caso geral:
Vamos ter de comparar todas as poisições de s1 com todas as posições de
s2. Mas, se a posição atual i de s1 for igual à j de s2, então, continuamos
a verificar as duas posições se coincidem. Assim que elas deixarem de coin
cidir, então, avançamos com a posição de s1 e voltamos a analisar com todas
as posições de s2. A comparação para até que as posições sejam diferentes.
Enquanto forem iguais, vamos avançando para "guardar" a string a devolver.
 */

//11.Função que inverte uma string
void strrev (char s[]) {
    int i, j, last;

    for (i = 0; s[i]; i++);
    i--;
    for (j = 0; j < i; i--, j++) {
        last = s[i];
        s[i] = s[j];
        s[j] = last;
    }
    return;
}

//12.Remoção de vogais de uma string
void mystrnoV (char s[]) {
    int j,i = 0;
    for (i=0; s[i];i++){
        if(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' ||s[i] == 'A' ||s[i] == 'E' ||s[i] == 'I' ||s[i] == 'O' ||s[i] == 'U'){
            for(j = i; s[j]; j++) s[j] = s[j+1];
            i--;
        }
    }
}

//13. Trunca as palavras com, no máximo, n careteres
void truncW (char t[], int n) {
    int i = 0, length = 0, j;
    while (t[i]) {
        if (t[i] == ' ' || t[i] == '\n' || t[i] == '\t') {
            length = 0;
            i++;
        } else if (length < n) {
            i++;
            length++;
        } else {
            for(j = i; t[j]; j++) t[j] = t[j+1];
        }
    }
}

//14.Char mais frequente na string s
char charMaisfreq (char s[]){

}

//15.


//16.

//17.
dar commit

