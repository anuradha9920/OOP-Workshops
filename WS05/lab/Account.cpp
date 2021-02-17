#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   void Account::setNew(){
       m_number = 0;
       m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const{
      if(this->m_number==-1 || this->m_number==0){
      	return false;
	  }
	  return true;
   }
   Account::operator int() const{ 
      int acc_number = this->m_number;
        return (acc_number);
   }
   Account::operator double() const{
      double acc_balance = this->m_balance;
      return (acc_balance);
   } 
   bool Account::operator ~()const{
      if(m_number==0){
      	return true;
	  }
	  return false;
   }  
   Account& Account::operator =(int number){
   		if(m_number==0){
   			setEmpty();
			if(number >= 10000 && number <= 99999){
   				this->m_number= number;	
			}	
		}
		return *this;
   }
   Account& Account::operator =(Account& acc){
   		if(int(acc)!=-1){
   			if(this->m_number==0){
   				this->m_number=int(acc);
   				this->m_balance=double(acc);
				acc.setNew();
			}
		}
		return *this;
   }
   Account& Account::operator +=(double val){
   		if(this->m_balance!=0 && this->m_balance!=-1 && val>0){
   			this->m_balance +=val;	
		}
		return *this;
   }
   Account& Account::operator -=(double val){
   		if(this->m_number!=-1 && val>0 && val<=this->m_balance){
   			this->m_balance -=val;
		}
		return *this;
   }
   Account& Account::operator <<(Account& acc){
   		
   		if(this->m_number!=int(acc)&& this->m_number!=-1 && this->m_number!=0 && int(acc)!=0 && int(acc)!=-1){
   			this->m_balance+=double(acc);
   			int acc_number=int(acc);
			acc.setNew();
			acc = acc_number;
		}
		return *this;
   }
   Account& Account::operator >>(Account& acc){
   		
   		if(this->m_number!=int(acc) && this->m_number!=-1 && this->m_number!=0 && int(acc)!=0 && int(acc)!=-1){
   			acc+=this->m_balance;
   			this->m_balance=0;
		}
		return *this;
   }
   double operator +(const Account& acc1,const Account& acc2){
   		if(int(acc1)!=-1&&int(acc2)!=-1){
   			return double(acc1)+double(acc2);	
		}
		return 0;
   }
   double operator +=(double& val,const Account& acc){
   		
   		if(int(acc)!=-1){
   			val+=double(acc);	
		}
		return val;
   }
}
