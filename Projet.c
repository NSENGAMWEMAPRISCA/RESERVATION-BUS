#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PASSENGERS 100
#define MAX_BUSES 20
#define MAX_SEATS 50
// Structures
typedef struct {
        char name[50];
        char contact[20];
        int reservation_history[10];
} Passenger;

typedef struct {
        int bus_id;
        int available_seats[MAX_SEATS];
        int num_passengers;
        Passenger passengers[MAX_PASSENGERS];
} Bus;
// Fonctions
void display_menu() {
        printf("Bienvenue dans le système de réservation de bus !\n");
        printf("Choisissez une option :\n");
        printf("1. Réserver un billet\n");
        printf("2. Afficher les réservations\n");
        printf("3. Effectuer un paiement\n");
        printf("4. Quitter\n");
}

void reserve_ticket(Bus *buses, int num_buses) {
        int bus_id, seat_num, payment_method;
        char passenger_name[50], passenger_contact[20];
        printf("Entrez le numéro du bus : ");
        scanf("%d", &bus_id);
        // Trouver le bus correspondant
        Bus *bus = NULL;
        for (int i = 0; i < num_buses; i++) {
        if (buses[i].bus_id == bus_id) {bus = &buses[i];
        break;
        }
}
if(bus == NULL) {
        printf("Désolé, ce bus n'existe pas.\n");
return;
}
    //Afficher les sièges disponibles
    printf("Sièges disponibles :\n");
    for (int i = 0; i < MAX_SEATS; i++) {
    if (bus->available_seats[i]) {
    printf("%d ", i+1);
    }
}
    printf("\nEntrez le numéro du siège : ");
    scanf("%d", &seat_num);
    // Vérifier la disponibilité du siège
    if (!bus->available_seats[seat_num-1]) {
    printf("Désolé, ce siège est déjà réservé.\n");
    return;
}
    //Ajouter le passager
    printf("Entrez le nom du passager : ");
    scanf("%s", passenger_name);
    printf("Entrez le contact du passager : ");
    scanf("%s", passenger_contact);
    bus->passengers[bus->num_passengers].name[0] = '\0';
    strncpy(bus->passengers[bus->num_passengers].name, passenger_name, 49);
    strncpy(bus->passengers[bus->num_passengers].contact, passenger_contact, 19);
    bus->passengers[bus->num_passengers].reservation_history[0] = seat_num;
    bus->available_seats[seat_num-1] = 0;
    bus->num_passengers++;
    printf("Réservation effectuée avec succès !\n");
    // Effectuer le paiement
    printf("Choisissez un moyen de paiement (1 - Mobile money, 2 - Autre) : ");
    scanf("%d", &payment_method);
    if (payment_method == 1) {
    printf("Paiement par mobile money en cours...\n");
    // Simuler le paiement par mobile moneyprintf("Paiement effectué avec succès !\n");
    }
    else {
    printf("Paiement par un autre moyen en cours...\n");
    // Simuler le paiement par un autre moyen
    printf("Paiement effectué avec succès !\n");
    }
    printf("Voici votre billet :\n");
    printf("Numéro du bus : %d\nNuméro du siège : %d\nNom du passager : %s\nContact :%s\n",bus_id, seat_num, passenger_name, passenger_contact);
}
int main() {
    Bus buses[MAX_BUSES];
    int num_buses = 0;
    int choice;
    // Initialisation des bus
    for (int i = 0; i < MAX_BUSES; i++) {
            buses[i].bus_id = i+1;
    for (int j = 0; j < MAX_SEATS; j++) {
            buses[i].available_seats[j] = 1;
        }
        buses[i].num_passengers = 0;
    }
        num_buses = 10;
    while (1) {
        display_menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                reserve_ticket(buses, num_buses);
            break;
            case 2:
                // Afficher les réservations
            break;
            case 3:
                // Effectuer un paiement
            break;
            case 4:
                printf("Au revoir !\n");
            default:
                printf("Choix invalide. Veuillez réessayer.\n");}
        }
        return 0;
}

