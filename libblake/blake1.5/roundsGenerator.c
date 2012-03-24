#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *table[8][4] = {
  { "0", "4", "8", "12"}, 
  { "1", "5", "9", "13"}, 
  { "2", "6", "10", "14"}, 
  { "3", "7", "11", "15"}, 
  { "0", "5", "10", "15"}, 
  { "1", "6", "11", "12"}, 
  { "2", "7", "8", "13"}, 
  { "3", "4", "9", "14"}, 
}; 

const char map[] = "abcd"; 
char *state_name; 
 int getChar(int c){
   int i=0; 
   for (i =0; i < 4 ; i++){
     if (map[i] == c) return i; 
   }
   printf("SAIIIIIIIIIINDO %d", 10); 
   exit(-1); 
 }

char *temp = "*a = ADD32((*a),(*b))+XOR32(m[s[r][i]], c[s[r][i+1]]);\n" \
	 "*d = ROT32(XOR32((*d),(*a)),16);\n" \
	 "*c = ADD32((*c),(*d));\n" \
	 "*b = ROT32(XOR32((*b),(*c)),12);\n" \
	 "*a = ADD32((*a),(*b))+XOR32(m[s[r][i+1]], c[s[r][i]]);\n" \
	 "*d = ROT32(XOR32((*d),(*a)), 8);\n" \
	 "*c = ADD32((*c),(*d));\n" \
         "*b = ROT32(XOR32((*b),(*c)), 7);\n";
char *anotherLevelOfIndirection; 
char *temp64 = "*a = ADD64((*a),(*b))+XOR64(m[s[r][i]], c[s[r][i+1]]); \n\
    *d = ROT64(XOR64((*d),(*a)),32); \n\
    *c = ADD64((*c),(*d)); \n\
    *b = ROT64(XOR64((*b),(*c)),25); \n\
    *a = ADD64((*a),(*b))+XOR64(m[s[r][i+1]], c[s[r][i]]); \n\
    *d = ROT64(XOR64((*d),(*a)),16); \n\
    *c = ADD64((*c),(*d)); \n\
    *b = ROT64(XOR64((*b),(*c)),11); \n"; 

void cospeTemplate(int r, int i,const char * type){
   int indexx;
   char *str = anotherLevelOfIndirection; 
   while (*str){
     switch(*str){
     case 's': 
       printf("sigma"); 
       break; 
     case '*': 
       str++; 
       indexx = getChar(*str); 
       printf(" (*%s%s) ", state_name, table[i/2][indexx]); 
       break; 
     case 'r': 
       printf("%d", r); 
       break;
     case 'i': 
       printf("%d", i); 
       break; 
     default: 
       putchar(*str); 
     }
     str++;
   }
 }

 int main(int argc, char **argv){
   int rounds, i; 
   if (argc != 2 ){
     printf("Usage : %s [-32 | -64]\n", argv[0]); 
     return 1; 
   }
   char *type; 
   int nrounds;
switch(argv[1][1]){
   case '6': 
     state_name = "v";
     anotherLevelOfIndirection = temp64;
     type = "64";
     nrounds = 16; 
     break;
   case '3': 
     state_name = "v"; 
     anotherLevelOfIndirection = temp; 
     type = "32"; 
     nrounds = 14; 
     break; 
   default : 
     printf("Usage : %s [-32 | -64]\n", argv[0]); 
     return 1; 
  }

for (rounds = 0 ; rounds < nrounds ; rounds++){
    printf("//ROUND :::::::::::: %d\n", rounds); 
    for (i=0 ; i <= 14 ; i += 2){
      printf("//round : %d , i: %d\n", rounds, i); 
      cospeTemplate(rounds,i,type); 
      printf("\n\n"); 
    }
  }
}
