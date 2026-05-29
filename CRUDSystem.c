#include <stdio.h>

int main()
{
    int choice;
    int elements;
    int condition = 1;
    int position;
    int missingNum;
    int changeElement;
    int arrayA = 0;
    int arrayB = 0;
    int arrayC = 0;

    while (condition == 1)
    {
        printf("\n\n\n\n");

        printf("==== ARRAY CRUD MENU ====\n");
        printf("1. Create (Input Element)\n");
        printf("2. Read (Display Element)\n");
        printf("3. Update (Modify Element)\n");
        printf("4. Delete (Remove Element)\n");
        printf("5. Search (Find Element)\n");
        printf("6. Exit\n\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Enter number of elements: ");
            scanf("%d", &elements);

            printf("Enter 3 elements: ", elements);
            scanf("%d %d %d", &arrayA, &arrayB, &arrayC);

            int numbers[3];
            numbers[1] = arrayA;
            numbers[2] = arrayB;
            numbers[3] = arrayC;
            break;

        case 2:
            printf(" %d\t", numbers[1]);
            printf(" %d\t", numbers[2]);
            printf(" %d\t", numbers[3]);
            break;

        case 3:
            printf("Select the Position: ");
            scanf("%d", &position);

            printf("Change Element: ");
            scanf("%d", &changeElement);

            numbers[position] = changeElement;
            break;

        case 4:
            printf("Select the Position: ");
            scanf("%d", &position);

            numbers[position] *= 0;

            break;

        case 5:
            printf("Search Number: ");
            scanf("%d", &missingNum);

            if (numbers[1] == missingNum)
            {
                printf("In Position 1");
            }
            else if (numbers[2] == missingNum)
            {
                printf("In Position 2");
            }
            else if (numbers[3] == missingNum)
            {
                printf("In Position 3");
            }
            else
            {
                printf("Cannot be Found");
            }
            break;

        case 6:
            condition -= 1;
            printf("Goodbye");
            break;

        default:
            printf("ERROR OCCURED");
            break;
        }
    }

    return 0;
}
