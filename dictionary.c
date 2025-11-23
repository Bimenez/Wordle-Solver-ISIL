int load_dictionary(Dictionary *dict, const char *filename) {
    printf("🟢 DEBUT: Je charge le dictionnaire...\n");
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("🔴 ERREUR: Fichier %s introuvable!\n", filename);
        return 0;
    }
    printf("🟢 Fichier ouvert avec succès\n");
    
    // ... le reste du code ...
    
    printf("✅ Dictionnaire chargé: %d mots trouvés\n", dict->count);
    
    // AFFICHE les 5 premiers mots pour vérifier
    printf("📖 Les 5 premiers mots:\n");
    for (int i = 0; i < 5 && i < dict->count; i++) {
        printf("  - %s\n", dict->words[i]);
    }
    
    return 1;
}
