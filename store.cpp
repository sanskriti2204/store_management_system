#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const double DISCOUNT_RATE = 0.1;

const double SPECIAL_MEMBER_DISCOUNT_RATE = 0.15;
long long int SPECIAL_MEMBER_MOBILE_NUMBER[] = {7985640321, 9557419393, 7489114332, 9045801674, 9456280633, 8171818912, 8383876383};

class Person {
public:
    Person(string name, long long int mobileNumber)
        : name(name), mobileNumber(mobileNumber) {}

    string getName() const {
        return name;
    }

    long long int getMobileNumber() const {
        return mobileNumber;
    }

private:
    string name;
    long long int mobileNumber;
};

class Customer : public Person {
public:
    Customer(string name, long long int mobileNumber)
        : Person(name, mobileNumber), isSpecialMember(false), totalSpent(0.0) {}

    void setSpecialMember(bool status) {
        isSpecialMember = status;
    }

    bool getSpecialMember() const {
        return isSpecialMember;
    }

    double getTotalSpent() const {
        return totalSpent;
    }

    void applyDiscount(double discount) {
        totalSpent -= discount;
    }

private:
    bool isSpecialMember;
    double totalSpent;
};

class Item {
public:
    Item(string name, double price) : name(name), price(price) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

private:
    string name;
    double price;
};

class CartItem {
public:
    CartItem(Item item, int quantity) : item(item), quantity(quantity) {}

    Item getItem() const {
        return item;
    }

    int getQuantity() const {
        return quantity;
    }

private:
    Item item;
    int quantity;
};

class Store {
public:
    Store() {
        items = {
            Item("TV", 10000.0), Item("MOBILE", 20000.0), Item("SPEAKER", 3000.0), Item("PS5", 100000.0),
            Item("EARPHONES", 1000.0), Item("FRIDGE", 30000.0), Item("MICROWAVES", 15000.0), Item("PHILLIPS TRIMMER", 3000.0),
            Item("CHARGER", 300.0), Item("FANS", 10000.0), Item("TOASTER", 4000.0), Item("DELL LAPTOP", 90000.0), Item("AIRPODS", 30000.0),
            Item("MAC", 120000.0), Item("BULB", 30.0), Item("TUBELIGHT", 100.0),
            Item("DISHWASH", 100.0), Item("ARIEL LIQ", 200.0), Item("SOAP", 40.0), Item("SUGAR 1KG", 70.0),
            Item("BESAN 1KG", 100.0), Item("FLOUR 1KG", 200.0), Item("OREO", 30.0), Item("DAL 1KG", 300.0),
            Item("RICE 1KG", 300.0), Item("OIL 1L", 500.0), Item("GHEE 1KG", 500.0), Item("CURD(100g)", 30.0), Item("MAGGI(150G)", 28.0),
            Item("SOUP", 20.0), Item("MILK 1L", 32.0), Item("GARAM MASALA (200G)", 50.0),
            Item("WATCHES", 2000.0), Item("BELTS", 1000.0), Item("WALLETS", 1000.0),
            Item("HANDBAGS", 1500.0), Item("BRACELETS", 500.0), Item("EARRINGS", 500.0), Item("CAPS AND HATS", 800.0), Item("HAIR ACCESORIES", 600.0),
            Item("JEWELLERY SETS", 2000.0), Item("MASKS", 250.0), Item("LAPTOP BAGS", 1500.0),
            Item("RINGS", 1000.0), Item("SOCKS", 300.0), Item("SUNGLASSES", 800.0), Item("UMBRELLAS", 500.0),
            Item("SNEAKERS", 3000.0), Item("CROCS", 2000.0), Item("FLATS", 1000.0), Item("WEDGES", 1500.0), Item("BOOTS", 2500.0), Item("SPORTS SHOES", 6000.0),
            Item("FLIP FLOPS", 500.0), Item("STILETTOS", 1000.0), Item("BALLERINAS", 800.0), Item("PUMPS", 1500.0),
            Item("LOAFERS", 2000.0), Item("LEATHER SHOES", 4000.0), Item("JORDANS", 20000.0), Item("SANDALS", 1000.0), Item("SLIPPERS", 250.0),
            Item("KURTA AND KURTI", 1000.0), Item("SALWARS AND CHURIDARS", 800.0),
            Item("DUPATTAS", 500.0), Item("JACKETS AND SHRUGS", 2000.0), Item("LEHENGA CHOLI SETS", 5000.0),
            Item("SKIRTS AND GHAGARAS", 2000.0), Item("SWEATERS AND CARDIGANS", 1000.0),
            Item("TROUSERS AND PANT", 1500.0), Item("SAREES", 5000.0), Item("JUMPSUITS AND PLAYSUITS", 2000.0),
            Item("ETHNIC BOTTOMS", 1500.0), Item("SHIRTS", 1000.0), Item("DRESS MATERIAL", 1000.0),
            Item("KURTA SUIT SETS", 2500.0), Item("LEGGINGS", 500.0)
        };
    }

    void displayAvailableItems() {
        cout << "Available Items:" << endl;

        cout << setw(30) << "Index" << setw(35) << "Item Name" << setw(30) << "Price" << endl;
        for (int i = 0; i < items.size(); i++) {
            cout << setw(30) << i << setw(35) << items[i].getName() << setw(30) << items[i].getPrice() << endl;
        }
    }

    void addItemToCart(int itemIndex, int quantity) {
        if (itemIndex < 0 || itemIndex >= items.size()) {
            cout << "Invalid item index. Please try again." << endl;
            return;
        }

        CartItem cartItem(items[itemIndex], quantity);
        cart.push_back(cartItem);
    }

    void displayCart() const {
        if (cart.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }

        cout << "ITEMS IN CART:" << endl;
        cout << setw(20) << "ITEM NAME:" << setw(20) << "PRICE" << setw(20) << "QTY" << endl;
        cout << endl;
        for (const CartItem& cartItem : cart) {
            cout << setw(25) << cartItem.getItem().getName()
                << setw(20) << cartItem.getItem().getPrice()
                << setw(20) << cartItem.getQuantity() << endl;
        }
    }

    double calculateSubtotal() {
        double subtotal = 0.0;

        for (const CartItem& cartItem : cart) {
            subtotal += cartItem.getItem().getPrice() * cartItem.getQuantity();
        }

        return subtotal;
    }

    double calculateDiscount(double subtotal, Customer& customer) {
        double discount = 0.0;

        for (int i = 0; i < 6; ++i) {
            if (customer.getMobileNumber() == SPECIAL_MEMBER_MOBILE_NUMBER[i]) {
                customer.setSpecialMember(true);
            }
        }

        if (customer.getSpecialMember()) {
            discount = subtotal * SPECIAL_MEMBER_DISCOUNT_RATE;
        } else {
            discount = subtotal * DISCOUNT_RATE;
        }
        return discount;
    }

    void displayBill(double subtotal, double discount, double total, Customer& customer) {
        cout << "\n*** MSM STORES **" << endl;

        cout << "CUSTOMER NAME: " << customer.getName() << endl;

        cout << endl;

        cout << "CUSTOMER MOBILE NO.:" << customer.getMobileNumber() << endl;

        cout << endl;

        cout << "SUBTOTAL : Rs." << subtotal << endl;

        cout << endl;
        cout << "DISCOUNT : Rs." << discount << endl;

        cout << endl;
        cout << "TOTAL: Rs. " << total << endl;

        cout << endl;
        cout << "TOTAL SPENT: Rs. " << customer.getTotalSpent() << endl;

        cout << endl;
        cout << "MEMBERSHIP STATUS: " << (customer.getSpecialMember() ? "Customer is an esteemed member of our store" : "Regular") << endl;

        cout << "\n*******" << endl;
    }

private:
    vector<Item> items;
    vector<CartItem> cart;
};

int main() {
    string name;
    long long int mobileNumber;

    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter customer mobile number: ";
    cin >> mobileNumber;

    Customer customer(name, mobileNumber);
    Store store;

    int choice;
    do {
        cout << "\n============ MSM STORES ==============" << endl;
        cout << "1. Display Available Items" << endl;
        cout << "\n||--------------------------------------||" << endl;
        cout << "2. Add Item to Cart" << endl;
        cout << "\n||--------------------------------------||" << endl;
        cout << "3. Display Cart" << endl;
        cout << "\n||--------------------------------------||" << endl;
        cout << "4. Checkout" << endl;
        cout << "\n||--------------------------------------||" << endl;
        cout << "5. Apply Special Membership" << endl;
        cout << "\n||--------------------------------------||" << endl;
        cout << "6. Exit" << endl;
        cout << "\n||======================================||" << endl;
        cout << endl;
        cout << endl;

        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                store.displayAvailableItems();
                break;
            case 2: {
                int itemIndex, quantity;
                cout << "Enter item index: ";
                cin >> itemIndex;
                cout << "Enter quantity: ";
                cin >> quantity;
                store.addItemToCart(itemIndex, quantity);
                break;
            }
            case 3:
                store.displayCart();
                break;
            case 4: {
                double subtotal = store.calculateSubtotal();

                double discount = store.calculateDiscount(subtotal, customer);

                double total = subtotal - discount;

                customer.applyDiscount(discount);

                store.displayBill(subtotal, discount, total, customer);
                break;
            }
            case 5:
                customer.setSpecialMember(true);
                cout << "Special membership applied." << endl;
                break;
            case 6:
                cout << "Thank you for visiting MSM Stores" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 6);
    return 0;
}
