class Calculator:

    # Type your code here.
    def __init__(self, val = 0.0):
        self.val = val
    def add(self, val):
        self.val += val
        return self.val
    def multiply(self, val):
        self.val *= val
        return self.val
    def subtract(self, val):
        self.val -= val
        return self.val
    def divide(self, val):
        self.val /= val
        return self.val
    def clear(self):
        self.val = 0.0
        
    def get_value(self):
        return self.val
        
if __name__ == "__main__":

    calc = Calculator()
    num1 = float(input())
    num2 = float(input())

    # 1. The initial value
    print(f'{calc.get_value():.1f}')

    # 2. The The value after adding num1
    calc.add(num1)
    print(f'{calc.get_value():.1f}')

    # 3. The value after multiplying by 3
    calc.multiply(3)
    print(f'{calc.get_value():.1f}')

    # 4. The value after subtracting num2
    calc.subtract(num2)
    print(f'{calc.get_value():.1f}')

    # 5. The value after dividing by 2
    calc.divide(2)
    print(f'{calc.get_value():.1f}')

    # 6. The value after calling the clear() method
    calc.clear()
    print(f'{calc.get_value():.1f}')