import re

class Employee:
    def __init__(this, name, phone, bday, email, position):
        this.__name = name
        this.__phone = phone
        this.__bday = bday
        this.__email = email
        this.__position = position

    def calculateAge(this):
        return this.bday
    def calculateSalary(this):
        return 0

    @property
    def name(this):
        return this.__name
    @name.setter
    def name(this, name):
        this.__name = name

    @property
    def phone(this):
        return this.__phone
    @phone.setter
    def phone(this, phone):
        this.__phone = phone 

    @property
    def bday(this):
        return this.__bday
    @bday.setter
    def bday(this, bday):
        this.__bday = bday
        
    @property
    def email(this):
        return this.__email
    @email.setter
    def email(this, email):
        this.__email = email 

    @property
    def position(this):
        return this.__position
    @position.setter
    def position(this, position):
        this.__position = position

class HourlyEmployee(Employee):
    def __init__(this, name, phone, bday, email, position, nmbrOfHour, hourlyPay):
        Employee.__init__(this, name, phone, bday, email, position)
        this.__nmbrOfHour = nmbrOfHour
        this.__hourlyPay = hourlyPay
    def calculateSalary(this):
        return this.nmbrOfHour * this.hourlyPay

    @property
    def nmbrOfHour(this):
        return this.__nmbrOfHour
    @nmbrOfHour.setter
    def nmbrOfHour(this, nmbrOfHour):
        this.__nmbrOfHour = nmbrOfHour

    @property
    def hourlyPay(this):
        return this.__hourlyPay
    @hourlyPay.setter
    def hourlyPay(this, hourlyPay):
        this.__hourlyPay = hourlyPay

class SlaryEmployee(Employee):
    def __init__(this, name, phone, bday, email, position, salary):
        Employee.__init__(this, name, phone, bday, email, position)
        this.__salary = salary

    def calculateSalary(this):
        return this.salray

    @property
    def salary(this):
        return this.__salary
    @salary.setter
    def salary(this, salary):
        this.__salary = salray

def verifyInput(regex, inputMess, errorMess):
    inp = input(inputMess)
    while re.search(regex, inp) == None:
        print(errorMess)
        inp = input(inputMess)
    return inp

def createEmployeeParams():
    name = verifyInput("^[a-zA-Z]{2,20}$", "Nume: ", "Nume invalid")
    phone = verifyInput("^\+373[0-9]{8}$", "Phone: ", "Phone invalid")
    bday = verifyInput("^(0[1-9]|[12][0-9]|3[01])\.(0[1-9]|1[012]).(19[6-9][0-9]|200[0-7])$", "Birth day: ", "birth day invalid")
    email = verifyInput("^[a-zA-Z0-9_|-|.]{2,20}@[a-zA-Z]{4,7}\.[a-zA-Z]{2,4}$", "Email: ", "Email invalid")
    position = verifyInput("^[a-zA-Z]{4,20}$", "Position: ", "Position invalid")
    return [name, phone, bday, email, position]

def createEmployee():
    eP = createEmployeeParams()
    return Employee(eP[0], eP[1], eP[2], eP[3], eP[4])

def createHourlyEmployee():
    eP = createEmployeeParams()
    workHours = verifyInput("^[0-9]{1,5}$", "Number of hours: ", "Numbers of hours invalid")
    hourlyPay = verifyInput("^[0-9]{1,10}$", "Money per hour: ", "Money per hoyr invalid")
    return HourlyEmployee(eP[0], eP[1], eP[2], eP[3], eP[4], int(workHours), int(hourlyPay))

def createSalaryEmployee():
    eP = createEmployeeParams()
    salary = verifyInput("^[0-9]{1,10}$", "Salary: ", "Salary invalid")
    return SlaryEmployee(eP[0], eP[1], eP[2], eP[3], eP[4], int(salary))

def displayEmployee(employee):
    print(f"""
Name: {employee.name}
Phone: {employee.phone}
Birth day: {employee.bday}
Email: {employee.email}
Position: {employee.position}
Salary: {employee.calculateSalary()}
    """)
