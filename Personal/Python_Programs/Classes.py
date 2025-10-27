class Person:

    amount = 0

    def __init__(self, name, age, height):
        self.name = name
        self.age = age
        self.height = height
        Person.amount += 1

    def __del__(self):
        Person.amount -= 1
        print("Person deleted")

    def helloWorld(self):
        print("Hello, World!")

    def getOlder(self, years):
        self.age += years

    def __str__(self):
        return "Name: {}, Age: {}, Height: {}".format(self.name, self.age, self.height)

class Worker(Person):

    def __init__(self, name, age, height, salary):
        super(Worker, self).__init__(name, age, height)
        self.salary = salary

    def __str__(self):
        text = super(Worker, self).__str__()
        text += ", Salary: {}".format(self.salary)
        return text

    def calcYearlySalary(self):
        return self.salary * 12
    
class Programmer(Worker):

    def __init__(self, name, age, height, salary, language):
        super(Programmer, self).__init__(name, age, height, salary)
        self.language = language

worker1 = Worker("Henry", 22, 180, 3500)
print(worker1)
print(worker1.calcYearlySalary())
