cards = [13, 11, 10, 9, 9, 9, 9, 9, 9, 9, 9, 7, 7, 7, 7, 6, 4, 3, 1, 0]
query = 7
# TODO: We need to write a program to find the position of a given number in a list 
# of numbers arranged in decreasing order. We also need to minimize the number of 
# times we access elements from the list.

# Output should be 3

# This is a linear search method that finds query
# in O(n) time
def locateCardLinearly(cards, query):
    for i in cards:
        if i == query:
            return cards.index(i)
    return -1

# result = locateCardLinearly(cards, query)

# This is a binary search method that finds qurey
# in O(log n) time
def test_location(cards, query, middle):
    if cards[middle] == query:
        if middle - 1 >= 0 and cards[middle - 1] == query:
            return "left"
        else:
            return "found"
    elif cards[middle] < query:
        return "left"
    else:
        return "right"

def locateCardBinSearch(cards, query):
    low, high = 0, len(cards) - 1
    while low <= high:
        middle = (low + high) // 2
        middleNum = cards[middle]
        print("lo:", low, ", hi:", high, ", mid:", middle, ", mid_number:", middleNum)
        result = test_location(cards, query, middle)

        if result == "found":
            return middle
        elif result == "left":
            high = middle - 1
        elif result == "right":
            low = middle + 1

    return -1

result = locateCardBinSearch(cards, query)
print(result)