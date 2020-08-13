/* Lab 1
 * Chris Cheng
 * Assignment Purpose: The purpose of this assignment is to model a Currency 
 * Simulator by manipulating a Canadian Dollar object and a U.S dollar object.
 */

#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

class Dollar {
protected:
	int note_value, coin_value;
	std::string note_name, coin_name;
public:
	/* Algorithm Dollar (int n_value = 0, int c_value = 0, 
								string n_name = "Dollars", string c_name = "Cents")
 * This algorithm is both the default constructor and the constructor
 * that takes an argument for each data member.
 * Pre: note_value - currency whole part value  
 		  coin_value - currency fractional part value
 		  note_name - currency whole part name
 		  coin_name - currency fractional part name
 * Post: no information passed back to calling function
 * Return: constructor has no return type
 */
	Dollar (int n_value = 0, int c_value = 0, 
				std::string n_name = "Dollars", std::string c_name = "Cents") {
		Set_Note_Value(n_value);
		Set_Coin_Value(c_value);
		Set_Note_Name(n_name);
		Set_Coin_Name(c_name);
	}

/* Algorithm Dollar (const Dollar& object)
 * This algorithm is the copy constructor and returns a Dollar object with
 * the attributes copied from the constant reference parameter Dollar object.
 * Pre: object - reference parameter Dollar object
 * Post:
 * Return: constructor has no return type
 */
	Dollar (Dollar& object) {
		note_value = object.note_value;
		coin_value = object.coin_value;
		note_name = object.note_name;
		coin_name = object.coin_name;
	}

/* Algorithm Set_Note_Value (int n_value)
 * This algorithm sets the currency note value. 
 * Pre: n_value - currency whole part value
 * Post: no information passed back to calling function
 * Return: void 
 */
	void Set_Note_Value(int n_value) {
		note_value = n_value;
	}

/* Algorithm Set_Coin_Value (int c_value)
 * This algorithm sets the currency coin value.
 * Pre: c_value - currency fractional part value
 * Post:
 * Return: void 
 */
	void Set_Coin_Value(int c_value) {
		coin_value = c_value;
	}

/* Algorithm Set_Note_Name (string n_name)
 * This algorithm sets the currency note name.
 * Pre: n_name - currency note name
 * Post:
 * Return: void
 */
	void Set_Note_Name(std::string n_name) {
		note_name = n_name;
	}
/* Algorithm Set_Coin_Name (string c_name)
 * This algorithm sets the currency coin name.
 * Pre: c_name - currency coin name
 * Post:
 * Return: void
 */
	void Set_Coin_Name(std::string c_name) {
		coin_name = c_name;
	}
/* Algorithm Get_Note_Value ()
 * This algorithm returns the currency note value. 
 * Pre: 
 * Post: n_value - currency whole part value
 * Return: int 
 */
	int Get_Note_Value() {
		return note_value;
	}

/* Algorithm Get_Coin_Value ()
 * This algorithm returns the currency coin value.
 * Pre: 
 * Post: c_value - currency fractional part value
 * Return: int 
 */
	int Get_Coin_Value() {
		return coin_value;
	}

/* Algorithm Get_Note_Name ()
 * This algorithm returns the currency note name.
 * Pre: 
 * Post: n_name - currency note name
 * Return: string
 */
	std::string Get_Note_Name() {
		return note_name;
	}
/* Algorithm Get_Coin_Name ()
 * This algorithm returns the currency coin name.
 * Pre: 
 * Post: c_name - currency coin name
 * Return: string
 */
	std::string Get_Coin_Name() {
		return coin_name;
	}

/* Algorithm operator+ (const Dollar& object)
 * This algorithm adds two objects of the same currency and 
 * returns the currency sum.
 * Pre: object - constant Dollar object reference parameter
 * Post: 
 * Return: Dollar object that contains the currency sum  
 */
	Dollar operator+(const Dollar& object) {
		Dollar temp;
		temp.note_name = object.note_name;
		temp.coin_name = object.coin_name;
		temp.note_value = object.note_value + note_value;
		temp.coin_value = object.coin_value + coin_value;
		// convert spare change into dollars if possible 
		if (temp.coin_value >= 100) {
			temp.note_value += temp.coin_value / 100;
			temp.coin_value %= 100;
		}
		return temp;
	}
/* Algorithm operator- (const Dollar& object)
 * This algorithm subtracts two objects of the same currency and returns
 * the currency difference.
 * Pre: object - constant Dollar object reference parameter
 * Post:
 * Return: Dollar object that contains the currency difference
 */
	Dollar operator-(const Dollar& object) {
		Dollar temp;
		temp.note_name = object.note_name;
		temp.coin_name = object.coin_name;
		int note_value_difference = note_value - object.note_value;
		int coin_value_difference = coin_value - object.coin_value;
		if (coin_value_difference < 0) {
			note_value_difference -= 1;
			coin_value = 100 + coin_value_difference;
		}
		else {
			coin_value = coin_value_difference;
		}
		note_value = note_value_difference;		
		return temp;
	}

/* Algorithm operator== (const Dollar& object)
 * This algorithm compares two objects of the same currency for equality
 * and returns True for equal currency amount and False for inequal currency
 * amount.
 * Pre: object - constant Dollar object reference parameter
 * Post:
 * Return: bool
 */
	bool operator==(const Dollar& object) {
		if (note_value == object.note_value && coin_value == object.coin_value) {
			return true;
		}
		return false;
	}

/* Algorithm operator> (const Dollar& object)
 * This algorithm compares two objects of the same currency and returns true
 * if the Dollar reference parameter currency amount is smaller than the 
 * calling Dollar object amount, and false if otherwise.
 * Pre: object - constant Dollar object reference parameter
 * Post:
 * Return: bool
 */
	bool operator>(const Dollar& object) {
		// calling object is larger if calling object note_value > parameter 
		// object note value or if they have same note value and calling object
		// has larger coin value
		if (note_value > object.note_value || 
			(operator==(object) && coin_value > object.coin_value)) {
			return true; 
		}
		return false;
	}

/* Algorithm operator<< (ostream& out, const Dollar& object)
 * This algorithm prints the attribute details of the currency object.
 * Pre: out - output stream object reference parameter
 		  object - constant Dollar object reference parameter
 * Post;
 * Return: ostream reference object
 */
	ostream& operator<<(ostream& out, const Dollar& object) {
		out << object.note_value << " " << object.note_name << " " 
		    << object.coin_value << " " << object.coin_name;
		return out;
	}
};

class CAD : public Dollar {
private:
	const double USD_CAD_conversion_factor = 1/1.36;
public:
/* Algorithm CAD ()
 * This algorithm 
 * Pre: no arguments
 * Post: 
 * Return: USD object 
 */

/* Algorithm Convert_To_USD ()
 * This algorithm 
 * Pre: no arguments
 * Post: 
 * Return: USD object 
 */
	Dollar Convert_To_Dollar() {
		Dollar temp;
		temp.note_value = note_value * USD_CAD_conversion_factor;
		temp.coin_value = coin_value * USD_CAD_conversion_factor;
		return temp;
	}

/* Algorithm Convert_From_USD (const Dollar& object)
 * This algorithm converts a USD object to a CAD object.
 * Pre: constant Dollar object reference parameter
 * Post:
 * Return: CAD object
 */
	CAD Convert_From_Dollar(const Dollar& object) {
		CAD temp;
		temp.note_value = object.note_value / USD_CAD_conversion_factor;
		temp.coin_value = object.coin_value / USD_CAD_conversion_factor;
		return temp;
	}
};

#endif // CURRENCY_H