#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "poly_creux.h"

#include <x86intrin.h>

p_polyf_t creer_polynome (int nbCoeffs)
{
  p_polyf_t p;
  
  p = (p_polyf_t) malloc(sizeof (polyf_t));
  p->nbCoeffs = nbCoeffs;
  p->coeff = (float *) malloc(nbCoeffs * sizeof (float));
  p->degCoeff = (int *) malloc(nbCoeffs * sizeof (int));

  return p;
}

void detruire_polynome (p_polyf_t p)
{
  free (p->coeff) ;
  free (p->degCoeff) ;
  free (p) ;

  return ;
}

void init_polynome (p_polyf_t p, float x)
{
  for (int i = 0 ; i <= p->nbCoeffs; ++i){
    p->degCoeff[i] = i;
    p->coeff[i]=x;
  }
    return ;
}



p_polyf_t lire_polynome_float (char *nom_fichier)
{
  FILE *f ;
  p_polyf_t p ;
  int nbCoeffs ;
  int i  ;
  int cr ;

  f = fopen (nom_fichier, "r") ;
  if (f == NULL)
  {
    fprintf (stderr, "erreur ouverture %s \n", nom_fichier) ;
    exit (-1) ;
  }

  cr = fscanf (f, "%d", &nbCoeffs) ;
  if (cr != 1)
  {
    fprintf (stderr, "erreur lecture du degre\n") ;
    exit (-1) ;
  }
  p = creer_polynome (nbCoeffs) ;
  printf("nbCoeff %d\n", nbCoeffs);
  for (i = 0 ; i < nbCoeffs; i++)
  {
    int val = fscanf (f, "%f", &p->coeff[i]) ;
    if (val != 1)
    {
      fprintf (stderr, "erreur lecture coefficient %d\n", i) ;
      exit (-1) ;
    }
    int deg = fscanf(f, "%d", &p->degCoeff[i]);
    if (deg != 1)
    {
      fprintf (stderr, "erreur lecture degre %d\n", i) ;
      exit (-1) ;
    }


  }

  fclose (f) ;

  return p ;
}

void ecrire_polynome_float (p_polyf_t p)
{
  if(p->nbCoeffs == 0) return;
  printf("%f X^%d", p->coeff[0], p->degCoeff[0]);
  for (int i = 1; i < p->nbCoeffs; i++)
  {
    printf (" + %f X^%d ", p->coeff [i], p->degCoeff[i]);
  }
  printf ("\n");
  return ;
}


int egalite_polynome (p_polyf_t p1, p_polyf_t p2)
{
  if(p1->nbCoeffs!=p2->nbCoeffs) return 0;
  for(int i=0;i<p1->nbCoeffs;i++){
    if(p1->coeff[i]!=p2->coeff[i]) return 0;
    if(p1->degCoeff[i]!=p2->degCoeff[i]) return 0;
  }
  return 1;
}

/*

p_polyf_t addition_polynome (p_polyf_t p1, p_polyf_t p2)
{
  
  for(int i=0;i<p2->nbCoeffs;i++){
    
  }
  p_polyf_t p3 =creer_polynome(nbCoeffp3);

}

p_polyf_t multiplication_polynome_scalaire (p_polyf_t p, float alpha)
{
  p_polyf_t res = creer_polynome(p->degre);
  for (int i = 0; i <= p->degre; i++) {
    res->coeff[i] = alpha * p->coeff[i];
  }
  return res;
}
*/
float eval_polynome (p_polyf_t p, float x)
{
  float res = 0;
  for (int i = 0; i < p->nbCoeffs; i++) {
    res += (p->coeff[i] * powf(x, p->degCoeff[i]));
  }
  return res;
}
/*

p_polyf_t multiplication_polynomes (p_polyf_t p1, p_polyf_t p2)
{
  p_polyf_t res ;
  res = creer_polynome(p1->degre + p2->degre);

  for (int i = 0; i < res->degre; ++i)
    res->coeff[i] = 0;

  for (int i = 0; i <= p1->degre; i++)
  {
    for (int j = 0; j <= p2->degre; j++)
      res->coeff[i + j] += p1->coeff[i] * p2->coeff[j];
  }

  return res;
}

p_polyf_t puissance_polynome (p_polyf_t p, int n)
{
  p_polyf_t res = p;
  for (int i = 1; i < n; i++) {
    res = multiplication_polynomes(res, p);
  }
  return res;
}

p_polyf_t composition_polynome (p_polyf_t p, p_polyf_t q)
{
  p_polyf_t res = creer_polynome(q->degre * p->degre);
  res->coeff[0] = p->coeff[0];
  for (int i = 1; i <= res->degre; i++) {
    res->coeff[i] = 0;
  }
  ecrire_polynome_float(res);
  for (int i = 1; i <= p->degre; i++) {
    p_polyf_t resPuiss = puissance_polynome(q, i);
    p_polyf_t resMult = multiplication_polynome_scalaire(resPuiss, p->coeff[i]);
    res = addition_polynome(res, resMult);
  }
  return res;
}*/