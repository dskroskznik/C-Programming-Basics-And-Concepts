/* Dylan Skroskznik	cop3514		Jan. 24 2021
 *  	This program calculates 0and prints the charge on stay for 
 *	a selected location, the duration, and food based on attendees. 
 */

#include <stdio.h>

int main(void)
{
	//request user input for a selected location
	int location, people, hours, capacity, room_rental, h_house, f_center, p_plaza, total_charge; 
	//variable placeholders

	//prompt rental room selection to user
	printf("Please select from the following location menu:\n1. Holiday House, 2. Fun Center, 3. Party Plaza\n\n");
	printf("Enter location selection: ");
	scanf("%d", &location); //scans for user input
	printf("%d", location);
	if (location < 1 || location > 3) { //determines selection for legal input
		printf("\nThis is an illegal input. Exiting program..");
	}
	else { 
	switch (location) { //switch case for room rental price
		case 1: h_house = 400;
			break;
		case 2: f_center = 300;
			break;
		case 3: p_plaza = 250;
			break;
		}
	}

	//if else statements for hours rental charge
	printf("\nEnter hours: ");
	scanf("%d", &hours);
	printf("%d", hours);
	if (hours < 1 || hours > 10) { //determines selection for legal input
		printf("\nThis is an illegal input. Exiting program..");
	}
	else if(hours == 10) { //gives 10 hour limits to max daily charge
	        switch (location) {
			case 1: room_rental = 1800;
				break;
			case 2: room_rental = 1300;
				break;
			case 3: room_rental = 800;
				break;
		}
	}
	else { 
		switch (location) {	
			case 1: room_rental = h_house + (hours - 1) * 200;
				break;
			case 2: room_rental = f_center + (hours - 1) * 150;
				break;
			case 3: room_rental = p_plaza + (hours - 1) * 120;
				break;
		}
	}
	//switch cases for person capacity charge
	printf("\nEnter number of people: ");
	scanf("%d", &capacity);
	printf("%d", capacity);
	switch (location) { //applies room rental to person capacity charge
		case 1:
			if (capacity > 200) {
				printf("\nThe person capacity has exceeded its limit. Exiting program..");
			}
			else { 
				people = capacity * 10;
			}
			break;
		case 2:
			if (capacity > 100) {
				printf("\nThe person capacity has exceeded its limit. Exiting program..");
			}
			else {
				people = capacity * 20;
			}
			break;
		case 3:
			if (capacity > 150) {
				printf("\nThe person capacity has exceeded its limit. Exiting program..");
			}
			else {
				people = capacity * 15;
			}
			break;
	}
		
	//giving total rental charge from all values
	total_charge = people + room_rental;
	printf("\nTotal room rental charge($): $ %d", total_charge);


	return 0;
}
