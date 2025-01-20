*Gestionnaire de Bibliothèque en C*
Ce programme est une application console pour gérer une bibliothèque, écrite en langage C.
Il permet aux utilisateurs de manipuler une base de données de livres enregistrée dans un fichier CSV.
Les fonctionnalités incluent l'ajout, la suppression, la modification, la recherche et le tri des livres.

*Fonctionnalités*
1. Ajouter un livre:
Permet d’ajouter un nouveau livre dans la bibliothèque.
Informations requises : titre, ID, auteur, catégorie, prix et description.
2. Modifier un livre
Permet de modifier les détails d’un livre existant dans la bibliothèque en fournissant son ID.
Informations pouvant être modifiées : titre, auteur, catégorie, prix et description.
3. Supprimer un livre
Supprime un livre existant en se basant sur son ID.
Met à jour le fichier CSV après suppression.
4. Rechercher un livre
Recherche un livre selon le titre ou l’auteur.
Affiche les résultats correspondants.
5. Trier les livres
Trie les livres en fonction d'un critère (titre ou catégorie).
Affiche les livres triés après l'opération.
6. Afficher les livres
Liste tous les livres actuellement disponibles dans la bibliothèque.

*Structure des Données*

Chaque livre est représenté par une structure livre contenant les champs suivants :
id : Identifiant unique du livre.
titre : Titre du livre.
auteur : Auteur du livre.
categorie : Catégorie du livre.
description : Brève description du livre.
prix : Prix du livre.

*Fichier CSV*
Le programme utilise un fichier nommé bibliotheque.csv pour stocker les informations des livres.
 Chaque ligne correspond à un livre avec les champs séparés par des virgules.
 Exemple de ligne dans bibliotheque.csv :
 ahmed , 1 , JKRowling , Fantasy , A wizard boy , 19.99 ,

 *Auteurs*
Développé par [zakaria sibousse,oussama chafik,yahya jaati,salah din arkhis,ghali abhar/zakaria sib].
