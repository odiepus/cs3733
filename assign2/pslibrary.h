#ifndef PSLIBRARY_H
#define PSLIBRARY_H
void proto(char *s1, char *s2, int x1, int y1, int z1,
           int x2, int y2, int z2);

void sjf(char *s1, char *s2, int x1, int y1, int z1,
         int x2, int y2, int z2);

void psjf(char *s1, char *s2, int x1, int y1, int z1,
          int x2, int y2, int z2);

void rr(char *s1, char *s2, int q, int x1, int y1, int z1,
        int x2, int y2, int z2);

void display(char *heading, char *s1, char *s2);
#endif // PSLIBRARY_H
