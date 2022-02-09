#include <stdio.h>
#include <stdlib.h>

#include "poly.h"


int main (int argc, char **argv)
{
  p_polyf_t p1, p2 ;
  
  if (argc != 3)
    {
      fprintf (stderr, "deux paramètres (polynomes,fichiers) sont à passer \n") ;
      exit (-1) ;
    }
      
  p1 = lire_polynome_float (argv [1]) ;
  p2 = lire_polynome_float (argv [2]) ;

  ecrire_polynome_float (p1) ;
  ecrire_polynome_float (p2) ;

  int res = egalite_polynome(p1, p2);
  printf("Egalité p1 / p2 : %s\n", res == 0 ? "non" : "oui");
  printf("\n");
  ecrire_polynome_float(multiplication_polynomes(p1, p2));

  /* Deux tests rapides sur la fonction eval_polynome */
  printf("p1(2) = %f\n", eval_polynome(p1, 2));
  printf("p2(4) = %f\n", eval_polynome(p2, 4));
  
  /* Deux tests rapides sur la fonction multiplication_polynome_scalaire */
  p_polyf_t multscal=multiplication_polynome_scalaire(p1,3);
  p_polyf_t multscal1=multiplication_polynome_scalaire(p2,3);
  ecrire_polynome_float(multscal);
  ecrire_polynome_float(multscal1);

  p_polyf_t compo1=composition_polynome(p1,p2);
  ecrire_polynome_float(compo1);

  /*
    ajouter du code pour tester les fonctions
    sur les polynomes
  */
}
