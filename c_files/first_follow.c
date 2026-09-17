#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int count; 
char prod[10][10];

void first(char result[], char c);
void follow(char result[], char c);
void addToSet(char result[], char val);

int main() {
    int i;
    char choice;
    char c;
    char result[20];
    
    printf("Enter the number of productions: ");
    scanf("%d", &count);
    
    printf("Enter the productions (e.g., E=TR, use '#' for epsilon):\n");
    for (i = 0; i < count; i++) {
        scanf("%s", prod[i]);
    }
    
    do {
        printf("\nFind FIRST and FOLLOW for non-terminal: ");
        scanf(" %c", &c);
        
        memset(result, '\0', sizeof(result));
        first(result, c);
        printf("FIRST(%c) = { %s }\n", c, result);
        
        memset(result, '\0', sizeof(result));
        follow(result, c);
        printf("FOLLOW(%c) = { %s }\n", c, result);
        
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}

void addToSet(char result[], char val) {
    int i;
    for (i = 0; result[i] != '\0'; i++) {
        if (result[i] == val) {
            return; 
        }
    }
    result[i] = val;
    result[i + 1] = '\0';
}

void first(char result[], char c) {
    int i, j;
    char subResult[20];
    
    if (!(isupper(c))) {
        addToSet(result, c);
        return;
    }
    

    for (i = 0; i < count; i++) {
        if (prod[i][0] == c) {
            if (prod[i][2] == '#') {
                addToSet(result, '#');
            } 
            else {
                memset(subResult, '\0', sizeof(subResult));
                first(subResult, prod[i][2]);
                
                for (j = 0; subResult[j] != '\0'; j++) {
                    addToSet(result, subResult[j]);
                }
            }
        }
    }
}

void follow(char result[], char c) {
    int i, j;
    char subResult[20];
    
    if (prod[0][0] == c) {
        addToSet(result, '$');
    }
    
    
    for (i = 0; i < count; i++) {
        for (j = 2; prod[i][j] != '\0'; j++) {
            
            
            if (prod[i][j] == c) {
                
                if (prod[i][j + 1] != '\0') {
                    
                    memset(subResult, '\0', sizeof(subResult));
                    first(subResult, prod[i][j + 1]);
                    
                    int k;
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] != '#') { 
                            addToSet(result, subResult[k]);
                        }
                    }
                }
                
                
                if (prod[i][j + 1] == '\0' && c != prod[i][0]) {
                    memset(subResult, '\0', sizeof(subResult));
                    follow(subResult, prod[i][0]);
                    
                    int k;
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToSet(result, subResult[k]);
                    }
                }
            }
        }
    }
}