/* Dylan Skroskznik	COP3514		9/1/21
 * 	This program is designed to calculate active parking meter prices to
 * 	accurately determine charges for patking in a parking garage.
*/
#include <stdio.h>
#define FREE_PARKING 30

int main()
{ 
	int t_hours, t_mins;

	printf("Enter total hours parked: ");	
	scanf("%d", &t_hours);
	printf("Enter total minutes parked: ");
	scanf("%d", &t_mins);
		
	if(t_mins < 0 || t_mins > 60) {
		printf("Invalid input for value, ending program...\n");
		return 0; }
	else if(t_hours < 0) {
		printf("Invalid input for value, ending program...\n");
		return 0; }

	int p_cost;

	if(t_hours <= 23 && t_mins < 60) {
		p_cost = 0.5 + (double)(((t_hours*60) + t_mins) - FREE_PARKING)/20; }
	else if(t_hours <= 23 && t_mins >= 0) {
		p_cost = 0.5 + (double)((t_hours*60) - FREE_PARKING)/20; }
	else if(t_hours == 0 && t_mins < 60) {
		p_cost = 0.5 + (double)(t_mins - FREE_PARKING)/20; }
	else if(t_hours > 24 && t_mins<60) {
		p_cost = 0.5 + (double)(((t_hours/24) * 12)) + (double)((((t_hours%24)*60) + t_mins) - FREE_PARKING)/20; }
		
	printf("Amount($) total for parking: $%d", p_cost);
	printf("\n"); 
	return 0;
}
