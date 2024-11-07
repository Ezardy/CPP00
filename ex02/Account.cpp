#include <iostream>
#include <iomanip>
#include <ctime>

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::makeDeposit(int deposit) {
	t::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	if (deposit > 0) {
		_amount += deposit;
		t::_totalAmount += deposit;
		_nbDeposits += 1;
		t::_totalNbDeposits += 1;
		std::cout << ";deposit:" << deposit << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits;
	} else
		std::cout << ";deposit:refused";
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	bool	made;
	t::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal > 0 && _amount - withdrawal >= 0) {
		_amount -= withdrawal;
		t::_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		t::_totalNbWithdrawals += 1;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals;
		made = true;
	} else {
		std::cout << ";withdrawal:refused";
		made = false;
	}
	std::cout << std::endl;
	return made;
}

int	Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	t::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(void) {
	const time_t	timer = std::time(NULL);
	const std::tm	*date = std::localtime(&timer);

	std::cout << std::put_time(date, "[%Y%m%d_%H%M%S]");
}

void	Account::displayAccountsInfos(void) {
	t::_displayTimestamp();
	std::cout << " accounts:" << t::getNbAccounts() << ";total:"
		<< t::getTotalAmount() << ";deposits:" << t::getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(void)
: _accountIndex(-1), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {

}

Account::~Account(void) {
	t::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" <<std::endl;
}

Account::Account(int initial_deposit)
: _accountIndex(t::_nbAccounts++), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	t::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount
		<< ";created" << std::endl;
}
