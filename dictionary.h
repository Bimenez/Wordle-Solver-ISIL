#ifndef DICTIONARY_H
#define DICTIONARY_H

#define WORD_LENGTH 5
#define MAX_WORDS 10000

typedef struct {
    char words[MAX_WORDS][WORD_LENGTH + 1];  // +1 pour le '\0'
    int count;  // Nombre de mots chargés
} Dictionary;

// Fonctions
int load_dictionary(Dictionary *dict, const char *filename);
char* get_random_word(Dictionary *dict);
int is_word_valid(Dictionary *dict, const char *word);

#endif
