class Plant:
    def __init__(self, plant_name, plant_cost):
        self.plant_name = plant_name
        self.plant_cost = plant_cost

    def print_info(self):
        print(f'   Plant name: { self.plant_name }')
        print(f'   Cost: { self.plant_cost }')

class Flower(Plant):
    def __init__(self, plant_name, plant_cost, is_annual, color_of_flowers):
        Plant.__init__(self, plant_name, plant_cost)
        self.is_annual = is_annual
        self.color_of_flowers = color_of_flowers

    def print_info(self):
        print(f'   Plant name: { self.plant_name }')
        print(f'   Cost: { self.plant_cost }')
        print(f'   Annual: { self.is_annual }')
        print(f'   Color of flowers: { self.color_of_flowers }')

# TODO:  Define the print_list() function that prints a list of plant (or flower) objects 
def print_list(garden):
    for idx, plants in enumerate(garden): #accesses the index number of the list
        print(f'Plant {idx + 1} Information:')
        plants.print_info()
        #if(idx + 1 != len(garden)):
        print("") #prints a new line
    
if __name__ == "__main__":

    # TODO: Declare a list called my_garden that can hold object of type plant
    my_garden = []
    user_string = input()
    
    while user_string != '-1':
        # TODO: Check if input is a plant or flower
        attribList = user_string.split()
        if(attribList[0] == 'plant'):
            my_plant = Plant(attribList[1], attribList[2])
            my_garden.append(my_plant)
        if(attribList[0] == 'flower'):
            my_flower = Flower(attribList[1], attribList[2],attribList[3], attribList[4])
            my_garden.append(my_flower)
        #print(attribList)
        #       Split the user_string input into variables - plant_name, plant_cost, color_of_flowers, is_annual
        #       Store as a plant object or flower object
        #       Add to the list my_garden
        user_string = input()

    # TODO: Call the print_list() function to print my_garden
    print_list(my_garden)