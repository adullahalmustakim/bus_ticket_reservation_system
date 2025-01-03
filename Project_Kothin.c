#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct bus_install
{
    char bus_registration_number[20];
    char driver_name[50];
    char arrival_time[10];
    char departure_time[10];
};

struct register_user
{
    char name[30];
    char phone_number[20];
    char email[50];
};

void install_bus()
{
    int admin_name[20];
    printf("Admin name: ");
    fflush(stdin);
    gets(admin_name);

    int password;
    printf("Password: ");
    scanf("%d", &password);

    if ((strcmp(admin_name, "Mustakim") == 0 && password == 1093) ||
            (strcmp(admin_name, "Miraj") == 0 && password == 1094) ||
            (strcmp(admin_name, "Shuvo") == 0 && password == 1169))
    {
        FILE *bus_details;
        bus_details = fopen("view_bus.txt", "a");

        if (bus_details == NULL)
        {
            printf("Error opening file.\n");
            exit(1);
        }

        struct bus_install bus[48];

        int n;
        printf("How many buses do you want to install? \n");
        scanf("%d", &n);
        getchar();

        fprintf(bus_details, "Arrival Time\tDeparture Time\tBus reg. no.\tDriver name\tStatus\n");
        fprintf(bus_details, "============\t==============\t============\t===========\t======\n");

        for (int i = 0; i < n; i++)
        {
            printf("\nEnter the arrival time[%d]: ", i + 1);
            fflush(stdin);
            gets(bus[i].arrival_time);

            printf("\nEnter the departure time[%d]: ", i + 1);
            fflush(stdin);
            gets(bus[i].departure_time);

            printf("\nEnter the bus registration number[%d]: ", i + 1);
            fflush(stdin);
            gets(bus[i].bus_registration_number);

            printf("\nEnter the driver name[%d]: ", i + 1);
            fflush(stdin);
            gets(bus[i].driver_name);

            printf("\nBus registration is successful.\n");
            fprintf(bus_details, "%s\t\t%s\t\t%s\t\t%s\t\tActive\n", bus[i].arrival_time, bus[i].departure_time, bus[i].bus_registration_number, bus[i].driver_name);
        }
        fclose(bus_details);

        bus_file(bus, n);

        exit(0);
    }
    else
    {
        printf("Your password is incorrect.\n");
        printf("\nReturning to main menu...\n\n");

        while (getchar() != '\n');
    }
}

void register_user()
{
    struct register_user number[48];
    int num;
    printf("Enter the number of the user: ");
    scanf("%d",&num);

    for(int i = 0; i < num; i++)
    {
        printf("\nEnter your name[%d]: ",i+1 );
        fflush(stdin);
        gets(number[i].name);

        printf("Enter your phone number[%d]: ", i+1);
        fflush(stdin);
        gets(number[i].phone_number);

        printf("Enter your email[%d]: ", i+1);
        fflush(stdin);
        gets(number[i].email);

        printf("Your registration is processing................\n");
        printf("Registration successful.\nThank you for registering in our system.\n");
    }
    exit(0);
}

void back_to_menu()
{
    printf("\nReturning to main menu...\n\n");

    while(getchar() != '\n');
}

void login()
{
    int choice_login;
    printf("\n******* LOGIN *******");
    printf("\n----------------------\n");
    printf("1. Install Bus\n");
    printf("2. Register\n");
    printf("3. Back to Menu\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice_login);

    switch(choice_login)
    {
    case 1:
        install_bus();
        break;
    case 2:
        register_user();
        break;
    case 3:
        back_to_menu();
        return;
    default:
        printf("Invalid choice. Please try again.\n");
    }
}

void bus_file(struct bus_install bus[], int n)
{
    FILE *bus_files[48];
    for (int i = 0; i < n; i++)
    {
        char filename[50];
        char bus_num[3];

        strncpy(bus_num, bus[i].arrival_time, 2);
        bus_num[2] = '\0';

        sprintf(filename, "Bus%s.txt", bus_num);

        bus_files[i] = fopen(filename, "w");

        if (bus_files[i] == NULL)
        {
            printf("Error creating file for bus %s.\n", bus_num);
            exit(1);
        }
        fprintf(bus_files[i], "Seat Number\tPassenger Name\tPhone Number\tStatus\n");
        fprintf(bus_files[i], "~~~~~~~~~~~\t~~~~~~~~~~~~~~\t~~~~~~~~~~~~~\t~~~~~~\n");

        for (char row = 'A'; row <= 'D'; row++)
        {
            for (int col = 1; col <= 9; col++)
            {
                fprintf(bus_files[i], "%c%d\t\tEmpty\t\t***********\tAvailable\n", row, col);
            }
        }

        fclose(bus_files[i]);
    }
}

void search_bus()
{
    char arrival_time[10];
    printf("Enter the arrival time to search for buses: ");
    fflush(stdin);
    gets(arrival_time);

    FILE *bus_details = fopen("view_bus.txt", "r");
    if (bus_details == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\nBuses arriving at %s:\n\n", arrival_time);
    printf("Arrival Time\tDeparture Time\tBus reg. no.\tDriver name\tStatus\n");
    printf("============\t==============\t============\t===========\t======\n");

    char line[150];
    while (fgets(line, sizeof(line), bus_details))
    {
        char temp_arrival_time[10];

        sscanf(line, "%s", temp_arrival_time);

        if (strcmp(temp_arrival_time, arrival_time) == 0)
        {
            printf("%s\n", line);
        }
    }

    fclose(bus_details);
}

void view_available_seats(char arrival_time[])
{
    char filename[50];
    char bus_num[3];

    strncpy(bus_num, arrival_time, 2);
    bus_num[2] = '\0';

    sprintf(filename, "Bus%s.txt", bus_num);

    FILE *bus_file = fopen(filename, "r");

    if (bus_file == NULL)
    {
        printf("Error opening file for bus %s.\n", bus_num);
        exit(1);
    }

    printf("Available seats for buses arriving at %s:\n\n", arrival_time);

    char line[150];

    while (fgets(line, sizeof(line), bus_file))
    {
        printf("%s\n", line);
    }

    fclose(bus_file);
}

void confirm_seat(char arrival_time[])
{
    char filename[50];
    char bus_num[3];

    strncpy(bus_num, arrival_time, 2);
    bus_num[2] = '\0';

    sprintf(filename, "Bus%s.txt", bus_num);

    FILE *bus_file = fopen(filename, "r+");

    if (bus_file == NULL)
    {
        printf("Error opening file for bus %s.\n", bus_num);
        exit(1);
    }

    char seat_number[5];
    printf("Enter the seat number you want to book (A-D)(1-9): ");
    scanf("%s", seat_number);

    char line[150];
    char temp_filename[] = "temp.txt";

    FILE *temp_file = fopen(temp_filename, "w");

    if (temp_file == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(bus_file);
        exit(1);
    }

    int seat_found = 0;
    char name[30];
    char phone_number[20];

    while (fgets(line, sizeof(line), bus_file))
    {
        char current_seat[5];
        sscanf(line, "%s", current_seat);
        if (strcmp(current_seat, seat_number) == 0 && strstr(line, "Available"))
        {
            seat_found = 1;

            printf("Enter your name: ");
            fflush(stdin);
            gets(name);

            printf("Enter your phone number: ");
            fflush(stdin);
            gets(phone_number);

            fprintf(temp_file, "%s\t\t%s\t\t%s\tBooked\n", current_seat, name, phone_number);
        }
        else
        {
            fputs(line, temp_file);
        }
    }

    fclose(bus_file);
    fclose(temp_file);

    if (seat_found)
    {
        remove(filename);
        rename(temp_filename, filename);
        printf("Seat %s successfully booked.\n", seat_number);

        printf("\n************** TICKET **************\n");
        printf("************************************\n");
        printf("Bus Ticket Reservation System\n");
        printf("------------------------------------\n");
        printf("Arrival Time: %s\n", arrival_time);
        printf("Seat Number: %s\n", seat_number);
        printf("Passenger Name: %s\n", name);
        printf("Phone Number: %s\n", phone_number);

        FILE *bus_details = fopen("view_bus.txt", "r");

        if (bus_details == NULL)
        {
            printf("Error opening view_bus.txt for reading.\n");
            exit(1);
        }

        char bus_line[150];

        while (fgets(bus_line, sizeof(bus_line), bus_details))
        {
            if (strstr(bus_line, arrival_time))
            {
                char bus_reg[20], driver_name[50], dep_time[10];
                sscanf(bus_line, "%s\t\t%s\t\t%s\t\t%s", arrival_time, dep_time, bus_reg, driver_name);
                printf("------------------------------------\n");
                printf("Bus Registration Number: %s\n", bus_reg);
                printf("Driver Name: %s\n", driver_name);
                printf("Departure Time: %s\n", dep_time);
                printf("************************************\n\n");
                break;
            }
        }
        fclose(bus_details);
    }
    else
    {
        remove(temp_filename);
        printf("Seat %s is not available. It is already booked.\n", seat_number);
    }
}

void book_tickets()
{
    int book_ticket;
    printf("\n******* Book Ticket *******");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Search Bus By Arrival Time\n");
    printf("2. View Available Seats\n");
    printf("3. Confirm Seat\n");
    printf("4. Back to Menu\n\n");
    printf("Enter your choice: ");
    scanf("%d", &book_ticket);
    printf("\n");

    switch(book_ticket)
    {
    case 1:
        search_bus();
        break;
    case 2:
    {
        char arrival_time[10];
        printf("Enter the arrival time to view available seats: ");
        fflush(stdin);
        gets(arrival_time);
        view_available_seats(arrival_time);
        break;
    }
    case 3:
    {
        char arrival_time[10];
        printf("Enter the arrival time for booking a seat: ");
        fflush(stdin);
        gets(arrival_time);
        confirm_seat(arrival_time);
        break;
    }
    case 4:
        back_to_menu();
        return;
    default:
        printf("Invalid choice. Please try again.\n");
    }

}

void cancel_seat(char arrival_time[], char seat_number[])
{
    char filename[50];
    char bus_num[3];

    strncpy(bus_num, arrival_time, 2);
    bus_num[2] = '\0';

    sprintf(filename, "Bus%s.txt", bus_num);

    FILE *bus_file = fopen(filename, "r");

    if (bus_file == NULL)
    {
        printf("Error opening file for bus %s.\n", bus_num);
        exit(1);
    }

    char temp_filename[] = "temp_cancel.txt";

    FILE *temp_file = fopen(temp_filename, "w");

    if (temp_file == NULL)
    {
        printf("Error creating temporary file.\n");
        fclose(bus_file);
        exit(1);
    }

    char line[150];
    int seat_found = 0;
    int line_count = 0;

    while (fgets(line, sizeof(line), bus_file))
    {
        line_count++;
        if (line_count <= 2)
        {
            fputs(line, temp_file);
        }
        else
        {
            char current_seat[5];
            sscanf(line, "%s", current_seat);
            if (strcmp(current_seat, seat_number) == 0 && strstr(line, "Booked"))
            {
                seat_found = 1;
                fprintf(temp_file, "%s\t\tEmpty\t\t***********\tAvailable\n", current_seat);
            }
            else
            {
                fputs(line, temp_file);
            }
        }
    }

    fclose(bus_file);
    fclose(temp_file);

    if (seat_found)
    {
        remove(filename);
        rename(temp_filename, filename);
        printf("Seat %s successfully cancelled.\n", seat_number);

        printf("\n************** CANCELLATION CONFIRMATION **************\n");
        printf("*******************************************************\n");
        printf("Bus Ticket Cancellation System\n");
        printf("-------------------------------------------------------\n");
        printf("Arrival Time: %s\n", arrival_time);
        printf("Seat Number: %s\n", seat_number);
        printf("Status: Canceled\n");
        printf("*******************************************************\n\n");
    }
    else
    {
        remove(temp_filename);
        printf("Seat %s is not booked or does not exist.\n", seat_number);
    }
}

void cancel_ticket()
{
    int cancel;
    printf("\n******* Cancel Ticket *******");
    printf("\n-----------------------------\n");
    printf("1. Search Bus By Arrival Time\n");
    printf("2. Back to Menu\n");
    printf("Enter your choice: ");
    scanf("%d", &cancel);

    switch(cancel)
    {
    case 1:
    {
        char arrival_time[10];
        printf("Enter the arrival time of the bus for which you want to cancel the ticket: ");
        fflush(stdin);
        gets(arrival_time);

        char seat_number[5];
        printf("Enter the seat number you want to cancel (A-D)(1-9): ");
        scanf("%s", seat_number);

        cancel_seat(arrival_time, seat_number);
        break;
    }
    case 2:
        back_to_menu();
        break;
    default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
}

void view_all_bus_status()
{
    FILE *bus_details;
    bus_details = fopen("view_bus.txt", "r");

    if (bus_details == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[150];
    while (fgets(line, sizeof(line), bus_details))
    {
        printf("%s\n", line);
    }

    fclose(bus_details);
}

void customer_service()
{
    char phone_number1[] = "01887867867";
    char phone_number2[] = "01818790057";
    char email1[] = "abdullahalmustakimjim@gmail.com";
    char email2[] = "teamwebspirder@gmail.com";

    printf("\nWelcome to Our Customer Services!\n");
    printf("---------------------------------\n\n");
    printf("** If you have any inquiries, please feel free to contact us! **\n\n");
    printf("** Phone Numbers:  \n");
    printf("- %s\n", phone_number1);
    printf("- %s\n\n", phone_number2);
    printf("** Email Addresses: \n");
    printf("- %s\n", email1);
    printf("- %s\n\n", email2);
    printf("** Thank you for choosing us! We're here to help. **\n\n");
    exit(0);
}
void feedback()
{
    char get_feedback[1000];
    printf("\nPlease provide your feedback: ");
    fflush(stdin);
    gets(get_feedback);

    FILE *feedback_file = fopen("feedback.txt", "a");
    if (feedback_file == NULL)
    {
        printf("Error opening feedback file.\n");
        exit(1);
    }

    fprintf(feedback_file, "Feedback: %s\n", get_feedback);

    fclose(feedback_file);

    printf("\nYour feedback is: %s \n\n", get_feedback);
    printf("Thanks for your feedback.\n\n");
    exit(0);
}


int main()
{
    while(1)
    {
        printf("******* BUS TICKET RESERVATION SYSTEM *******\n");
        printf("\t\tWELCOME\n");
        printf("=============================================\n");
        printf("1.Login\n");
        printf("2.Book Tickets\n");
        printf("3.Cancel Tickets\n");
        printf("4.View Bus Status\n");
        printf("5.Customer Service\n");
        printf("6.Feedback\n");
        printf("7.Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d",&choice);

        getchar();

        switch(choice)
        {
        case 1:
            login();
            break;
        case 2:
            book_tickets();
            break;
        case 3:
            cancel_ticket();
            break;
        case 4:
            view_all_bus_status();
            break;
        case 5:
            customer_service();
            break;
        case 6:
            feedback();
            break;
        case 7:
            printf("Thank you.\n");
            printf("Exiting the program........\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            printf("Please try again within number(1-7).\n\n");
        }
    }

    return 0;
}
