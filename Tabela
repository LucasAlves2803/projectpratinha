#include <iostream>
#include <iomanip>

using namespace std;
struct times {
   string time;
   int vit,emp,der,jog,golfv,golso;
   int pt,sg;
};
typedef times clubes;
void partida(clubes []);
void resultado(clubes *);
void pontos (clubes *,int);
void gols(clubes *,int);
void tabela(clubes *, int);
void ordenacao(clubes *, int);
void troca(int *, int *);
void trocastring(string*, string*);

int main()
{
   clubes dupla[2];
   partida(dupla);
   tabela(dupla,2);
   ordenacao(dupla,2);
   tabela(dupla,2);
    return 0;
}

void partida(clubes d[])
{  int i,todos=2;
   d[0].time = "Flamengo";
   d[1].time = "Botafogo";
   for (i=0; i<todos ;i++){
       d[i].vit = 0;
       d[i].emp = 0;
       d[i].der = 0;
       d[i].jog = 0;
       d[i].golfv = 0;
       d[i].golso = 0;
       d[i].sg = 0;
       d[i].pt = 0;
   }
    // a ideia é que o resultado do jogo seja lido por um arquivo (agora vou usar uma API)
    // para teste eu coloco um resultado qualquer
    d[0].jog++;
    d[1].jog++;
    d[0].golfv = 3;
    d[1].golfv = 3;
    resultado(d);
    pontos(d,todos);
    gols(d,todos);
  }
/*
void zera (clubes * d, int todos)
{
   for (i=0; i<todos ;i++){
       d[i].vit = 0;
       d[i].emp = 0;
       d[i].der = 0;
       d[i].jog = 0;
       d[i].golfv = 0;
       d[i].golso = 0;
       d[i].sg = 0;
       d[i].pt = 0;
   }
}
*/
void resultado (clubes  *d){
    if (d[0].golfv > d[1].golfv){
        d[0].vit++;
        d[1].der++;
    }
    else if (d[0].golfv < d[1].golfv){
        d[1].vit++;
        d[0].der++;
    }
    else{
        d[1].emp++;
        d[0].emp++;
    }
}

void pontos (clubes * d, int todos)
{   int i;
    for (i=0; i < todos; i++)
    d[i].pt = 3*d[i].vit + d[i].emp;
}

void gols (clubes * d,int todos){
   int i;
   d[0].golso += d[1].golfv;
   d[1].golso += d[0].golfv;
   for(i=0; i < todos; i++)
        d[i].sg = d[i].golfv - d[i].golso;
}

void tabela (clubes * d, int todos){
int i;
cout << setw(12) << left << "Time" << setw(3) << " P" << setw(3) << " V" << setw(3) <<" J" << setw(3) << " E" << setw(3) << " D" << setw(3) << "GP" << setw(3) << "GC" << setw(3) << "SG"  << setw(3) << endl;
for (i =0 ; i < todos; i++){
cout << setw(13) << left << d[i].time << setw(3) << d[i].pt << setw(3) << d[i].vit << setw(3) << d[i].jog << setw(3) << d[i].emp
<< setw(3) << d[i].der << setw(3) << d[i].golfv << setw(3) << d[i].golso << setw(3) << d[i].sg << endl;
}
}

void ordenacao (clubes * d, int todos){
    int i , j;
    int maxi=0;
    for (i=0; i < todos-1; i++){
        maxi= i;
        for (j=i+1; j < todos; j++){
            if (d[j].pt >= d[maxi].pt){
                if (d[j].pt == d[maxi].pt){
                    if (d[j].vit >= d[maxi].vit){
                        if (d[j].vit == d[maxi].vit){
                            if (d[j].golfv >= d[maxi].golfv){
                                if (d[j].golfv == d[maxi].golfv){
                                    if (d[j].sg >= d[maxi].sg){
                                        if (d[j].sg == d[maxi].sg){
                                            // ordeno por ordem alfabética
                                            if (d[j].time < d[maxi].time)
                                                maxi = j;
                                        }
                                        else maxi = j;
                                    }
                                }
                                else maxi = j;
                            }
                        }
                        else maxi = j;
                    }
                }
                else maxi = j;
            }
        }
        // ainda vai ter outro recurso de calcular quantas posições um time mudou
        trocastring(&d[i].time, &d[maxi].time);
        troca(&d[i].vit,&d[maxi].vit);
        troca(&d[i].emp,&d[maxi].emp);
        troca(&d[i].der,&d[maxi].der);
        troca(&d[i].jog,&d[maxi].jog);
        troca(&d[i].golfv,&d[maxi].golfv);
        troca(&d[i].golso,&d[maxi].golso);
        troca(&d[i].pt,&d[maxi].pt);
        troca(&d[i].sg,&d[maxi].sg);
    }
}

void troca (int * i, int * j){
 int aux;
 aux = *i;
 *i = *j;
 *j = aux;
}

void trocastring(string * nom1, string * nom2){
 string aux;
 aux = *nom1;
 *nom1 = *nom2;
 *nom2 = aux;
}
