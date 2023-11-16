#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include <random>
//#include <windows.h>

using namespace std;

std::string getOrdinalForm(int number) {
    if (number >= 10 && number <= 20) {
        return std::to_string(number) + "th";
    }

    switch (number % 10) {
        case 1: return std::to_string(number) + "st";
        case 2: return std::to_string(number) + "nd";
        case 3: return std::to_string(number) + "rd";
        default: return std::to_string(number) + "th";
    }
}

class PaymentPlan {
public:
    string planName;
    float planAmount;
    string planDuration;
};
class node
{
        public:
		float val;
		float cash;
		long long phn;
		string email;
		string name;
		string lname;
		string fullName;
		int id;
		vector<PaymentPlan> paymentPlans;

		node * next;
};
class bank //new class
{
	private:
		node * head; //first node
	public:
		int length = 0;
		bank()
	{
	head = NULL; //initial address of first node
	}

void displayDetails();
void insertData(); //open account
void deleteAccount();
void deposite(int );
void withdrawal(int );
void update();
void search();
};
void addPaymentPlan(node& account) {
    int numPlans;
    cout <<endl<< "Enter the number of payment plans: ";
    cin >> numPlans;
    cin.ignore();  // Clear the newline character from the input buffer

    for (int i = 0; i < numPlans; i++) {
        PaymentPlan plan;
        cout << "Enter Plan Name: ";
        cin >> plan.planName;
        cout << "Enter Plan Amount (in Rupees): ";
        cin >> plan.planAmount;
        cin.ignore();  // Clear the newline character from the input buffer
        cout << "Enter Plan Deduction (in months): ";
        getline(cin, plan.planDuration);
        account.paymentPlans.push_back(plan);
    }
}

void bank::displayDetails() // to display linked list
{
    node *p = head;
    if (head == NULL) // condition to check if the list is empty or not
    {
        cout << "\nThere is no data found!!"; 
    }
    else
    {
        cout << "\nBank Account Management System\n";
        while (p != NULL)
        {
            cout << "------------------------------------------------------------------------------------" << endl;
            cout << "Account Number: " << p->id<< "\n" << "Full Name: " << p->fullName << "\n" << "Phone number: " << p->phn << "\n" << "Email id: " << p->email << "\n" << "Cash in account: Rs. " << p->cash << "\n";
            cout << "------------------------------------------------------------------------------------" << endl;
            if (!p->paymentPlans.empty()) {
                cout << "Payment Plans:\n";
                for (const PaymentPlan &plan : p->paymentPlans) {
                    cout << "  Plan Name: " << plan.planName << " | Amount: Rs. " << plan.planAmount << " | Deduction Date: " << plan.planDuration << "\n";
                }
            }
            p = p->next;
        }
    }



//while closed
cout<<"\nTotal AccountHolders= "<<length;
}
/*int generateRandomAccountID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1000000, 999999999); // Range of 7-9 digits

    return distribution(gen);*/
#include <regex> // Include the regex library

// ...

void bank::insertData() // open account
{
    long long no = 1, ca, ph;
    string fullName, em;
    node* temp = new node;

    cin.ignore(); // Clear the input buffer
    cout << "\nEnter full name (including middle name if any): ";
    getline(cin, fullName);

    // Split the full name into first and last names
    string firstName, lastName;
    istringstream nameStream(fullName);
    nameStream >> firstName; // Extract the first name
    string lastPart;
    while (nameStream >> lastPart) {
        lastName += lastPart + " "; // Concatenate multiple words as the last name
    }

    // Store the first and last names in the node
    temp->name = firstName;
    temp->lname = lastName;
    temp->fullName = fullName; // Store the full name

    // Loop until a valid phone number is entered
    while (true) {
        cout << "\nEnter phone number (ten digits): ";
        string phoneInput;
        cin >> phoneInput;

        // Check if the phone number input has exactly ten digits
        if (phoneInput.length() == 10 && std::all_of(phoneInput.begin(), phoneInput.end(), ::isdigit)) {
            long long ph = stoll(phoneInput);
            temp->phn = ph; // Store the phone number
            break; // Valid phone number, exit the loop
        } else {
            cout << "Invalid phone number. Please enter a 10-digit numeric phone number." << endl;
        }
    }

    // Validate the email format using a regular expression
    while (true) {
        cout << "\nEnter valid email id (e.g., xyz@abc.com): ";
        cin >> em;
        // Use a regular expression to validate the email format
        if (std::regex_match(em, std::regex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}"))) {
            break; // Valid email format, exit the loop
        } else {
            cout << "Invalid email format. Please enter a valid email address (e.g., xyz@abc.com)." << endl;
            cin.clear(); // Clear any error flags
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        }
    }
    //cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

    // Prompt for the account ID and check for validity
    bool isDuplicateID;
    long long id;

    for (int attempts = 0; attempts < 3; attempts++) {
        cout << "\nEnter new account Number of 8-9 digits: "<<"(attempt: "<<attempts<<") ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.clear();
        cin >> id;
        if (id >= 10000000 && id <= 999999999) {
            bool isDuplicateID = false;
            node* current = head;
            while (current != nullptr) {
                if (current->id == id) {
                    isDuplicateID = true;
                    cout << "Account Number already exists. Please choose a different Number." << endl;
                    break;
                }
                current = current->next;
            }
            if (!isDuplicateID) {
                break; // Valid account ID
            }
        } else {
            cout << "Invalid account Number. Please enter a unique Number of 8-9 digits." << endl;
        }

        if (attempts == 2) {
            cout << "Exceeded maximum attempts. Account creation failed." << endl;
            return;
        }
    }

    cout << "\nEnter your cash (in Rupees) = ";
    cin >> ca;

    temp->val = no;
    temp->cash = ca;
    temp->name = firstName;
    temp->lname = lastName;
    temp->email = em;
    temp->id = id;

    // Enter the number of payment plans
    int numPlans;
    std::cout << "\nEnter the number of payment plans: ";
    std::cin >> numPlans;

    for (int i = 0; i < numPlans; i++) {
        PaymentPlan plan;
        std::cout << "\nEnter details for the " << getOrdinalForm(i + 1) << " payment plan:" << std::endl;
        std::cout << "Enter the " << getOrdinalForm(i + 1) << " Plan Name: ";
        std::cin >> plan.planName;
        std::cout << "Enter the " << getOrdinalForm(i + 1) << " Plan Amount (in Rupees): ";
        std::cin >> plan.planAmount;
        std::cout << "Enter the " << getOrdinalForm(i + 1) << " deduction Date (dd-mm-yyyy): ";
        std::cin >> plan.planDuration;
        temp->paymentPlans.push_back(plan);
    }

    temp->next = head;
    head = temp;
    length++;
    cout << "\nNEW ACCOUNT CREATED SUCCESSFULLY" << endl;
    cout << "Account Number: " << id << endl; // Display the account ID
}
//function closed
void bank::deposite(int id) {
    int amt;
    bool found = false;
    int flag = 0;
    node* p = head;
    while(p!=NULL)
	{
	if(p->id==id)
	{
	flag=1;
	break;
	}
	p=p->next;
	}
	if(flag==0){
            cout << "Account Number not found" <<"." << endl;
            return;
    }

    // If the account at the specified index is found
    if (p != nullptr) {
        found = true;
        cout << "Account Number " << p->id << " is selected." << endl;
    }

    if (found) {
        cout << "Enter amount you want to deposit: ";
        cin >> amt;
        p->cash += amt;  // Deposit the amount into the selected account
        cout << "After deposit, the total amount in the selected account with Number " << p->id << " is: Rs. " << p->cash << endl;
    }
}
void bank::withdrawal(int id) {
    node* current = head;
    int amt;
    bool found = false;

    if (head == NULL) {
        cout << "Data is not found" << endl;
        return;
    }

    while (current != NULL) {
        if (current->id == id) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        cout << "Enter amount you want to withdraw: ";
        cin >> amt;
        if(amt > current->cash){
            cout<<"Insufficient balance in account.";
        }
        else{
        int total = current->cash - amt;
        current->cash = total;
        cout << "After withdrawal, your total amount in the account is " << total << endl;
        }
    }
    else {
        cout << "Account not found." << endl;
    }
        
}

void bank::deleteAccount() {
    int deleteID;
    cout << "Enter the Account Number of the account to be deleted: ";
    cin >> deleteID;

    node *current = head;
    node *prev = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->id == deleteID) {
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    }

    if (found) {
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        length--;

        cout << "\nAccount with Number " << deleteID << " is deleted successfully!" << endl;
    } else {
        cout << "\nAccount with Number " << deleteID << " not found." << endl;
    }
}

void bank::update() {
    int id;
    cout << "Enter the account Number: ";
    cin >> id;
    node* p = head;
    int flag = 0;
    while (p != NULL) {
        if (p->id == id) {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0) {
        cout << "\nNumber NOT FOUND!!!\n";
    } else {
        string new_fullName, new_em;
        long long new_ph;

        cout << "Enter new full name (including first name, middle name, and last name): ";
        cin.ignore(); // Clear the input buffer
        getline(cin, new_fullName);

        // Loop until a valid phone number is entered
        while (true) {
            cout << "Enter new phone number (exactly 10 digits): ";
            cin >> new_ph;
            if (cin.good() && to_string(new_ph).length() == 10) {
                break; // Valid phone number, exit the loop
            } else {
                cout << "Invalid phone number. Please enter exactly 10 digits." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }
        }

        // Validate the email format using a regular expression
        while (true) {
            cout << "Enter new email id (e.g., xyz@abc.com): ";
            cin >> new_em;
            // Use a regular expression to validate the email format
            if (std::regex_match(new_em, std::regex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}"))) {
                break; // Valid email format, exit the loop
            } else {
                cout << "Invalid email format. Please enter a valid email address (e.g., xyz@abc.com)." << endl;
            }
        }

        // Update account details in the existing node
        p->fullName = new_fullName;
        p->phn = new_ph;
        p->email = new_em;

        cout << "ACCOUNT UPDATED SUCCESSFULLY!" << endl;
        cout << "\nUPDATED DETAILS:\n";
        cout << "Full Name: " << p->fullName << endl;
        cout << "Phone Number: " << p->phn << endl;
        cout << "Email: " << p->email << endl;
    }
}

//function closed
void bank::search()
{
    int id;
    int flag = 0;
    node* p = NULL;
    p = head;
    cout << "Enter account Number = ";
    cin >> id;
    while (p != NULL)
    {
        if (p->id == id)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        cout << "\n Account not found.\n";
    }
    else
    {
        cout << "\n-------------DETAILS OF THE ACCOUNT HOLDER \n";
        cout << "\nFull Name: " << p->fullName << endl;
        cout << "Phone number: " << p->phn << endl;
        cout << "Account Number: " << p->id << endl;
        cout << "Email id: " << p->email << endl;
        cout << "Cash in account: Rs. " << p->cash << "\n";
    }
}

/*void setColor(int color){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void pattern(){
    setColor(3);
cout <<         " _  _  _    _  _   _  _   __  _   _ \n"
                 "|  _    ||   _   ||  |  | ||   | | ||   | |       ||  | |  |\n"
                 "| ||   ||  ||  ||   || ||   || ||   | |    ||  ||  |\n"
                 "|       ||       ||       ||      | |   | |   |_ |       |\n"
                 "|  _   | |       ||  _    ||     |_ |   | |    |  |     _|\n"
                 "| |_|   ||   _   || | |   ||    _  ||   | |   |      |   |  \n"
                 "|_||| ||||  |||| |||| ||      ||  \n";

                 cout<<"\n                  NEW AGE BANKING "<<endl;
                 setColor(14);
                 }*/

int main()
{
    bank l1;
    //pattern();
    int id;
    int ch, choice;

    do {
        cout << "\nPress 1 to start = ";
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            cout << "Invalid input. Please enter 1 to start." << endl;
            continue; // Restart the loop
        }

        if (ch == 1) {
            while (ch == 1) {
                cout << "\n MENU ";
                cout << "\n1. Open Account (payment plan)\n2. Display Details\n3. Deposit\n4. Withdrawal\n5. Delete Account\n6. Update\n7. Search\n";
                cout << "\nEnter your choice = ";

                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                    cout << "Invalid input. Please enter a valid choice from the menu." << endl;
                    continue; // Restart the loop
                }

                switch (choice) {
                case 1:
                    l1.insertData();
                    break;
                case 2:
                    l1.displayDetails();
                    break;
                case 3:
                    cout << "Enter account Number" << endl;
                    cin >> id;
                    l1.deposite(id);
                    break;
                case 4:
                    cout << "Enter account Number" << endl;
                    cin >> id;
                    l1.withdrawal(id);
                    break;
                case 5:
                    cout << "\nDelete an Account\n" << endl;
                    l1.deleteAccount();
                    break;
                case 6:
                    l1.update();
                    break;
                case 7:
                    l1.search();
                    break;
                default:
                    cout << "Invalid choice. Please select a valid option from the menu." << endl;
                    break;
                }
            }
        } else {
            cout << "Invalid input. Please enter 1 to start." << endl;
        }
    } while (ch != 1);

    return 0;
}
