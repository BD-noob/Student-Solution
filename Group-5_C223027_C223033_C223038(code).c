#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void registration(void);
void login(void);
void fitForTheGame(void);
void orderFood(void);
void borrowBook(void);
int i = 0, noAccnt = 0;
struct students
{
    char fullName[60], id[30], bookName[100];
};
void borrowBook(void)
{
    system("CLS");
    time_t now = time(NULL);
    int choice;
    char ch;
    struct students stud;
    FILE *books = fopen("booknames.txt", "r");

    printf("\n Bofore borrowing books, please give the below information.\n\n");
    ch = getchar();
    printf(" Full name: ");
    gets(stud.fullName);
    //scanf("%[^\n]", &stud.fullName);
    //ch = getchar();
    printf(" Id: ");
    gets(stud.id);
    //scanf("%[^\n]", &stud.id);

    printf("\n");
    int iterate = 1;
    while(!feof(books))
    {
        fgets(stud.bookName, 256, books);
        printf(" %d. ", iterate);
        printf("%s", stud.bookName);
        iterate++;
    }
    fclose(books);
    printf("\n\n");
    printf(" Enter number of the book you want to borrow: ");
    scanf(" %d", &choice);

    books = fopen("booknames.txt", "r");
    iterate = 1;
    while(!feof(books))
    {
        fgets(stud.bookName, 50, books);
        if(choice == iterate)
        {
            break;
        }
        iterate++;
    }

    char*string_now = ctime(&now);
    if(choice == iterate)
    {
        printf(" Thank you for choosing a book.\n\n");
        printf(" Name: %s\n", stud.fullName);
        printf(" ID: %s\n", stud.id);
        printf(" Borrowed book: %s", stud.bookName);
        printf(" Borrowed date: %s\n", string_now);
    }
    fclose(books);

    printf("\n MENU\n");
    printf(" .....\n\n");
    printf(" 1. Order food from canteen.\n");
    printf(" 2. Borrow a book from the library.\n");
    printf(" 3. Give fitness test for the upcoming tournament.\n");
    printf(" 4. Exit.\n\n");
    printf(" Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: orderFood();break;
        case 2: borrowBook();break;
        case 3: fitForTheGame();break;
        case 4: exit(1);break;
        default: printf("\n Sorry, there is no such option. Please restart the program to continue...\n\n");
    }
}

void orderFood(void)
{
    system("CLS");
    char ch;
    int choice, qnt[40], orderedItem[40];
    double fdPrice[20] = {0, 60, 65, 70, 6, 10, 50, 10, 15, 7, 15, 15};




    printf("....................................................................");
    printf(" Welcome ");
    printf(" ....................................................................\n\n");
    printf(" MENU\n");
    printf(" .....\n\n");
    printf(" 1. Chicken Burger    %.2f TK\n", fdPrice[1]);
    printf(" 2. Beef Burger       %.2f TK\n", fdPrice[2]);
    printf(" 3. Biriyani          %.2f TK\n", fdPrice[3]);
    printf(" 4. Shingara          %.2f TK\n", fdPrice[4]);
    printf(" 5. Role              %.2f TK\n", fdPrice[5]);
    printf(" 6. Chicken Khichuri  %.2f TK\n", fdPrice[6]);
    printf(" 7. Coffee            %.2f TK\n", fdPrice[7]);
    printf(" 8. Tea               %.2f TK\n", fdPrice[8]);
    printf(" 9. Water             %.2f TK\n", fdPrice[9]);
    printf(" 10.Juice             %.2f TK\n", fdPrice[10]);

    int j = 1;
    int iterate = 1;

    printf("\n What do you like to have?");
    while(1)
    {
        printf("\n Please enter any number from 1 to 10 to choose your item (Ex: 5 for Role): ");
        scanf(" %d", &orderedItem[j]);
        printf(" Please enter quantity: ");
        scanf(" %d", &qnt[j]);
        fdPrice[orderedItem[j]] *= qnt[j];
        printf("\n Enter 1 to order more. Enter 0 to get billed: ");
        scanf("%d", &choice);

        if(choice != 1)
            break;

        iterate++;
        j++;
    }
    printf("\n\n");
    printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("                            BILL                        \n");
    printf("                            ----                        \n\n");

    double total = 0;
    for(j=1; j<=40; j++)
    {
        switch(orderedItem[j])
        {
            case 1: printf("    Chicken Burger   ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[1]);break;
            case 2: printf("    Beef Burger      ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[2]);break;
            case 3: printf("    Biriyani         ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[3]);break;
            case 4: printf("    Shingara         ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[4]);break;
            case 5: printf("    Role             ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[5]);break;
            case 6: printf("    Chicken Khichuri ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[6]);break;
            case 7: printf("    Coffee           ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[7]);break;
            case 8: printf("    Tea              ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[8]);break;
            case 9: printf("    Water            ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[9]);break;
            case 10: printf("    Juice            ||   %d   ||   %.2f TK\n",qnt[j], fdPrice[10]);break;
        }
        total += fdPrice[orderedItem[j]];

        if(iterate == 1)
            break;
        iterate--;
    }

    printf("                            Total: %.3f TK  \n\n", total);
    printf(" @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");



    printf("\n MENU\n");
    printf(" .....\n\n");
    printf(" 1. Order food from canteen.\n");
    printf(" 2. Borrow a book from the library.\n");
    printf(" 3. Give fitness test for the upcoming tournament.\n");
    printf(" 4. Exit.\n\n");
    printf(" Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: orderFood();break;
        case 2: borrowBook();break;
        case 3: fitForTheGame();break;
        case 4: exit(1);break;
        default: printf("\n Sorry, there is no such option. Please restart the program to continue...\n\n");
    }


}

void fitForTheGame(void)
{
    int choice;
    float bmi, w, h; //w = weight , h = height

    system("CLS");

    printf("....................................................................");
    printf(" Welcome to the fitness test! ");
    printf(" ....................................................................\n\n");
    printf(" \n Please Enter your weight in kilograms(Ex: 60): ");
    scanf("%f", &w);
    printf(" Please Enter your Height in feet-inches(Ex: 5.4): ");
    scanf("%f", &h);

    h = h*0.3048; //feet to meter conversion
    bmi=(w)/(h*h);

    printf("\n\n Your BMI is : %.2f", bmi);

    if(bmi >= 25)
    {
        printf("\n Condition: Overweight.");
        printf("\n Loose your weight and try again later. All the best.\n");
    }

    else if(bmi <25 && bmi >= 18.5)
    {
        printf("\n Condition: Optimal");
        printf("\n You are fit for the game. See you in the field.\n\n");
        printf(" *************************************\n");
        printf(" *                                   *\n");
        printf(" *  Time: Monday at 11 am.           *\n");
        printf(" *  Location: IIUC central field.    *\n");
        printf(" *  Group: A                         *\n");
        printf(" *                                   *\n");
        printf(" *  Do bring this coupon with you.   *\n");
        printf(" *                                   *\n");
        printf(" *************************************\n");
    }
    else
    {
        printf("\n Condition: Underweight");
        printf("\n Gain some weight and try again later. All the best\n.");
    }


    printf("\n MENU\n");
    printf(" .....\n\n");
    printf(" 1. Order food from canteen.\n");
    printf(" 2. Borrow a book from the library.\n");
    printf(" 3. Give fitness test for the upcoming tournament.\n");
    printf(" 4. Exit.\n\n");
    printf(" Your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: orderFood();break;
        case 2: borrowBook();break;
        case 3: fitForTheGame();break;
        case 4: exit(1);break;
        default: printf("\n Sorry, there is no such option. Please restart the program to continue...\n\n");
    }
}

void registration()
{
    system("CLS");
    char username[50], password[50], ch;

    FILE *usernames = fopen("usernames.txt", "r");
    FILE *passwords = fopen("passwords.txt", "r");

    if(noAccnt == 1)
    {
        printf(" You don't have an account. Please register first.\n\n");
    }

    printf("..................................................................");
    printf(" Welcome to the registration process ");
    printf(".................................................................\n\n");

    if(usernames == NULL)
    {
        fclose(usernames);
        fclose(passwords);

        FILE *usernames = fopen("usernames.txt", "w");
        FILE *passwords = fopen("passwords.txt", "w");

        printf(" Please select an username without any space: ");
        //ch = getchar();
        //printf("%c", ch);
        //gets(st[i].username);
        scanf("%s", username);

        printf(" Give a password: ");
        //ch = getchar();
        //gets(st[i].password);
        scanf("%s", password);


        fputs(username, usernames);

        fputs(password, passwords);

        fclose(usernames);
        fclose(passwords);

    }
    else
    {
        fclose(usernames);
        fclose(passwords);

        FILE *usernames = fopen("usernames.txt", "a");
        FILE *passwords = fopen("passwords.txt", "a");

        printf(" Please select an username without any space: ");
        //ch = getchar();
        //printf("%c", ch);
        //gets(st[i].username);
        scanf("%s", username);

        printf(" Give a password: ");
        //ch = getchar();
        //gets(st[i].password);
        scanf("%s", password);


        fprintf(usernames, "\n");
        fputs(username, usernames);


        fprintf(passwords, "\n");
        fputs(password, passwords);

        fclose(usernames);
        fclose(passwords);
    }



    login();
}

void login(void)
{
    system("CLS");
    int value, choice, userLineNum = 0, passLineNum = 0;
    char str1[50], str2[50], str3[50], str4[50], ch[2];
    FILE *usernames = fopen("usernames.txt", "r");

    if(usernames == NULL)
    {
        noAccnt = 1;
        registration();
    }

    printf("...................................................................");
    printf(" Welcome to the Log in process ");
    printf("..................................................................\n\n");

    printf(" Please enter your username: ");
    scanf("%s", str1);

    while(!feof(usernames))   //searching for user name.....
    {
        userLineNum++;
        fscanf(usernames, "%s", str2);


        value = strcmp(str1, str2);

        if(value == 0)
            break;
    }

    if(value == 0)
        {
            fclose(usernames);
            FILE *passwords = fopen("passwords.txt", "r");

            printf(" Please enter your password: ");
            scanf("%s", str3);

            passLineNum = 0;
            while(!feof(passwords))   //searching for password.....
            {
                if(feof(passwords))
                {
                    break;
                }
                passLineNum++;
                fscanf(usernames, "%s", str4);
                if(passLineNum == userLineNum)
                {

                    value = strcmp(str3, str4);
                    if(value == 0)
                        break;
                }
            }
            if(value == 0)
            {
                printf("\n\n......................................................................... Login successful ");
                printf("........................................................................\n\n");
                printf(" MENU\n");
                printf(" .....\n\n");
                printf(" 1. Order food from canteen.\n");
                printf(" 2. Borrow a book from the library.\n");
                printf(" 3. Give fitness test for the upcoming tournament.\n");
                printf(" 4. Exit.\n\n");
                printf(" Your choice: ");
                scanf("%d", &choice);

                switch(choice)
                {
                    case 1: orderFood();break;
                    case 2: borrowBook();break;
                    case 3: fitForTheGame();break;
                    case 4: exit(1);break;
                    default: printf("\n Sorry, there is no such option. Please restart the program to continue...\n\n");
                }

            }
           else
            {
                fclose(passwords);
                printf(" Wrong password\nPlease select one\n 1. Try again\n 2. Exit\n");
                scanf("%d", &choice);
                system("CLS");

                switch(choice)
                {
                    case 1:login();break;
                    case 2:exit(1);break;
                }
             }


            fclose(passwords);
        }
        else
        {
            fclose(usernames);
            printf("Username doesn't match.\nPlease select one\n1. Try again\n2. Exit\n");
            scanf("%d", &choice);
            system("CLS");

            switch(choice)
            {
                case 1:login();break;
                case 2:exit(1);break;
            }
        }

}

int main(void)
{
    int choice;
    char ch;
    printf(".........................................................................");
    printf(" Welcome to the Student Solution ");
    printf("........................................................................\n\n");
    printf(" Choose one option:\n ..................\n\n 1. Log in\n 2. Register\n 3. Exit\n\n");
    printf(" Your choice: ");
    scanf("%d", &choice);


    switch(choice)
    {
        case 1: login();break;
        case 2: registration();break;
        case 3: exit(1);break;
        default: printf("\n You typed wrong option. Please restart the program to continue...\n\n");
    }
    return 0;
}







