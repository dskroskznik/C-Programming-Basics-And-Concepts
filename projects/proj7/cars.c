/* Dylan Skroskznik 	COP3514		11/6/21
 *  	This program reads an input file listing a dataset of some all-wheel-drive cars and 
 *  	how much fuel each car uses, then lists the top 10 cars with the highest mpg in city.
 */
#include <stdio.h>
#include <string.h>

#define INPUT 200 //input array length
#define CARS 6000 //car struct length
#define FIELD 150 //field array length

struct car { // struct car with 7 characteristics
	char id[FIELD+1]; //car identification
	char c[FIELD+1]; //car classification
	char e[FIELD+1]; //car engine type 
	char t[FIELD+1]; //car transmission
	int c_mpg; //car city miles/gallon
	char f[FIELD+1]; //car fuel type
	int h_mpg; //car highway miles/gallon 
};
//sort city miles/gallon cars in decending order
void sort_city_mpg(struct car list[], int n); 
//locates largest structure  member line by line
int find_largest(struct car list[], int n);
int main() //sets the input filename to open and apply order list to output file
{
	struct car list[CARS+1]; //create car struct to hold charcteristics 
	char filename[INPUT+1]; //filename array
	FILE *fr; //file read
	FILE *fw; //file write
	int i=0;

	printf("Enter the file name: ");
	scanf("%s", filename);

	fr = fopen(filename,"r"); //open file
	if(fr == NULL) {
		printf("ERROR OPENING FILE\n");
		return 1;
	}
	
	//if the file has not ended, scan and put car characteristics to list
	while(!feof(fr)&&!ferror(fr)) {
	if(fscanf(fr,"%[^,], %[^,], %[^,], %[^,], %d, %[^,], %d\n",
		 list[i].id, list[i].c, list[i].e, list[i].t, &list[i].c_mpg, list[i].f, &list[i].h_mpg)==7) {
		}
	i++;//increment the amount of cars in list
	}

	sort_city_mpg(list, i); //call structure to sort car list

	fw = fopen("Top10_city_mpg.csv", "w"); //write new file
	if(fw == NULL) {
		printf("ERROR WRITING FILE\n");
		return 1;
	}
	
	int j;
	//for loop applies the ordered list into the new files 
	//struct car list until the output fle ends at line 10 
	for(j=i-1;j>i-11;j--) {
	fprintf(fw, "%s, %s, %s, %s, %d, %s, %d\n", 
		list[j].id, list[j].c, list[j].e, list[j].t, list[j].c_mpg, list[j].f, list[j].h_mpg);

	}

	printf("Sorting...\n\n");	
	printf("Output File: Top10_city_mpg.csv\n"); //display output file name

	fclose(fr);//close read file
	fclose(fw);//close written file
	return 0;	
}//end main

//selection array sorting the car in decending order by highest city mpg
void sort_city_mpg(struct car list[], int n)
{
	struct car temp; 
	int larg=0;

	if(n==1) return;//return if only 1 object in array

	larg = find_largest(list, n);

	//sorts by each index to put largest ahead of the other
	if(n-1>larg) {
		temp=list[n-1];
		list[n-1]=list[larg];
		list[larg]=temp;
	}
	
	sort_city_mpg(list, n-1);//function recursion until the final cars are sorted
	

}//end sort_city_mpg

//largest will be held up front and sorted into other function
int find_largest(struct car list[], int n)
{
	int larg_index=0;
	int i;
	for(i=1;i<n;i++) {
		if(list[i].c_mpg > list[larg_index].c_mpg) {
			larg_index=i;
		}
	}
	return larg_index;
}//end find_largest
