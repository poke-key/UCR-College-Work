class Instrument:
    def __init__(self, name, manufacturer, year_built, cost):
        self.name = name
        self.manufacturer = manufacturer
        self.year_built = year_built
        self.cost = cost
      
    def print_info(self):
        print(f'Instrument Information:')
        print(f'   Name: { self.name }')
        print(f'   Manufacturer: { self.manufacturer }')
        print(f'   Year built: { self.year_built }')
        print(f'   Cost: { self.cost }')


class StringInstrument(Instrument):
    # TODO: Define constructor with attributes: 
    def __init__(self, name, manufacturer, year_built, cost, num_strings, num_frets, is_bowed):
    #       name, manufacturer, year_built, cost, num_strings, num_frets, is_bowed
        Instrument.__init__(self, name, manufacturer, year_built, cost) #calls the base class constructor
        self.num_strings = num_strings
        self.num_frets = num_frets
        self.is_bowed = is_bowed
      

if __name__ == "__main__":
    instrument_name = input()
    manufacturer_name = input()
    year_built = int(input())
    cost = int(input())
    string_instrument_name = input()
    string_manufacturer = input()
    string_year_built = int(input())
    string_cost = int(input())
    num_strings = int(input())
    num_frets = int(input())
    is_bowed = eval(input())
    
    my_instrument = Instrument(instrument_name, manufacturer_name, year_built, cost)
    my_string_instrument = StringInstrument(string_instrument_name, string_manufacturer, string_year_built, string_cost, num_strings, num_frets, is_bowed)

    my_instrument.print_info()
    my_string_instrument.print_info()
   
    print(f'   Number of strings: { my_string_instrument.num_strings}')
    print(f'   Number of frets: { my_string_instrument.num_frets}')
    print(f'   Is bowed: { my_string_instrument.is_bowed}')