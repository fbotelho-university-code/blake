#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "defs.h"
#include "blake256.h"	
#include <string.h>

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

//ficheiro 1
unsigned char *data1;
char *digest1, *digest2;
#define SIZE1 9597
//ficheiro2
unsigned char *data2;
char *digest3, *digest4;
#define SIZE2 1069374
//ficheiro 3
unsigned char *data3;
char *digest5, *digest6;
#define SIZE3 10538218

FILE *file = NULL;
FILE *output = NULL;

/*
* data      - input buffer that we want to calculate the digest
* len       - number of bytes of the input buffer
* salt      - input buffer with the optional salt value
* lenDigest - desired number of bytes of the digest (either 32 or 64)
* digest    - (pre-allocated) buffer where the digest should be returned
*/
void BLAKE(unsigned char *data, unsigned len, unsigned
	char *salt, unsigned lenDigest, char *digest);


//vai ler a informacao do ficheiro
unsigned char* readFile(char *name, int size){
	//abre o ficheiro
	file = fopen(name, "r");
	if(file == NULL){
		perror("Erro a abrir o ficheiro - readFile\n");
		exit(-1);
	}
	//bloco de dados para o conteudo do ficheiro
	unsigned char *data = (unsigned char *)malloc((size+1)*sizeof(unsigned char));
	if(data==NULL){
		perror("Erro a alocar memoria para o ficheiro - readFile1\n");
		fclose(file);
		exit(-1);
	}
	//leitura do ficheiro
	int read = fread(data, 1, size, file);
	fclose(file);
	if(read != size){
		perror("Erro a ler o ficheiro - readFile1\n");
		free(data);
		exit(-1);
	}     
	return data;
}


//funcao que inicia os digest
void initDigest(){
	//ficheiro 1
	digest1 = (char *)malloc(33*sizeof(char));
	digest2 = (char *)malloc(65*sizeof(char));
	//ficheiro2
	digest3 = (char *)malloc(33*sizeof(char));
	digest4 = (char *)malloc(65*sizeof(char));
	//ficheiro 3
	digest5 = (char *)malloc(33*sizeof(char));
	digest6 = (char *)malloc(65*sizeof(char));

// ---------- ESCOLHER UMA OPCAO ----------
	if(digest1 == NULL || digest2 == NULL || digest3 == NULL ||  digest4 == NULL|| digest5 == NULL || digest6 == NULL){
		perror("Erro a alocar memoria dos digest!\n");
		exit(-1);
	}
// -----------                   ----------
	if(digest1 == NULL){
		perror("Erro a alocar memoria dos digest1!\n");
		exit(-1);
	}
	if(digest2 == NULL){
		perror("Erro a alocar memoria dos digest2!\n");
		free(digest1);
		exit(-1);
	}
	if(digest3 == NULL){
		perror("Erro a alocar memoria dos digest3!\n");
		free(digest1);
		free(digest2);
		exit(-1);
	}
	if(digest4 == NULL){
		perror("Erro a alocar memoria dos digest4!\n");
		free(digest1);
		free(digest2);
		free(digest3);
		exit(-1);
	}		
	if(digest5 == NULL){
		perror("Erro a alocar memoria dos digest5!\n");
		free(digest1);
		free(digest2);
		free(digest3);
		free(digest4);
		exit(-1);
	}	
	if(digest6 == NULL){
		perror("Erro a alocar memoria dos digest6!\n");
		free(digest1);
		free(digest2);
		free(digest3);
		free(digest4);
		free(digest5);
		exit(-1);
	}
}

//funcao para obter os tempos e evocar o blake
void runFile(char *filename, int numfile, int mode){
	if(numfile == 1){ //ficheiro 1
		if(mode == 32){
			//tempo inicial
			gettimeofday(&begin, NULL);
			BLAKE(data1, SIZE1, salt, 32, digest1);
			//tempo final
			gettimeofday(&end, NULL);
			//colocar o hash num ficheiro diferente
			file = fopen("10k_256","w");
			//fwrite(digest1, 1, 32, file);	
		}else{
			//tempo inicial
			gettimeofday(&begin, NULL);
			BLAKE(data1, SIZE1, salt, 64, digest2);
			//tempo final
			gettimeofday(&end, NULL);
			//colocar o hash num ficheiro diferente
			file = fopen("10k_512","w");
			//fwrite(digest2, 1, 64, file);	
		}			
	}else if(numfile ==2){ //ficheiro 2
		if(mode == 32){
			//tempo inicial
			gettimeofday(&begin, NULL);
			//BLAKE(data2, SIZE2, salt, 32, digest3);
			//tempo final
			gettimeofday(&end, NULL);
			//colocar o hash num ficheiro diferente
			file = fopen("1M_256","w");
			//fwrite(digest3, 1, 32, file);	
		}else{
			//tempo inicial
			gettimeofday(&begin, NULL);
			//BLAKE(data2, SIZE2, salt, 64, digest4);
			//tempo final
			gettimeofday(&end, NULL);
			//colocar o hash num ficheiro diferente
			file = fopen("1M_512","w");
			//fwrite(digest4, 1, 64, file);	
		}
	}else{ //ficheiro 3
		if(mode == 32){
			//tempo inicial
			gettimeofday(&begin, NULL);
			//BLAKE(data3, SIZE3, salt, 32, digest5);
			//tempo final
			gettimeofday(&end, NULL);
			//colocar o hash num ficheiro diferente
			file = fopen("10M_256","w");
			//fwrite(digest5, 1, 32, file);	
		}else{
			//tempo inicial
			gettimeofday(&begin, NULL);
			//BLAKE(data3, SIZE3, salt, 64, digest6);
			//tempo final
			gettimeofday(&end, NULL);
			//colocar o hash num ficheiro diferente
			file = fopen("10M_512","w");
			//fwrite(digest6, 1, 64, file);	
		}
	}
	//fechar o ficheiro que contem o hash
	fclose(file);
	//abrir ficheiro para colocar a informacao do tempo.
	output = fopen("result","a+");	
	printTime(output, filename, begin, end);
	fclose(output);
}

//fazer varios runs sonre o mesmo input
void doMultipleRuns(char* filename, int numfile, int mode){
	int run = 1;
	char *temp = (char *)malloc(30*sizeof(char));
	if(temp == NULL){
		perror("Erro a alocar memoria - doMultipleRuns.\n");
		exit(-1);
	}

	while(run <= 1){
		//formatar a string para colocar no ficheiro de benchmark
		snprintf(temp,30, "%s%d ", filename,run);
		runFile(temp, numfile, mode);
		run++;
	}
	free(temp);
}

void main(int argc , char **argv){
  //data1 = readFile(argv[1], SIZE1);
       	data1 = readFile("10K.png", SIZE1); 
//	data2 = readFile("1MB.png", SIZE2);
//	data3 = readFile("10MB.png", SIZE3);
//	initDigest();

	//digest 256 bits
	doMultipleRuns("Ficheiro 10k.png - run ", 1, 32);
//	doMultipleRuns("Ficheiro 1M.png - run ", 2, 32);
//	doMultipleRuns("Ficheiro 10M.png - run ", 3, 32);

	//digest 512 bits
/	doMultipleRuns("Ficheiro 10k.png - run ", 1, 64);
//	doMultipleRuns("Ficheiro 1M.png - run ", 2, 64);
//	doMultipleRuns("Ficheiro 10M.png - run ", 3, 64);	

	//libertar memoria
	free(data1);
/*	free(data2);
	free(data3);
	free(digest1);
	free(digest2);
	free(digest3);
	free(digest4);
	free(digest5);
	free(digest6);
*/
}
