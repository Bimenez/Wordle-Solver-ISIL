#include <stdio.h>
#include "dictionary.h"

int main() {
    printf("=== TEST DICTIONNAIRE ===\n");
    
    Dictionary dict;
    
    // Test 1: Chargement
    if (!load_dictionary(&dict, "words.txt")) {
        printf("Échec du chargement\n");
        return 1;
    }
    
    // Test 2: Mot aléatoire
    char *mot_secret = get_random_word(&dict);
    printf("🎲 Mot secret: %s\n", mot_secret);
    
    // Test 3: Validation
    printf("Test 'TABLE': %s\n", is_word_valid(&dict, "TABLE") ? "VALIDE" : "INVALIDE");
    printf("Test 'XYZAB': %s\n", is_word_valid(&dict, "XYZAB") ? "VALIDE" : "INVALIDE");
    
    return 0;
}
