
#include "Word.h"

#include <string>
#include <algorithm>
#include <istream>
#include <ostream>
#include <cctype>
#include <locale>
#include <stdexcept>

namespace word
{
	const std::locale loc{};


	Word::Word(std::string const & word)
		: word{word}
	{
		if(!isValidWord(word)) {
			throw std::invalid_argument("invalid word");
		}
	}

	Word::Word(std::istream & in)
		: word{}
	{
		read(in);
	}

	bool word::Word::isValidWord(const std::string& word) {

		return !word.empty() &&
				std::all_of(
						std::begin(word),
						std::end(word),
						static_cast<int(*)(int)>(std::isalpha));
	}

	std::istream & word::Word::discardInvalidPrefix(std::istream & is) {

		while(is.good() && !std::isalpha(is.peek())) {
			is.ignore();
		}

		return is;
	}

	std::istream & word::Word::read(std::istream & is)
	{
		if(is.eof()) {
			throw std::out_of_range("invalid word");
		}

		discardInvalidPrefix(is);

		std::string buffer{};

		while(is.good() && std::isalpha(is.peek())) {
			buffer += is.get();
		}

		if(isValidWord(buffer)){
			word = buffer;
		} else {
			is.setstate(std::ios_base::failbit);
			return is;
		}

		return is;
	}

	std::ostream & word::Word::print(std::ostream & os) const
	{
		os << word;
		return os;
	}
}
