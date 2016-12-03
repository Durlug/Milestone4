//Milestone 4
//CustomMade.h
//Shaun Richardson
//110392156
//srichardson6@myseneca.ca

#ifndef ICT_CUSTOMMADE_H__
#define ICT_CUSTOMMADE_H__

#include "OnShelf.h"
#include "Date.h"
#include "Error.h"
namespace ict {
   class CustomMade :public OnShelf{
   private:
	   Date delivery_;
   public:
	   CustomMade();
	   const Date& delivery() const;
       void delivery(const Date &value);
	   std::fstream& store(std::fstream& file, bool linear = true);
	   std::fstream& load(std::fstream& file);
	   std::ostream& display(std::ostream& ostr, bool linear);
	   std::istream& conInput(std::istream& istr);
   };
}


#endif
