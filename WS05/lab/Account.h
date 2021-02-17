#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account{
      int m_number;
      double m_balance; 
      void setEmpty();
    public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator ~()const;
      Account& operator =(int number);
      Account& operator =(Account& acc);
      Account& operator +=(double val);
      Account& operator -=(double val);
      Account& operator <<(Account& acc);
      Account& operator >>(Account& acc);
      double friend operator+(const Account acc1,const Account acc2);
	  double friend operator+=(const double& val,const Account acc2);
   };
   
   
}
#endif // SDDS_ACCOUNT_H_
