#include <stdio.h>
#include "dictionary.h"

int main() {
    printf("=== TEST DICTIONNAIRE ===\n");
    
    Dictionary dict;
    
    // Test 1: Chargement
    if (!load_dictionary(&dict, "../data/words.txt")) {
        printf("❌ Echec du chargement\n");
        return 1;
    }
    
    // Test 2: Mot aléatoire
    char *mot = get_random_word(&dict);
    printf("🎲 Mot aléatoire: %s\n", mot);
    
    // Test 3: Validation
    printf("🔍 'TABLE' est valide? %s\n", 
           is_word_valid(&dict, "TABLE") ? "OUI" : "NON");
    printf("🔍 'XYZAB' est valide? %s\n", 
           is_word_valid(&dict, "XYZAB") ? "OUI" : "NON");
    
    printf("✅ Tests dictionnaire terminés!\n");
    return 0;
}
