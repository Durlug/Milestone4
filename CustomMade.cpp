//Milestone 4
//CustomMade.cpp
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca

#include "CustomMade.h"

namespace ict 
{

	CustomMade::CustomMade(): OnShelf('C')
	{
	}

	const Date& CustomMade::delivery() const
	{
		return delivery_;
	}

	void CustomMade::delivery(const Date& value)
	{
		delivery_ = value;
	}

	std::fstream& CustomMade::store(std::fstream& file, bool addNewLine) const
	{
		OnShelf::store(file, false);
		file << ",";
		delivery_.write(file);

		if (addNewLine)
		{
			file << std::endl;
		}
		return file;
	}

	std::fstream& CustomMade::load(std::fstream& file)
	{
		OnShelf::load(file);
		delivery_.read(file);
		file.ignore(1);
		return file;
	}

	std::ostream& CustomMade::display(std::ostream& os, bool linear) const
	{
		OnShelf::display(os, linear);
		if (err_.isClear()) 
		{
			if (linear)
			{
				os << delivery();
			}
			else
			{
				os << std::endl << "Delivery Date: " << delivery();
			}
		}
		return os;
	}

	std::istream& CustomMade::conInput(std::istream& is)
	{
		Date temp;
		OnShelf::conInput(is);

		if (err_.isClear())
		{
			std::cout << "Delivery Date (YYYY/MM/DD):";
			is >> temp;

			if (temp.bad())
			{
				if (temp.errCode() == CIN_FAILED)
				{
					err_.message("Invalid Date Entry");
				}
				else if (temp.errCode() == YEAR_ERROR)
				{
					err_.message("Invalid Year in Date Entry");
				}
				else if (temp.errCode() == MON_ERROR)
				{
					err_.message("Invalid Month in Date Entry");
				}
				else if (temp.errCode() == DAY_ERROR)
				{
					err_.message("Invalid Day in Date Entry");
				}
				is.setstate(std::ios::failbit);
			}
			else
			{
				delivery(temp);
			}
		}
		return is;
	}
}
