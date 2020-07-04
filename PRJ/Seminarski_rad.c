//Darko Djuricic NRT148/18
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 120+1 /* Broj korisnih karaktera u stringu*/
#define MAX1 5 /*Broj igraca kojima cuva rezultat igre*/

void pocetak();
void opcije(int x);
void igra(struct igrac *ptr_igrac);
void uputstvo();
void knjizevnost(struct igrac *ptr_igrac,int i);
void geografija(struct igrac *ptr_igrac,int i);
void istorija(struct igrac *ptr_igrac,int i);
void film(struct igrac *ptr_igrac,int i);
void rezultat(struct igrac *ptr_igrac,int i);
void lista_rezultata(struct igrac *ptr_igrac,int i);

struct igrac{
	char ime[MAX+1];
	int rezultat;
	}*igrac1;

int i; 
int doz_br;  /*Broj koji odredjuje koliko je kategorija odigrano*/

 main()
{
	int n;
	
	igrac1=malloc(MAX1*sizeof(struct igrac));
	if(igrac1==NULL)
	{
		fprintf(stderr,"Greska pri dodeli memorije!");
		exit(1);
	}

	pocetak();
	printf("    Unesite broj opcije koju zelite: "); scanf(" %d",&n); fflush(stdin); /*n je promenljiva koja se prenosi funkciji opcije,koja sluzi za biranje ponudjenih opcija*/
	opcije(n);

	

}

void pocetak() /*Funkcija koja prikazuje opcije na ekranu*/
{
	printf("    Dobrodosli u igru znanja! :)\n");
	printf("---------------------------------------\n\n");
	printf(" 1. Igraj\n");
	printf(" 2. Upustvo\n");
	printf(" 3. Napusti igru\n\n");
	printf("---------------------------------------\n");
}

void opcije(int x)
{
	switch(x)
	{
	case 1:
		igra(igrac1);
		system("cls"); /*Brisanje svega prethodnog zbog preglednosti ekrana*/
		break;
	case 2:
		uputstvo();
		break;
	case 3:
		exit(0); /*Izlaz bez greske*/
		free(igrac1);
	default:
		printf("\n Niste uneli nijednu ponudjenu opciju!\n\n\n"); main();
	}

}

void uputstvo() /*Funkcija koja prikazuje upustvo kako se igra igrica*/
{
	int j;
	FILE *fptr;
	char bafer[MAX+1],c;
	
	printf("---------------------------------------\n");
	printf("         Uputstvo \n\n");

		
	
		/*Otvaranje datoteke za citanje*/
		if((fptr=fopen("uputstvo.txt","r"))==NULL)
			printf("\nGreska pri otvaranju datoteke za citanje\n");

		while(!feof(fptr))
		{
			fgets(bafer, MAX+1,fptr);
			printf("%s",bafer);
		}

	
		do{
			printf("\n\nAko zelite da se vratite nazad u meni, upisite slovo B (BACK):"); c=getchar(); fflush(stdin);
			
			if(c=='b' || c=='B')
			{
				puts("\n\n");
				system("cls");
				main();
			}
		}while(c!='b' || c!='B');



}

void igra(struct igrac *ptr_igrac) /*Funckija gde se bira kategorija igre*/
{
	int br,br1,br2,br3,br4; 
	int broj;
	char c;

	printf("---------------------------------------\n");
	for(i=0;i<MAX1;i++)
	{
		doz_br=0;
		br=0; br1=0; br2=0 ;br3=0; br4=0; /*Promenljive koje odredjuju da li su kategorije vec odigrane*/
		(ptr_igrac+i)->rezultat=0;

		printf("1. Zapocni igru\t 2. Vrati se u meni (Vracanjem resetujete sve i pocinjete igru ispocetka)\n");
		un: printf("\nUnesite broj opcije koju zelite: "); scanf(" %d",&broj); fflush(stdin);
		if(broj!=1)
			if(broj==2)
			{	
				system("cls");
				main();	
			}
			else
			{
				printf("\n Pogresan unos\n");
				goto un;
			}

		printf("\n\nUnesite Vase ime: "); scanf("%s",(ptr_igrac+i)->ime); fflush(stdin);
		system("cls");
		printf("\n*************Zdravo %s!**************\n",(ptr_igrac+i)->ime);

start:	if(doz_br>3)/*Provera da li su odigrane sve kategorije*/
		{
			printf("\n\nUspesno ste odigrali sve kategorije\n\n"); 
			goto rez;

		}

		printf("\n    Izaberite kategoriju \n\n");
		printf("1. Knjizevnost\t 2. Geografija\n");
		printf("3. Istorija\t 4. Film\n");
		printf("\nUnesite broj opcije koju zelite: "); scanf("%d",&broj);fflush(stdin);
		system("cls");

		switch(broj)
		{
			case 1:
				if(br1>0)	/*Provera da li je vec odigrana data kategorija */
				{
					printf("\n Vec ste odigrali ovu kategoriju!\n\n");  
					goto start;
			
				}
			
				knjizevnost(igrac1,i);
				printf("\n\nZelite da nastavite sa igrom?(D za DA, bilo koji taster za izlaz): "); c=getchar(); fflush(stdin);
				puts("\n");
				if(c=='d' || c=='D')
				{
					br1++;
					system("cls");
					goto start;
				}
				else
					break;

			case 2:
				if(br2>0)
					{
						printf("\n Vec ste odigrali ovu kategoriju!\n\n");
						goto start;
			
					}

				geografija(igrac1,i);
				printf("\n\nZelite da nastavite sa igrom?(D za DA, bilo koji taster za izlaz): "); c=getchar(); fflush(stdin);
				puts("\n");
				if(c=='d' || c=='D')
				{
					br2++;
					system("cls");
					goto start;
				}
				else
					break;
			case 3:
				if(br3>0)
				{
					printf("\n Vec ste odigrali ovu kategoriju!\n\n");
					goto start;
			
				}

				istorija(igrac1,i);
				printf("\n\nZelite da nastavite sa igrom?(D za DA, bilo koji taster za izlaz): "); c=getchar(); fflush(stdin);
				puts("\n");
				if(c=='d' || c=='D')
				{
					br3++;
					system("cls");
					goto start;
				}
				else
					break;
			case 4:
				if(br4>0)
				{
					printf("\n Vec ste odigrali ovu kategoriju!\n\n");
					goto start;
			
				}

				film(igrac1,i);
				printf("\n\nZelite da nastavite sa igrom?(D za DA, bilo koji taster za izlaz): "); c=getchar(); fflush(stdin);
				puts("\n");
				if(c=='d' || c=='D')
				{
					br4++;
					system("cls");
					goto start;
				}
				else
					break;

			default:
				printf("\nNiste uneli nijednu ponudjenu opciju!\n\n"); goto start;
			}
		
			system("cls");
	rez:	rezultat(igrac1,i);

			printf("\n\n\nZapoceti ispocetka?(D za DA/bilo koji taster za NE): "); c=getchar(); fflush(stdin);

			if(c=='d' || c=='D')
			{
				system("cls");
				continue;
			}

			else
			{
				printf("\n\nDovidjenja %s! :)\n",(ptr_igrac+i)->ime);
				exit(0); 
				free(igrac1);
			}
			
		}

		printf("\n\nDovidjenja! :)\n");
		exit(0); 
		free(igrac1);
}

/*Naredne 4 funkcije su kategorije sa pitanjima*/

void knjizevnost(struct igrac *ptr_igrac,int i)
{
	int br; 

	printf("                Knjizevnost\n\n");

	/*Prvo pitanje iz knjizevnosti*/
	printf(" I. Ivo Andric je dobio Nobelovu nagradu za:\n\n");
	printf(" 1) Roman na Drini cuprija\n 2) Za doprinost knnjizevnosti\n 3) Roman Prokleta avlija");
	odg1: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br);fflush(stdin);

	if(br==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br==1 || br==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg1;
		}
	
	/*Drugo pitanje iz knjizevnosti*/
	printf("\n\n II. Ko je napisao Dervis i smrt :\n\n");
	printf(" 1) Branko Copic\n 2) Dobrica Cosic\n 3) Mesa Selimovic");
	odg2: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br);fflush(stdin);

	if(br==3)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br==1 || br==2)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg2;
		}

	/*Trece pitanje iz knjizevnosti*/
	printf("\n\n III. Zivot i prikljucenije je autobiografija kog pisca:\n\n");
	printf(" 1) Branko Nusic \n 2) Laza Kostic\n 3) Dositej Obradovic");
	odg3: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br);fflush(stdin);

	if(br==3)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br==1 || br==2)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}

		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg3;
		}

	/*Cetvrto pitanje iz knjizevnosti*/
	printf("\n\n IV. Kako se zove konj u Marka Kraljevica:\n\n");
	printf(" 1) Kokan \n 2) Sarac\n 3) Ilija");
	odg4: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br);fflush(stdin);

	if(br==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br==1 || br==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg4;
		}

	/*Peto pitanje iz knjizevnosti*/
	printf("\n\n V. Santa Maria della Salute je napisao:\n\n");
	printf(" 1) Laza Kostic \n 2) Jovan Jovanovic Zmaj\n 3) Mika Antic");
	odg5: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br);fflush(stdin);

	if(br==1)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br==2 || br==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg5;
		}

		doz_br++; 


}

void geografija(struct igrac *ptr_igrac,int i)
{
	int br1; 

	printf("                Geografija\n\n");

	/*Prvo pitanje iz geografije*/
	printf(" I. Najzapadnija kontinentalna tacka Evrope je:\n\n");
	printf(" 1) Kabo da Roka, Portugalija\n 2) Cois Na Sionna, Portugalija\n 3) Pontevedra, Spanija");
	odg1: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br1);fflush(stdin);

	if(br1==1)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br1==2 || br1==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg1;
		}
	
	/*Drugo pitanje iz geografije*/
	printf("\n\n II. Najdublje jezero na svetu je:\n\n");
	printf(" 1) Jezero Malavi\n 2) Bajkalsko jezero\n 3) Kaspijsko jezero");
	odg2: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br1);fflush(stdin);

	if(br1==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br1==1 || br1==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg2;
		}

	/*Trece pitanje iz geografije*/
	printf("\n\n III. Kako se zove narodna nosnja japana:\n\n");
	printf(" 1) Sari \n 2) Kilt\n 3) Kimono");
	odg3: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br1);fflush(stdin);

	if(br1==3)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br1==1 || br1==2)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}

		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg3;
		}

	/*Cetvrto pitanje iz geografije*/
	printf("\n\n IV. Glavni grad Finske je :\n\n");
	printf(" 1) Edinburg\n 2) Helsinki\n 3) Oslo");
	odg4: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br1);fflush(stdin);

	if(br1==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br1==1 || br1==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg4;
		}

	/*Peto pitanje iz geografije*/
	printf("\n\n V. Koliko kontinenata ima na svetu:\n\n");
	printf(" 1) 5 \n 2) 7\n 3) 6");
	odg5: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br1);fflush(stdin);

	if(br1==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br1==1 || br1==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg5;
		}

		doz_br++;
}

void istorija(struct igrac *ptr_igrac,int i)
{
	int br2; 

	printf("               Istorija\n\n");

	/*Prvo pitanje iz istorije*/
	printf(" I. Kosovska bitka odigrala se:\n\n");
	printf(" 1) 1398.godine\n 2) 1938. godine\n 3) 1389. godine");
	odg1: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br2);fflush(stdin);

	if(br2==3)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br2==1 || br2==2)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg1;
		}
	
	/*Drugo pitanje iz istorije*/
	printf("\n\n II. Gde je rodjen poznati crnogorski junak Nikola Tomanovic\n zvani Nikac:\n\n");
	printf(" 1) Cetinje\n 2) Niksic\n 3) Rovin");
	odg2: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br2);fflush(stdin);

	if(br2==3)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br2==1 || br2==2)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg2;
		}

	/*Trece pitanje iz istorije*/
	printf("\n\n III. Ko je ubio austrijskog prestolonaslednika Franca Ferdinanda,\n cije se ubistvo smatra za motiv Prvog svetskog rata:\n\n");
	printf(" 1) Dragutin DImitrijevic Apis\n 2) Gavrilo Princip\n 3) Antonije Antic");
	odg3: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br2);fflush(stdin);

	if(br2==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br2==1 || br2==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}

		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg3;
		}

	/*Cetvrto pitanje iz istorije*/
	printf("\n\n IV. U drzavnom udaru Majski prevrat ubijeni su:\n\n");
	printf(" 1) kralj Milan Obrenovic i kneginja Natalija \n 2) kralj Petar I Karadjoredjevic i kneginja Zorka\n 3) kralj Aleksandar Obrenovic i kraljica Draga");
	odg4: printf("\n\nUnesite broj opcije koju zelite: "); scanf("%d",&br2);fflush(stdin);

	if(br2==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br2==1 || br2==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg4;
		}

	/*Peto pitanje iz istorije*/
	printf("\n\n V. Kad je pocela francuksa revolucija:\n\n");
	printf(" 1) 1789. godine \n 2) 1799. godine\n 3) 1793. godine");
	odg5: printf("\n\nUnesite broj opcije koju zelite: "); scanf("%d",&br2);fflush(stdin);

	if(br2==1)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br2==2 || br2==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg5;
		}

		doz_br++;
}

void film(struct igrac *ptr_igrac,int i)
{
		int br3; 

	printf("               Film\n\n");

	/*Prvo pitanje iz filma*/
	printf(" I. Za koji film je Leonardo DiCaprio dobio oskara?:\n\n");
	printf(" 1) The Wolf of Wall Street\n 2) The Revenant\n 3) Blood Diamond");
	odg1: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br3);fflush(stdin);

	if(br3==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br3==1 || br3==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg1;
		}
	
	/*Drugo pitanje iz filma*/
	printf("\n\n II. Koje godine je snimljen Titanic?\n\n");
	printf(" 1) 1997. godine\n 2) 1998. godine\n 3) 2000. godine");
	odg2: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br3);fflush(stdin);

	if(br3==1)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br3==2 || br3==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg2;
		}

	/*Trece pitanje iz filma*/
	printf("\n\n III. Ko je glumio Don Vito Corleone-a u filmu The Godfather:\n\n");
	printf(" 1) Al Pacino\n 2) Marlon Brando\n 3) James Caan");
	odg3: printf("\n\nUnesite redni broj odgovora: "); scanf("%d",&br3);fflush(stdin);

	if(br3==2)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br3==1 || br3==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}

		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg3;
		}

	/*Cetvrto pitanje iz filma*/
	printf("\n\n IV. Ko je glumio boksera u filmu Lajanje na zvezde:\n\n");
	printf(" 1) Dragan Micanovic\n 2) Nebojsa Milovanovic\n 3) Nikola Djuricko");
	odg4: printf("\n\nUnesite broj opcije koju zelite: "); scanf("%d",&br3);fflush(stdin);

	if(br3==3)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br3==1 || br3==2)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg4;
		}

	/*Peto pitanje iz filma*/
	printf("\n\n V. Koji domaci glumac ima najvise snimljenih filmova u jednoj drzavi:\n\n");
	printf(" 1) Bata Zivojinovic\n 2) Nikola Simic\n 3) Dragan Jovanovic");
	odg5: printf("\n\nUnesite broj opcije koju zelite: "); scanf("%d",&br3);fflush(stdin);

	if(br3==1)
	{
		printf("\n\nTacan odgovor! Osvojili ste 5 poena");
		(ptr_igrac+i)->rezultat+=5;
		printf("\n\n---------------------------------------\n");
		printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
		printf("\n---------------------------------------\n");
	}
	else
		if(br3==2 || br3==3)
		{
			printf("\n\nNetacan odgovor! Osvojili ste 0 poena\n");
			printf("\n---------------------------------------\n");
			printf("Trenutni rezultat: %d",(ptr_igrac+i)->rezultat);
			printf("\n---------------------------------------");
		}
		else
		{
			printf("\n\nNije validan odgovor! Pokusajte ponovo");
			goto odg5;
		}

		doz_br++;
}

void rezultat(struct igrac *ptr_igrac,int i)/*Funckija koja prikazuje rezultat koji je igrac postigao igrajuci */
{
	char c;

	printf("Cestitamo %s !\nVas konacni rezultat je: %d\n",(ptr_igrac+i)->ime,(ptr_igrac+i)->rezultat);
	printf("\n\nPogledaj tabelu rezultata? (D za DA/nilo koji taster za NE): "); c=getchar(); fflush(stdin);

		if(c=='d' || c=='D')
		{
			system("cls");
			lista_rezultata(igrac1,i);
		}
}

void lista_rezultata(struct igrac *ptr_igrac,int i) /*Funkcija koja prikazuje listu imena i rezultata od 5 mogucih igraca*/
{
	int k=1,j=0;
	char bafer1[MAX+1],c;
	FILE *fptr;

	
	printf("Ime i poeni -> ");

	/*Otvaranje datoteke za upis*/
	if((fptr=fopen("listrez.txt","w"))==NULL)
		printf("\nGreska pri otvaranju datoteke za citanje\n");
	
	while(j<i+1)
	{
		fprintf(fptr,"| %d. %s\t%d|",k,(ptr_igrac+j)->ime,(ptr_igrac+j)->rezultat);
		j++; k++;
	}
			fclose(fptr);


	/*Otvaranje datoteke za citanje*/
	if((fptr=fopen("listrez.txt","r"))==NULL)
		printf("\nGreska pri otvaranju datoteke za citanje\n");

	while(!feof(fptr))
	{
		fgets(bafer1, MAX+1,fptr);
		puts(bafer1);
		
	}

	fclose(fptr);

	if(doz_br>3)
	{
		if(i>MAX)
		{
			printf("\n\nDovidjenja %s! :)\n",(ptr_igrac+i)->ime);
			exit(0);
		}
	
	}

	
}

	