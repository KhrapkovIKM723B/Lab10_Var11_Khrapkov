#include <iostream>
#include <string>
using namespace std;

struct Product
{
    string name;
    int code;
    int quantity;
    float price;
};

void print_product(const Product& product)
{
    cout << "Товар: " << product.name << ", Код: " << product.code
        << ", Кількість: " << product.quantity << ", Ціна: " << product.price << " грн" << endl;
}

void sort_by_price(Product* products, int num)
{
    for (int i = 0; i < num - 1; i++) 
    {
        int min_index = i;
        for (int j = i + 1; j < num; j++) 
        {
            if (products[j].price < products[min_index].price)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            Product temp = products[i];
            products[i] = products[min_index];
            products[min_index] = temp;
        }
    }
}

int main() 
{
    system("chcp 65001");

    int num;
    cout << "Введіть кількість товарів: ";
    cin >> num;
    cin.ignore();

    Product* products = new Product[num];
    for (int i = 0; i < num; i++) 
    {
        cout << "Введіть назву товару: ";
        getline(cin, products[i].name);
        cout << "Введіть код товару: ";
        cin >> products[i].code;
        cout << "Введіть кількість товару: ";
        cin >> products[i].quantity;
        cout << "Введіть ціну товару: ";
        cin >> products[i].price;
        cin.ignore();
    }

    cout << "\nВсі товари:\n";
    for (int i = 0; i < num; i++)
    {
        print_product(products[i]);
    }

    sort_by_price(products, num);

    cout << "\nТовари відсортовані за ціною:\n";
    for (int i = 0; i < num; i++) 
    {
        print_product(products[i]);
    }

    delete[] products;
    return 0;
}
