---
title: "TP1 Méthodes Numériques"
author:
- Lucas Matthieu
- Jérémy Pucci
- Eloi Charra
date: 14/02/2022
# Pour des marges un peu plus petites
numbersections: true
geometry: margin=20mm
---
# Calculs de performance

Cette première partie consiste à mesure la puissance de nos machines. Pour cela nous allons calculé la puissance théorique et réelle de nos processeurs respectifs. La puissance d'un processeur se mesure en FLOPS/s (nombre d'opérations flottantes par seconde).

## Performance théorique

Nous avons premièrement calculé la puissance théorique de chacun de nos processeurs. Ce calcul prend en compte la fréquence d'horloge du processeur ainsi que son nombre de coeurs physiques :

$$ freq.proc * nbCoeurs * 16 = x GFLOPS/s$$

Voici un tableau résumant nos calculs :

|        | Fréquence processeur | Nombre de coeurs | GLFOPS/s |
|--------|----------------------|------------------|----------|
| Lucas  |  $1.6*10^9$          | 4                | 83.2     |
| Jérémy |  $2.6*10^9$          | 2                | 102.4    |
| Eloi   |  $2.1*10^9$          | 4                | 134.4    |

## Performance mesurée

Après un calcul théorique, nous allons tester ces valeurs en lançant un même algorithme sur 3 langages différents. Ce programme réalise une multiplication de matrice pour une matrice de grande taille. Nous prendrons N = 2048 comme nombre de colonnes et de lignes de la matrice. Grâce au temps de calcul du programme ainsi que la taille de la matrice nous pouvons approcher une valeur en FLOPS/s de la puissance de l'ordinateur. Nous comparerons ensuite les valeurs calculées via les programmes avec les valeurs théoriques.

### Python

|        | Temps (s) | Température (°C) | Energie CPU (J) | Energie Mémoire (J) |
|--------|-----------|------------------|-----------------|---------------------|
| Lucas  | 2288      | 49               | 9778            | 1001                |
| Jérémy | 2714      | 44               | 16672           |                     |
| Eloi   | 2971      | 58               | 6842            |                     |

- $PEloi = 2^{34} / 2971 = 0.0058 GFLOP/S$ Soit `0,006%` de la capacité du processeur
- $PJérémy = 2^{34} / 2714 = 0.0063 GFLOP/S$ Soit `0,006%` de la capacité du processeur
- $PLucas = 2^{34} / 2288 = 0.0075 GFLOP/S$ Soit `0,009%` de la capacité du processeur

### Java

|        | Temps (s) | Température (°C) | Energie CPU (J) | Energie Mémoire (J) |
|--------|-----------|------------------|-----------------|---------------------|
| Lucas  | 121       | 45               | 464             | 65                  |
| Jérémy | 153       | 57               | 470             |                     |
| Eloi   | 85        | 51               | 225             |                     |


- $PEloi = 2^{34} / 85 = 0.03 GFLOP/S$ Soit `0,2%` de la capacité du processeur
- $PJérémy = 2^{34} / 153 = 0.11 GFLOP/S$ Soit `0,11%` de la capacité du processeur
- $PLucas = 2^{34} / 121 = 0.14 GFLOP/S$ Soit `0,17%` de la capacité du processeur

### C

|        | Temps (s) | Température (°C) | Energie CPU (J) | Energie Mémoire (J) |
|--------|-----------|------------------|-----------------|---------------------|
| Lucas  | 284       | 49               | 733             | 341                 |
| Jérémy | 262       | 56               | 700             |                     |
| Eloi   | 485       | 44               | 645             |                     |

- $PEloi = 2^{34} / 485 = 0.2 GFLOP/S$ Soit `0,02%` de la capacité du processeur
- $PJérémy = 2^{34} / 262 = 0.06 GFLOP/S$ Soit `0,06%` de la capacité du processeur
- $PLucas = 2^{34} / 284 = 0.06 GFLOP/S$ Soit `0,07%` de la capacité du processeur

Avec -O3 :

|      | Temps (s) | Température (°C) | Energie CPU (J) | Energie Mémoire (J) |
|------|-----------|------------------|-----------------|---------------------|
| Eloi | 54        | 43               | 94              |                     |

- $PEloi = 2^{34} / 54 = 0.32 GFLOP/S$ Soit `0,24%` de la capacité du processeur

## Conclusion

???

# TP1 Polynômes

