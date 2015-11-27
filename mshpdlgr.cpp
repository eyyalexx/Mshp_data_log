#include <stdio.h>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class shopper {
	 protected:
	 	char *shopper_name;
	 	int years_a_member;
	 	double avg_monthly_purchases = 50;
	 	double membership_cost = 50;
	 	double nominal_membership_cost = 50;

	 public:
	 	shopper(void);		//Constructor outside the class.
	 	shopper(char *sh_nm, int yrs_a_mbr, double av_mnth_prchs);
	 	~shopper(void){
	 		delete [] shopper_name;
	 	}

	 	virtual void set_membership_cost(void){
	 		if(years_a_member < 5){
	 			membership_cost = nominal_membership_cost - ((avg_monthly_purchases * 0.01)/2) - (50*0.04*years_a_member);
	 		} else {
	 			membership_cost = 30;
	 		}
	 	}

	 	double get_membership_cost(void){
	 		return membership_cost+=2;
	 	}

	 	char * get_shopper_name(void){
	 		return shopper_name;
	 	}
};

shopper::shopper(void){		//Constructor
	years_a_member = 0;
	avg_monthly_purchases = 250;
	shopper_name = new char[1];


}

shopper::shopper(char *sh_nm, int yrs_a_mbr, double av_mnth_prchs){
	shopper_name = new char[strlen(sh_nm)+1];
	strcpy(shopper_name, sh_nm);
	years_a_member = yrs_a_mbr;
	avg_monthly_purchases = av_mnth_prchs;
}

ostream& operator<<(ostream& os, shopper& shpr){	//operator overloaded for the base class
	os << shpr.get_shopper_name() << " has yearly membership cost of $" << shpr.get_membership_cost() << endl;
	return os;
}

class family_shopper : public shopper {	//derived class from shopper
	private:
		double family_discount;

	public:
		family_shopper(double fam_disc = 10, int yrs_a_mbr = 2, double av_mnth_prchs = 100, char *f_sh_nm = new char[1]){
			strcpy(shopper_name, f_sh_nm);
			avg_monthly_purchases = av_mnth_prchs;
			years_a_member = yrs_a_mbr;
			family_discount = fam_disc;
		}

		virtual void set_membership_cost(void){
			if(years_a_member < 5){
	 			membership_cost = nominal_membership_cost - ((avg_monthly_purchases * 0.01)/2) - (50*0.04*(1-family_discount/100));
	 		} else {
	 			membership_cost = 30;
	 		}
		}

		friend ostream& operator<<(ostream& os, family_shopper& f_shpr){
			os << f_shpr.shopper_name << " is a family shopper whose annual membership with discount of " << setprecision (0) << fixed << f_shpr.family_discount << "% is $" 
			   << setprecision(2) << fixed << f_shpr.membership_cost << endl;
			return os;
		}

};


int main (){

	shopper shpr1("ABC", 3, 600);
	shopper shpr2("DEF", 6, 0);
	family_shopper f_shpr1(12, 2, 100, "GHI");

	shopper *ptr;

	cout.setf(ios::fixed);
	cout.precision(0);

	ptr = &shpr1;
	ptr->set_membership_cost();
	cout << shpr1 << endl;

	ptr = &shpr2;
	ptr->set_membership_cost();
	cout << shpr2 << endl;

	ptr = &f_shpr1;
	ptr->set_membership_cost();
	cout << f_shpr1 << endl;


	return 0;
}