#include "fraction.h"
#include <format>

fraction_t::fraction_t() {  // конструктор без параметрів - констуктор за замовчанням
	numerator = 0;          // f = new fraction_t  або  f = new fraction_t()
	denominator = 1;
}

fraction_t::fraction_t(int n) {  // конструктор з параметрами, його слід зазначати
	numerator = n;               // прямо (не за замовчанням) f = new fraction_t(10)
	denominator = 1;             // Присвоювання значень
}

fraction_t::fraction_t(int numerator, int denominator) : // ініціалізація полів
	numerator{ numerator }, denominator{ denominator }   // на відміну від присвоювання
{                                                        // дозволяє задавати значення
}                                                        // незмінним полям (константам)

int fraction_t::get_numerator() {
	return numerator;
}

int fraction_t::get_denominator() {
	return denominator;
}

void fraction_t::set_numerator(int numerator) {
	this->numerator = numerator;
	/* this - покажчик на об'єкт, неявний параметр, що передається у 
	   нестатичні методи класу. */
}

void fraction_t::set_denominator(int denominator) {
	this->denominator = denominator;
}

std::string fraction_t::to_string() {
	// форматування рядків - заповнення "формату" - рядка з плейсхолдерами
	//                    v   v - placeholders
	return std::format("({0}/{1})", numerator, denominator);
	//                                  ^           ^
	//               дані, які будуть підставлені на міце плейсхолдерів
}

/*
Д.З. Описати клас, що задає вектор на площині (vector_2 / vector2_t)
склад: 2 поля-координати х та у (дробові)
+ аксессори для них
Розділити оголошення типу та реалізацію його методів на різні файли.
*/