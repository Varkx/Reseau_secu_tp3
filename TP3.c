#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <time.h>
#include <assert.h>

//Partie 1 – Manipulation des grands nombres (début)

//exercice 1.1
typedef struct tabcar 
{
	int x;
    //tableau de x caractere
	char *integer;

} tabcar;

//exercice 1.2
tabcar initialiser0()
{
    tabcar tbcar;
    tbcar.x = 10;
    int x = tbcar.x;
    tbcar.integer = (char *)malloc(x * sizeof(char));

    for( int i = 0 ; i < tbcar.x ; i++)
    {
        tbcar.integer[i] = 0; 
    } 
    return tbcar;
}

tabcar initialiser0_add()
{
    tabcar tbcar;
    tbcar.x = 20;
    int x = tbcar.x;
    tbcar.integer = (char *)malloc(x * sizeof(char));

    for( int i = 0 ; i < tbcar.x ; i++)
    {
        tbcar.integer[i] = 0; 
    } 
    return tbcar;
}


tabcar initialiser0_add2()
{
    tabcar tbcar;
    tbcar.x = 100;
    int x = tbcar.x;
    tbcar.integer = (char *)malloc(x * sizeof(char));

    for( int i = 0 ; i < tbcar.x ; i++)
    {
        tbcar.integer[i] = 0; 
    } 
    return tbcar;
}

//exercice 1.3
tabcar initialiser1()
{
    tabcar tbcar;
    tbcar.x = 10;
    int x = tbcar.x;
    tbcar.integer = (char *)malloc( x* sizeof(char));
    tbcar.integer[0] = 1;
    for( int i = 1 ; i < tbcar.x ; i++)
    {
        tbcar.integer[i] = 0; 
    } 
    return tbcar;
}

tabcar initialisern()
{
    tabcar tbcar;
    tbcar.x = 10;
    int x = tbcar.x;
    tbcar.integer = (char *)malloc( x* sizeof(char));
    tbcar.integer[0] = 1;
    for( int i = 1 ; i < tbcar.x ; i++)
    {
        if(i%2==0)
        {
            tbcar.integer[i] = 0; 
        } 
        else
        {
            tbcar.integer[i] = 1; 
        } 
    } 
    return tbcar;
}

tabcar initialiser_random()
{
    tabcar tbcar;
    tbcar.x = 10;
    int x = tbcar.x;
    tbcar.integer = (char *)malloc( x* sizeof(char));
    for( int i = 0 ; i < tbcar.x ; i++)
    {
        tbcar.integer[i] = rand()%2;

    } 
    return tbcar;
}

//exercice 1.4
void libererNombre(tabcar tbcar)
{
    free(tbcar.integer);
}

//exercice 1.5
void affichage(tabcar tbcar)
{
    int nombre = 0;
    for(int i=tbcar.x-1 ; i >= 0 ;i--)
    {
        printf("%d",tbcar.integer[i]);
    } 
    printf("\n");
    
} 

//exercice 1.6

int comparer(tabcar tbcar1,tabcar tbcar2)
{
    if(tbcar1.x != tbcar2.x)
    {
        return 0;
    } 
    for(int i = 0 ; i <tbcar1.x ; i++)
    {
        if(tbcar1.integer[i] != tbcar2.integer[i])
        {
            return 0;
        } 
    } 
   
    return 1;
    
}

//exercice 1.7
int pair(tabcar tbcar)
{
    if(tbcar.integer[0] == 1 ){
        printf("Le nombre est impair\n ");
        return 1;
    }
    else
    {
        printf("Le nombre est pair\n ");
        return 0;
    } 
}

//exercice 1.8
void divisePar2(tabcar tbcar)
{
    int x = tbcar.x;
    for(int i = 0 ; i <= tbcar.x-1 ; i++)
    {
        tbcar.integer[i] = tbcar.integer[i+1];
    } 
    tbcar.integer[x] = 0; 
   
}


//exercice 1.9
void reduireDe1(tabcar tbcar)
{
    int indice = -1;
    for(int i = 0 ; i < tbcar.x ; i++)
    {
        if( tbcar.integer[i] == 1 )
        {
            tbcar.integer[i] = 0;
            indice = i;
            break; 
        }  
    } 
    for(int j = indice-1 ; j >= 0; j--)
    {
        tbcar.integer[j] = 1; 
    } 
}

//exercice 1.10
void multiplierPar2(tabcar tbcar)
{
    int x = tbcar.x;
    for(int i = x-1 ; i > 0 ; i--)
    {
        tbcar.integer[i] = tbcar.integer[i-1]; 
    } 
    tbcar.integer[0] = 0;  
}

//exercice 1.11
tabcar ajouterDeuxNombres(tabcar tbcar1, tabcar tbcar2)
{
    tabcar tbres = initialiser0_add();
    int taille = tbcar1.x;
    for(int i = 0 ; i < taille ; i++)
    {
        if(tbcar1.integer[i] + tbcar2.integer[i] == 0  )
        {
            tbres.integer[i] += 0; 
        } 
        if(tbcar1.integer[i] + tbcar2.integer[i] == 1 )
        {
            tbres.integer[i] += 1;
            if(tbres.integer[i] == 2 )
            {
                tbres.integer[i] = 0;
                tbres.integer[i+1] = 1;  
            }  
        } 
        if(tbcar1.integer[i] + tbcar2.integer[i] == 2 )
        {
            if(tbres.integer[i]  == 0)
            {
                tbres.integer[i+1] = 1; 
            } 
            if(tbres.integer[i]  == 1)
            {
                tbres.integer[i] = 1;
                tbres.integer[i+1] = 1; 
            }                                                                                                                                                                                                                                                                                                                                                                            
        }
    } 
    return tbres;


}

//exercice 1.12

tabcar MultiplierDeuxNombres(tabcar tbcar1, tabcar tbcar2)
{
    tabcar tbtmp = initialiser0();
    tabcar tbres = initialiser0();
    int taille = tbcar2.x;
    int taille2 = tbcar1.x;
    
    int c = 1;
    if(tbcar2.integer[taille - 1] == 1) {
        for(int i = taille; i > 0; i--) {
            tbres.integer[i] = tbcar1.integer[i];
        }
    }

    for(int i = 0; i < taille2 - 2; i++) {
        for(int i = taille; i > 0; i--) {
            tbtmp.integer[i] = tbcar1.integer[i];
        }
        if(tbcar2.integer[i]  == 1) {
            for(int j = c; j > 0; j--) {
                multiplierPar2(tbtmp);
            }
            tbres = ajouterDeuxNombres(tbres, tbtmp);
        }
        c++;
    }

    return tbres;
       
} 

int puissance(int a , int b)
{
    int tmp = a;
    for(int i = 1 ; i < b ; i++)
    {
        tmp *= a;
    }
    return tmp; 
} 

tabcar multiplier(tabcar tbcar1, tabcar tbcar2)
{
	tabcar res = initialiser0();
    int taille = tbcar1.x;
    
	for(int i = 0 ; i < taille ; ++i)
	{
        int pow = puissance(2,i);
		if(tbcar2.integer[i] == '1')
		{
			for(int j = 0 ; j < pow ; ++j)
			{
				res = ajouterDeuxNombres(res,tbcar1);
			}
		}
	}
	return res;
}


//exercice 1.13
tabcar exponentiationRapideSansModulo(tabcar tbcar1, tabcar tbcar2)
{
	tabcar res = initialiser1();
	tabcar base = tbcar1;
	int start_flag = 0;
    int taille = tbcar1.x;
	for(int i = taille-1 ; i >= 0 ; --i)
	{
		if(tbcar2.integer[i] == '1')
			start_flag = 1;
		if(start_flag)
		{
			if(tbcar2.integer[i] == '1')
			{
				res = multiplier(res,base);
			}
			base = multiplier(base,base);
		}
	}
	return res;
}

//Exercice 1.14
tabcar soustraire(tabcar a, tabcar b) {
    tabcar c = initialiser0();

    int r = 0;
    for(int i = 0; i <= a.x - 1; i++) {
        if(a.integer[i] - b.integer[i] == 0) {
            if(r == 1) {
                c.integer[i] = 1;
                r = 1;
            }
            else {
                c.integer[i] = 0;
                }
        }

        if(a.integer[i] - b.integer[i] == -1) {
            if(r == 1) {
                c.integer[i] = 0;
                r = 1;
            }
            else {
                c.integer[i] = 1;
                r = 1;
            }
        }

        if(a.integer[i] - b.integer[i] == 1) {
            if(r == 1) {
                c.integer[i] = 0;
                r = 0;
            }
            else {
                c.integer[i] = 1;
            }
        }
    }
    return c;
}

//Exercice 1.15

int greaterThan(tabcar a , tabcar b){
    for(int i = a.x ; i >= 0 ; i-- )
    {
        if(a.integer[i] == '1' && b.integer[i] == '0')
        {
            return 1;
        } 
        else if (a.integer[i] == '0' && b.integer[i] == '1'  )
        {
            return 0;
        } 
    } 
    return 0;
} 

tabcar modulo(tabcar a, tabcar b) {

    tabcar new = a;
    while(greaterThan(b,new) != 0)
    {
        new = soustraire(new , b);
    }  
    return new;
}

//Partie 2 – Chiffrement et déchiffrement
// Partie 3 – Manipulation des grands nombres (fin)
// Exercice 3.2

int PGCD(int nb1 , int nb2)
{
    int pgcd;

    for(int i=1; i <= nb1 && i <= nb2; ++i)
    {
        if(nb1%i==0 && nb2%i==0)
            pgcd = i;
    }
    if(pgcd != 1){
        printf("Les deux nombres ne sont pas premier entre eux, PGCD de %d et %d = %d\n ", nb1, nb2, pgcd);
    } 
    else{
        printf("les deux nombres sont premiers entre eux, PGCD de %d et %d = %d\n ", nb1, nb2, pgcd);
    } 
   
}

// Partie 4 – Création des clés

//Exercice 4.1


int main(int argc, char *argv[])
{
    srand(time(NULL));

    tabcar tbcar;
    tabcar tbcar2;
    tabcar tbcar3;
    //2
    tbcar = initialiser0();
    //3
    tbcar2 = initialiser1();
    tbcar3 = initialisern();
    //5
    affichage(tbcar);
    affichage(tbcar2);
    affichage(tbcar3);
    //6
    printf(" comparer deux nombre : %d\n",comparer(tbcar,tbcar2));
    //7
    printf("%d\n",pair(tbcar));
    //8
    tabcar tbdiv;
    tbdiv = initialisern();
    divisePar2(tbdiv);
    printf("Division par 2 :\n "); 
    affichage(tbdiv);
    printf("\n");
    //9
    tabcar tbred;
    tbred = initialisern();
    reduireDe1(tbred);
    printf("Reduction de 1 :\n "); 
    affichage(tbred);
    printf("\n");
    //10
    tabcar tbmul;
    tbmul = initialisern(),
    multiplierPar2(tbmul);
    printf("Multiplication par 2 :\n "); 
    affichage(tbmul);
    printf("\n");
   
    //11
    tabcar tbadd1;
    tabcar tbadd2;
    tabcar tbres;
    tbadd1 = initialiser_random();
    tbadd2 = initialiser_random();
    affichage(tbadd1);
    affichage(tbadd2);
    tbres = ajouterDeuxNombres(tbadd1,tbadd2);
    printf("Addition de deux nombres :\n ");
    affichage(tbres);
    
    //12
    printf("\n ");
    tabcar tbmul1;
    tabcar tbmul2;
    tabcar tbres2;
    tbmul1 = initialiser_random();
    tbmul2 = initialiser_random();
    affichage(tbmul1);
    affichage(tbmul2);
    tbres2 = multiplier(tbmul1,tbmul2);
    printf("Multiplication de deux nombres :\n ");
    affichage(tbres2);

    //13
    tabcar tbexprap1;
    tabcar tbexprap2;
    tabcar tbres4;
    tbexprap1 = initialiser_random();
    tbexprap2 = initialiser_random();
    affichage(tbexprap1);
    affichage(tbexprap2);
    tbres4 = exponentiationRapideSansModulo(tbexprap1,tbexprap2);
    printf("exponentiation rapide sans modulo : \n ");
    affichage(tbres4);

    //14
    tabcar tbsub1;
    tabcar tbsub2;
    tabcar tbres3;
    tbsub1 = initialiser_random();
    tbsub2 = initialiser_random();
    affichage(tbsub1);
    affichage(tbsub2);
    tbres3 = soustraire(tbadd1,tbadd2);
    printf("Soustraction de deux nombres :\n ");
    affichage(tbres3);

    
    
    //15
    tabcar tbmod1;
    tabcar tbmod2;
    tabcar tbres5;
    tbmod1 = initialiser_random();
    tbmod2 = initialiser_random();
    affichage(tbmod1);
    affichage(tbmod2);
    tbres5 = modulo(tbmod1,tbmod2);
    printf("Modulo deux nombres :\n ");
    affichage(tbres5);
    
    //3.1
    int pgcd = PGCD(19,17);

    return 0;
}






