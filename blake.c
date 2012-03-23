#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/stat.h>
#include "libblake/blake.h"


/*
* Get the elapsed time in microseconds.
* Usage:
* 1) declare two timeval structures - struct timeval begin, end;
* 2) To get the time at the beginning - getTime(begin);
* 3) To get the time at the end - getTime(end);
* 4) To print the results - printTime(stdout, "", begin, end);
*/
#define getTime(BEGIN) gettimeofday(&(BEGIN),(struct timezone*)0)
#define elapTime(BEGIN, END) \
	(1e+6*((END).tv_sec - (BEGIN).tv_sec) + \
	((END).tv_usec - (BEGIN).tv_usec))
#define printTime(FILE, MESG, BEGIN, END) \
	fprintf(FILE, "Elapsed time(usec) %s :%.2f\n", \
	MESG, elapTime(BEGIN, END))
struct timeval begin, end;

/*
* data      - input buffer that we want to calculate the digest
* len       - number of bytes of the input buffer
* salt      - input buffer with the optional salt value
* lenDigest - desired number of bytes of the digest (either 32 or 64)
* digest    - (pre-allocated) buffer where the digest should be returned
*/
void BLAKE(unsigned char *data, unsigned len, unsigned
	char *salt, unsigned lenDigest, char *digest);
void BLAKE2(unsigned char *data, unsigned len, unsigned
	char *salt, unsigned lenDigest, char *digest);

//vai ler a informacao do ficheiro
unsigned char* readFile(char *name, int size){
	//abre o ficheiro
  FILE * file = fopen(name, "r");
	if(file == NULL){
		perror("Erro a abrir o ficheiro - readFile\n");
		exit(-1);
	}
	//bloco de dados para o conteudo do ficheiro
	unsigned char *data = (unsigned char *)malloc((size+6024)*sizeof(unsigned char));
	if(data==NULL){
		perror("Erro a alocar memoria para o ficheiro - readFile1\n");
		fclose(file);
		exit(-1);
	}
	//leitura do ficheiro
	int read = fread(data, 1, size, file);
	if(read != size){
		perror("Erro a ler o ficheiro - readFile1\n");
		free(data);
		fclose(file);
		exit(-1);
	}     
	fclose(file);
	return data;
}

unsigned filesize (const char *path){
  struct stat st; 
  stat(path, &st); 
  return (unsigned) st.st_size; 
}

void main(int argc , char **argv){
  //data1 = readFile(argv[1], SIZE1);
  unsigned char salt[64]; 
  unsigned char *msg2; 
  unsigned char digest2[64]; 
  int i; 

  for (i = 0 ; i < 64 ; i ++){
    salt[i] = 'a'; 
  }

  unsigned char digest[64]; 
  unsigned size;
  unsigned char *msg; 

    if (argc == 3){
        size = filesize(argv[1]); 
        msg = readFile(argv[1], size); 
	msg2 = readFile(argv[1], size); 

	//BLAKE2(msg,size, salt, atoi(argv[2]), digest);     
	getTime(begin); 
        BLAKE(msg, size, salt, atoi(argv[2]), digest);
	getTime(end); 
	elapTime(begin,end); 
	printTime(stdout, "", begin,end); 
	int result =  atoi(argv[2]); 
	if (result == 32){
	  convertNinja32(digest, 32); 
	  prettyPrinter32(digest, result , "Result: "); 
	  //prettyPrinter32(digest, result , "Result Deles: "); 
	}
	if (result == 64){
	  convertNinja64(digest, 64); 
	  prettyPrinter64(digest, result, "Result: "); 
	  //prettyPrinter64(digest2, result, "Result Deles: "); 
	}
    }
    else{
      printf("Usage: %s filePath [32 | 64]\n", argv[0]); 
    }
}
