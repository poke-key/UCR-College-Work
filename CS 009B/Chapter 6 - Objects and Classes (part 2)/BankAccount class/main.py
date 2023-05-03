# TODO: Define BankAccount class
class BankAccount:
    # TODO: Define constructor with parameters to initialize instance attributes
    def __init__(self, name, checking_balance, savings_balance):
        self.name = name
        self.checking_balance = checking_balance
        self.savings_balance = savings_balance
    # TODO: Define deposit_checking()
    def deposit_checking(self, amount):
        if(amount > 0):
            self.checking_balance += amount
    # TODO: Define deposit_savings()
    def deposit_savings(self, amount):
        if(amount > 0):
            self.savings_balance += amount
    # TODO: Define withdraw_checking()
    def withdraw_checking(self, amount):
        if(amount > 0):
            self.checking_balance -= amount
    # TODO: Define withdraw_savings()
    def withdraw_savings(self, amount):
        if(amount > 0):
            self.savings_balance -= amount
    # TODO: Define transfer_to_savings()
    def transfer_to_savings(self, amount):
        if(amount > 0):
            self.checking_balance -= amount
            self.savings_balance += amount

if __name__ == "__main__":
    account = BankAccount("Mickey", 500.00, 1000.00)
    account.checking_balance = 500
    account.savings_balance = 500
    account.withdraw_savings(100)
    account.withdraw_checking(100)
    account.transfer_to_savings(300)

    print(account.name)
    print(f'${account.checking_balance:.2f}')
    print(f'${account.savings_balance:.2f}')