#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int id;
	char titre[20];
	char auteur[30];
	char description [100];
	char categorie [30];
	char name_user[25];
	float prix;
	char dispo[5];
}livre;
void trierLivres() {
    FILE *file = fopen("bibliotheque.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }

    livre livres[100];
    int n = 0;
    char critere[20];

    // Lecture des livres dans l'ordre spécifié
    while (fscanf(file, "%s %d %s %s %[^\n]s %f \n",
                  livres[n].titre, &livres[n ].id, livres[n].auteur,
                  livres[n].categorie, livres[n].description, &livres[n].prix) == 6) {
        n++;
    }
    fclose(file);

    printf("Trier par (Titre/Categorie) : ");
    scanf("%s", critere);
int i;
int j;
    // Tri selon le critère choisi
    for ( i = 0; i < n - 1; i++) {
        for ( j = i + 1; j < n; j++) {
            if ((strcmp(critere, "Titre") == 0 && strcmp(livres[i].titre, livres[j].titre) > 0) ||
                (strcmp(critere, "Categorie") == 0 && strcmp(livres[i].categorie, livres[j].categorie) > 0)) {
                livre temp = livres[i];
                livres[i] = livres[j];
                livres[j] = temp;
            }
        }
    }

    // Affichage des livres triés
    printf("\nLivres triés par %s :\n", critere);
    for ( i = 0; i < n; i++) {
        printf("ID: %d, Titre: %s, Auteur: %s, Catégorie: %s, Description: %s, Prix: %.2f\n",
               livres[i].id, livres[i].titre, livres[i].auteur,
               livres[i].categorie, livres[i].description, livres[i].prix);
    }
}

void rechercher_livre() {
    FILE *file = fopen("bibliotheque.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }

    char critere[20], valeurRecherchee[30];
    livre t;

    printf("Rechercher par (Titre/Auteur) : ");
    scanf("%s", critere);
    printf("Entrez la valeur recherchée : ");
    scanf("%s", valeurRecherchee);

    int trouve = 0;
    printf("\nRésultats de la recherche :\n");
    while (fscanf(file, "%s %d %s %s %[^\n]s %f \n",
                  t.titre, &t.id, t.auteur, t.categorie, t.description, &t.prix) == 6) {
        if ((strcmp(critere, "Titre") == 0 && strcmp(t.titre, valeurRecherchee) == 0) ||
            (strcmp(critere, "Auteur") == 0 && strcmp(t.auteur, valeurRecherchee) == 0)) {
            printf("ID: %d, Titre: %s, Auteur: %s, Catégorie: %s, Description: %s, Prix: %.2f\n",
                   t.id, t.titre, t.auteur, t.categorie, t.description, t.prix);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun livre trouvé.\n");
    }

    fclose(file);
}


void supprimer() {
    livre s;
    FILE *file = fopen("bibliotheque.csv", "r");
    FILE *f = fopen("aide.csv", "w");
    if (file == NULL || f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }
    int id;
    printf("Entrez l'ID du livre ï¿½ supprimer : ");
    scanf("%d", &id);
    int found = 0;

    while (!feof) 
	{
	fscanf(file, "%[^,]s %[^ ,]d %[^,]s %[^,]s %[^,]s %.2f \n",
                 s.titre,&s.id, s.auteur,s.categorie ,
                  s.description, &s.prix) ;
       
    }
     if (s.id == id) {
            found = 1;
        } 

    fclose(file);
    fclose(f);

    if (found) {
        remove("bibliotheque.csv");
        rename("aide.csv", "bibliotheque.csv");
        printf("Livre supprime½ avec succï¿½s.\n");
    } else {
        remove("aide.csv");
        printf("Livre avec l'ID %d non trouve.\n", id);
    }
}

	
	void modifier() {
		livre t;
    FILE *file = fopen("bibliotheque.csv","r");
    FILE *f = fopen("aide.csv", "a");
    if (file == NULL || f == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }
    int id;
    printf("Entrez l'ID du livre ï¿½ modifier : ");
    scanf("%d",&id); 
	 	livre a;
    int found = 0;

    while (!feof){
	
	fscanf(file, "%s %d %s %s %[^\n]s %.2f \n",
                 t.titre,&t.id, t.auteur,t.categorie ,
                  t.description, &t.prix) ; 
                  }
        if (t.id == id) {
            found = 1;

            printf("Entrez le nouveau titre du livre : ");
            scanf("%s", a.titre);
            printf("Entrez le nouvel ID du livre : ");
            scanf("%d", &a.id);
            printf("Entrez le nouvel auteur du livre : ");
            scanf("%s",a.auteur);
            printf("Entrez la nouvelle catï¿½gorie du livre : ");
            scanf("%s", a.categorie);
            printf("Entrez le nouveau prix du livre : ");
            scanf("%f", &a.prix);
            printf("Entrez la nouvelle description du livre :");
            
            fgets(a.description, sizeof(a.description), stdin);
              
        }
        fprintf(f,"%d , %s , %s , %s ,  %.2f , %s ,",a.id, a.titre, a.auteur,a.categorie,a.prix,a.description);
        
       
    

    fclose(file);
    fclose(f);

    if (found) {
        remove("bibliotheque.csv");
        rename("aide.csv", "bibliotheque.csv");
        printf("Livre modifiï¿½ avec succï¿½s.\n");
    } else {
        remove("aide.csv");
        printf("Livre avec l'ID %d non trouvï¿½.\n", id);
    }
}

void Ajout (){
	livre t;
	FILE *file;
	file=fopen("bibliotheque.csv","a");
			if(file==NULL){
		printf("error d'ouverture de fichier\n");
		exit(1);
	}
		
		printf("entre le titre  du livre ");
		scanf("%s",t.titre);
		printf("entre le id  du livre ");
		scanf("%d",&t.id);
		printf("entre le auteure  du livre ");
		scanf("%29s",t.auteur);
		printf("entre la categorie  du livre ");
		scanf("%s",t.categorie);
		printf("entre le prix  du livre ");
		scanf("%f",&t.prix);
		printf("entre la description  du livre : ");
		getchar();
	 	fgets(t.description, sizeof(t.description), stdin);
		fprintf(file,"%s , %d , %s , %s , %.2f , %s ,",t.titre,t.id,t.auteur,t.categorie,t.prix,t.description);

	} 

	void afficherLivres() {
    FILE *file = fopen("bibliotheque.csv", "r");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        exit(1);
    }

    livre s;

    printf("\nListe des livres disponibles :\n");


    while (!feof) {
    	fscanf(file, "%s %d %s %s %[^\n] %.2f \n",
                 s.titre,&s.id, s.auteur,s.categorie ,
                  s.description, &s.prix) ; 
    	
        printf("%s %d %s %s %s %.2f\n",
               s.titre,&s.id, s.auteur,s.categorie ,
                  s.description, &s.prix);
    }

    fclose(file);
}


int main (){

char name_user[20];
	int tache;
	

	printf("bienvenu \n");
	printf("\n");
	printf("entre votre nom:");
	scanf("%s",name_user);
	
	printf("que souhaite faire aujourdhui\n");
	printf("pour ajouter un livre entrer 1\n pour modifier un livre entrer 2\npour supprimer un livre entrer 3\n ");
	scanf("%d",&tache);



 switch (tache) {
    case 1:
        Ajout();
        break;
    case 2:
        modifier();
        break;
    case 3:
        supprimer();
        break;
    case 4:
        rechercher_livre();
        break;
    case 5:
        trierLivres();
        break;
    default:
        printf("Choix invalide.\n");
        break;
}

    printf("\nEnregistrement effectue avec succes !\n");
    return 0;
}