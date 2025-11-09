#include "app.h"#
#include <iostream>
#include <format>


// read number of results
// read all student data
// read grade and output grade statistics
// read letter and output letter statistics
int main()
{
	// program u?itava rezultate - prvo broj unosa, nakon toga za svakog studenta: ime (jedna rije?) i ocjena (cijeli broj)
	unsigned int brojStudenata;
	std::cout << "Unesite broj studenata: ";
	std::cin >> brojStudenata;

	vsite::oop::v3::results r(brojStudenata);


	for (int i = 0; i < brojStudenata; i++)
	{
		std::string ime;
		int ocjena;
		std::cout << std::format("Unesite ime i ocjenu za studenta {}: ", i + 1);
		
		std::cin >> ime >> ocjena;
		r.add({ ime, ocjena });
	}

	std::cout << "\n";
	// prvo se unosi ocjena za koju se želi statistika - program ispisuje broj studenata sa tom ocjenom
	int grade;
	std::cout << "Unesite ocjenu za statistiku: ";
	std::cin >> grade;
	std::cout << std::format("Broj studenata sa ocjenom {}: {}\n", grade, r.has_grade(grade));
	

	std::cout << "\n";
	// nakon toga unosi se prvo slovo studenata za koje se želi statistika - 
	// program ispisuje broj studenata koji po?inju tim slovom(neovisno malo / veliko)
	char letter;
	std::cout << "Unesite slovo za statistiku: ";
	std::cin >> letter;

	std::cout << std::format("Broj studenata koji pocinju slovom '{}': {}\n", letter, r.starts_with_letter(letter));



	return 0;

}
