
![Logo](https://camo.githubusercontent.com/77bfe1f95f9cce05481c0df359421bfa50e322a206ede23abb0b196205913092/68747470733a2f2f63646e2d696d616765732d312e6d656469756d2e636f6d2f6669742f742f313630302f3438302f312a717441767862394f7a2d3964334949735f57317463512e706e67)


# Gasrouard Application

Cette application permet l'indexation de vos fichiers dans une base de données et intègre également une Finite State Machine.


## Créateurs

- [@alexisbrouard](https://www.github.com/alexisbrouard)
- [@CameronBGassedat](https://www.github.com/CameronBGassedat)
- [@Ammooss](https://www.github.com/Ammooss)

## Fonctionnalités implémentés

- Indexation du disque C: dans une base de données avec leur nom, leur chemin,leur extension, leur date de création et de modification
- La FSM implémente les commandes GET, CLEAR, ADD, INDEXER et partiellement SEARCH.
## Comment utiliser l'application ?

### Indexation des fichiers

L'indexation des fichiers est autonome et ne nécessite aucune intervention.

### Utilisation de la FSM

Ecrire dans la console : 

`GET <WHITELIST| FILTERS| WHITELIST| BLACKLIST>`

`CLEAR <WHITELIST| FILTERS| WHITELIST| BLACKLIST>`

`ADD <WHITELIST| FILTERS| WHITELIST| BLACKLIST> nom_fichier`

`INDEXER <RESUME | STOP | START | PAUSE | STATUS>``SEARCH <...>`

**Toutes ces données ne sont pas CaseSensitve !**

### Commandes SQL
Création d'une requêtes SQL pour les commandes :

`GET - Exécution d'une requête SELECT afin de récupérer les données de la base`

`CLEAR - Exécution d'une requête DELETE afin de supprimer les données de la base`

`ADD - Exécution d'une requête UPDATE afin de changé le statuts des fichiers dans la base de données`

`SEARCH - Exécution d'une requête SELECT afin de récupérer un fichier qui correspond à tous les paramètres donnés, pouvant être interchangé ou absent de la commande`

## Problèmes rencontrés

- L'indexer est bien détecté mais n'a aucun effet sur l'application.
- Le SEARCH est compliqué et demande un trop grand nombre de possibilités, et donc nous n'avons pas pu l'implémenter dans les temps

## Documentation

-  [Github](https://github.com/alexisbrouard/Gasrouard_App)

