#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dictionary.h"

int load_dictionary(Dictionary *dict, const char *filename) {
    printf("📖 Chargement du dictionnaire...\n");
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("❌ Erreur: Impossible d'ouvrir %s\n", filename);
        return 0;
    }
    
    dict->count = 0;
    char buffer[100];
    
    while (fgets(buffer, sizeof(buffer), file) && dict->count < MAX_WORDS) {
        // Enlève le saut de ligne
        buffer[strcspn(buffer, "\n")] = 0;
        
        // Garde seulement les mots de 5 lettres
        if (strlen(buffer) == WORD_LENGTH) {
            strcpy(dict->words[dict->count], buffer);
            dict->count++;
        }
    }
    
    fclose(file);
    
    // Initialise l'aléatoire
    srand(time(NULL));
    
    printf("✅ Dictionnaire chargé: %d mots\n", dict->count);
    return 1;
}

char* get_random_word(Dictionary *dict) {
    if (dict->count == 0) {
        return NULL;
    }
    int index = rand() % dict->count;
    return dict->words[index];
}

int is_word_valid(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->words[i], word) == 0) {
            return 1;  // Trouvé
        }
    }
    return 0;  // Non trouvé
}
