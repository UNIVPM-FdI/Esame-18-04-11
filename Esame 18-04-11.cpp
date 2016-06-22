#include <iostream>
#include <fstream>
#define MAX 50
using namespace std;
int conta_caratteri(char[]);
//int conta_caratteri2(char[]);//funzione in piu per fare il metodo mio
void leggi_nome_file(char []);
int contaparole(char [], char[]);
void cercaparola(char []);
//bool uguali(char [],char[]);//funzione in piu per fare il metodo mio
int main(){
char s;
char file[16],parola[MAX];
leggi_nome_file(file);
do{
do{
cout << "\nScegli cosa vuoi fare:\n";
cout << "\na) Contare quante volte si ripete una parola nel file";
cout << "\nb) Trovare la parola piu' lunga tra tutte quelle presenti nel file";
cout << "\nc) Cambiare il file da processare";
cout << "\nd) Per uscire dal programma\n";
cout << "\nScelta:";
cin>>s;
if(s!='a'&&s!='b'&&s!='c'&&s!='d')
    cout<<"lettera non contentita"<<endl;
}while(s!='a'&&s!='b'&&s!='c'&&s!='d');
cin.get();
switch(s){
    case 'a':{
        cout<<"inserisci la parola che vuoi cercare"<<endl;
        cin>>parola;
        cout<<"la parola "<<parola<<" e' presente nel file "<<contaparole(parola,file)<<" volte"<<endl;
    break;
    }
    case 'b':{
        cout<<"le parole più lunghe sono"<<endl;
        cercaparola(file);
    break;
    }
    case 'c':{
        leggi_nome_file(file);
    break;
    }
}
}while(s!='d');
}


int conta_caratteri(char b[]){
    int i=0;
    while(b[i]!='\0'){
        i++;
    }
    return i;
}

void leggi_nome_file(char a[]){
  do{
    cout<<"inserisci il nome del file di input"<<endl;
    cin>>a;
    if(conta_caratteri(a)>=15){
        cout<<"lunghezza del file non valida"<<endl;
        cout<<"inserisci massimo 15 caratteri"<<endl;
    }
  }while(conta_caratteri(a)>=15);
}
/*
int conta_caratteri2(char parola[]){
 int i=0;
    while(parola[i]!='.'&&parola[i]!=','&&parola[i]!=';'&&parola[i]!=':'&&parola[i]!='?'&&parola[i]!='"'&&parola[i]!='!'&&parola[i]!='^'&&parola[i]!='/'&&parola[i]!='\\'&&parola[i]!='\n'&&parola[i]!=' '){
        i++;
    }
    return i;
}

bool uguali(char a[],char b[]){
    int i=0;
    bool flag=false;
while(a[i]!='\0'){
    if(a[i]==b[i]){
        i++;
        flag=true;
    }
    else flag=false;
}
if(flag)return true;
else return false;
}
*/
int contaparole(char p[], char nomefile[])
{
char c;
int i = 0, cont = 0, n=0, m=0;
char appoggio[MAX];
fstream input;
input.open(nomefile,ios::in);
n = conta_caratteri(p);
while(input.get(c))
{
while(i < 50 && (c != ' ' && c != '\n' && c != ',' && c != '.' && c != ';' && c != ':' && c != '!' && c != '?'))
{
appoggio[i] = c;
i++;
input.get(c); //Fa la stessa cosa di sopra
}
appoggio[i] = '\0';
i = 0;
m = conta_caratteri(appoggio);
if(n == m)
{
do{
if(p[i] == appoggio[i])
i++;
else
i = 100;
}while(i < n);
if(i == n)
cont ++;
}
i = 0;
}
input.close();
return cont;
}

void cercaparola(char nomefile[])
{
char c;
int i = 0, cont = 0, max = 0, n=0;
char appoggio[MAX];
fstream input1, input2;
input1.open(nomefile,ios::in);
while(input1.get(c))//prendo un carattere alla volta dal testo
    {
while(i < 50 && (c != ' ' && c != '\n' && c != ',' && c != '.' && c != ';' && c != ':' && c != '!' && c != '?'))//controllo se superiore a 50 o sia punteggiatura
{
appoggio[i] = c;//lo copio dentro a appoggio
i++;
input1.get(c);//serve per uscire dal while e serve per leggere fino alla fine della parola
}
appoggio[i] = '\0';
i = 0;
n = conta_caratteri(appoggio);
if(n > max)
{
max = n;
cont = 1;
}
else if(n == max)
cont++;
}
input1.close();
input2.open(nomefile,ios::in);
while(input2.get(c) && cont != 0)
{
while(i < 50 && (c != ' ' && c != '\n' && c != ',' && c != '.' && c != ';' && c != ':' && c != '!' && c != '?'))
{
appoggio[i] = c;
i++;
input2.get(c);
}
appoggio[i] = '\0';
i = 0;
n = conta_caratteri(appoggio);
if(n == max)
{
    cout << appoggio << endl;
cont--;
}
}
input2.close();
}

//Coded by DarkCerfa
