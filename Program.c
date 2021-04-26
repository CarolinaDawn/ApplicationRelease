#include <stdio.h> 

/*This section sets up budgetItem as a new type to be used later
Also sets up character to allow 500 characters in category list*/
typedef struct _budgetItem
{
	struct _budgetItem* next;
	int cost;
	char name[500]; //means char* name; //copiler statically initializes 500 elements for you, 
		//if you did your self you'd have to malloc(name, sizeof(char)*500);
	//#define sizeOfName  500;
} budgetItem;
budgetItem budget[100];

//Program asks user for input on what they will be spending, uses pointers to indicate what part of the typedef to use
int budgetThing(budgetItem* b, int whatigot) {
	printf("What I got: %i\n", whatigot);
	
	printf("What category are you spending from? \n");
	scanf_s("%s", b->name,500); 
	//JEremy 623-330-9139
	//-> mean (*b).name
	
	
	printf("How much are you spending? \n");
	scanf_s("%i", &b->cost);
	//Structure to set up budget end when it gets to 0

	while (b->cost > whatigot) {
		printf("That cost too much!");
		printf("How much are you spending? \n");
		scanf_s("%i", &b->cost);
	} //todo Carolina try with do...while
	return 0;
}

//What do you want? 
// A list of categories.
// list mean => array
#define NUM_OF_CATEGORIES 10
char* categories[NUM_OF_CATEGORIES];


void setupCategories() {
	categories[0] = "Food";
	categories[1] = "Not Food";
}

// Want the user to be able to pick one.

#if 0
//Return index of a category
int pickACategory() {
	for(int i = 0; i < NUM_OF_CATEGORIES; ++i) {
		printf("%d: %s", categories[i]);
	}
	int choice;
	scan_f("Pick on> " &choice); //TODO Caroline finish this scan_f call
	//TODO consider 10 categories and the user inputs "16". What happens?
	return choice;
}
#else 
//Return the category itself, or a custom one
char* pickACategory() { 
	for(int i = 0; i < NUM_OF_CATEGORIES; ++i) {
		printf("%d: %s", categories[i]);
	}
	printf("-1: Custom");
	int choice;
	scan_f("Pick on> " &choice); //TODO Caroline finish this scan_f call
	if(choice == -1) {
		//ask user for their custom category.
		//return that custom category
	}

	//otherwise
	//TODO consider 10 categories and the user inputs "16". What happens?
	return categories[choice];
}

#endif


int main(int argc, const char* argv[])
{
	int cost;
	char* name;
	int totalIncome = 0;
	int numberofHours;
	int amountPaid;
	int paytype;
	int salarypay;

	printf("Select 1 for hourly employee, or 2 for salaried employee (1-2): ");
	scanf_s("%i", &paytype);
	if (paytype == 1)
	{
		//program will ask how many hours they work
		// program will ask how much they are paid

		printf("How much do you get paid per hour? ");
		scanf_s("%i", &amountPaid);

		printf("How many hours per week do you work? ");
		scanf_s("%i", &numberofHours);

		if (numberofHours == 40)
		{
			totalIncome = amountPaid * 2080 / 12;
		}
		else
		{
			totalIncome = numberofHours * amountPaid * 52 / 12;
		}

		/*Here include an if...else statement that includes different calculations for 40 hours/wk vs. random hours/wk??
		* Or is there a better way to include that differentiation?
		* Is it beneficial to include a list of categories they can choose from or better to just let them fill it in?*/


		//calculation of monthly income
		//totalIncome = numberofHours * amountPaid * 2080 / 12;
	}
	else 
	{
			//User will enter total monthly income
		printf("How much do you get paid per month? ");
		scanf_s("%i", &salarypay);

		totalIncome = salarypay;
	}
		

		int spendAmount = 0;
		int budgetAmount = totalIncome;
		
		budgetItem* currentLineItem =  budget;
		int numberofitems = 0;

//Program will calculate based on user input and outpt what category is, how much is left, and how much is currently being spent
		while (budgetAmount > 0)
		{
			int ok = budgetThing(currentLineItem, budgetAmount);
			budgetAmount = budgetAmount - currentLineItem->cost;
			printf("\n%s: %i, Amount Left: %i\n", currentLineItem->name, currentLineItem->cost, budgetAmount);
			currentLineItem++;
			numberofitems++;
			//Potential mitigation make the list dynamic
			// budgetItem* nextItem = (budgetItem*)malloc(sizeof(budgetItem));
			//if nextIem != NULL 
			//currentLineItem->next = nextItem;
		}

		int i = 0;
		for (budgetItem* currentLineItem = budget; i < 10; i++) 
		{
			printf("\n%s: Cost: %i\n", currentLineItem->name, currentLineItem->cost);
			currentLineItem++;
		}


		return 0;

}