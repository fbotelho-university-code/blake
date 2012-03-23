#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <sys/stat.h>
#include "../libblake/blake.h"	
#include <math.h>

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
	fprintf(FILE, "Elapsed time(usec) %s : %.2f\n", \
	MESG, elapTime(BEGIN, END))


struct timeval begin, end;

//vai ler a informacao do ficheiro
unsigned char* readFile(char *name, int size){
	//abre o ficheiro
  FILE * file = fopen(name, "r");
	if(file == NULL){
		perror("Erro a abrir o ficheiro - readFile\n");
		exit(-1);
	}
	//bloco de dados para o conteudo do ficheiro
	unsigned char *data = (unsigned char *)malloc((size+145)*sizeof(unsigned char));
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

int floatcmp(const void* a, const void* b){
	
    if(*(const float*)a < *(const float*)b)
        return -1;
    return *(const float*)a > *(const float*)b;
}

int main(int argc , char **argv){
  unsigned char salt[64]; 
  int i; 
	unsigned char digest[64]; 
	unsigned size;
	unsigned char *msg; 
	float values[1000];
	float median=0;
	float deviation=0;
	
	
	// Init salt
  for (i = 0 ; i < 64 ; i ++){
    salt[i] = 'a'; 
  }
	
	puts("\n		-=BLAKEMARK=-\n");
	
	// 10K
	puts("10K.png");
	size = filesize("/Users/sa/Documents/M.S.I./TS/blake/imgs/10K.png"); 
    msg = readFile("/Users/sa/Documents/M.S.I./TS/blake/imgs/10K.png", size); 

	// BLAKE-256
	puts("--BLAKE-256");
	for (i=0; i<500; i++) {
		getTime(begin);
		BLAKE(msg, size, salt, 32, digest);
		getTime(end);
		values[i] = elapTime(begin, end);
		//printTime(stdout, "10K.png (256)", begin, end);
	}
	qsort(values, 500, sizeof(float), floatcmp);

	// median
	for(i=0; i<100; i++){
		median+=(values[i]/100.0);
	}
	// deviation
	for(i=0;i<100;i++){
		deviation += powf(values[i]-median,2)/100.0;
		deviation = sqrtf(deviation);		
	}
	fprintf(stdout, "Elapsed time(usec): media=%.2f desvio=%.2f\n", median, deviation);

	if(argv[1]){	
	// BLAKE-512
	puts("--BLAKE-512");
	for (i=0; i<1000; i++) {
		getTime(begin);
		BLAKE(msg, size, salt, 64, digest);
		getTime(end);
		values[i] = elapTime(begin, end);
		//printTime(stdout, "10K.png (512)", begin, end);
	}
	qsort(values, 1000, sizeof(float), floatcmp);
	
	// median
	for(i=0; i<100; i++){
		median+=(values[i]/100.0);
	}
	// deviation
	for(i=0;i<100;i++){
		deviation += powf(values[i]-median,2)/100.0;
		deviation = sqrtf(deviation);		
	}
	fprintf(stdout, "Elapsed time(usec): media=%.2f desvio=%.2f\n", median, deviation);
	}
	// 1MB
	puts("\n1MB.bmp");
	size = filesize("/Users/sa/Documents/M.S.I./TS/blake/imgs/1MB.bmp"); 
    msg = readFile("/Users/sa/Documents/M.S.I./TS/blake/imgs/1MB.bmp", size); 
	
	// BLAKE-256
	puts("--BLAKE-256");
	for (i=0; i<500; i++) {
		getTime(begin);
		BLAKE(msg, size, salt, 32, digest);
		getTime(end);
		values[i] = elapTime(begin, end);
		//printTime(stdout, "1MB.bmp (256)", begin, end);
	}
	qsort(values, 500, sizeof(float), floatcmp);
	
	// median
	for(i=0; i<100; i++){
		median+=(values[i]/100.0);
	}
	// deviation
	for(i=0;i<100;i++){
		deviation += powf(values[i]-median,2)/100.0;
		deviation = sqrtf(deviation);		
	}
	fprintf(stdout, "Elapsed time(usec): media=%.2f desvio=%.2f\n", median, deviation);
	
	if(argv[1]){	
	// BLAKE-512
	puts("--BLAKE-512");
	for (i=0; i<1000; i++) {
		getTime(begin);
		BLAKE(msg, size, salt, 64, digest);
		getTime(end);
		values[i] = elapTime(begin, end);
		//printTime(stdout, "1MB.bmp (512)", begin, end);
	}
	qsort(values, 1000, sizeof(float), floatcmp);
	
	// median
	for(i=0; i<100; i++){
		median+=(values[i]/100.0);
	}
	// deviation
	for(i=0;i<100;i++){
		deviation += powf(values[i]-median,2)/100.0;
		deviation = sqrtf(deviation);		
	}
	fprintf(stdout, "Elapsed time(usec): media=%.2f desvio=%.2f\n", median, deviation);
	}
	// 10MB
	puts("\n10MB.bmp");
	size = filesize("/Users/sa/Documents/M.S.I./TS/blake/imgs/10MB.bmp"); 
    msg = readFile("/Users/sa/Documents/M.S.I./TS/blake/imgs/10MB.bmp", size); 
	
	// BLAKE-256
	puts("--BLAKE-256");
	for (i=0; i<500; i++) {
		getTime(begin);
		BLAKE(msg, size, salt, 32, digest);
		getTime(end);
		values[i] = elapTime(begin, end);
		//printTime(stdout, "10MB.bmp (256)", begin, end);
	}
	qsort(values, 500, sizeof(float), floatcmp);
	
	// median
	for(i=0; i<100; i++){
		median+=(values[i]/100.0);
	}
	// deviation
	for(i=0;i<100;i++){
		deviation += powf(values[i]-median,2)/100.0;
		deviation = sqrtf(deviation);		
	}
	fprintf(stdout, "Elapsed time(usec): media=%.2f desvio=%.2f\n", median, deviation);
	
	if(argv[1]){	
	// BLAKE-512
	puts("--BLAKE-512");
	for (i=0; i<1000; i++) {
		getTime(begin);
		BLAKE(msg, size, salt, 64, digest);
		getTime(end);
		values[i] = elapTime(begin, end);
		//printTime(stdout, "10.bmp (512)", begin, end);
	}
	qsort(values, 1000, sizeof(float), floatcmp);
	
	// median
	for(i=0; i<100; i++){
		median+=(values[i]/100.0);
	}
	// deviation
	for(i=0;i<100;i++){
		deviation += powf(values[i]-median,2)/100.0;
		deviation = sqrtf(deviation);		
	}
	fprintf(stdout, "Elapsed time(usec): media=%.2f desvio=%.2f\n", median, deviation);
	}
		
	return(0);
}
