#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    int hash[m];

    // Initialize table
    for (int i = 0; i < m; i++) {
        hash[i] = EMPTY;
    }

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int i = 0;
            while (i < m) {
                int index = (key % m + i * i) % m;

                if (hash[index] == EMPTY) {
                    hash[index] = key;
                    break;
                }
                i++;
            }
        }

        else if (strcmp(op, "SEARCH") == 0) {
            int i = 0, found = 0;

            while (i < m) {
                int index = (key % m + i * i) % m;

                if (hash[index] == key) {
                    found = 1;
                    break;
                }

                if (hash[index] == EMPTY) {
                    break;
                }

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}