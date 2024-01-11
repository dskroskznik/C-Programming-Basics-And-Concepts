/* Dylan Skroskznik	cop3514		APR. 25 2021
 * 	This program read an input file of a data selection of hospitals located in Florida
 * 	and organize each average to high rated hospital based on cost, and output the 
 * 	organized list in an output file
 *
 * */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> //insert string funcs
#define MAX_LEN 300 //set definition for MAX lengths
struct hospitals { //structure initialized for hospitals
	char n[MAX_LEN+1]; //name
	char c[MAX_LEN+1]; //city
	char s[MAX_LEN+1]; //state
	int r; //rating
	int ct; //cost
	char q[MAX_LEN+1]; //pneumonia quality
	char v[MAX_LEN+1]; //pneumonia value
};//end struct

int comp_hospitals(const void* p, const void* q);//define find largest func

int main()
{
//	struct hospitals in[MAX_LEN];
	struct hospitals *in;
	in = malloc(MAX_LEN*sizeof(struct hospitals));	
	char fname[MAX_LEN+1];//character array for file name
	FILE *fread; //FILE pointer to point to reading file
	FILE *fwrite;//writing file pointer
	int x=0;
		
	printf("Enter file name: ");
	  scanf("%s", fname);// scans for input filename
	fread = fopen(fname, "r"); //reads file
	                                                       
	if(fread == NULL) { //if file is nonexistent ERROR
		printf("ERROR OPENING FILE\n");
		return 1;	
	}
	
	while(!feof(fread)&&!ferror(fread)) { //checks for end of file or a file error
		if(fscanf(fread, "%[^,], %[^,], %[^,], %d, %d, %[^,], %s\n", 
	  	   in[x].n, in[x].c, in[x].s, &in[x].r, &in[x].ct, in[x].q, in[x].v)==7) {
		}
		   x++;		
		
	}

	fclose(fread); //closes read file

	fwrite = fopen("output.csv", "w"); //writing the output file opened
	
	if(fwrite == NULL) { //if file is corrupt or not there ERROR
		printf("ERROR OPENING FILE\n");	
		return 1;
	}
	
	printf("...Sorting. \nOutput File:  ");// sorting the hospitals...
	printf("output.csv\n\n");
	int y;
	
	qsort(in,MAX_LEN,sizeof(struct hospitals),comp_hospitals);//sorts hospitals in order of cost	

	for(y=x-1;y>x-MAX_LEN;y--) { //condition statments to oly apply hospitals at certain echelons
		if((in[y].r >= 3) && (strcmp(in[y].q, "Worse")!=0)) { //strcmp for cmparing letter values		
			fprintf(fwrite, "%s, %s, %s, %d, %d, %s, %s\n",
			 in[y].n, in[y].c, in[y].s, in[y].r, in[y].ct, in[y].q, in[y].v);
	 	}
	}
	printf("\n");

	fclose(fwrite);//closes file written
	return 0;
}//end main

//void function for sorting the hospitals
int comp_hospitals(const void* p, const void* q)
{
	const struct hospitals *a = p;
	const struct hospitals *b = q;
	
	if(a->ct < b->ct)
	  return -1;	
	if(a->ct == b->ct)
	  return 0;
	else
	  return 1;
//	return (a->ct) - (b->ct) ;
	
}//end func
