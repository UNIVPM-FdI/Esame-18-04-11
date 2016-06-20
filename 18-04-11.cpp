#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
fstream giulia;

/* Questa funzione conta i caratteri del nome del file e restituisce tale valore */
int conta_caratteri(char b[])
{
	int i=0;
	while (b[i] != '\0')
	{ i++;}
	return i;
}
/* Questa procedura legge da tastiera il nome del file e controlla che esso non superi la lunghezza prefissata */
void leggi_nome_file(char a[])
{
int d=conta_caratteri(a);
while (d>15)
{
	cout << "Devi inserire un nome con al massimo 15 caratteri:"<< endl;
	cin >> a;
	d=conta_caratteri(a);
}
}
// Questa funzione conta quante volte la parola data da tastiera si ripete nel testo del file
int contaparole(char p[], char nomefile[])
{
	int i=0,d=0;
	char c;
	char nome[50];
	int contatore=0;
	bool f=false;
	giulia.open(nomefile,ios::in);
while(giulia.get(c)) // se usate il get che prende l'intera parola avete il problema che vi prende anche i segni ortografici
{
	while(i < 50 && (c != ' ' && c != '\n' && c != ',' && c != '.' && c != ';' && c != ':' && c != '!' && c != '?'))
	{ //cicla finche non incontra un segno ortografico
		nome[i]=c; // metto ogni lettere letta nella stringa
		i++;
		//cout << "i= " << i << endl;
		giulia.get(c);
		}
	while (i>0)
	{
		if (p[d]==nome[d]) // vado a verificare se le parole sono uguali
		{
			f=true;
			d++; // incremento d per continuare la lettura
		//	cout << "d= " << d << endl; li ho lasciati, sono per verificare l'intera procedura
			i=i-1; //... e decremento i
		//	cout << "i= " << i << endl; li ho lasciati, sono per verificare l'intera procedura
		}
		else {
			f=false;
			i=0; // se non è uguale finisce l'operazione di confronto
		}
	}

	if(f) contatore=contatore+1; // se f è true, ha trovato la parola e incrementa il contatore
	//cout << "contatore= " << contatore << endl; mi è servito a verificare la procedura
	f=false; // riparte il primo while, leggendo un nuova parola
	i=0; // riparte il primo while, leggendo un nuova parola
	d=0; // riparte il primo while, leggendo un nuova parola
}
giulia.close();
return contatore;
}
// Questa procedura cerca le parole più lunghe tra tutte quelle presenti nel testo del file
int cercaparola(char nomefile[])
{
	int i=0,f,g=0,b=0;
	char nome[20],h[20],c;
	giulia.open(nomefile,ios::in);
	while(giulia.get(c))
	{
	while(i < 50 && (c != ' ' && c != '\n' && c != ',' && c != '.' && c != ';' && c != ':' && c != '!' && c != '?'))
	{
		nome[i]=c;
		i++;
		giulia.get(c);
		}
		while (i>0)
		{
		f=conta_caratteri(nome); //mi dica quanti caratteri ha la parola
		if (f>g) // vede se f è piu grande di g
	{
		g=f; // se si g prende il valore di f
		strcpy(h,nome); // mi scocciavo a fare con il while, prendo la parola lette e la metto in h
		i=0;	// riparte il ciclo
		}
		else i=0; // riparte il ciclo
		}
	}
	cout << "la parola piu' lunga e' " << h << endl; // stampa la parola più lunga
	giulia.close();
}

int main ()
{
	char r;
	char parola[25];
	char nomefile[16];
	cout << "Inserisci il nome del file da leggere: " << endl;
	cin >> nomefile;
	leggi_nome_file(nomefile);
	
do {
	cout << "Scegli cosa vuoi fare:\na) Contare quante volte si ripete una parola nel file" << endl
 << "b) Trovare le parole piu' lunghe tra tutte quelle presenti nel file" << endl
<< "c) Caricare un nuovo file da processare" << endl
<< "d) Per uscire dal programma" << endl;
	cin >> r;
	cin.get();
	switch (r) 
	{
		case 'a' : {
			cout << "Inserisci la parola che vuoi cercare: " << endl;
			cin >> parola;
			cout << "La parola " << parola << " si ripete " << contaparole(parola,nomefile) << " volte" << endl;
		}break;
		case 'b' : {
			cercaparola(nomefile);
		} break;
		case 'c' :
		{
	cout << "Inserisci il nome del nuovo file da leggere: " << endl;
	cin >> nomefile;
	leggi_nome_file(nomefile);
		} break;
	case 'd': {	}break;
	default : {
		cout << "Hai digitato la lettera sbagliata, usa solo le lettere consentite dal Menù" << endl;
	}break;
	}
}
while (r!='d');
}
