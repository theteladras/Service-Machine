#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAXCHAR 1000

int selections(int category) {
	FILE *fp;
	FILE *fp2;
	FILE *temp;
	char str[MAXCHAR];
	char str2[MAXCHAR];
	char *filename = "items.txt";
	char *filename2 = "customerEntry.txt";
	char *tempFN = "temp.txt";
	char itemID[4];
	int itemQ;
	int userID;
	int i = 0;
	int j;
	int n;
	int vvv = 10;
	char a[100][10];
	int flag = 1;
	int ppu;

	if (category == 1) {
		printf("\nItemID\\Quantity\\Price Per Unit (SAR)\n");
		fp = fopen(filename, "r");
		if (fp == NULL) {
			printf("Could not open file %s", filename);
			return 1;
		}

		while (fgets(str, MAXCHAR, fp) != NULL) {
			printf("%s", str);
		}
		fclose(fp);
		printf("\n");
	}
	if (category == 2) {
		printf("\nEnter item ID: ");
		fgets(itemID, sizeof(itemID), stdin);

		fp = fopen(filename, "r");
		if (fp == NULL) {
			printf("Could not open file %s", filename);
			return 1;
		}
		while (fgets(str, MAXCHAR, fp) != NULL) {
			strcpy(a[i], str);
			if(a[i][0] == itemID[0] && a[i][1] == itemID[1] && a[i][2] == itemID[2] && a[i][3] == itemID[3]) {
				printf("\nItemID\\Quantity\\Price Per Unit (SAR)\n");
				printf("\n\n");
				puts(str);
				flag = 0;
			}
			else if (flag == 1 && i > vvv - 2) {
				printf("\nThe item with the entered index does not exist!!!\n");
			}
			i++;
		}
		flag = 1;
		fclose(fp);
	}
	if (category == 3) {
		printf("\nCustomerID\\ItemID\\Quantity\n");
		fp2 = fopen(filename2, "r");
		if (fp2 == NULL) {
			printf("Could not open file %s", filename2);
			return 1;
		}

		while (fgets(str2, MAXCHAR, fp2) != NULL) {
			printf("%s", str2);
		}
		fclose(fp2);
		printf("\n");
	}
	if (category == 8) {
		exit(0);
	}
	if (category < 1 || (category > 8 && category != 123)) {
		printf("\nInvalid selection, please try again...\n");
		printf("\n");
	}
	if (category == 4) {
		printf("\nEnter User ID: ");
		scanf("%d", &userID);
		if (userID < 10 || userID > 60) {
			printf("\nThe customerID is not in the range 10 to 60 inclusive.\n");
		}
		else {
			printf("\nEnter item ID: ");
			fgets(itemID, sizeof(itemID), stdin);
			fp = fopen(filename, "r");
			temp = fopen(tempFN, "w+");
			if (fp == NULL) {
				printf("Could not open file %s", filename);
			}
			while (fgets(str, MAXCHAR, fp) != NULL) {
				strcpy(a[i], str);

				if (a[i][0] == itemID[0] && a[i][1] == itemID[1] && a[i][2] == itemID[2] && a[i][3] == itemID[3]) {
					if (a[i][6] == ' ') {
						j = a[i][5] - '0';
						if (j > 0) {
							str[5] = j - 1 + '0';
							printf("\nYou purchased ONE! Remaining quantity of this item in stock: %d", j - 1);
						}
						else {
							printf("\nThere is not enough quantity available for the item to purchase.");
						}
					}
					else {
						j = 10 * (a[i][5] - '0');
						j = j + a[i][6] - '0';
						if (j > 0) {
							str[5] = (j - 1)/10 + '0';
							str[6] = (j - 1)%10 + '0';
							printf("\nYou purchased ONE! Remaining quantity of this item in stock: %d", j - 1);
							vvv--;
						}
						else {
							printf("\nThere is not enough quantity available for the item to purchase.");
						}
					}
				}
				else if (flag == 1 && i > vvv - 2) {
					printf("\nThe item with the entered index does not exist!!!\n");
				}
				fprintf(temp, "%s", str);
				flag = 0;
				i++;
			}
			fclose(temp);
			fclose(fp);
			remove("items.txt");
			rename(tempFN, "items.txt");
			flag = 1;
		}
	}

	if (category == 5) {
		printf("\nEnter User ID: ");
		scanf("%d", &userID);
		if (userID < 10 || userID > 60) {
			printf("\nThe customerID is not in the range 10 to 60 inclusive.\n");
		}
		else {
			printf("\nEnter item ID: ");
			fgets(itemID, sizeof(itemID), stdin);
			fp = fopen(filename, "r");
			temp = fopen(tempFN, "w+");
			if (fp == NULL) {
				printf("Could not open file %s", filename);
			}
			while (fgets(str, MAXCHAR, fp) != NULL) {
				strcpy(a[i], str);
				if (a[i][0] == itemID[0] && a[i][1] == itemID[1] && a[i][2] == itemID[2] && a[i][3] == itemID[3]) {
					printf("\nEnter item quantity you want to return: ");
					scanf("%d",&itemQ);
					if (str[6] == ' ') {
						n = str[5] - '0';
						itemQ = itemQ + n;

						if (itemQ > 9) {
							str[10] = '\n';
							str[9] = str[8];
							str[8] = str[7];
							str[7] = ' ';
							str[5] = itemQ/10 + '0';
							str[6] = itemQ%10 + '0';
						}
						else {
							str[5] = itemQ + '0';
						}
					}
					else {
						n = 10*(str[5]) - '0';
						itemQ = itemQ + n;
						n = str[6] - '0';
						itemQ = itemQ + n;

						if (itemQ > 9) {
							str[10] = '\n';
							str[9] = str[8];
							str[8] = str[7];
							str[7] = ' ';
							str[5] = itemQ/10 + '0';
							str[6] = itemQ%10 + '0';
						}
						else {
							str[5] = itemQ + '0';
						}
					}
					printf("\n\n HERE IT IS IT IS: %s", str);
				}
				fprintf(temp, "%s", str);
				i++;
			}
			fclose(temp);
			fclose(fp);
			remove("items.txt");
			rename(tempFN, "items.txt");
			flag = 1;
		}
	}

	if (category == 6) {
		fp = fopen(filename, "r+");
		if (fp == NULL) {
			printf("Could not open file %s", filename);
		}
		printf("\nEnter item ID u wish to add: ");
		fgets(itemID, sizeof(itemID), stdin);
		i = 0;
		while (fgets(str, MAXCHAR, fp) != NULL) {
			strcpy(a[i], str);
			if (str[0] == itemID[0] && str[1] == itemID[1] && str[2] == itemID[2] && str[3] == itemID[3]) {
				printf("\nThe item with that ID already exists!\n");
				return 0;
			}
			else {
				if (itemID[0] - '0' < 1 || itemID[4] || itemID[0] - '0' > 9 || itemID[1] - '0' < 0 || itemID[1] - '0' > 9 || itemID[2] - '0' < 0 || itemID[2] - '0' > 9 || itemID[3] - '0' < 0 || itemID[3] - '0' > 9) {
					printf("\nItem ID should be in range of 1000-9999!\n");
				}
			}
			i++;
		}
		printf("\nEnter price per unit (less than 100): ");
		scanf("%d", &ppu);
		if (ppu >= 100 || ppu < 0) {
			printf("\nYou have entered a invalid price...\n");
		}
		else {
			fprintf(fp, "\n%s 1 %d", itemID, ppu);
			vvv++;
		}

		fclose(fp);
	}
	if (category == 7) {
		printf("\nEnter item ID: ");
		fgets(itemID, sizeof(itemID), stdin);
		fp = fopen(filename, "r");
		temp = fopen(tempFN, "w+");
		if (fp == NULL) {
			printf("Could not open file %s", filename);
		}
		i = 0;
		while (fgets(str, MAXCHAR, fp) != NULL) {
			strcpy(a[i], str);
			if (str[0] == itemID[0] && str[1] == itemID[1] && str[2] == itemID[2] && str[3] == itemID[3]) {
				str[0] = '\0';
			}
			fprintf(temp, "%s", str);
			i++;
		}
		flag = 1;
		fclose(temp);
		fclose(fp);
		remove("items.txt");
		rename(tempFN, "items.txt");
		flag = 1;
	}
	return 1;
}

int main() {
	int category;
	FILE *fp;
	char *filename = "items.txt";

	while (1) {
		printf("1.Display Item Info for all Items\n");
		printf("2.Display Item Info for a particular item\n");
		printf("3.Display Customer Info for all customers\n");
		printf("4.Purchase Item\n");
		printf("5.Return Item\n");
		printf("6.Add New Item\n");
		printf("7.Delete Item\n");
		printf("8.Exit\n");
		printf("Please select your choice (or type '123' to reset the text file): ");
		scanf("%d", &category);
		if (category == 123) {
			fp = fopen(filename, "w+");
			if (fp == NULL){
				printf("Could not open file %s", filename);
			}
			fprintf(fp, "1007 5 30\n");
			fprintf(fp, "1004 4 10\n");
			fprintf(fp, "1003 3 20\n");
			fprintf(fp, "1002 2 10\n");
			fprintf(fp, "1006 4 40\n");
			fprintf(fp, "1005 5 50\n");
			fprintf(fp, "1001 1 70\n");
			fprintf(fp, "1008 6 20\n");
			fprintf(fp, "1010 4 90\n");
			fprintf(fp, "1009 3 10");
			fclose(fp);
		}

		selections(category);
		printf("\n");
		printf("Press any key to continue...");
		printf("\n");
		getch();
		printf("\n");
	}
}
