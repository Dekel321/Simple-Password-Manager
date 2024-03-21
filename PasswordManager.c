#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


char line1[100];
char line2[100];

char user[50];
char pass[50];

// option 1----------------------------------------------------------------------
void op1(char locat[50]){
    char location[100];
    int status = mkdir(locat);
    if (status == -1) {
        printf("Error creating folder.\n");
        
    }

    sprintf("password.txt", "%s/password.txt", locat);


    printf("Enter User: ");
    scanf("%s", user);

    printf("Enter Password: ");
    scanf("%s", pass);

    FILE *fsave;
    fsave = fopen("password.txt", "w");
    if (fsave == NULL) {
        printf("Error opening file.\n");
    }
    fprintf(fsave, "%s\n%s", user, pass);
    fclose(fsave);

    printf("Saved in ");
}

// option 2----------------------------------------------------------------------
void op2() {
    // Future addition: copy to clipboard
    //char location[100]

    FILE *fread;
    fread = fopen("password.txt", "r");

    fgets(line1, 100, fread);
    fgets(line2, 100, fread);

    printf("Your Information is:\n%s%s", line1, line2);

    fclose(fread);
}







void op1_1(){

    FILE *fchange;
    fchange = fopen("password.txt", "r");
    fgets(line1, 100, fchange);
    fgets(line2, 100, fchange);

    fchange = fopen("password.txt", "w");

    printf("Enter New Username: ");

    scanf("%s", line1);

    fprintf(fchange, "%s\n", line1);

    printf("Enter New Password: ");

    scanf("%s", line2);

    fprintf(fchange, "%s", line2);

fclose(fchange);
}


void op2_2() {

    FILE *fuser;
    fuser = fopen("password.txt", "r");

    fgets(line1, 100, fuser);
    fgets(line2, 100, fuser);

    fclose(fuser);

    fuser = fopen("password.txt", "w");

    printf("Enter New Username: ");
    scanf("%s", line1);

    fprintf(fuser, "%s\n%s", line1, line2);

    fclose(fuser);

    printf("Done");
}
// if 1-3 -------------------------------------------------------------------------
void op3_3() {

    FILE *fpass;
    fpass = fopen("password.txt", "r");

    fgets(line1, 100, fpass);
    fgets(line2, 100, fpass);

    fclose(fpass);

    fpass = fopen("password.txt", "w");

    printf("Enter New Password: ");
    scanf("%s", line2);

    fprintf(fpass, "%s%s", line1, line2);

    fclose(fpass);

    printf("Done");
}



int main() {

    int option;

    while (1) {
    printf("1 Save: \n2 Read: \n3 Change: ");
    scanf("%d", &option);



// if 1 ------------------------------------------
    if (option == 1) {
    char infoinput[100];
    printf("What is this password for: ");
    scanf("%s", infoinput);
        op1(infoinput);
        return 0;
    }
// if 2 -------------------------------------------------------------------------
    else if (option == 2) {
        op2();
        return 0;
    }
// if 3 -------------------------------------------------------------------------
    else if (option == 3) {
        int option1;

        printf("1 User And Password: \n2 User Only: \n3 Password only: ");

        scanf("%d", &option1);
// if 1-1 -------------------------------------------------------------------------
        if (option1 == 1) {
        op1_1();

    return 0;
// if 1-2 -------------------------------------------------------------------------
        } else if (option1 == 2) {

        return 0;
// if 1-3 -------------------------------------------------------------------------
        } else if (option1 == 3) {
        op3_3();

    return 0;
        }

    }
    else {
        printf("Please Only Use Numbers 1 - 3\n");
    }

    if (option <= 1 >= 3)
    break;
    }


    return 0;
}



