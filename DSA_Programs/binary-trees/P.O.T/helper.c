#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char String[20];

typedef struct {
	String name;
	String breed;
	String petType;
} pet;

typedef struct node{
	pet petList;
	struct node* link;
} List, *ListPtr;

typedef ListPtr Store[2];

//HELPER FUNC
pet createPet(String name, String breed, String petType) {
	pet temp;
	
	strcpy(temp.name, name);
	strcpy(temp.breed, breed);
	strcpy(temp.petType, petType);
	
	return temp;
}

void initializeStore(Store S) {
	int i;
	
	for(i = 0; i < 2; i++) {
		S[i] = NULL;
	} 
}
void insertSorted(ListPtr* L, pet P) {
	ListPtr* trav;
	
	for(trav = L; *trav != NULL && strcmp((*trav)->petList.name, P.name) < 0; trav = &(*trav)->link) {}
	
	if(*trav == NULL || (*trav)->petList.name < P.name) {
		ListPtr temp = (ListPtr) malloc(sizeof(List));
		if(temp != NULL) {
			temp->petList = P;
			temp->link = *trav;
			*trav = temp;
		}
	}
}
void populateStore(Store S) {
	int i;
	pet petArr[6] = {
		{ "Bella", "Saiamese", "Cat" },
		{ "Pooch", "Azkal", "Dog" },
		{ "Pop", "Burmese", "Cat" },
		{ "Birch", "Birman", "Cat" },
		{ "Peach", "Poodle", "Dog" },
		{ "Trump", "German Shepherd", "Dog" }
	};
	
	for(i = 0; i < 6; i++) {
		if(strcmp(petArr[i].petType, "Cat") == 0) {
			insertSorted(&S[0], createPet(petArr[i].name, petArr[i].breed, petArr[i].petType));
		}
		else if(strcmp(petArr[i].petType, "Dog") == 0) {
			insertSorted(&S[1], createPet(petArr[i].name, petArr[i].breed, petArr[i].petType));
		}
	}
	
}

void displayStore(Store S) {
    int i;

    for (i = 0; i < 2; i++) {
        if (i == 0) {
            printf("CAT LIST IS : \n");

            ListPtr trav;

            for (trav = S[i]; trav != NULL; trav = trav->link) {
                printf("| %20s | %20s | %20s |\n",
                       trav->petList.name, trav->petList.breed, trav->petList.petType);
            }
        } else if (i == 1) {
            printf("DOG LIST IS : \n");

            ListPtr trav;

            for (trav = S[i]; trav != NULL; trav = trav->link) {
                printf("| %20s | %20s | %20s |\n",
                       trav->petList.name, trav->petList.breed, trav->petList.petType);
            }
        }

        printf("\n-------------------------------------------\n");
    }
}


int main() {
	Store petStore;
	
	//INITIALIZE STORE HERE
	initializeStore(petStore);
	
	/* INSERT THESE PETS, STORE[0] IS FOR CATS OTHER ONE IS STORE[1] LIST IS SORTED BY NAME
		Bella, Saiamese, Cat
		Pooch, Azkal, Dog
		Pop, Burmese, Cat
		Birch, Birman, Cat
		Peach, Poodle, Dog
		Trump, German Shepherd, Dog
	*/
	populateStore(petStore);
	
	//DISPLAY BOTH LISTS
	displayStore(petStore);
	
	return 0;
} 
