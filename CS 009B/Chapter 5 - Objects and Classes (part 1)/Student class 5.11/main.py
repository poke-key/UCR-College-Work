class Student:
    # Type your code here
    def __init__(self, name = "Louie", gpa = 1.0):
        self.name = name
        self.gpa = gpa
    def set_name(self, name):
        self.name = name   
    def get_name(self):
        return self.name
    def set_gpa(self, gpa):
        self.gpa = gpa
    def get_gpa(self):
        return self.gpa

if __name__ == "__main__":
    initial_student = Student()
    print(f'{ initial_student.get_name() } / { initial_student.get_gpa() }')

    initial_student.set_name('Felix')
    initial_student.set_gpa(3.7)
    print(f'{ initial_student.get_name() } / { initial_student.get_gpa() }')