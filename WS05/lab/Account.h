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
      void setNew();
      std::ostream& display()const;
      explicit operator int()const;
      explicit operator double()const;
      operator bool()const;
      bool operator ~()const;
      Account& operator =(int number);
      Account& operator =(Account& acc);
      Account& operator +=(double val);
      Account& operator -=(double val);
      Account& operator <<(Account& acc);
      Account& operator >>(Account& acc);
      friend  double operator +=(double& val,const Account& acc2);
      friend double operator +(const Account& acc1,const Account& acc2);
   };
   
   
}
#endif // SDDS_ACCOUNT_H_
