class SimpleCar:
    def __init__(self):
        self.miles = 0

    def drive(self, dist):
        self.miles = self.miles + dist
        
    def reverse(self, dist):
        self.miles = self.miles - dist
        
    def get_odometer(self):
        return self.miles
    
    def honk_horn(self):
        print('beep beep')
        
    def report(self):
        print(f'Car has driven: {self.miles} miles')
        
if __name__ == "__main__":
    # TODO: Create SimpleCar object
    distance1 = int(input())
    distance2 = int(input())
    simplecar = SimpleCar()
    # TODO: Drive input number of miles forward
    simplecar.drive(distance1)
    # TODO: Drive input number of miles in reverse
    simplecar.reverse(distance2)
    # TODO: Honk the horn
    simplecar.honk_horn()
    # TODO: Report car status
    simplecar.report()