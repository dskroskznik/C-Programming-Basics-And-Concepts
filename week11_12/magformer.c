#include <stdio.h>
#include <string.h>
#define NUM_CHARS 30

//declare struct
struct magformer{
	char color[NUM_CHARS +1];
	char shape[NUM_CHARS +1];
	int quantity;
};

//compares two magformers by color and shape
int compare_magformer(struct magformer m1, struct magformer m2);

int main()
{
	struct magformer m2;
	struct magformer m1={"blue", "square", 5};	
	printf("%s %s %d\n", m1.shape, m1.color, m1.quantity);
	
	printf("Enter quantity");
	scanf("%d", &m2.quantity);
	printf("Enter shape:");
	scanf("%s", m2.shape);
	printf("Enter color:");
	scanf("%s", m2.color);
	printf("%s %s %d\n", m2.shape, m2.color, m2.quantity);
	
	printf("%d\n", compare_magformer(m1, m2));	


	return 0;
}


int compare_magformer(struct magformer m1, struct magformer m2)
{
	//shape are the same and color are the same
	if(strcmp(m1.color, m2.color )==0 && strcmp(m1.shape, m2.shape)==0)
		return 1;
	else
		return 0;	
}


