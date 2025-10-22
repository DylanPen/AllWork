cards = [13, 11, 10, 7, 6, 4, 3, 1, 0]
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

def locateCardBinSearch(cards, query):
    low, high = 0, len(cards) - 1
    while low <= high:
        middle = (low + high) // 2
        middleNum = cards[middle]
        print("lo:", low, ", hi:", high, ", mid:", middle, ", mid_number:", middleNum)

        if middleNum == query:
            return middle
        elif middleNum < query:
            high = middle - 1
        else:
            low = middle + 1

    return -1

result = locateCardBinSearch(cards, query)
print(result)