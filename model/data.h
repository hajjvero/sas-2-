#ifndef DATA_H
#define DATA_H

// Model of date
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

// Model of Cleint
typedef struct
{
    int id; // Auto increment
    char nom[80]; // String
    char prenom[80]; // String
    char email[80]; // String concatenation between nom and prenom by format nom.prenom@email.com
    float solde = 5000; // solde of cleint by default 5000 DH
} Cleint;

// Model of Product
typedef struct
{
    int id; // Auto increment
    char nom[80]; // String
    char categorie[80]; // String
    float prix; // Float
    int stock; // Quantity disponible
    char description[100]; // String
    Date date; // Date created
} Product;


// Linked list node for Prpduct
typedef struct ProducNode {
    Product data;
    struct ProducNode* next;
} ProducNode;

#endif