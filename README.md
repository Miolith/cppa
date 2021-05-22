# Projet CPP Avancé
C++ Avancé - Sujet 2 - Une approche bibliothèque au JIT en C++ appliquée au traitement d’images
## Introduction
L’objectif de ce projet est d’apporter une solutionJIT logicielle avec ASMJit pour optimiser des sections critiques d’algorithmes de traitement d’images. Lors de ce projet, nous avons dû implémenter un algorithme permettant d'effectuer à la fois l'opération d'érosion et de dilatation. Le principe est le suivant, nous parcourons chaque pixel de l'image et et y appliquons un masque appelé élément structurant. Cela permet de parcourir les voisins du pixel actuel jusqu'à une certaine distance afin de pouvoir récupérer la valeur la plus petite / grande en fonction de l'opération donnée. Enfin, il suffit d'attribuer au pixel actuel la valeur obtenue. L'algorithme que nous avons implémenté est basé sur celui de Van Herk.
## Login des membres du groupe
- gregoire.casanova
- nam.duong
- nelson.vicel-farah
- william.fan
## Commandes de compilation
```
$ mkdir build && cd build
$ conan install .. -s compiler.cppstd=20 -s compiler.libcxx=libstdc++11
$ cmake ..
```
Pour lancer les tests :
```
make test
```
Pour lancer le benchmark :
```
make bench
```
