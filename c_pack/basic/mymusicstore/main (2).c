#include<stdio.h>

void main(void )
{
        welcome();
        printf("\n\n**********");
        login();
        printf("**********\n\n");
        selectService();
        logout();
}

void welcome()
{
    printf("Welcome to AG-Music-Store!\n");
    printf("This is a command-line music management software.\n");
}

void login()
{
    printf("Username:");
    scanf("%f",&username);
    printf("Password:");
    scanf("%d",&password);

}

void logout()
{
    printf("Logging out.......\n");
    printf("Log out!\n");
}

void selectService()
{
    switch(int x)
    case 0: addAlbum();
            break;
    case 1: addSong();
            break;
    case 2: deleteAlbum();
            break;
    case 3: deleteSong();
            break;
    case 4: showAllAlbum();
            break;
    case 5: showAllSong();
            break;
    case 6: addUser();
            break;
    case 7: deleteUser();
            break;
    case 8: userConfig();
            break;
}
