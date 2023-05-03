class Pet:
    def __init__(self):
        self.name = ''
        self.age = 0
    
    def print_info(self):
        print(f'Pet Information:')
        print(f'   Name: { self.name }')
        print(f'   Age: { self.age }')

class Cat(Pet):
    def __init__(self):
        Pet.__init__(self) 
        self.breed = ''
    def print_info(self):
        Pet.print_info(self)
        print(f'   Breed: { self.breed }')

my_pet = Pet()
my_cat = Cat()

pet_name = input()
pet_age = int(input())
cat_name = input()
cat_age = int(input())
cat_breed = input()

# TODO: Create generic pet (using pet_name, pet_age) and then call print_info()
my_pet.name = pet_name
my_pet.age = pet_age
my_pet.print_info()
# TODO: Create cat pet (using cat_name, cat_age, cat_breed) and then call print_info()
my_cat.name = cat_name
my_cat.age = cat_age
my_cat.breed = cat_breed
my_cat.print_info()
# TODO: Use my_cat.breed to output the breed of the cat

