# bus_ticket_reservation_system
The Bus Ticket Reservation System is a C-based application designed to manage bus services, allowing users to book, cancel, and manage bus tickets efficiently. It supports functionalities such as bus installation, seat reservation, ticket cancellation, and feedback collection, providing a streamlined solution for bus transportation services.

Features

Admin Panel:

Add new buses to the system with driver details and schedules.

View all registered buses and their statuses.

User Registration:

Register users with name, phone number, and email.

Ticket Booking:

Search buses by arrival time.

View available seats for a selected bus.

Confirm and book seats with passenger details.

Ticket Cancellation:

Cancel a booked seat by providing the seat number and arrival time.

Feedback System:

Collect user feedback for service improvement.

Customer Service:

Display customer support contact details.

How to Run

Compile the program using any C compiler

Functional Flow

The program begins with a main menu offering various options such as login, ticket booking, cancellation, etc.

Users can navigate through the menu by entering corresponding numbers.

The admin section is protected by a username-password system.

Data such as bus details, feedback, and booking statuses are stored in text files.

File Structure

view_bus.txt: Stores details of all installed buses.

Bus<arrival_time>.txt: Maintains seat information for each bus based on arrival time.

feedback.txt: Stores user feedback.

Key Functions

install_bus(): Allows the admin to add buses to the system.

register_user(): Registers user information.

search_bus(): Searches buses based on arrival time.

view_available_seats(): Displays available seats for a specific bus.

confirm_seat(): Confirms a seat reservation.

cancel_seat(): Cancels a previously booked seat.

feedback(): Collects and stores user feedback.

Admin Credentials

The application supports predefined admin usernames and passwords:

Username: Mustakim, Password: 1093

Username: Miraj, Password: 1094

Username: Shuvo, Password: 1169

Future Enhancements

Integration with a database for better data management.

Adding a graphical user interface (GUI).

Enabling online payments for ticket reservations.

Contact Information

For any queries or issues, please contact our customer service:

Phone Numbers:

01887867867

Emails:

abdullahalmustakimjim@gmail.com


Acknowledgments

This project was developed as a learning initiative to explore system programming and management techniques using C.

Disclaimer

This project is for educational purposes and may require further development for real-world deployment.

