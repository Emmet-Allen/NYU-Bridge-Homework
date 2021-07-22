#include <iostream>

using namespace std;

const float DISCOUNT_RATE = 0.10;

int main() {

	float firstItem, secondItem ,basePrice;
	char clubCard; 
	float taxRate, discountPrice, totalPrice, totalTax, totalDiscount; 

	cout << "Enter price of first item: ";
	cin >> firstItem;
	cout << "Enter price of second item: ";
	cin >> secondItem;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> clubCard;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> taxRate; 


	basePrice = firstItem + secondItem;
	cout << "Base price: " << basePrice << endl;

	if (firstItem < secondItem) {
		firstItem = firstItem * 0.5;
		basePrice = firstItem + secondItem;
	}

	else if(secondItem <= firstItem) {
		secondItem = secondItem * 0.5;
		basePrice = firstItem + secondItem;
	}


	if (clubCard ==  'Y') {
		totalDiscount = basePrice * DISCOUNT_RATE;
		discountPrice = basePrice - totalDiscount;
		cout << "Price after discounts: " << discountPrice << endl;
	}
	else {
		discountPrice = basePrice;
		cout << "Price after discounts: " << discountPrice << endl; 
	}

	taxRate = taxRate / 100;

	totalTax = (discountPrice * taxRate); 
	totalPrice =discountPrice + totalTax;

	cout << "Total price: " << totalPrice << endl; 



























	return 0;
}