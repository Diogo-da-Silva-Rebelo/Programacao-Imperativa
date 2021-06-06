#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//Parte A
//1
char *my_strcpy (char*dest, char source[]){
    int i;
    if (!strlen(source)) return NULL;
    for (i = 0; source[i];i++){
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

//2
void my_strnoV (char s[]) {
    int i,j;

    for (i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
            || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            for (j = i; s[j]; j++) s[j] = s[j+1];
            i--;
        }
    }
}

//3 inorder (left, visit, right)
int dumpAbinAux (ABin a, int v[], int N, int i) {
    if (a == NULL) return i;
    else {
        i = dumpAbinAux(a -> left, v, N, i);
        if (i != N) v[i++] = a -> data;
        i = dumpAbinAux(a->right, v, N, i);
    }
    return i;
}

int dumpAbin (ABin a, int *v, int N) {
    return dumpAbinAux(a, v, N, 0);
}

//PosOrder (visit, left, right)
int dumpAbinIdx (ABin a, int v[], int N, int i) {
    int esq, dir;
    if (a == NULL || i == N) return 0;
    v[i] = a->valor;
    esq = dumpAbinIdx(a->esq, v, N, i + 1);
    dir = dumpAbinIdx(a->dir, v, N, i + 1 + esq);
    return esq + dir + 1;
}

int dumpAbin (ABin a, int v[], int N) {
    return dumpAbinIdx(a, v, N, 0);
}

//4
int lookupAB(ABin a, int x){
    if (!a) return 0;
    else {
        while(a){
            if (a->valor == x){
                return 1;
            } else if (x < a->valor) {
                a = a->esq;
            } else {
                a = a->dir;
            }
        }
    }
    return 0;
}

//Parte B

int main(){
    char dest[20];
    printf("%s\n", my_strcpy(dest,"Diogo Rebelo"));
    my_strnoV(dest);
    printf("%s\n", dest);
    return 0;
}
