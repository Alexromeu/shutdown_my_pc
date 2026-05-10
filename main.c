#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


int hrs, mins;
struct Times
{
    int hrs;
    int mins;
};

void timer(struct Times *tm)
{
    int hrs, mins, total;
    int segs = 59;
    hrs = tm->hrs;
    mins = tm->mins;
    total = hrs*3600 + mins*60;
    bool hour0 = tm->hrs == 0;

    while (1) {
        if (hrs == 0 && mins == 0 && segs == 0) {
            break;
       }

       system("cls");
       if (hrs == 0) hour0 = true;

       if (!hour0) {
        printf("The time left is: %d:%d:%d\n", hrs, mins, segs);
       } else {
        printf("The time left is: %d:%d\n", mins, segs);
       }

       
       sleep(1);

       if (segs == 0) {
            if (mins == 0) {
                if (hrs > 0) {
                    hrs--;
                    mins = 59;
                    segs = 59;
                }
            } else {
                mins--;
                segs = 59;
            }
       } else segs--;

    }
}

void menu(struct Times *tm)
{
    bool running = true;
    while (running) {
        system("cls");
        int hrs = -1;
        int mins = -1;
        printf("Enter the hours to turn off.\n HOURS: ");
        scanf("%d", &hrs);

        printf("Enter the minutes to turn off.\n NIMUTES: ");
        scanf("%d", &mins);

        if (hrs >= 0 && mins >= 0) {
            tm->hrs = hrs;
            tm->mins = mins;
            break;
        } else {
            printf("Something is wrong with the time, try again.");
            continue;
        }

    }
}

void shutdown()
{
    char* prompt = "C:\\Windows\\System32\\shutdown /s";
    system(prompt);
}


int main()
{
    struct Times tms;
    menu(&tms);
    timer(&tms);
    // printf("==time off==");
    // sleep(5);
    shutdown();
    printf("BYE BYE!...");
    return 0;
}
