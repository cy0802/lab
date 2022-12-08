#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PLAYERNUM 82

int n, m, k;
int selectCols[5];
int orderCols[5];

/* FIFA 2022 PLAYER FIELDS */
typedef struct player {
  int id;                // 0
  int age;               // 1
  float potential;       // 2
  char nationality[32];  // 3
  char name[32];         // 4
} Player;

/* DO NOT MODIFY ANY DATA */
const Player o_players[PLAYERNUM] = {
    {233055, 26, 0.73, "Japan", "D. Suzuki"},
    {220488, 21, 0.68, "Italy", "F. Costa"},
    {235559, 18, 0.62, "France", "L. Alessandri"},
    {215570, 21, 0.72, "Republic of Ireland", "G. Rea"},
    {227536, 25, 0.77, "Mali", "M. Marega"},
    {223186, 20, 0.67, "Denmark", "J. Thomasen"},
    {237218, 21, 0.66, "United States", "J. Hayes"},
    {226523, 20, 0.76, "Sweden", "F. Brorsson"},
    {232718, 31, 0.66, "Japan", "Y. Takahashi"},
    {189891, 25, 0.62, "England", "F. Franks"},
    {216018, 29, 0.66, "Argentina", "J. Blanco"},
    {180819, 28, 0.83, "England", "A. Lallana"},
    {175932, 27, 0.73, "Belgium", "R. De Laet"},
    {202078, 25, 0.75, "United States", "D. Nagbe"},
    {211536, 20, 0.73, "Scotland", "M. O'Hara"},
    {213378, 25, 0.69, "Ukraine", "I. Berezovskyi"},
    {220833, 19, 0.7, "France", "A. Mandrea"},
    {189242, 24, 0.89, "Brazil", "Coutinho"},
    {220782, 20, 0.74, "France", "M. Ilaimaharitra"},
    {188135, 27, 0.78, "Spain", "Juanfran"},
    {229083, 23, 0.67, "Denmark", "C. Jakobsen"},
    {189024, 30, 0.71, "Ecuador", "M. Banguera"},
    {237599, 18, 0.68, "Italy", "A. De Angelis"},
    {227678, 18, 0.8, "England", "E. Konsa"},
    {211061, 25, 0.75, "Romania", "A. Maxim"},
    {162900, 30, 0.67, "Australia", "N. Kilkenny"},
    {173654, 28, 0.68, "Scotland", "P. McGowan"},
    {232882, 20, 0.77, "Japan", "K. Misao"},
    {208916, 29, 0.73, "Saudi Arabia", "M. Al Sahlawi"},
    {215455, 21, 0.8, "Croatia", "B. Petkovic"},
    {228348, 23, 0.71, "Morocco", "F. Rherras"},
    {237889, 17, 0.63, "Republic of Ireland", "J. Keaney"},
    {211707, 25, 0.68, "Scotland", "P. McGinn"},
    {231857, 22, 0.67, "United States", "J. Calistri"},
    {202789, 24, 0.78, "Germany", "A. Schwolow"},
    {229776, 19, 0.74, "Denmark", "M. Hedegaard"},
    {187528, 29, 0.7, "Russia", "K. Kombarov"},
    {198731, 23, 0.71, "Kosovo", "E. Rashani"},
    {207897, 24, 0.74, "Germany", "A. Jung"},
    {169386, 34, 0.74, "Italy", "S. Floccari"},
    {237966, 18, 0.71, "Portugal", "Paulo Alves"},
    {233505, 17, 0.64, "England", "R. Sandford"},
    {215004, 21, 0.68, "Argentina", "L. Salas"},
    {228613, 23, 0.69, "Saudi Arabia", "F. Al Masrahi"},
    {202921, 26, 0.72, "New Zealand", "J. Gleeson"},
    {184267, 26, 0.82, "Algeria", "Y. Brahimi"},
    {233917, 18, 0.75, "Switzerland", "D. Kutesa"},
    {235804, 19, 0.62, "Denmark", "B. Lund"},
    {211132, 22, 0.74, "Spain", "Andrés Prieto"},
    {238514, 18, 0.67, "Argentina", "A. Verdugo"},
    {230561, 18, 0.76, "Netherlands", "J. Grot"},
    {236690, 25, 0.75, "Cameroon", "M. Ngadeu-Ngadjui"},
    {235353, 18, 0.85, "Senegal", "I. Sarr"},
    {237174, 28, 0.54, "Peru", "R. Frank"},
    {201999, 23, 0.77, "England", "J. Flanagan"},
    {179475, 32, 0.71, "Ukraine", "O. Rybka"},
    {233171, 24, 0.66, "Japan", "T. Ishikawa"},
    {209162, 23, 0.69, "Colombia", "E. Correa"},
    {187942, 27, 0.74, "Benin", "R. Gestede"},
    {200653, 27, 0.74, "Argentina", "G. Burdisso"},
    {223615, 28, 0.67, "Argentina", "C. Chimino"},
    {210488, 24, 0.71, "Netherlands", "P. van Ooijen"},
    {173695, 29, 0.68, "Scotland", "M. Reynolds"},
    {162890, 30, 0.72, "United States", "J. Spector"},
    {159578, 32, 0.7, "Jamaica", "C. Donaldson"},
    {189172, 26, 0.74, "Spain", "Fidel"},
    {179586, 27, 0.68, "DR Congo", "C. Mongongu"},
    {236001, 18, 0.8, "Brazil", "Rai"},
    {179973, 27, 0.68, "Switzerland", "M. Morganella"},
    {188599, 31, 0.71, "Italy", "M. Antenucci"},
    {220041, 21, 0.69, "Switzerland", "N. Luchinger"},
    {211703, 30, 0.74, "Germany", "M. Schnatterer"},
    {214331, 29, 0.7, "Colombia", "L. Ruiz"},
    {213367, 23, 0.72, "France", "L. Abergel"},
    {209024, 23, 0.63, "Republic of Ireland", "A. Barry"},
    {201374, 26, 0.71, "Spain", "Fernandez"},
    {214899, 31, 0.58, "England", "D. Wright"},
    {215404, 24, 0.73, "Brazil", "Bruno Pires"},
    {231620, 18, 0.66, "South Africa", "B. Banda Jr."},
    {233981, 32, 0.63, "Brazil", "Alan Besseiro"},
    {194954, 25, 0.67, "Russia", "V. Ustinov"},
    {167706, 28, 0.73, "Denmark", "N. Bendtner"},
};
/* TODO: SORT SPECIFIED COLUMNS IN ASCENDING ORDER */
int compare(const void *a, const void *b) {
  /* WRITE YOUR CODE HERE */
  Player *_a = (Player*)a;
  Player *_b = (Player*)b;
  for(int i = 0; i < m; i++){
    if(orderCols[i] == 0){
        if(_a->id == _b->id) continue;
        else return (_a->id > _b->id ? 1 : -1);
    } else if(orderCols[i] == 1){
        if(_a->age == _b->age) continue;
        else return (_a->age > _b->age ? 1 : -1);
    } else if(orderCols[i] == 2){
        if((int)(_a->potential*100) == (int)(_b->potential*100)) continue;
        else return (_a->potential > _b->potential ? 1 : -1);
    } else if(orderCols[i] == 3){
        if(strcmp(_a->nationality, _b->nationality) == 0) continue;
        else return strcmp(_a->nationality, _b->nationality);
    } else if(orderCols[i] == 4){
        if(strcmp(_a->name, _b->name) == 0) continue;
        else return strcmp(_a->name, _b->name);
    }
  }
  return (_a->id > _b->id ? 1 : -1);
}

/* TODO: PRINT k PLAYERS WITH n COLUMNS AFTER SORTING */
void print(const Player *p) {
  /* WRITE YOUR CODE HERE */
  for(int i = 0; i < n; i++){
    if(selectCols[i] == 0){
        printf("%d", p->id);
    } else if(selectCols[i] == 1){
        printf("%d", p->age);
    } else if(selectCols[i] == 2){
        printf("%.2lf", p->potential);
    } else if(selectCols[i] == 3){
        printf("%s", p->nationality);
    } else if(selectCols[i] == 4){
        printf("%s", p->name);
    }
    if(i != n-1) printf(" ");
  }
  printf("\n");
  return;
}

int main() {
  int testCase;
  scanf("%d", &testCase);
  while (testCase--) {
    // read #selections, #orders, #output rows
    scanf("%d%d%d", &n, &m, &k);
    // read selected column index
    for (int i = 0; i < n; i++) {
      scanf("%d", &selectCols[i]);
    }
    // read order column index
    for (int i = 0; i < m; i++) {
      scanf("%d", &orderCols[i]);
    }
    // temp variable
    Player players[PLAYERNUM];
    // TODO : USE `memcpy` TO COPY `o_players` TO `players`
    memcpy(&players, &o_players, sizeof(o_players));
    // TODO : USE `qsort` with `compare` function above
    qsort((void*)players, PLAYERNUM, sizeof(players[0]), compare);
    // TODO : Print players via `print` function above
    for(int i = 0; i < k; i++){
        print(&players[i]);
    }
    printf("\n");
  }
  return 0;
}

