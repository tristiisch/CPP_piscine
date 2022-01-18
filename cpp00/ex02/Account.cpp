#include "Account.hpp"
#include <iostream>

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "Account info"  << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
}

Account::~Account(void)
{

}

void	Account::makeDeposit(int deposit)
{

}

bool	Account::makeWithdrawal(int withdrawal)
{
	
}

int		Account::checkAmount(void) const
{

}

void	Account::displayStatus(void) const
{

}
