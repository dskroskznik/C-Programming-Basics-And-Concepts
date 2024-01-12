#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
void print_list(struct node *list);
int count_n(struct node *list, int n);
void clear_list(struct node *list);

struct node {
	int value;          /* data stored in the node  */
	struct node *next;  /* pointer to the next node */
};

int main()
{

 	struct node *first = NULL;
	int number, count = 0;	

	/* inserting nodes */
	first = add_to_list(first, 3);
	first = add_to_list(first, 64);
	first = add_to_list(first, 98);
	first = add_to_list(first, 3);
        first = add_to_list(first, 64);
	first = add_to_list(first, 3);
	first = add_to_list(first, 136);

	print_list(first);

	struct node *s_node = search_list(first, 56);
	if(s_node!=NULL) printf("56 found\n");
	else printf("56 not found\n");

	
	printf("Enter a number: ");
	scanf("%d", &number);
	
	count = count_n(first, number);
	printf("The number of nodes that contains %d is %d.\n", number, count);
	
	clear_list(first);
	return 0;

}

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

struct node *search_list(struct node *list, int n)
{
	  struct node *p;
	
	  for (p = list; p != NULL; p = p->next)
	    if (p->value == n)
	      return p;
	  return NULL;
}

void print_list(struct node *list)
{
	struct node *p;
	for(p= list; p!=NULL; p = p->next)
		printf("%d\t", p->value);
	printf("\n");
}

void clear_list(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	 p = list;
     list = list->next;
     if( p!= NULL)
           free(p);
  }
}
int count_n(struct node *list, int n){
	int count =0;
	struct node *p;
	for(p = list; p!=NULL; p=p->next){
		if(p->value== n)
			count++;
	}
	return count;

}


