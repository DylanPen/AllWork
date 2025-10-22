# Strings
# Strings are immutable
string = "Quandale"
stringLen = len(string)
# Slicing
print(string[:stringLen])

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Lists
# Supports concatanation and slicing
squares = [1, 4, 9, 16, 25]
prime = [1, 2, 3, 5, 7]
sp = [squares, prime]
squares.append(6*6)
listLen = len(squares)
print("Squares List Length: ", listLen)
print(sp)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Loops
# While Loop
# respective variable definition
a, b = 0, 1
while a < 10:
    print(a)
    a, b = b, a+b

# For Loop
words = ["cat", "dog", "fish"]
for i in words:
    print(i, len(i))
# This is a collection
users = {"Blazer": "active", "Fanz": "inactive"}
print(users)
# Iterating over a collection
for user, status in users.copy().items():
    if status == "inactive":
        del users[user]
print(users)

activeUsers = {}
for user, status in users.items():
    if status == "active":
        activeUsers[user] = status
print(activeUsers)

# Use range() to iterate over a set amount
rangeNum = 2
for i in range(rangeNum):
    print("3")
    # ELSE CLAUSES
    # else after for loop will run after loop ends - for while loop it runs after condition is false
    for j in range(3):
        print("2")
    else:
        print("Else Clause")
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# If Statements

x = 1
if x == 1:
    x = 0
elif x == 0:
    x = 1
else:
    print("wtf")

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Switch-Case statement
# In python its a match-case statement and use return instead of break

def matchCase(matchArg):
    match matchArg:
        case 3:
            return "Nope"
        case 4:
            return "Not this one"
        case 5:
            return "Yep"
        case _:
            return "wtf"

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# Functions

def fib(n):
    """Print a Fibonacci series less than n."""
    a, b = 0, 1
    while a < n:
        print(a, end= " ")
        a, b = b, a+b
    print()

fib(100)

def fib2(n):  # return Fibonacci series up to n
    """Return a list containing the Fibonacci series up to n."""
    result = []
    a, b = 0, 1
    while a < n:
        result.append(a)    # see below
        a, b = b, a+b
    return result

f100 = fib2(100)
print(f100)

# You can add a value to a function parameter to make it optional to set the value

def onePlusNum(num = 1):
    """One plus num function"""
    return 1 + num
num = onePlusNum()
print("Default: ", num)
num = onePlusNum(5)
print("Modified: ", num)

def cheeseshop(kind, *arguments, **keywords):
    print("-- Do you have any", kind, "?")
    print("-- I'm sorry, we're all out of", kind)
    for arg in arguments:
        print(arg)
    print("-" * 40)
    for kw in keywords:
        print(kw, ":", keywords[kw])

cheeseshop("Limburger", "It's very runny, sir.",
           "It's really very, VERY runny, sir.",
           shopkeeper="Michael Palin",
           client="John Cleese",
           sketch="Cheese Shop Sketch")