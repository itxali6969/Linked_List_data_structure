#include <iostream>
using namespace std;
class Node {
private:
    string name;
    int id;
    int quantity;
    double price;
    Node* next;
public:
    // Getter methods
    string getName()  {
        return name;
    }

    int getId() {
        return id;
    }

    int getQuantity()  {
        return quantity;
    }

    double getPrice()  {
        return price;
    }

    Node* getNext()  {
        return next;
    }

    // Setter methods
    void setName(string name) {
        this->name = name;
    }

    void setId(int id) {
        this->id = id;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setNext(Node* next) {
        this->next = next;
    }
};

class Inventory {
private:
    Node* head;
    Node* current;

public:
    Inventory() {
        head = NULL;
        current = NULL;
    }

 
void addProduct(string name, int id, int quantity, double price) {
    Node* newNode = new Node();
    newNode->setName(name);
    newNode->setId(id);
    newNode->setQuantity(quantity);
    newNode->setPrice(price);
    newNode->setNext(NULL);

    if (head == NULL) {
        head = newNode;
        current = head; // initialize current pointer
    }
    else {
        current->setNext(newNode);
        current = current->getNext(); // update current pointer
    }
    cout << "Product added successfully." << endl;
}
    // Remove a product from the inventory
    void removeProduct(int id) {
        if (head == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        else if (head->getId() == id) {
            Node* temp = head;
            head = head->getNext();
            delete temp;
            cout << "Product removed successfully." << endl;
            return;
        }
        else {
            Node* current = head;
            while (current->getNext() != NULL && current->getNext()->getId() != id) {
                current = current->getNext();
            }
            if (current->getNext() == NULL) {
                cout << "Product not found." << endl;
                return;
            }
            else {
                Node* temp = current->getNext();
                current->setNext(temp->getNext());
                delete temp;
                cout << "Product removed successfully." << endl;
                return;
            }
        }
    }

    // Update a product in the inventory
    void updateProduct(int id, int quantity, double price) {
        if (head == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        else {
            Node* current = head;
            while (current != NULL && current->getId() != id) {
                current = current->getNext();
            }
            if (current == NULL) {
                cout << "Product not found." << endl;
                return;
            }
            else {
                current->setQuantity(quantity);
                current->setPrice(price);
                cout << "Product updated successfully." << endl;
                return;
            }
        }
    }

    // Display the inventory
    void displayInventory() {
        if (head == NULL) {
            cout << "Inventory is empty." << endl;
            return;
        }
        else {
            Node* current = head;
            cout << "Inventory:" << endl;
            cout << "Name\tID\tQuantity\tPrice" << endl;
            while (current != NULL) {
                cout << current->getName() << "\t" << current->getId() << "\t" << current->getQuantity() << "\t\t" << current->getPrice() << endl;
                current = current->getNext();
            }
        }
    }
};

int main(){
	Inventory obj;
    int choice;

    do {
        cout << "Please choose an action:" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Remove product" << endl;
        cout << "3. Update product" << endl;
        cout << "4. Display inventory" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int numProducts;
                cout << "How many products do you want to add? ";
                cin >> numProducts;

                for (int i = 0; i < numProducts; i++) {
                    string name;
                    int id, quantity;
                    float price;

                    cout << "Enter product name: ";
                    cin >> name;

                    cout << "Enter product ID: ";
                    cin >> id;

                    cout << "Enter product quantity: ";
                    cin >> quantity;

                    cout << "Enter product price: ";
                    cin >> price;

                    obj.addProduct(name, id, quantity, price);
                }

                break;
            }

            case 2: {
                int id;
                cout << "Enter product ID to remove: ";
                cin >> id;

                obj.removeProduct(id);
                break;
            }

            case 3: {
                int id, quantity;
                float price;

                cout << "Enter product ID to update: ";
                cin >> id;

                cout << "Enter new quantity: ";
                cin >> quantity;

                cout << "Enter new price: ";
                cin >> price;

                obj.updateProduct(id, quantity, price);
                break;
            }

            case 4: {
                obj.displayInventory();
                break;
            }

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
